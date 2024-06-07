/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern char** __MINGW_IMP_SYMBOL(_pgmptr);

char** __cdecl __p__pgmptr(void);
char** __cdecl __p__pgmptr(void)
{
    return __MINGW_IMP_SYMBOL(_pgmptr);
}
char** (__cdecl *__MINGW_IMP_SYMBOL(__p__pgmptr))(void) = __p__pgmptr;
