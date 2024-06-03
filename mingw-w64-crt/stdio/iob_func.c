/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

typedef struct FILE FILE;

extern FILE* __MINGW_IMP_SYMBOL(_iob);

FILE* __cdecl __iob_func(void);
FILE* __cdecl __iob_func(void)
{
    return __MINGW_IMP_SYMBOL(_iob);
}
FILE* (__cdecl *__MINGW_IMP_SYMBOL(__iob_func))(void) = __iob_func;

FILE* __attribute__ ((alias ("__iob_func"))) __cdecl __p__iob(void);
extern FILE* (__cdecl * __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(__iob_func))))) __MINGW_IMP_SYMBOL(__p__iob))(void);
