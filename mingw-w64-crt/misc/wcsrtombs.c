/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "mingw-wchar.h"

size_t wcsrtombs (
  char *__restrict__ mbs,
  const wchar_t **__restrict__ wcs,
  size_t count,
  mbstate_t *__restrict__ state
) {
  /* Buffer to store single converted character */
  char mbc[2];
  /* Total number of bytes stored in `mbs` */
  size_t mbcConverted = 0;

  /* Next wide character to convert */
  const wchar_t *wc = *wcs;

  /* Code page used by current locale */
  unsigned cp = ___lc_codepage_func ();

  /* Maximum character length in `cp` */
  int mb_cur_max = ___mb_cur_max_func ();

  while (1) {
    const size_t length = __mingw_wcrtomb_cp (mbc, *wc, state, cp, mb_cur_max);

    /* Conversion failed */
    if (length == (size_t) -1) {
      if (mbs != NULL) {
        *wcs = wc;
      }
      return (size_t) -1;
    }

    /* POSIX and ISO C are silent about this */
    if (mbs != NULL && count == 0) {
      return 0;
    }

    /* Terminating '\0' has been converted, stop */
    if (mbc[0] == '\0') {
      if (mbs != NULL) {
        *mbs = '\0';
        *wcs = NULL;
      }
      break;
    }

    /* Storing `mbc` in `mbs` would exceed `count` */
    if (mbs != NULL && mbcConverted + length > count) {
      *wcs = wc;
      break;
    }

    /* Write `mbc` to `mbs` */
    if (mbs != NULL) {
      memcpy (mbs, mbc, length);
      mbs += length;
    }

    mbcConverted += length;
    wc += 1;

    /* `count` bytes have been written to `mbs`, stop */
    if (mbs != NULL && mbcConverted == count) {
      *wcs = wc;
      break;
    }
  }

  return mbcConverted;
}
