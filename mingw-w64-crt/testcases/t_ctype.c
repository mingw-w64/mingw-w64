/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _CTYPE_DISABLE_MACROS
#include <assert.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>

#include "ctype-test.h"

/**
 * Test conformance of ctype.h functions to POSIX specification.
 *
 * Reference: <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/basedefs/V1_chap07.html#tag_07_03_01>
 */

int main (void) {
  assert (setlocale (LC_ALL, "C") != NULL);

  for (int i = 0; i < (int) _countof (CharTypeTable); ++i) {
    assert (!!isalnum (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_ALNUM));
    assert (!!isalpha (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_ALPHA));
    assert (!!isblank (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_BLANK));
    assert (!!iscntrl (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_CONTROL));
    assert (!!isdigit (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_DIGIT));
    assert (!!isgraph (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_GRAPH));
    assert (!!islower (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_LOWER));
    assert (!!isprint (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_PRINT));
    assert (!!isspace (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_SPACE));
    assert (!!isupper (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_UPPER));
    assert (!!isxdigit (i) == !!(CharTypeTable[i].CharType & CHARTYPE_BIT_XDIGIT));
  }

  return 0;
}
