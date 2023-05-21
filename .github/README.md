Parser for Applesoft BASIC
==========================

![unit tests](https://github.com/dfgordon/tree-sitter-applesoft/actions/workflows/node.js.yml/badge.svg)

This is a parser for Applesoft BASIC intended for use with language servers.  It is built using the [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) system.  Bindings are available for several languages.  The following pre-built packages are available:

* [Parsing Applesoft with C++](https://github.com/dfgordon/tree-sitter-applesoft/releases)
* [Parsing Applesoft with Rust](https://crates.io/crates/tree-sitter-applesoft)
* [Parsing Applesoft with WASM](https://github.com/dfgordon/tree-sitter-applesoft/releases)

For details on parser usage and design see the [wiki](https://github.com/dfgordon/tree-sitter-applesoft/wiki).

Parsing Files
-------------

For a quick study in parsing Applesoft, download `applesoft-cpp-parsing.zip` from the [latest release](https://github.com/dfgordon/tree-sitter-applesoft/releases).  Unpack and build it (see the README).  Run the executable by typing `./abas`.  For this example, enter the line `10 pr#int "hello world!"` (error is deliberate), followed by `bye`.  This should output the syntax tree
```
(source_file (ERROR (linenum) (tok_prn) (tok_int) (str)))
```
Here, the parser must interpret the erroneous line of code as starting with the `PR#` token, which in turn leads to the `INT` token.  The important thing is that the parser detects the error.

You can use `./abas` as a syntax checker in this way (also by redirecting input, e.g., `./abas < myprog.bas`), but the main purpose of the `applesoft-cpp-parsing` project is to provide a building block for more elaborate C++ projects requiring an Applesoft parser.

Build Process
-------------

The build products are generated using `build.py`.  The Docker daemon must be running for `build.py` to succeed.  The daemon may require `sudo`.

This is a cascaded build.  The starting files are `token_list.txt`, `grammar-src.js`, and `scanner-src.c`.  These are used by `token_processor.py` to produce `grammar.js` and `src/scanner.c` (a simplified TextMate grammar is also generated here).  These are used by `tree-sitter generate` to produce `src/parser.c` and, in turn, the bindings for Node and Rust.  These are used by `tree-sitter build-wasm` to produce the WASM parser.

The `build.py` script produces two versions of the WASM parser, one case sensitive, one case insensitive.  It leaves all the other products in the case insensitive state.

References
-----------

1. [Applesoft BASIC Programmer's Reference Manual - Volume 1](https://www.apple.asimov.net/documentation/programming/basic/49163042-Apple-II-Applesoft-BASIC-Programmer-s-Reference-Manual-Volume-1.pdf)
2. [Applesoft BASIC Programmer's Reference Manual - Volume 2](https://www.apple.asimov.net/documentation/programming/basic/49163108-Apple-II-Applesoft-BASIC-Programmer-s-Reference-Manual-Volume-2.pdf)
