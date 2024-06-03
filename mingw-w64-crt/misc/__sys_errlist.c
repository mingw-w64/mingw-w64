/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern char** __MINGW_IMP_SYMBOL(_sys_errlist);

char** __cdecl __sys_errlist(void);
char** __cdecl __sys_errlist(void)
{
    return __MINGW_IMP_SYMBOL(_sys_errlist);
}
char** (__cdecl *__MINGW_IMP_SYMBOL(__sys_errlist))(void) = __sys_errlist;
