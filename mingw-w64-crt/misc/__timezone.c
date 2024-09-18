/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern long* __MINGW_IMP_SYMBOL(_timezone);

long* __cdecl __timezone(void);
long* __cdecl __timezone(void)
{
    return __MINGW_IMP_SYMBOL(_timezone);
}
long* (__cdecl *__MINGW_IMP_SYMBOL(__timezone))(void) = __timezone;

long* __attribute__ ((alias ("__timezone"))) __cdecl __p__timezone(void);
extern long* (__cdecl * __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(__timezone))))) __MINGW_IMP_SYMBOL(__p__timezone))(void);
