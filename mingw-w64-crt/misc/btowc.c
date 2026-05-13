/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __LARGE_MBSTATE_T

#include <limits.h> /* MB_LEN_MAX */
#include <wchar.h>
#include <stdio.h>  /* EOF        */
#include <stdlib.h> /* MB_CUR_MAX */

wint_t btowc (int c)
{
  if (c == EOF)
    return (WEOF);

  /* Use dummy string so that mbrtowc will never return (size_t)-2 */
  char str[MB_LEN_MAX] = {(unsigned char) c, 0, 0, 0, 0};

  wint_t    wc = WEOF;
  mbstate_t state = {0};

  if (mbrtowc (&wc, (char *) str, MB_CUR_MAX, &state) == (size_t) -1) {
    return WEOF;
  }

  return wc;
}

wint_t (__cdecl *__MINGW_IMP_SYMBOL (btowc)) (int) = btowc;
