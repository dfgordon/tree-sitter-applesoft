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

# Form the string of token rules

def insert_space_runs(tok):
    ans = ''
    if len(tok)>1:
        for c in t[:-1]:
            ans += c + ' *'
        ans += t[-1]
        ans = '/' + ans + '/'
        ans = ans.replace('$','\$')
    else:
        ans = "'" + t + "'"
    return ans

token_rule_string = ''
for t in rules:
    rule_value = insert_space_runs(t)
    # special cases: SCRN,SPC,TAB are kept with left-parenthesis
    # ATN cannot have space between T and N
    # TO cannot have space if there is an A preceding
    token_rule_string += '\t\t' + rules[t] + ': $ => token(prec(2,' + rule_value + ')),\n'

# Create the grammar from the working file

with open('grammar-src.js','r') as f:
    grammar = f.read()
    for t in rules:
        patt = "'" + t + "'"
        grammar = re.sub(re.escape(patt),'$.'+rules[t],grammar)
    grammar = grammar.replace('\t\t// token rules go here DO NOT EDIT this line',token_rule_string)
with open('grammar.js','w') as f:
    f.write(grammar)
