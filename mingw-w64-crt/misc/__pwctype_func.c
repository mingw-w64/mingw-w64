/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
#include <corecrt.h>

_CRTIMP const wctype_t** __cdecl __p__pwctype(void);

const wctype_t* __cdecl __pwctype_func(void);
const wctype_t* __cdecl __pwctype_func(void)
{
    return *__p__pwctype();
}
const wctype_t* (__cdecl *__MINGW_IMP_SYMBOL(__pwctype_func))(void) = __pwctype_func;
