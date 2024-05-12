Parser for Applesoft BASIC
==========================

This is the node binding for `tree-sitter-applesoft`.  See the main README [here](https://github.com/dfgordon/tree-sitter-applesoft).

Here is a sample `package.json`:

```json
{
  "name": "parsing-example",
  "version": "1.0.0",
  "description": "applesoft basic parsing example",
  "main": "index.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "author": "",
  "license": "ISC",
  "dependencies": {
    "tree-sitter": "^0.21.1",
    "tree-sitter-applesoft": "^3.2.1"
  }
}
```

With an example `index.js` as follows:

```js
const Parser = require('tree-sitter');
const Applesoft = require('tree-sitter-applesoft');

const basicCode = '10 print "HELLO WORLD!"\n';
const parser = new Parser();
parser.setLanguage(Applesoft);
tree = parser.parse(basicCode);
console.log(tree.rootNode.toString());
```

This should print the syntax tree

```
(source_file (line (linenum) (statement (tok_print) (str))))
```

For more on parsing with node, see the general guidance [here](https://github.com/tree-sitter/node-tree-sitter).
