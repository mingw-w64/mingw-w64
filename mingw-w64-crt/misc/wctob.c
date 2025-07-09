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
#include <stdlib.h>
#include <errno.h>
#include <windows.h>

int wctob (wint_t wc)
{
  /* Return early */
  if (IS_LOW_SURROGATE (wc) || IS_HIGH_SURROGATE (wc) || wc == WEOF) {
    return EOF;
  }

  mbstate_t state = {0};
  /* Buffer large enough to hold any multibyte character */
  char mbc[MB_LEN_MAX];

  size_t length = wcrtomb (mbc, wc, &state);
  if (length > 1) {
    return EOF;
  }

  return (unsigned char) mbc[0];
}
