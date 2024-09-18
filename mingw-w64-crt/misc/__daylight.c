/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern int* __MINGW_IMP_SYMBOL(_daylight);

int* __cdecl __daylight(void);
int* __cdecl __daylight(void)
{
    return __MINGW_IMP_SYMBOL(_daylight);
}
int* (__cdecl *__MINGW_IMP_SYMBOL(__daylight))(void) = __daylight;

int* __attribute__ ((alias ("__daylight"))) __cdecl __p__daylight(void);
extern int* (__cdecl * __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(__daylight))))) __MINGW_IMP_SYMBOL(__p__daylight))(void);
