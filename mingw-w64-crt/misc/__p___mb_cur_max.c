/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern int* __MINGW_IMP_SYMBOL(__mb_cur_max);

int* __cdecl __p___mb_cur_max(void);
int* __cdecl __p___mb_cur_max(void)
{
    return __MINGW_IMP_SYMBOL(__mb_cur_max);
}
int* (__cdecl *__MINGW_IMP_SYMBOL(__p___mb_cur_max))(void) = __p___mb_cur_max;
