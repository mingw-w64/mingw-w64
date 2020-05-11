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

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x501
#endif

#define _beginthreadex ___beginthreadex
#define _endthreadex ___endthreadex
#include <windef.h>
#include <winbase.h>
#include <processthreadsapi.h>
#undef _endthreadex
#undef _beginthreadex

uintptr_t __cdecl _beginthreadex(void *_Security, unsigned _StackSize,
                                         unsigned (__stdcall *_StartAddress) (void *),
                                         void *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr)
{
    return (uintptr_t)CreateThread(_Security, _StackSize, (LPTHREAD_START_ROUTINE)_StartAddress,
                        _ArgList, _InitFlag, (LPDWORD)_ThrdAddr);
}

void __cdecl _endthreadex(unsigned _Retval)
{
    ExitThread(_Retval);
}

#ifdef _X86_
uintptr_t (__cdecl *__MINGW_IMP_SYMBOL(_beginthreadex))(void*, unsigned, unsigned (__stdcall *)(void *), void *,unsigned, unsigned*) __asm__("__imp___beginthreadex") = _beginthreadex;
void (__cdecl *__MINGW_IMP_SYMBOL(_endthreadex))(unsigned) __asm__("__imp___endthreadex") = _endthreadex;
#else
uintptr_t (__cdecl *__MINGW_IMP_SYMBOL(_beginthreadex))(void*, unsigned, unsigned (__stdcall *)(void *), void *,unsigned, unsigned*) __asm__("__imp__beginthreadex") = _beginthreadex;
void (__cdecl *__MINGW_IMP_SYMBOL(_endthreadex))(unsigned) __asm__("__imp__endthreadex") = _endthreadex;
#endif
