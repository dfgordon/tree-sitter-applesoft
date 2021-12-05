10 D$ = CHR$(4)
11 REM  ^ function.builtin
20 A$ = LEFT$(B$,3)
21 REM        ^ variable
30 A$ = MID$(B$,1,2)
40 A$ = RIGHT$(B$,3)
50 PRINT SPC(5);"HELLO WORLD": REM left parenthesis part of token
60 A$ = STR$(X)
70 PRINT TAB(1);"HELLO WORLD": REM left parenthesis part of token
