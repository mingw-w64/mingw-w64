/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern long* __MINGW_IMP_SYMBOL(_dstbias);

long* __cdecl __dstbias(void);
long* __cdecl __dstbias(void)
{
    return __MINGW_IMP_SYMBOL(_dstbias);
}
long* (__cdecl *__MINGW_IMP_SYMBOL(__dstbias))(void) = __dstbias;

long* __attribute__ ((alias ("__dstbias"))) __cdecl __p__dstbias(void);
extern long* (__cdecl * __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(__dstbias))))) __MINGW_IMP_SYMBOL(__p__dstbias))(void);
