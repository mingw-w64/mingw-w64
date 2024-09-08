/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern unsigned int* __MINGW_IMP_SYMBOL(_osver);

unsigned int* __cdecl __p__osver(void);
unsigned int* __cdecl __p__osver(void)
{
    return __MINGW_IMP_SYMBOL(_osver);
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__osver))(void) = __p__osver;
