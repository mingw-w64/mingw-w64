/*
    Copyright (c) 2013-2016 mingw-w64 project

    Contributing authors: Jean-Baptiste Kempf

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

#define _WIN32_WINNT 0x502 /* GetFileAttributesEx is XP+ */

/* GetFileAttributesA is not defined, as ANSI functions are not available
 * in Windows Store applications */

#define GetFileAttributesW __GetFileAttributesW
#include <windef.h>
#include <winbase.h>
#undef GetFileAttributesW

DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName)
{
    WIN32_FILE_ATTRIBUTE_DATA fileInformation;
    if( GetFileAttributesExW(lpFileName, GetFileExInfoStandard, &fileInformation) != 0)
        return fileInformation.dwFileAttributes;
    else
        return INVALID_FILE_ATTRIBUTES;
}

#ifdef _X86_
DWORD (WINAPI *__MINGW_IMP_SYMBOL(GetFileAttributesW))(LPCWSTR lpFileName) __asm__("__imp__GetFileAttributesW@4") = GetFileAttributesW;
#else
DWORD (WINAPI *__MINGW_IMP_SYMBOL(GetFileAttributesW))(LPCWSTR lpFileName) __asm__("__imp_GetFileAttributesW") = GetFileAttributesW;
#endif
