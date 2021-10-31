Parser for AppleSoft BASIC
==========================

This is a comprehensive language description and fast parser for AppleSoft BASIC built using the [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) system.  The system auto-builds a C-language parser based on a language description contained in the file `grammar.js`.  Tree-sitter uses [Node.js](https://nodejs.org/en/) to build the parser.

Once the parser is built, it can be used from within several languages, including Python, Rust, Node.js, and others.

Current Status
--------------

As of this writing the parser has only been in development for a few days, but it appears to be essentially working.  It parses complex AppleSoft BASIC programs such as the high level *Realm* sources without reporting any syntax errors.  This of course does not mean the parser is error-free, only that it can digest selected real-life AppleSoft BASIC programs.

Tasks
-------

This parser can serve a variety of purposes, such as checking for syntax errors on a modern computer.  Further development envisioned here includes

* Publish the working parser on `npm`
* Syntax highlights for the Atom editor
* Python wrapper for error-checking BASIC programs on a modern system
* Higher level BASIC abstraction language - "AppleSoft metaBASIC" (tentative)
