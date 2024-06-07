/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
#include <stddef.h>

extern wchar_t*** __MINGW_IMP_SYMBOL(_wenviron);

wchar_t*** __cdecl __p__wenviron(void);
wchar_t*** __cdecl __p__wenviron(void)
{
    return __MINGW_IMP_SYMBOL(_wenviron);
}
wchar_t*** (__cdecl *__MINGW_IMP_SYMBOL(__p__wenviron))(void) = __p__wenviron;
