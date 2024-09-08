/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern unsigned int* __MINGW_IMP_SYMBOL(_winminor);

unsigned int* __cdecl __p__winminor(void);
unsigned int* __cdecl __p__winminor(void)
{
    return __MINGW_IMP_SYMBOL(_winminor);
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__winminor))(void) = __p__winminor;
