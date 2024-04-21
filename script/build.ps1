# Update the parser and build the WASM files.
# The emscripten SDK must be activated: `emsdk activate latest`
# Run from project directory: `./script/build.ps1`

Set-Variable allowCallArgs 1

Set-Location script
python token_processor.py --allow-lower-case 1 --allow-call-args $allowCallArgs
Set-Location ..
npx tree-sitter generate
if ($allowCallArgs) {
    npx tree-sitter test
} else {
    npx tree-sitter test --exclude extended
}
npx tree-sitter build --wasm .
