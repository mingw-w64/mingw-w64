/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _CTYPE_DISABLE_MACROS
#include <wctype.h>

/**
 * CRT's `iswctype` has inconsistent behavior for TAB character when used with
 * `wctype_t` objects returned by `wctype` function which contain `_BLANK` bit.
 *
 * In all CRTs up to msvcrt.dll version 6.1, it returns zero in "C" locale
 * and non-zero otherwise.
 *
 * Since msvcr70.dll up to msvcr110.dll it always returns non-zero;
 * OS-specific versions of msvcrt.dll follow this behavior.
 *
 * In msvcr120.dll and UCRT it always returns zero.
 *
 * This behavior affects both `iswblank` and `iswprint` functions;
 * either or both of them have non-conforming behavior.
 */

/**
 * This is CRT's `iswctype` renamed to `__msvcrt_iswctype`.
 */
extern int (__cdecl *__MINGW_IMP_SYMBOL(__msvcrt_iswctype)) (wint_t, wctype_t);

int iswctype (wint_t _C, wctype_t _Type) {
  /**
   * `wctype_t` object returned for "print" character class contains _BLANK;
   * make sure TAB is handled correctly.
   */
  if (_C == L'\t' && (_Type & _BLANK)) {
    return (_Type == _BLANK ? _BLANK : 0);
  }

  return __MINGW_IMP_SYMBOL (__msvcrt_iswctype) (_C, _Type);
}

int (__cdecl *__MINGW_IMP_SYMBOL (iswctype)) (wint_t, wctype_t) = iswctype;
