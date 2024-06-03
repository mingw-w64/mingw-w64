/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern int* __MINGW_IMP_SYMBOL(_sys_nerr);

int* __cdecl __sys_nerr(void);
int* __cdecl __sys_nerr(void)
{
    return __MINGW_IMP_SYMBOL(_sys_nerr);
}
int* (__cdecl *__MINGW_IMP_SYMBOL(__sys_nerr))(void) = __sys_nerr;
