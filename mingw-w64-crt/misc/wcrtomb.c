/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <errno.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "mingw-wchar.h"

/**
 * __mingw_wcrtomb_cp is internal implementation for C95 functions wcrtomb and
 * wcsrtombs.
 *
 * In order to perform conversion we need the following information:
 *
 *  - code page used by active locale (which can be a thread locale for
 *    msvcr80.dll and later); obtained by calling ___lc_codepage_func
 *
 *  - maximum character length in used code page; obtained by calling
 *    ___mb_cur_max_func
 *
 * crtdll.dll's ___lc_codepage_func is quite expensive as it obtains this
 * information by parsing return value of setlocale(LC_CTYPE, NULL). Using
 * __mingw_wcrtomb_cp allows wcsrtombs call both ___lc_codepage_func and
 * ___mb_cur_max_func only once.
 */

size_t __mingw_wcrtomb_cp (
  char *__restrict__ mbc,
  wchar_t wc,
  mbstate_t *__restrict__ state,
  unsigned cp,
  int mb_cur_max
) {
  /* Set `state` to initial state */
  if (mbc == NULL) {
    if (state != NULL) {
      *state = 0;
    }
    return 1;
  }

  /* Detect invalid conversion state */
  if (state != NULL && *state) {
    errno = EINVAL;
    return (size_t) -1;
  }

  /* Store terminating L'\0' */
  if (wc == L'\0') {
    if (mbc != NULL) {
      mbc[0] = '\0';
    }
    return 1;
  }

  /* Handle "C" locale */
  if (cp == 0) {
    if (wc > 0xFF) {
      goto eilseq;
    }
    if (mbc != NULL) {
      mbc[0] = (char) wc;
    }
    return 1;
  }

  BOOL defaultCharacterUsed = FALSE;
  char buffer[2] = {0, 0};

  /* For consistency with CRT, we do not use WC_NO_BEST_FIT_CHARS */
  int ret = WideCharToMultiByte (
    cp, 0, &wc, 1, buffer, mb_cur_max, NULL, &defaultCharacterUsed
  );

  if (ret == 0 || ret > mb_cur_max || defaultCharacterUsed) {
    goto eilseq;
  }

  memcpy (mbc, buffer, ret);
  return ret;

eilseq:
  errno = EILSEQ;
  return (size_t) -1;
}

size_t wcrtomb (
  char *__restrict__ mbc,
  wchar_t wc,
  mbstate_t *__restrict__ state
) {
  /* Code page used by current locale */
  unsigned cp = ___lc_codepage_func ();

  /* Maximum character length in `cp` */
  int mb_cur_max = ___mb_cur_max_func ();

  return __mingw_wcrtomb_cp (mbc, wc, state, cp, mb_cur_max);
}
