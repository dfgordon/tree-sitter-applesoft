'''This program performs automatic edits to the sources for the parser.
This is automatically invoked by running `build.py`.
Inputs:
`token_list.txt` - CSV file with the A2ROM tokens
`allow_lower_case` - variable defined below
Mappings:
`scanner-src.c` to `src/scanner.c`,
`grammar-src.js` to `grammar.js`
Products:
`applesoft.tmGrammar.json` (simple TextMate grammar, not the main grammar)
`token_list.json` data for every token'''

import sys
import pathlib
import csv
import re
import json

def Usage():
    print('Usage: python token_processor.py --allow-call-args <bool> --allow-lower-case <bool> [--help]')
    print('--allow-lower-case: 0 or 1, forbid or allow lower case in tokens and variable names')
    print('--allow-call-args: 0 or 1, forbid or allow trailing expressions following CALL statement')

flags = ['--allow-lower-case','--allow-call-args','--help']
allow_lower_case = None
allow_call_args = None
arg_idx = 1
while (arg_idx<len(sys.argv)):
    if sys.argv[arg_idx] not in flags:
        raise ValueError('unrecognized argument '+sys.argv[arg_idx])
    if sys.argv[arg_idx]=='--help':
        Usage()
        exit(0)
    if sys.argv[arg_idx]=='--allow-lower-case':
        arg_idx += 1
        allow_lower_case = bool(int(sys.argv[arg_idx]))
    if sys.argv[arg_idx]=='--allow-call-args':
        arg_idx += 1
        allow_call_args = bool(int(sys.argv[arg_idx]))
    arg_idx += 1

if allow_lower_case==None or allow_call_args==None:
    raise ValueError('flags must be explicitly set')

# First step is to gather and check the tokens

tokens = []

# Mapping of special characters to javascript identifier fragments

sp_map = {  '#' : 'n',
            '$' : '',
            ':' : '',
            '&' : 'amp',
            '(' : 'p',
            '+' : 'plus',
            '-' : 'minus',
            '*' : 'times',
            '/' : 'div',
            '^' : 'pow',
            '>' : 'gtr',
            '=' : 'eq',
            '<' : 'less'
}

with open('token_list.txt','r') as f:
    reader = csv.reader(f,delimiter=',')
    i = 0
    for row in reader:
        for item in row:
            tokens += [{'code':i+0x80,'lexeme':item}]
            i += 1

expected_num = 0xea-0x80+1
if len(tokens)!=expected_num:
    raise ValueError('Number of tokens is off by '+str(len(tokens)-expected_num))
else:
    print('Found',expected_num,'tokens as expected.')

check = set()
for t in tokens:
    check.add(t['lexeme'])
if len(check)!=len(tokens):
    raise ValueError('There were duplicate tokens.')
else:
    print('Uniqueness check OK')

# Now add the rule id's

for t in tokens:
    print(hex(t['code']),t['lexeme']) # spot check
    # form a suitable javascript identifier
    id = ''
    for c in t['lexeme']:
        if c in sp_map.keys():
            id += sp_map[c]
        else:
            id += c
    t['rule id'] = "tok_" + id

# Form a token rule as regex for Tree-sitter (JavaScript)

def allow(c):
    if allow_lower_case:
        return '[' + c.upper() + c.lower() + ']'
    else:
        return c.upper()

def tok_regex_js(tok):
    ans = ''
    if len(tok)>1:
        
        for c in tok[:-1]:
            ans += allow(c) + ' *'
        ans += allow(tok[-1])
        ans = '/' + ans + '/'
        ans = ans.replace('$','\$')
        ans = ans.replace('(','\(')
    else:
        ans = "'" + tok + "'"
    return ans

# Form a token rule as regex for TextMate (JSON)

def tok_regex_json(tok):
    ans = ''
    if len(tok)>1:
        for c in tok[:-1]:
            ans += allow(c) + ' *'
        ans += allow(tok[-1])
        ans = ans.replace('$','\$')
        ans = ans.replace('(','\(')
    else:
        ans = tok
    return ans

# Build some C-code for the external scanner
# N.b. `AT` token requires special handling

scanner_code = ''
num_exclusions = 0
for t in tokens:
    lx = t['lexeme']
    if len(lx)>1 and lx!='at':
        num_exclusions += 1
scanner_code += 's->num_exclusions = ' + str(num_exclusions) + ';\n'
count = 0
for t in tokens:
    lx = t['lexeme']
    if len(lx)>1 and lx!='at':
        scanner_code += '  create_exclusion(&s->exclusions['+str(count)+'],"'+lx.upper()+'",'+str(len(lx))+');\n'
        count += 1

# Modify the scanner

