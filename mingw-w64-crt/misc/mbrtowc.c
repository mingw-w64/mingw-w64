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
 * __mingw_mbrtowc_cp is internal implementation for C95 functions mbrlen,
 * mbrtowc and mbsrtowcs.
 *
 * In order to perform conversion we need the following information:
 *
 *  - code page used by active locale (which can be a thread locale for
 *    msvcr80.dll and later); obtained by calling ___lc_codepage_func
 *
 *  - maximum character length in used code page; obtained by calling
 *    ___mb_cur_max_func
 *
 *  - for double-byte code pages, we need to recognize leading bytes in order
 *    to correctly convert multibyte characters; this can be done with Win32
 *    function IsDBCSLeadByteEx or CRT function isleadbyte
 *
 * crtdll.dll's ___lc_codepage_func is quite expensive as it obtains this
 * information by parsing return value of setlocale(LC_CTYPE, NULL). Using
 * __mingw_mbrtowc_cp allows mbsrtowcs call both ___lc_codepage_func and
 * ___mb_cur_max_func only once.
 */

size_t __mingw_mbrtowc_cp (
  wchar_t *__restrict__ wc,
  const char *__restrict__ mbs,
  size_t count,
  mbstate_t *__restrict__ state,
  unsigned cp,
  int mb_cur_max
) {
  /**
   * Calling mbrtowc (..., NULL, ..., state) is equivalent to
   *
   *  mbrtowc (NULL, "", 1, state)
   */
  if (mbs == NULL) {
    wc = NULL;
    mbs = "";
    count = 1;
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

  /* Number of bytes consumed from `mbs` */
  int bytes_consumed = 0;

  if (conversion_state.bytes[0]) {
    conversion_state.bytes[1] = mbs[0];
    bytes_consumed = 1;
    length = 2;
  } else if (mb_cur_max == 2 && isleadbyte ((unsigned char) mbs[0])) {
    conversion_state.bytes[0] = mbs[0];

    /* We need to examine mbs[1] */
    if (count < 2) {
      *state = conversion_state.state;
      return (size_t) -2;
    }

    conversion_state.bytes[1] = mbs[1];
    bytes_consumed = 2;
    length = 2;
  } else {
    conversion_state.bytes[0] = mbs[0];
    bytes_consumed = 1;
  }

  /* Store terminating '\0' */
  if (conversion_state.bytes[0] == '\0') {
    if (wc != NULL) {
      *wc = L'\0';
    }

    /* Set `state` to initial conversion state */
    *state = 0;

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
  }

  /* Set `state` to initial conversion state */
  *state = 0;

  return bytes_consumed;

eilseq:
  errno = EILSEQ;
  return (size_t) -1;

einval:
  errno = EINVAL;
  return (size_t) -1;
}

size_t mbrtowc (
  wchar_t *__restrict__ wc,
  const char *__restrict__ mbs,
  size_t count,
  mbstate_t *__restrict__ state
) {
  /* Use private `mbstate_t` if caller did not supply one */
  if (state == NULL) {
    static mbstate_t state_mbrtowc = {0};
    state = &state_mbrtowc;
  }

  /* Code page used by current locale */
  unsigned cp = ___lc_codepage_func ();

  /* Maximum character length used by current locale */
  int mb_cur_max = ___mb_cur_max_func ();

  return __mingw_mbrtowc_cp (wc, mbs, count, state, cp, mb_cur_max);
}
