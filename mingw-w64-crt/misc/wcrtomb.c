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

size_t wcrtomb (
  char *__restrict__ mbc,
  wchar_t wc,
  mbstate_t *__restrict__ state
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

  /* Code page used by current locale */
  unsigned cp = ___lc_codepage_func ();

  /* Maximum character length in `cp` */
  int mb_cur_max = ___mb_cur_max_func ();

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
