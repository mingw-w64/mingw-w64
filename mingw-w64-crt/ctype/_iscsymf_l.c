/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define __MSVCRT_VERSION__ 0x0800

#define _CTYPE_DISABLE_MACROS
#include <ctype.h>

/**
 * See ctype.h for rationale.
 *
 * Note that import symbol __MINGW_IMP_SYMBOL(_iscsymf_l) is not provided on
 * purpose.
 */

int __cdecl _iscsymf_l (wint_t _C, _locale_t _Locale) {
  return (_isalpha_l (_C, _Locale) || _C == '_');
}
