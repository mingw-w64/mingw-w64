/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern int* __MINGW_IMP_SYMBOL(__argc);

int* __cdecl __p___argc(void);
int* __cdecl __p___argc(void)
{
    return __MINGW_IMP_SYMBOL(__argc);
}
int* (__cdecl *__MINGW_IMP_SYMBOL(__p___argc))(void) = __p___argc;
