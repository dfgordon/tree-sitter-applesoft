Parser for Applesoft BASIC
==========================

This is a comprehensive language description and fast parser for Applesoft BASIC built using the [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) system.  The system auto-builds a C-language parser based on a language description contained in the file `grammar.js`.  Tree-sitter uses [Node.js](https://nodejs.org/en/) to build the parser.

Once the parser is built, it can be used from within several languages, including Python, Rust, Node.js, and others.

Current Status
--------------

A full set of tests (see `test/corpus`) are passing.  The tests cover all statements and functions, many syntax variations, and emulation behaviors.

Emulation
---------

This parser is intended to emulate the behavior of the Apple II ROM interpreter (A2ROM).  The emulation rules are:

1. If the A2ROM would execute a statement without a `SYNTAX ERROR`, it is valid.
2. If the A2ROM would execute a statement with a `SYNTAX ERROR`, it is invalid.
3. If a statement is valid, `tree-sitter-applesoft` must resolve it according to the syntax defined in Ref. 2.
4. If a statement is invalid, `tree-sitter-applesoft` must produce an error.
5. Error identification must be accurate to within a line (we will usually do much better)

Here are a few cases showing how `tree-sitter-applesoft` emulates the pathologies of the A2ROM:

```bas
10 FOR A = LOFT OR LEFT TO 15
11 REM ERR: parsed as FOR A = LOF TO RLEFT TO 15

20 IF B = A THEN 100
21 REM ERR: parsed as IF B = AT H E N 1 00

30 FOR I = A TO B
31 REM OK, the hidden AT is not tokenized
```

Tasks
-------

This parser can serve a variety of purposes, such as checking for syntax errors on a modern computer.  Further development envisioned here includes

* Publish the working parser on `npm`
* Syntax highlights for the Atom editor
* Python wrapper for error-checking BASIC programs on a modern system
* Higher level BASIC abstraction language - "Applesoft metaBASIC" (tentative)

References
-----------

1. [Applesoft BASIC Programmer's Reference Manual - Volume 1](https://www.apple.asimov.net/documentation/programming/basic/49163042-Apple-II-Applesoft-BASIC-Programmer-s-Reference-Manual-Volume-1.pdf)
2. [Applesoft BASIC Programmer's Reference Manual - Volume 2](https://www.apple.asimov.net/documentation/programming/basic/49163108-Apple-II-Applesoft-BASIC-Programmer-s-Reference-Manual-Volume-2.pdf)
