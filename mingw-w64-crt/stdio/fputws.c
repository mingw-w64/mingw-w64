/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>

int __cdecl fputws(const wchar_t * __restrict__ _Str, FILE * __restrict__ _File)
{
    return __ms_fwprintf(_File, L"%ls", _Str);
}
