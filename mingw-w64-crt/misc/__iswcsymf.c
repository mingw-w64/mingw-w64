/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
#include <corecrt.h>

#undef iswalpha
_CRTIMP int __cdecl iswalpha(wint_t c);

#undef __iswcsymf
int __cdecl __iswcsymf(wint_t c);
int __cdecl __iswcsymf(wint_t c)
{
  return iswalpha(c) || c == L'_';
}
int (__cdecl *__MINGW_IMP_SYMBOL(__iswcsymf))(wint_t) = __iswcsymf;
