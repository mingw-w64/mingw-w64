/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <corecrt.h>
#include <stddef.h>

__MINGW_ATTRIB_NORETURN void __cdecl _invalid_parameter_noinfo_noreturn(void)
{
    _invalid_parameter_noinfo();
    _invoke_watson(NULL, NULL, NULL, 0, 0);
}
__MINGW_ATTRIB_NORETURN void (__cdecl *__MINGW_IMP_SYMBOL(_invalid_parameter_noinfo_noreturn))(void) = _invalid_parameter_noinfo_noreturn;
