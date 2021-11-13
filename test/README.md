Testing
-------

The test files correspond to chapters one through seven in "Apple II Applesoft BASIC Programmer's Reference, Volume 1" according to the mapping

| chapter | file |
| ------- | ---- |
| 1 | `general.txt` |
| 2 | `vars-arithmetic.txt` |
| 3 | `control-statements.txt` |
| 4 | `arrays-strings.txt` |
| 5 | `input-output.txt` |
| 6 | `graphics.txt` |
| 7 | `utility.txt` |

The file contents parallel the corresponding chapter.  The aim is to exhaustively cover all statements and functions.

Emulation Tests
---------------

There is an "extra" file of tests called `emulation.txt`.  These tests are intended to verify that the parser captures detailed behavior of the Apple II ROM, including its pathologies.
