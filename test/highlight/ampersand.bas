10 & PLT(X,Y)
11 REM ^ string
12 REM   ^ variable
20 & "SURF" TO X,Y AT Z
21 REM      ^ keyword.builtin
22 REM           ^ variable
23 REM             ^ keyword.builtin
24 REM                ^ variable
30 & ("DRAW",X,Y)
31 REM         ^ variable
40     & ALIGN;A$,B$
41 REM ^ keyword.builtin
42 REM   ^ string
50 & PRINT "custom print" AT 5,5
51 REM ^ keyword.builtin
52 REM      ^ string
53 REM                    ^ keyword.builtin
60 & PRNT USNG > "000.00";A$,B$
61 REM ^ string
62 REM         ^ operator
63 REM             ^ string