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

#define VirtualProtect __VirtualProtect
#include <windef.h>
#include <winbase.h>
#undef VirtualProtect


BOOL WINAPI VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect)
{
#if _WIN32_WINNT >= _WIN32_WINNT_WIN10
    ULONG OldProtection;
    BOOL res = VirtualProtectFromApp(lpAddress, dwSize, flNewProtect,
                                     lpflOldProtect ? &OldProtection : NULL);
    if (lpflOldProtect)
        *lpflOldProtect = OldProtection;
    return res;
#else /* _WIN32_WINNT < _WIN32_WINNT_WIN10 */
    SetLastError(ERROR_ACCESS_DENIED);
    return FALSE;
#endif /* _WIN32_WINNT < _WIN32_WINNT_WIN10 */
}

#ifdef _X86_
BOOL (WINAPI *__MINGW_IMP_SYMBOL(VirtualProtect))(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect) __asm__("__imp__VirtualProtect@16") = VirtualProtect;
#else
BOOL (WINAPI *__MINGW_IMP_SYMBOL(VirtualProtect))(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect) __asm__("__imp_VirtualProtect") = VirtualProtect;
#endif
