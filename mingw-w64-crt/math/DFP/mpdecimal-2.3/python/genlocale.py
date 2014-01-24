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
# Very extensive test that comes close to brute force testing
# all format string combinations containing either a thousands
# separator or the 'n' specifier.
#
# Usage:  python3.2 genlocale.py | ../runtest -
#


import sys, random, locale
from formathelper import locale_list, printit
from formathelper import integers, numbers, randfill
from formathelper import all_fillchars, all_format_sep, all_format_loc
from randdec import randdec, randint, un_incr_digits


testno = 0
print("rounding: half_even")

# unicode fill character test
for x in range(10):
    for fill in all_fillchars():
        intpart = fracpart = ''
        while (not intpart) and (not fracpart):
            intpart = random.choice(integers)
            fracpart = random.choice(integers)
        s = ''.join((random.choice(('', '-')), intpart, '.', fracpart))
        fmt = randfill(fill)
        testno += 1
        printit(testno, s, fmt, 'utf-8')

# thousands separator test
for fmt in all_format_sep():
    for s in un_incr_digits(15, 384, 30):
        testno += 1
    for sign in ('', '-'):
        for intpart in integers:
            for fracpart in integers:
                if (not intpart) and (not fracpart):
                    continue
                s = ''.join((sign, intpart, '.', fracpart))
                testno += 1
                printit(testno, s, fmt)
    for s in numbers:
        testno += 1
        printit(testno, s, fmt)
    for x in range(100):
        s = randdec(20, 425)
        testno += 1
        printit(testno, s, fmt)
    for x in range(100):
        s = randint()
        testno += 1
        printit(testno, s, fmt)

# locale test
for loc in locale_list:
    try:
        locale.setlocale(locale.LC_ALL, loc)
    except locale.Error as err:
        sys.stderr.write("%s: %s\n" % (loc, err))
        continue
    print("locale: %s" % loc)
    for fmt in all_format_loc():
        for sign in ('', '-'):
            intpart = fracpart = ''
            while (not intpart) and (not fracpart):
                intpart = random.choice(integers)
                fracpart = random.choice(integers)
            s = ''.join((sign, intpart, '.', fracpart))
            testno += 1
            printit(testno, s, fmt)
        for s in random.sample(numbers, 3):
            testno += 1
            printit(testno, s, fmt)
        for x in range(10):
            s = randdec(20, 425000000)
            testno += 1
            printit(testno, s, fmt)
