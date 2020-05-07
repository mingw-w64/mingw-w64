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

#define _WIN32_WINNT 0x0600 /* FlsAlloc, FlsFree are Vista+ */

#define TlsAlloc __TlsAlloc
#define TlsFree __TlsFree
#define TlsGetValue __TlsGetValue
#define TlsSetValue __TlsSetValue
#include <windef.h>
#include <windows.h>
#undef TlsAlloc
#undef TlsFree
#undef TlsGetValue
#undef TlsSetValue

DWORD WINAPI TlsAlloc (void);
WINBOOL WINAPI TlsFree (DWORD id);
WINBOOL WINAPI TlsSetValue (DWORD id, void *p);
LPVOID WINAPI TlsGetValue (DWORD id);

static void WINAPI __ic_fls_free (void *data)
{
    (void)data;
}

LPVOID WINAPI TlsGetValue (DWORD id)
{
    return FlsGetValue (id);
}

WINBOOL WINAPI TlsSetValue (DWORD id, LPVOID p)
{
    return FlsSetValue (id, p);
}

WINBOOL WINAPI TlsFree (DWORD id)
{
    return FlsFree (id);
}

DWORD WINAPI TlsAlloc (void)
{
    return FlsAlloc (__ic_fls_free);
}

#ifdef _X86_
DWORD (WINAPI *__MINGW_IMP_SYMBOL(TlsAlloc))(void) __asm__("__imp__TlsAlloc@0") = TlsAlloc;
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(TlsFree))(DWORD) __asm__("__imp__TlsFree@4") = TlsFree;
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(TlsSetValue))(DWORD, LPVOID) __asm__("__imp__TlsSetValue@8") = TlsSetValue;
LPVOID (WINAPI *__MINGW_IMP_SYMBOL(TlsGetValue))(DWORD) __asm__("__imp__TlsGetValue@4") = TlsGetValue;
#else
DWORD (WINAPI *__MINGW_IMP_SYMBOL(TlsAlloc))(void) __asm__("__imp_TlsAlloc") = TlsAlloc;
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(TlsFree))(DWORD) __asm__("__imp_TlsFree") = TlsFree;
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(TlsSetValue))(DWORD, LPVOID) __asm__("__imp_TlsSetValue") = TlsSetValue;
LPVOID (WINAPI *__MINGW_IMP_SYMBOL(TlsGetValue))(DWORD) __asm__("__imp_TlsGetValue") = TlsGetValue;
#endif
