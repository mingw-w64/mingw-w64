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

#define _WIN32_WINNT 0x600 /* CreateSemaphoreExW is Vista+ */

#define CreateSemaphoreW __CreateSemaphoreW
#define CreateSemaphoreA __CreateSemaphoreA
#include <windef.h>
#include <winbase.h>
#undef CreateSemaphoreW
#undef CreateSemaphoreA

HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
                               LONG lInitialCount,
                               LONG lMaximumCount,
                               LPCWSTR lpName)
{
    return CreateSemaphoreExW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName, 0, EVENT_ALL_ACCESS);
}

#ifdef _X86_
HANDLE (WINAPI *__MINGW_IMP_SYMBOL(CreateSemaphoreW))(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCWSTR lpName) __asm__("__imp__CreateSemaphoreW@16") = CreateSemaphoreW;
#else
HANDLE (WINAPI *__MINGW_IMP_SYMBOL(CreateSemaphoreW))(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCWSTR lpName) __asm__("__imp_CreateSemaphoreW") = CreateSemaphoreW;
#endif

/*
 This is not really a proper implementation, but it is needed by gcc/libstdc++
 */
HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
                               LONG lInitialCount,
                               LONG lMaximumCount,
                               LPCSTR lpName)
{
    LPCWSTR lpwName;
    if( lpName == NULL )
        lpwName = NULL;
    else
    {
        SetLastError( ERROR_BAD_ARGUMENTS );
        return NULL; 
    }
    return CreateSemaphoreW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpwName );
}

#ifdef _X86_
HANDLE (WINAPI *__MINGW_IMP_SYMBOL(CreateSemaphoreA))(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCSTR lpName) __asm__("__imp__CreateSemaphoreA@16") = CreateSemaphoreA;
#else
HANDLE (WINAPI *__MINGW_IMP_SYMBOL(CreateSemaphoreA))(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCSTR lpName) __asm__("__imp_CreateSemaphoreA") = CreateSemaphoreA;
#endif
