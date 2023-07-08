\ Sat  8 Jul 16:06:33 UTC 2023

0 [IF]

  1633837924 = 0x61626364 = '0xa0xb0xc0xd'

[THEN]

\ = 'abcd' = (('a'*256 + 'b')*256 + 'c')*256 + 'd'

    : ndefaa [char] a 256 * ; CR
."  : ndefaa [char] a 256 * ;"     12 spaces ndefaa . 4 spaces
." char b ." char b . CR
    : ndefab [char] b ndefaa + ;
."  : ndefab [char] b ndefaa + ;"   9 spaces ndefab . CR
    : ndefac ndefab 256 * ;
."  : ndefac ndefab 256 * ;"       12 spaces ndefac . 4 spaces
    : ndefad ndefac [char] c + ;

." char c ." char c . CR

."  : ndefad ndefac [char] c + ;"  7 spaces ndefad . CR

CR


0 [if]
    ERRATA = 'abcd' = (('a'*256 + 'b')*256 + `c`)*256 + 'd'
[then]

." famnextdo " CR

\ END.