with open('scanner-src.c','r') as f:
    scanner = f.read()
    scanner = scanner.replace('// Build exclusions - DO NOT EDIT line\n',scanner_code)
    if allow_lower_case:
        scanner = re.sub('allow_lower_case\s*=\s*(true|false)','allow_lower_case = true',scanner)
    else:
        scanner = re.sub('allow_lower_case\s*=\s*(true|false)','allow_lower_case = false',scanner)
        scanner = re.sub('applesoft_external','applesoftcasesens_external',scanner)
with open(pathlib.Path.cwd().parent/'src'/'scanner.c','w') as f:
    f.write(scanner)

# Define all the token rules for the JavaScript grammar
# Also build the retoken rule that chooses any token

token_rule_string = ''
retoken_rule_string = '\t\t_retok: $ => choice('
for t in tokens:
    lx = t['lexeme']
    rule_value = tok_regex_js(lx)
    # Special Cases:
    # ? shorthand for PRINT
    if lx=='print':
        rule_value = rule_value[:-1] + '|\?/'
    # ATN cannot have space between T and N
    if lx=='atn':
        if allow_lower_case:
            rule_value = '/[Aa] *[Tt][Nn]/'
        else:
            rule_value = '/A *TN/'
    # AT and TO resolution: /A *TO/ = (A)(TO) ; /A *T +O/ = (AT)(O)
    # Handle this by consuming the A (or not) as NAME in the external scanner.
    # Hence nothing to do here.
    token_rule_string += '\t\t\t' + t['rule id'] + ': $ => '+rule_value+',\n'
    if len(lx)>1:
        retoken_rule_string += '$.' + t['rule id'] + ','
retoken_rule_string = retoken_rule_string[:-1] + '),\n'


# Create the grammar from the working file

with open('grammar-src.js','r') as f:
    grammar = f.read()
    for t in tokens:
        lx = t['lexeme']
        patt = "'" + lx.upper() + "'"
        grammar = re.sub(re.escape(patt),'$.'+t['rule id'],grammar)
    grammar = grammar.replace('\t\t// token rules go here DO NOT EDIT this line',token_rule_string)
    grammar = grammar.replace('\t\t// retoken rule goes here DO NOT EDIT',retoken_rule_string)
    grammar = re.sub('allow_lower_case\s*=\s*\w+','allow_lower_case = '+str(allow_lower_case).lower(),grammar)
    grammar = re.sub('allow_call_args\s*=\s*\w+','allow_call_args = '+str(allow_call_args).lower(),grammar)
with open(pathlib.Path.cwd().parent/'grammar.js','w') as f:
    f.write(grammar)

# Write out the token data for possible use elsewhere

with open('token_list.json','w') as f:
    f.write(json.dumps(tokens,sort_keys=True,indent=4))

# Create a simple TextMate grammar for use where needed (e.g. vscode hover highlights).
# This grammar is very light, Tree-sitter grammar should always be preferred.

tmGrammar = {}
tmGrammar['scopeName'] = 'source.bas'
tmGrammar['patterns'] = []

# Use tree-sitter highlight query to help assign highlight names
with open(pathlib.Path.cwd().parent/'queries'/'highlights.scm','r') as f:
    highlights = f.read()

if allow_lower_case:
    var_match_rule = '[A-Za-z]+[$%]?'
    comment_match_rule = '[Rr] *[Ee] *[Mm].*$'
    atn_match_rule = '[Aa] *[Tt][Nn]'
else:
    var_match_rule = '[A-Z]+[$%]?'
    comment_match_rule = 'R *E *M.*$'
    atn_match_rule = 'A *TN'

# Ordering of list is significant

tmGrammar['patterns'] += [{'name': 'comment',
    'match': comment_match_rule}]
tmGrammar['patterns'] += [{'name': 'support.function',
    'match': atn_match_rule}]

for t in tokens:
    lx = t['lexeme']
    if len(lx)>1:
        highlight_name = 'keyword.control'
        match = re.search(t['rule id']+'[) @]*(\w+)',highlights)
        if (match):
            if ('function' in match[1]):
                highlight_name = 'support.function'
        tmGrammar['patterns'] += [{'name': highlight_name,
            'match': tok_regex_json(lx)}]

# Don't allow tmGrammar to highlight strings.
# Because: vscode will use this to highlight things that TS does *not* highlight.
# This is not the behavior we want.

# tmGrammar['patterns'] += [{'name': 'string',
#     'begin': '"',
#     'end': '("|\r?\n)'}]

tmGrammar['patterns'] += [{'name': 'variable',
    'match': var_match_rule}]

with open('applesoft.tmGrammar.json','w') as f:
    f.write(json.dumps(tmGrammar,sort_keys=False,indent=4))
