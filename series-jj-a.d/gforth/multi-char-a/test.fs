\ Sat  8 Jul 16:06:33 UTC 2023

0 [IF]

  1633837924 = 0x61626364 = '0xa0xb0xc0xd'

[THEN]

\ = 'abcd' = (('a'*256 + 'b')*256 + 'c')*256 + 'd'

    : ndefaa [char] a 256 * ; CR
                                        48 spaces ." char a  ." space char a . ."  ok" CR
."  : ndefaa [char] a 256 * ;"     12 spaces ndefaa . 4 spaces
                                                  ." char b  ." space char b . ."  ok" CR
    : ndefab [char] b ndefaa + ;
."  : ndefab [char] b ndefaa + ;"   9 spaces ndefab . CR
    : ndefac ndefab 256 * ;
."  : ndefac ndefab 256 * ;"       12 spaces ndefac . 4 spaces
    : ndefad ndefac [char] c + ;
                                                  ." char c  ." space char c . ."  ok" CR

\ = 'abcd' = (('a'*256 + 'b')*256 + 'c')*256 + 'd'

."  : ndefad ndefac [char] c + ;"   7 spaces ndefad . 4 spaces CR
    : ndefae ndefad 256 * ;
."  : ndefae ndefad 256 * ;"        9 spaces ndefae . 4 spaces
    : ndefaf ndefae [char] d + ;
                                                  ." char d ." space char d . ."  ok" CR
."  : ndefaf ndefae [char] d + ;"   4 spaces ndefaf . 4 spaces CR

33 spaces ." 1633837924 = 0x61626364 = '0xa0xb0xc0xd'" CR
CR


0 [if]
    ERRATA = 'abcd' = (('a'*256 + 'b')*256 + `c`)*256 + 'd'
[then]
CR
." famnextdo " CR

." Sat  8 Jul 17:57:11 UTC 2023" CR
\ END.
