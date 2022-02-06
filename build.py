'''Update the parser and build the WASM files
The Docker daemon must be running.'''

import subprocess
import os

subprocess.run(['python','token_processor.py','--allow-lower-case','0']).check_returncode()
subprocess.run(['tree-sitter','generate']).check_returncode()
subprocess.run(['tree-sitter','test']).check_returncode()
subprocess.run(['tree-sitter','build-wasm']).check_returncode()

subprocess.run(['python','token_processor.py','--allow-lower-case','1']).check_returncode()
subprocess.run(['tree-sitter','generate']).check_returncode()
subprocess.run(['tree-sitter','test']).check_returncode()
subprocess.run(['tree-sitter','build-wasm']).check_returncode()
