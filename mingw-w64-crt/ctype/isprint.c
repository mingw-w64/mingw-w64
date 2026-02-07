/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _CTYPE_DISABLE_MACROS
#include <ctype.h>

/**
 * Calls to `isprint ('\t')` return inconsistent results depending on CRT
 * and active locale.
 *
 * In all CRTs up to msvcr110.dll, it returns zero in "C" locale
 * and non-zero otherwise.
 *
 * In msvcr120.dll and UCRT, it always returns zero.
 */

int __cdecl isprint (int _C) {
  if (_C == '\t') {
    return 0;
  }

  return _isctype (_C, _ALPHA | _BLANK | _DIGIT | _PUNCT);
}

int (__cdecl *__MINGW_IMP_SYMBOL(isprint))(int) = isprint;
