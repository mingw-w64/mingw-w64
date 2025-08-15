/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <errno.h>
#include <windows.h>

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

  /* Code page used by current locale */
  unsigned cp = ___lc_codepage_func ();

  /* Maximum character length used by current locale */
  int mb_cur_max = ___mb_cur_max_func ();

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
  } else if (mb_cur_max == 2 && isleadbyte (mbs[0])) {
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
  errno = EILSEQ;
  return (size_t) -1;

einval:
  errno = EINVAL;
  return (size_t) -1;
}
