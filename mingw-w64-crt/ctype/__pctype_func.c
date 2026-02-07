/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

_CRTIMP const unsigned short** __cdecl __p__pctype(void);

const unsigned short* __cdecl __pctype_func(void);
const unsigned short* __cdecl __pctype_func(void)
{
    return *__p__pctype();
}
const unsigned short* (__cdecl *__MINGW_IMP_SYMBOL(__pctype_func))(void) = __pctype_func;
