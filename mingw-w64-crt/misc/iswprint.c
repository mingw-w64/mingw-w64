/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _CTYPE_DISABLE_MACROS
#include <wctype.h>

/**
 * Calls to `iswprint (L'\t')` return inconsistent results depending on CRT
 * and active locale.
 *
 * In all CRTs up to msvcrt.dll version 6.1, it returns zero in "C" locale
 * and non-zero otherwise.
 *
 * Since msvcr70.dll up to msvcr110.dll, it always returns non-zero;
 * OS-specific versions of msvcrt.dll follow this behavior.
 *
 * In msvcr120.dll and UCRT, it always returns zero.
 */

int __cdecl iswprint (wint_t _C) {
  /**
   * mingw-w64's `iswctype` is a wrapper around CRT's `iswctype` which
   * properly handles TAB character.
   */
  return iswctype (_C, _ALPHA | _BLANK | _DIGIT | _PUNCT);
}

int (__cdecl *__MINGW_IMP_SYMBOL(iswprint))(wint_t) = iswprint;
