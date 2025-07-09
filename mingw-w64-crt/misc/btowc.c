/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "mb_wc_common.h"
#include <limits.h>
#include <wchar.h>
#include <stdio.h>
#include <windows.h>

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
