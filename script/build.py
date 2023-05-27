'''Update the parser and build the WASM files
The Docker daemon must be running.
Run from script directory.

On Windows you may have better luck with `build.ps1`.'''

import subprocess
import pathlib
import os

script_dir = pathlib.Path.cwd()
root_dir = script_dir.parent

os.chdir(script_dir)
subprocess.run(['python','token_processor.py','--allow-lower-case','0']).check_returncode()
os.chdir(root_dir)
subprocess.run(['tree-sitter','generate']).check_returncode()
subprocess.run(['tree-sitter','test']).check_returncode()
subprocess.run(['tree-sitter','build-wasm']).check_returncode()

os.chdir(script_dir)
subprocess.run(['python','token_processor.py','--allow-lower-case','1']).check_returncode()
os.chdir(root_dir)
subprocess.run(['tree-sitter','generate']).check_returncode()
subprocess.run(['tree-sitter','test']).check_returncode()
subprocess.run(['tree-sitter','build-wasm']).check_returncode()
