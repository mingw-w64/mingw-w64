/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
#include <corecrt.h>

#undef iswalnum
_CRTIMP int __cdecl iswalnum(wint_t c);

#undef __iswcsym
int __cdecl __iswcsym(wint_t c);
int __cdecl __iswcsym(wint_t c)
{
  return iswalnum(c) || c == L'_';
}
int (__cdecl *__MINGW_IMP_SYMBOL(__iswcsym))(wint_t) = __iswcsym;
