/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>

size_t mbsrtowcs (
  wchar_t *wcs,
  const char **__restrict__ mbs,
  size_t count,
  mbstate_t *__restrict__ state
) {
  /* Use private `mbstate_t` if caller did not supply one */
  if (state == NULL) {
    static mbstate_t state_mbsrtowcs = {0};
    state = &state_mbsrtowcs;
  }

  /* Treat `state` as array of bytes */
  union {
    mbstate_t state;
    char bytes[4];
  } conversion_state = {.state = *state};

  /* Total number of wide character written to `wcs` */
  size_t  wcConverted = 0;
  /* Converted wide character */
  wchar_t wc = 0;

  /* Next multibyte character to convert */
  const char *mbc = *mbs;

  /* Maximum character length in `cp` */
  int mb_cur_max = ___mb_cur_max_func();

  while (1) {
    const size_t length = mbrtowc (
      &wc, mbc, mb_cur_max, &conversion_state.state
    );

    /* Conversion failed */
    if (length == (size_t) -1) {
      if (wcs != NULL) {
        *mbs = mbc;
        *state = conversion_state.state;
      }
      return (size_t) -1;
    }

    /* POSIX and ISO C are silent about this */
    if (wcs != NULL && count == 0) {
      return 0;
    }

    /* Store terminating L'\0' and stop */
    if (length == 0) {
      if (wcs != NULL) {
        *wcs = L'\0';
        *mbs = NULL;
      }
      break;
    }

    /* Store converted `wc` in `wcs` */
    if (wcs != NULL) {
      *wcs = wc;
      wcs += 1;
    }

    wcConverted += 1;
    mbc += length;

    /* `count` wide characters have been stored in `wcs`, stop */
    if (wcs != NULL && wcConverted == count) {
      *mbs = mbc;
      break;
    }
  }

  if (wcs != NULL) {
    *state = conversion_state.state;
  }

  return wcConverted;
}
