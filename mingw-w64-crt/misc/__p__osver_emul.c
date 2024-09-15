/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdlib.h>
#include <windows.h>

#undef _osver
static unsigned int _osver;

#undef _winmajor
static unsigned int _winmajor;

#undef _winminor
static unsigned int _winminor;

#undef _winver
static unsigned int _winver;

static void init_versions(void)
{
    static int init = 0;
    if (!init)
    {
        unsigned int version = GetVersion();
        _winmajor = version & 0xFF;
        _winminor = (version >> 8) & 0xFF;
        _winver = (_winmajor << 8) | _winminor;
        _osver = (version >> 16) & 0xFFFF;
        init = 1;
    }
}

unsigned int* __cdecl __p__osver(void)
{
    init_versions();
    return &_osver;
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__osver))(void) = __p__osver;

unsigned int* __cdecl __p__winmajor(void)
{
    init_versions();
    return &_winmajor;
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__winmajor))(void) = __p__winmajor;

unsigned int* __cdecl __p__winminor(void)
{
    init_versions();
    return &_winminor;
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__winminor))(void) = __p__winminor;

unsigned int* __cdecl __p__winver(void)
{
    init_versions();
    return &_winver;
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__winver))(void) = __p__winver;
