/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _DEBUG /* needed for _invalid_parameter */
#include <corecrt.h>
#undef _DEBUG
#include <stddef.h>

void __cdecl _invalid_parameter_noinfo(void)
{
    _invalid_parameter(NULL, NULL, NULL, 0, 0);
}
void (__cdecl *__MINGW_IMP_SYMBOL(_invalid_parameter_noinfo))(void) = _invalid_parameter_noinfo;
