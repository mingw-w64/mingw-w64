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
#include <windows.h>

/**
 * Private `mbstate_t` to use if caller did not supply one.
 */
static mbstate_t state_mbrlen = {0};
static mbstate_t state_mbrtowc = {0};
static mbstate_t state_mbsrtowcs = {0};

static size_t mbrtowc_cp (
  wchar_t *__restrict__ wc,
  const char *__restrict__ mbs,
  size_t count,
  mbstate_t *__restrict__ state,
  unsigned cp,
  int mb_cur_max
) {
  /* Set `state` to initial state */
  if (mbs == NULL) {
    *state = 0;
    return 0;
  }

  /* Detect invalid conversion state */
  if ((unsigned) *state > 0xFF) {
    goto einval;
  }

  /* Both ISO C and POSIX do not mention this case */
  if (count == 0) {
    return (size_t) -2;
  }

  /* Treat `state` as an array of bytes */
  union {
    mbstate_t state;
    char bytes[4];
  } conversion_state = {.state = *state};

  /* For SBCS code pages `state` must always be in initial state */
  if (mb_cur_max == 1 && conversion_state.bytes[0]) {
    goto einval;
  }

  /* Handle "C" locale */
  if (cp == 0) {
    if (wc != NULL) {
      *wc = (unsigned char) mbs[0];
    }
    return !!mbs[0];
  }

  /* Length of potential multibyte character */
  int length = 1;

  if (conversion_state.bytes[0]) {
    conversion_state.bytes[1] = mbs[0];
    length = 2;
  } else if (mb_cur_max == 2 && IsDBCSLeadByteEx (cp, (BYTE) mbs[0])) {
    conversion_state.bytes[0] = mbs[0];

    /* We need to examine mbs[1] */
    if (count < 2) {
      *state = conversion_state.state;
      return (size_t) -2;
    }

    conversion_state.bytes[1] = mbs[1];
    length = 2;
  } else {
    conversion_state.bytes[0] = mbs[0];
  }

  /* Store terminating '\0' */
  if (conversion_state.bytes[0] == '\0') {
    if (wc != NULL) {
      *wc = L'\0';
      *state = 0;
    }
    return 0;
  }

  /* Truncated multibyte character */
  if (length == 2 && conversion_state.bytes[1] == '\0') {
    goto eilseq;
  }

  /* Converted wide character */
  wchar_t wcOut = WEOF;

  int ret = MultiByteToWideChar (
    cp, MB_ERR_INVALID_CHARS, conversion_state.bytes, length, &wcOut, 1
  );

  if (ret != 1) {
    goto eilseq;
  }

  if (wc != NULL) {
    *wc = wcOut;
    *state = 0;
  }

  return length;

eilseq:
  _set_errno (EILSEQ);
  return (size_t) -1;

einval:
  _set_errno (EINVAL);
  return (size_t) -1;
}

size_t mbrlen (
  const char *__restrict__ mbs,
  size_t count,
  mbstate_t *__restrict__ state
) {
  /* Use private `mbstate_t` if caller did not supply one */
  if (state == NULL) {
    state = &state_mbrlen;
  }
  wchar_t wc = WEOF;
  return mbrtowc (&wc, mbs, count, state);
}

size_t mbrtowc (
  wchar_t *__restrict__ wc,
  const char *__restrict__ mbs,
  size_t count,
  mbstate_t *__restrict__ state
) {
  /* Use private `mbstate_t` if caller did not supply one */
  if (state == NULL) {
    state = &state_mbrtowc;
  }

  /* Code page used by current locale */
  unsigned cp = ___lc_codepage_func ();
  /* Maximum character length in `cp` */
  int mb_cur_max = MB_CUR_MAX;

  return mbrtowc_cp (wc, mbs, count, state, cp, mb_cur_max);
}

size_t mbsrtowcs (
  wchar_t *wcs,
  const char **__restrict__ mbs,
  size_t count,
  mbstate_t *__restrict__ state
) {
  /* Use private `mbstate_t` if caller did not supply one */
  if (state == NULL) {
    state = &state_mbsrtowcs;
  }

  /* Code page used by current locale */
  unsigned cp = ___lc_codepage_func ();
  /* Maximum character length in `cp` */
  int mb_cur_max = MB_CUR_MAX;

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

  while (1) {
    const size_t length = mbrtowc_cp (
      &wc, mbc, mb_cur_max, &conversion_state.state, cp, mb_cur_max
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
