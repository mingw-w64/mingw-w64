/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

extern const unsigned short** __MINGW_IMP_SYMBOL(_pctype);

const unsigned short** __cdecl __p__pctype(void);
const unsigned short** __cdecl __p__pctype(void)
{
    return __MINGW_IMP_SYMBOL(_pctype);
}
const unsigned short** (__cdecl *__MINGW_IMP_SYMBOL(__p__pctype))(void) = __p__pctype;
