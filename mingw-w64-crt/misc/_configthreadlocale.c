/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <locale.h>

int __cdecl _configthreadlocale(int flag)
{
    /* _ENABLE_PER_THREAD_LOCALE can't work on msvcrt.dll. */
    if (flag == 0 || flag == _DISABLE_PER_THREAD_LOCALE) {
        return _DISABLE_PER_THREAD_LOCALE;
    }
    return -1;
}

int (__cdecl *__MINGW_IMP_SYMBOL(_configthreadlocale)) (int) = _configthreadlocale;
