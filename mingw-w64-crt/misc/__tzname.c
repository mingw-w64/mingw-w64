/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern char** __MINGW_IMP_SYMBOL(_tzname);

char** __cdecl __tzname(void);
char** __cdecl __tzname(void)
{
    return __MINGW_IMP_SYMBOL(_tzname);
}
char** (__cdecl *__MINGW_IMP_SYMBOL(__tzname))(void) = __tzname;

char** __attribute__ ((alias ("__tzname"))) __cdecl __p__tzname(void);
extern char** (__cdecl * __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(__tzname))))) __MINGW_IMP_SYMBOL(__p__tzname))(void);
