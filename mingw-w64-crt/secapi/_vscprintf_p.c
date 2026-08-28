#include <stdio.h>

int __cdecl _vscprintf_p(const char *format, va_list arglist)
{
    return _vscprintf_p_l(format, NULL, arglist);
}

int __cdecl (*__MINGW_IMP_SYMBOL(_vscprintf_p))(const char *, va_list) = _vscprintf_p;
