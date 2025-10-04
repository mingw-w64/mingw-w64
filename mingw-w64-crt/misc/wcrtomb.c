/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>

#include "mingw-wchar.h"

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
