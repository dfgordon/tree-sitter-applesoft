Parser for Applesoft BASIC
==========================

![unit tests](https://github.com/dfgordon/tree-sitter-applesoft/actions/workflows/node.js.yml/badge.svg)

This is a parser for Applesoft BASIC intended for use with language servers.  It is built using the [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) system.  Bindings are available for several languages.  The following pre-built packages are available:

* [Parsing Applesoft with C++](https://github.com/dfgordon/tree-sitter-applesoft/releases)
* [Parsing Applesoft with Rust](https://crates.io/crates/tree-sitter-applesoft)
* [Parsing Applesoft with WASM](https://github.com/dfgordon/tree-sitter-applesoft/releases)
* [Parsing Applesoft with Node](https://www.npmjs.com/package/tree-sitter-applesoft)

For details on parser usage and design see the [wiki](https://github.com/dfgordon/tree-sitter-applesoft/wiki).

Build Process
-------------

The build products are generated using `script/build.py, see docstring within for dependencies.

This is a cascaded build.  The starting files are `token_list.txt`, `grammar-src.js`, and `scanner-src.c`.  These are used by `token_processor.py` to produce `grammar.js` and `src/scanner.c` (a simplified TextMate grammar is also generated here).  These are used by `tree-sitter generate` to produce `src/parser.c` and, in turn, the bindings for various languages.  These are used by `tree-sitter build` to produce the WASM parser.

The `build.py` script produces a case insensitive parser that accepts extended `CALL` syntax, but can be easily modified to produce a more strict parser.

References
-----------

1. Applesoft BASIC Programmer's Reference Manual - Volume 1
2. Applesoft BASIC Programmer's Reference Manual - Volume 2
