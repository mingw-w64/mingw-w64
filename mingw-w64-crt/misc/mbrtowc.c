/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>

#include "mingw-wchar.h"

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
