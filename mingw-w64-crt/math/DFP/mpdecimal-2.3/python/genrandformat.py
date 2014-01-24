#
# Copyright (c) 2008-2010 Stefan Krah. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#


#
# Test formatting using random format strings. This must be run
# in a UFT-8 terminal.
#
# Usage:  python3.2 genrandformat.py | ../runtest -
#


import random
from formathelper import rand_format, rand_fillchar, integers, printit
from randdec import un_incr_digits
print("rounding: half_even")


testno = 0
for x in range(1000):
    for sign in ('', '-'):
        intpart = fracpart = ''
        while (not intpart) and (not fracpart):
            intpart = random.choice(integers)
            fracpart = random.choice(integers)
        s = ''.join((sign, intpart, '.', fracpart))
        fmt = rand_format(rand_fillchar())
        testno += 1
        printit(testno, s, fmt, 'utf-8')
    for s in un_incr_digits(15, 384, 30):
        fmt = rand_format(rand_fillchar())
        testno += 1
        printit(testno, s, fmt, 'utf-8')
