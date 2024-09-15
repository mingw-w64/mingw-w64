/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>

#undef _osplatform
static unsigned int _osplatform;

unsigned int* __cdecl __p__osplatform(void);
unsigned int* __cdecl __p__osplatform(void)
{
    if (!_osplatform)
    {
        OSVERSIONINFOA osvi;
        osvi.dwOSVersionInfoSize = sizeof(osvi);
        if (GetVersionExA(&osvi))
            _osplatform = osvi.dwPlatformId;
    }
    return &_osplatform;
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__osplatform))(void) = __p__osplatform;
