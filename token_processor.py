'''This program takes a CSV file with all the tokens and
formats them as tree-sitter rules.
It then creates a finished grammar from the working file.'''

import csv
import re

# First step is to gather and check the tokens

tokens = []
rules = {}

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
    for row in reader:
        tokens += row

expected_num = 0xea-0x80+1
if len(tokens)!=expected_num:
    raise ValueError('Number of tokens is off by '+str(len(tokens)-expected_num))
else:
    print('Found',expected_num,'tokens as expected.')

check = set()
for t in tokens:
    check.add(t)
if len(check)!=len(tokens):
    raise ValueError('There were duplicate tokens.')
else:
    print('Uniqueness check OK')

# Now set up dictionary of tokens and associated tree-sitter rules

for i,t in enumerate(tokens):
    print(hex(0x80+i),t) # not used, just for spot checking
    # form a suitable javascript identifier
    id = ''
    for c in t:
        if c in sp_map.keys():
            id += sp_map[c]
        else:
            id += c
    rules[t.upper()] = id + "_tok"

# Form a token rule as regex

def tok_regex(tok):
    ans = ''
    if len(tok)>1:
        for c in t[:-1]:
            ans += c + ' *'
        ans += t[-1]
        ans = '/' + ans + '/'
        ans = ans.replace('$','\$')
        ans = ans.replace('(','\(')
    else:
        ans = "'" + t + "'"
    return ans

# Form a token rule as TS sequence

def tok_ts_seq(tok):
    ans = ''
    if len(tok)>1:
        ans = 'seq('
        for c in t[:-1]:
            ans += "'" + c + "',"
        ans += "'" + t[-1] + "')"
    else:
        ans = "'" + t + "'"
    return ans

# Build some C++-code for the scanner

scanner_code = ''
for t in rules:
    if len(t)>1:
        scanner_code += '    exclusions.push_back(exclusion("'+t+'",'+str(len(t))+'));\n'

# Modify the scanner

with open('src/scanner-src.cc','r') as f:
    scanner = f.read()
    scanner = scanner.replace('// Build exclusions - DO NOT EDIT line',scanner_code)
with open('src/scanner.cc','w') as f:
    f.write(scanner)

# Define all the token rules for the JavaScript grammar

token_rule_string = ''
for t in rules:
    rule_value = tok_regex(t)
    # Special Cases:
    # ATN cannot have space between T and N
    if t=='ATN':
        rule_value = '/A *TN/'
    # TO cannot have space if there is an A preceding
    # Maybe need an external scanner for this one - ingore for now
    token_rule_string += '\t\t\t' + rules[t] + ': $ => '+rule_value+',\n'

# Create the grammar from the working file

with open('grammar-src.js','r') as f:
    grammar = f.read()
    for t in rules:
        patt = "'" + t + "'"
        grammar = re.sub(re.escape(patt),'$.'+rules[t],grammar)
    grammar = grammar.replace('\t\t// token rules go here DO NOT EDIT this line',token_rule_string)
with open('grammar.js','w') as f:
    f.write(grammar)
