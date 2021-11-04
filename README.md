Parser for AppleSoft BASIC
==========================

This is a comprehensive language description and fast parser for AppleSoft BASIC built using the [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) system.  The system auto-builds a C-language parser based on a language description contained in the file `grammar.js`.  Tree-sitter uses [Node.js](https://nodejs.org/en/) to build the parser.

Once the parser is built, it can be used from within several languages, including Python, Rust, Node.js, and others.

Current Status
--------------

A large number of tests (see `test/corpus`) are working, but more are still to be added.

Emulation
---------

The parser does not yet perfectly emulate the Apple II ROM (A2ROM).  The tests in `test/corpus/emulation.txt` illusrate cases where the A2ROM would parse things differently.  For example,

```bas
100 IF B = A THEN 100
```

would be parsed by the A2ROM as

```bas
100 IF B = AT HEN100
```

while `Tree-Sitter` parses this "correctly."

Tasks
-------

This parser can serve a variety of purposes, such as checking for syntax errors on a modern computer.  Further development envisioned here includes

* Publish the working parser on `npm`
* Syntax highlights for the Atom editor
* Python wrapper for error-checking BASIC programs on a modern system
* Higher level BASIC abstraction language - "AppleSoft metaBASIC" (tentative)
