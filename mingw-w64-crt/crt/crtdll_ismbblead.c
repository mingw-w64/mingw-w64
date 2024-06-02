/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>
#include <windows.h>

/**
 * Implementation of _ismbblead() function called by crtexewin.c startup code
 * for crtdll.dll library which in some versions does not contain this function.
 */

static int __cdecl emu_ismbblead(unsigned int __UNUSED_PARAM(_C))
{
    /* Fallback implementation for crtdll.dll version which is not MBCS aware. */
    return 0;
}

static int __cdecl init_ismbblead(unsigned int _C);

int (__cdecl *__MINGW_IMP_SYMBOL(_ismbblead))(unsigned int _C) = init_ismbblead;

static int __cdecl init_ismbblead(unsigned int _C)
{
    HMODULE crtdll;
    int (__cdecl *func)(unsigned int _C) = NULL;

    crtdll = GetModuleHandleA("crtdll.dll");

    if (crtdll)
        func = (int (__cdecl *)(unsigned int _C))GetProcAddress(crtdll, "_ismbblead");

    if (!func)
        func = emu_ismbblead;

    return (__MINGW_IMP_SYMBOL(_ismbblead) = func)(_C);
}

int __cdecl _ismbblead(unsigned int _C);
int __cdecl _ismbblead(unsigned int _C)
{
    return __MINGW_IMP_SYMBOL(_ismbblead)(_C);
}
