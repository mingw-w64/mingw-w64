/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <corecrt_startup.h>

int __cdecl _initterm_e(_PIFV * first_func, _PIFV * last_func)
{
    _PIFV * func;
    int ret;

    for (func = first_func; func < last_func; func++)
    {
        if (!*func)
            continue;
        ret = (**func)();
        if (ret)
            return ret;
    }

    return 0;
}
int (__cdecl *__MINGW_IMP_SYMBOL(_initterm_e))(_PIFV *, _PIFV *) = _initterm_e;
