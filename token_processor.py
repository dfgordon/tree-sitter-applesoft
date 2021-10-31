'''This program takes a CSV file with all the tokens and
formats them as tree-sitter rules.
It then creates a finished grammar from the working file.'''

import csv
import re

# First step is to gather and check the tokens

tokens = []
rules = {}

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
        if c.isalpha() or c.isdigit():
            id += c
        if c=='#':
            id += 'n'
    id += '_tok'
    # add the rule if it is not an operator
    if id != '_tok':
        rules[t.upper()] = id

# Form the string of token rules

token_rule_string = ''
for t in rules:
    token_rule_string += '\t\t' + rules[t] + ': $ => \'' + t + '\',\n'

# Create the grammar from the working file

with open('grammar-working.js','r') as f:
    grammar = f.read()
    for t in rules:
        patt = "'" + t + "'"
        grammar = re.sub(re.escape(patt),'$.'+rules[t],grammar)
    grammar = re.sub('\t\t// token rules go here DO NOT EDIT this line',token_rule_string,grammar)
with open('grammar.js','w') as f:
    f.write(grammar)
