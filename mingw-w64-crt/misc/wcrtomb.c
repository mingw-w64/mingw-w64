/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "mb_wc_common.h"
#include <wchar.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <windows.h>

static size_t wcrtomb_cp (
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
    _set_errno (EINVAL);
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
  _set_errno (EILSEQ);
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
  int mb_cur_max = MB_CUR_MAX;

  return wcrtomb_cp (mbc, wc, state, cp, mb_cur_max);
}

size_t wcsrtombs (
  char *__restrict__ mbs,
  const wchar_t **__restrict__ wcs,
  size_t count,
  mbstate_t *__restrict__ state
) {
  /* Code page used by current locale */
  unsigned cp = ___lc_codepage_func ();
  /* Maximum character length in `cp` */
  int mb_cur_max = MB_CUR_MAX;

  /* Buffer to store single converted character */
  char mbc[2];
  /* Total number of bytes stored in `mbs` */
  size_t mbcConverted = 0;

  /* Next wide character to convert */
  const wchar_t *wc = *wcs;

  while (1) {
    const size_t length = wcrtomb_cp (mbc, *wc, state, cp, mb_cur_max);

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
