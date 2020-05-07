/*
    Copyright (c) 2016 mingw-w64 project

    Contributing authors: Hugo Beauzée-Luyssen

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

#define GetStartupInfo __GetStartupInfo
#include <windows.h>
#undef GetStartupInfo

VOID WINAPI GetStartupInfo( LPSTARTUPINFO lpStartupInfo )
{
    // This stub is provided solely to allow configure to compile a test program
    // linking with libwindowsapp.a
    // There is no reason for a winstore application to call this function
    abort();
}

#ifdef _X86_
VOID (WINAPI *__MINGW_IMP_SYMBOL(GetStartupInfoA))(LPSTARTUPINFO) __asm__("__imp__GetStartupInfoA@4") = GetStartupInfo;
VOID (WINAPI *__MINGW_IMP_SYMBOL(GetStartupInfoW))(LPSTARTUPINFO) __asm__("__imp__GetStartupInfoW@4") = GetStartupInfo;
#else
VOID (WINAPI *__MINGW_IMP_SYMBOL(GetStartupInfoA))(LPSTARTUPINFO) __asm__("__imp_GetStartupInfoA") = GetStartupInfo;
VOID (WINAPI *__MINGW_IMP_SYMBOL(GetStartupInfoW))(LPSTARTUPINFO) __asm__("__imp_GetStartupInfoW") = GetStartupInfo;
#endif
