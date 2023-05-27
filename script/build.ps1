# Update the parser and build the WASM files.
# The emscripten SDK must be activated.
# Run from script directory.
# .\node_modules\.bin has to be in path.

# On Mac/Linux you may have better luck with `build.py`

python token_processor.py --allow-lower-case 0
Set-Location ..
tree-sitter generate
tree-sitter test
tree-sitter build-wasm

Set-Location script
python token_processor.py --allow-lower-case 1
Set-Location ..
tree-sitter generate
tree-sitter test
tree-sitter build-wasm
