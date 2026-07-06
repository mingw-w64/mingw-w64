/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _CTYPE_DISABLE_MACROS
#include <ctype.h>

int __cdecl _ispunct_l(int _C, _locale_t _Locale)
{
  return _isctype_l(_C, _PUNCT, _Locale);
}
int (__cdecl *__MINGW_IMP_SYMBOL(_ispunct_l))(int, _locale_t) = _ispunct_l;
