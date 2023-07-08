#!/bin/sh
# Sat  8 Jul 15:42:05 UTC 2023

# way incomplete ;)
# went with a Makefile early on, after this was begun.

# 'abcd' = (('a'*256 + 'b')*256 + `c`)*256 + 'd' = 1633837924 = 0x61626364 = '0xa0xb0xc0xd'

gforth -e 'CR ." decimal 5 3 * ." 9 spaces' -e 'decimal 5 3 * .' -e 'bye'

gforth -e 'CR CR ." char a 256 * ." 4 spaces' -e '3 spaces char a 256 * . CR CR'

# end.
