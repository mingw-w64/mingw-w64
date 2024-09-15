/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

#if defined(__arm__) || defined(__aarch64__) || defined(_ARM_) || defined(_ARM64_)

/*
 * ARM versions of msvcrt.dll do not provide _winver global variable, so emulate
 * __p__winver() pointer via private variable and fill _winver variable value
 * from _winmajor and _winminor global variables. All ARM versions provide
 * _winmajor and _winminor global variables, but do not provide __p__winmajor()
 * and __p__winminor() functions. To avoid referencing mingw-w64 emulations of
 * these __p_ functions, access global variables directly.
 */

extern unsigned int* __MINGW_IMP_SYMBOL(_winmajor);
extern unsigned int* __MINGW_IMP_SYMBOL(_winminor);

static unsigned int _winver;

unsigned int* __cdecl __p__winver(void);
unsigned int* __cdecl __p__winver(void)
{
    if (!_winver)
        _winver = (*__MINGW_IMP_SYMBOL(_winmajor) << 8) | *__MINGW_IMP_SYMBOL(_winminor);
    return &_winver;
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__winver))(void) = __p__winver;

#else

extern unsigned int* __MINGW_IMP_SYMBOL(_winver);

unsigned int* __cdecl __p__winver(void);
unsigned int* __cdecl __p__winver(void)
{
    return __MINGW_IMP_SYMBOL(_winver);
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__winver))(void) = __p__winver;

#endif
