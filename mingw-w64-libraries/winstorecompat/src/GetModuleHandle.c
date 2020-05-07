/*
    Copyright (c) 2013-2016 mingw-w64 project

    Contributing authors: Rafaël Carré

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

#define GetModuleHandleA __GetModuleHandleA
#define GetModuleHandleW __GetModuleHandleW
#include <windows.h>
#include <stdio.h>
#undef GetModuleHandleA
#undef GetModuleHandleW

HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName)
{
    wchar_t msg[512];

    _snwprintf(msg, 511, L"GetModuleHandleA (%S) call suppressed\n", lpModuleName);
    msg[511] = '\0';

    OutputDebugStringW(msg);

    return NULL;
}

HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName)
{
    wchar_t msg[512];

    _snwprintf(msg, 511, L"GetModuleHandleW (%ws) call suppressed\n", lpModuleName);
    msg[511] = '\0';

    OutputDebugStringW(msg);

    return NULL;
}

#ifdef _X86_
HMODULE (WINAPI *__MINGW_IMP_SYMBOL(GetModuleHandleA))(LPCSTR) __asm__("__imp__GetModuleHandleA@4") = GetModuleHandleA;
HMODULE (WINAPI *__MINGW_IMP_SYMBOL(GetModuleHandleW))(LPCWSTR) __asm__("__imp__GetModuleHandleW@4") = GetModuleHandleW;
#else
HMODULE (WINAPI *__MINGW_IMP_SYMBOL(GetModuleHandleA))(LPCSTR) __asm__("__imp_GetModuleHandleA") = GetModuleHandleA;
HMODULE (WINAPI *__MINGW_IMP_SYMBOL(GetModuleHandleW))(LPCWSTR) __asm__("__imp_GetModuleHandleW") = GetModuleHandleW;
#endif
