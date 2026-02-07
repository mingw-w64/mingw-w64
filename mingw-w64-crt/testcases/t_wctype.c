/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _CTYPE_DISABLE_MACROS
#include <assert.h>
#include <locale.h>
#include <stdlib.h>
#include <wctype.h>

#include "ctype-test.h"

/**
 * Test conformance of wctype.h functions to POSIX specification.
 *
 * Reference: <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/basedefs/V1_chap07.html#tag_07_03_01>
 */

int main (void) {
  assert (setlocale (LC_ALL, "C") != NULL);

  for (int i = 0; i < (int) _countof (CharTypeTable); ++i) {
    assert (!!iswalnum (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_ALNUM));
    assert (!!iswalpha (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_ALPHA));
    assert (!!iswblank (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_BLANK));
    assert (!!iswcntrl (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_CONTROL));
    assert (!!iswdigit (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_DIGIT));
    assert (!!iswgraph (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_GRAPH));
    assert (!!iswlower (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_LOWER));
    assert (!!iswprint (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_PRINT));
    assert (!!iswspace (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_SPACE));
    assert (!!iswupper (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_UPPER));
    assert (!!iswxdigit (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_XDIGIT));
  }

  return 0;
}
