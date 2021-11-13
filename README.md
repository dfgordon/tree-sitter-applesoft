Parser for Applesoft BASIC
==========================

This is a comprehensive language description and fast parser for Applesoft BASIC built using the [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) system.  The system auto-builds a C-language parser based on a language description contained in the file `grammar.js`.  Tree-sitter uses [Node.js](https://nodejs.org/en/) to build the parser.

Once the parser is built, it can be used from within several languages, including Python, Rust, Node.js, and others.

Current Status
--------------

A full set of tests (see `test/corpus`) are working.  The tests cover all statements and functions, including various syntax variations.  Emulation is getting close, but still not perfect (see below).

Emulation
---------

This parser is meant to emulate the behavior of the Apple II ROM (A2ROM), including its pathologies, but with more helpful error detection.  The tests in `test/corpus/emulation.txt` illustrate some of these cases.  For example,

```bas
100 IF B = A THEN 100
```

produces a syntax error because of the `AT` token (`A THEN` becomes `AT HEN`), just as the A2ROM would.  On the other hand, `tree-sitter-applesoft` also produce a syntax error for

```bas
100 FOR I = A TO B
```

whereas the A2ROM would not.

At present, the `PRINT` statement is also not precisely emulated.  The A2ROM would interpret the following two lines as the same statement:

```bas
100 PRINT A$ B$
110 PRINT A$;B$
```

In contrast `tree-sitter-applesoft` considers the first form a syntax error.

Tasks
-------

This parser can serve a variety of purposes, such as checking for syntax errors on a modern computer.  Further development envisioned here includes

* Publish the working parser on `npm`
* Syntax highlights for the Atom editor
* Python wrapper for error-checking BASIC programs on a modern system
* Higher level BASIC abstraction language - "Applesoft metaBASIC" (tentative)
