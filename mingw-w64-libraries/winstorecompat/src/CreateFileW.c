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

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x602 /* CreateFile2 is Win8 APP Family */
#endif

#define CreateFileW __CreateFileW
#include <windef.h>
#include <winbase.h>
#undef CreateFileW

HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,
                          DWORD dwDesiredAccess,
                          DWORD dwShareMode,
                          LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                          DWORD dwCreationDisposition,
                          DWORD dwFlagsAndAttributes,
                          HANDLE hTemplateFile)
{
    CREATEFILE2_EXTENDED_PARAMETERS createExParams;
    createExParams.dwSize = sizeof(CREATEFILE2_EXTENDED_PARAMETERS);
    createExParams.dwFileAttributes = dwFlagsAndAttributes & 0xFFFF;
    createExParams.dwFileFlags = dwFlagsAndAttributes & 0xFFF00000;
    createExParams.dwSecurityQosFlags = dwFlagsAndAttributes & 0x000F0000;
    createExParams.lpSecurityAttributes = lpSecurityAttributes;
    createExParams.hTemplateFile = hTemplateFile;
    return CreateFile2(lpFileName, dwDesiredAccess, dwShareMode, dwCreationDisposition, &createExParams);
}

#ifdef _X86_
HANDLE (WINAPI *__MINGW_IMP_SYMBOL(CreateFileW))(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile) __asm__("__imp__CreateFileW@28") = CreateFileW;
#else
HANDLE (WINAPI *__MINGW_IMP_SYMBOL(CreateFileW))(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile) __asm__("__imp_CreateFileW") = CreateFileW;
#endif
