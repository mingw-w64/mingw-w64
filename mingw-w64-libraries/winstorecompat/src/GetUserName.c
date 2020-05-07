/*
    Copyright (c) 2020 mingw-w64 project

    Contributing authors: Steve Lhomme

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

#define GetUserNameA __GetUserNameA
#define GetUserNameW __GetUserNameW
#include <windows.h>
#undef GetUserNameA
#undef GetUserNameW

WINBOOL WINAPI GetUserNameA(LPSTR lpBuffer, LPDWORD pcbBuffer)
{
#if _WIN32_WINNT >= _WIN32_WINNT_WIN10
    DWORD written = GetEnvironmentVariableA("USERNAME", lpBuffer, *pcbBuffer);
    if (written != 0 && written <= *pcbBuffer) {
        *pcbBuffer = written + 1;
        return TRUE;
    }
#endif
    SetLastError(ERROR_ENVVAR_NOT_FOUND);
    return FALSE;
}

WINBOOL WINAPI GetUserNameW(LPWSTR lpBuffer, LPDWORD pcbBuffer)
{
#if _WIN32_WINNT >= _WIN32_WINNT_WIN10
    DWORD written = GetEnvironmentVariableW(L"USERNAME", lpBuffer, *pcbBuffer);
    if (written != 0 && written <= *pcbBuffer) {
        *pcbBuffer = written + 1;
        return TRUE;
    }
#endif
    SetLastError(ERROR_ENVVAR_NOT_FOUND);
    return FALSE;
}

#ifdef _X86_
WINBOOL(WINAPI *__MINGW_IMP_SYMBOL(GetUserNameA))(LPSTR lpBuffer, LPDWORD pcbBuffer) __asm__("__imp__GetUserNameA@8") = GetUserNameA;
WINBOOL(WINAPI *__MINGW_IMP_SYMBOL(GetUserNameW))(LPWSTR lpBuffer, LPDWORD pcbBuffer) __asm__("__imp__GetUserNameW@8") = GetUserNameW;
#else
WINBOOL(WINAPI *__MINGW_IMP_SYMBOL(GetUserNameA))(LPSTR lpBuffer, LPDWORD pcbBuffer) __asm__("__imp_GetUserNameA") = GetUserNameA;
WINBOOL(WINAPI *__MINGW_IMP_SYMBOL(GetUserNameW))(LPWSTR lpBuffer, LPDWORD pcbBuffer) __asm__("__imp_GetUserNameW") = GetUserNameW;
#endif
