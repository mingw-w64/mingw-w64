/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _CTYPE_DISABLE_MACROS
#include <wctype.h>

/**
 * Both `wctrans` and `towctrans` functions were added in msvcr120.dll.
 *
 * CRT's `towctrans` does not properly handle case when second argument is
 * `(wctrans_t)0`.
 */

/**
 * This is CRT's `towctrans` renamed to `__msvcrt_towctrans`.
 */
extern wint_t (__cdecl *__MINGW_IMP_SYMBOL (__msvcrt_towctrans)) (wint_t, wctrans_t);

wint_t __cdecl towctrans (wint_t _C, wctrans_t _Type) {
  /**
   * POSIX requires that if `_Type` is zero, `_C` is returned unchanged.
   */
  if (_Type == (wctrans_t) 0) {
    return _C;
  }

  return __MINGW_IMP_SYMBOL (__msvcrt_towctrans) (_C, _Type);
}

wint_t (__cdecl *__MINGW_IMP_SYMBOL (towctrans)) (wint_t, wctrans_t) = towctrans;
