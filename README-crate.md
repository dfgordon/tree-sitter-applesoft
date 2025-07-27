Parser for Applesoft BASIC
==========================

This is the rust binding for [tree-sitter-applesoft](https://github.com/dfgordon/tree-sitter-applesoft).  To use the parser, include the following in your package's `Cargo.toml`:
```toml
[dependencies]
tree-sitter = "0.25.8"
tree-sitter-applesoft = "5.0.0"
```
Here is a trivial `main.rs` example:
```rust
use tree_sitter;
use tree_sitter_applesoft;

fn main() {
    let code = "10 GOTO 10\n";
    let mut parser = tree_sitter::Parser::new();
    parser.set_language(&tree_sitter_applesoft::LANGUAGE.into())
      .expect("Error loading Applesoft grammar");
    let tree = parser.parse(code,None).unwrap();

    println!("{}",tree.root_node().to_sexp());
}
```
This should print the syntax tree
```
(source_file (line (linenum) (statement (tok_goto) (linenum))))
```

For more on parsing with rust, see the general guidance [here](https://github.com/tree-sitter/tree-sitter/blob/master/lib/binding_rust/README.md).

For specific guidance on this parser, see the [wiki](https://github.com/dfgordon/tree-sitter-applesoft/wiki).

For an example of a project that uses this library, see [a2kit](https://github.com/dfgordon/a2kit).
