/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

unsigned int* __cdecl __p__osplatform(void);
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__osplatform))(void) = __p__osplatform;

/* older i386 versions of msvcrt.dll do not provide _osplatform symbol, so resolve it at runtime */
#if defined(__LIBMSVCRT_OS__) && defined(__i386__)

#include <windows.h>
#include <msvcrt.h>

static unsigned int* _osplatform_ptr;
static unsigned int _osplatform_static;

unsigned int* __cdecl __p__osplatform(void)
{
    if (!_osplatform_ptr)
    {
        HMODULE msvcrt = __mingw_get_msvcrt_handle();
        if (msvcrt)
            _osplatform_ptr = (unsigned int*)GetProcAddress(msvcrt, "_osplatform");
        if (!_osplatform_ptr)
        {
            OSVERSIONINFOA osvi;
            osvi.dwOSVersionInfoSize = sizeof(osvi);
            if (GetVersionExA(&osvi))
                _osplatform_static = osvi.dwPlatformId;
            _osplatform_ptr = &_osplatform_static;
        }
    }
    return _osplatform_ptr;
}

#else

extern unsigned int* __MINGW_IMP_SYMBOL(_osplatform);

unsigned int* __cdecl __p__osplatform(void)
{
    return __MINGW_IMP_SYMBOL(_osplatform);
}

#endif
