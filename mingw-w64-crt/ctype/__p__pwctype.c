/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
#include <corecrt.h>

extern const wctype_t** __MINGW_IMP_SYMBOL(_pwctype);

const wctype_t** __cdecl __p__pwctype(void);
const wctype_t** __cdecl __p__pwctype(void)
{
    return __MINGW_IMP_SYMBOL(_pwctype);
}
const wctype_t** (__cdecl *__MINGW_IMP_SYMBOL(__p__pwctype))(void) = __p__pwctype;
