\ Sat  8 Jul 16:06:33 UTC 2023

0 [IF]

  1633837924 = 0x61626364 = '0xa0xb0xc0xd'

[THEN]

\ NEW: '1234' evaluate to what
\ old model followed below.

\ = 'abcd' = (('a'*256 + 'b')*256 + 'c')*256 + 'd'

    : ndefaa [char] 1 256 * ; CR
                                        48 spaces ." char 1  ." space char 1 . ."  ok" CR
."  : ndefaa [char] 1 256 * ;"     12 spaces ndefaa . 4 spaces
                                                  ." char 2  ." space char 2 . ."  ok" CR
    : ndefab [char] 2 ndefaa + ;
."  : ndefab [char] 2 ndefaa + ;"   9 spaces ndefab . CR
    : ndefac ndefab 256 * ;
."  : ndefac ndefab 256 * ;"       12 spaces ndefac . 4 spaces
    : ndefad ndefac [char] 3 + ;
                                                  ." char 3  ." space char 3 . ."  ok" CR

\ = 'abcd' = (('a'*256 + 'b')*256 + 'c')*256 + 'd'

."  : ndefad ndefac [char] 3 + ;"   7 spaces ndefad . 4 spaces CR
    : ndefae ndefad 256 * ;
."  : ndefae ndefad 256 * ;"       10 spaces ndefae . 4 spaces
    : ndefaf ndefae [char] 4 + ;
                                                  ." char 4  ." space char 4 . ."  ok" CR
."  : ndefaf ndefae [char] 4 + ;"   5 spaces ndefaf . 4 spaces CR

." NEW: "
21 spaces ." decimal 825373492 hex . 31323334" CR

." OLD: "
28 spaces ." 1633837924 =   0x61626364 = '0xa0xb0xc0xd'" CR

CR
." hex 64 63 62 61 emit emit emit emit abcd ok" CR
." hex 34 33 32 31 emit emit emit emit 1234 ok"


0 [if]
    ERRATA = 'abcd' = (('a'*256 + 'b')*256 + `c`)*256 + 'd'
[then]
CR
." famnextdo " CR

." Sat  8 Jul 19:44:45 UTC 2023" CR
\ END.
