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

#define _WIN32_WINNT 0x501 /* SetErrorMode is XP+ */

#define SetErrorMode __SetErrorMode
#include <windef.h>
#include <winbase.h>
#undef SetErrorMode

UINT WINAPI SetErrorMode(UINT uMode)
{
    static LONG oldMode;
    return InterlockedExchange(&oldMode, (LONG)uMode);
}

#ifdef _X86_
UINT (WINAPI *__MINGW_IMP_SYMBOL(SetErrorMode))(UINT uMode) __asm__("__imp__SetErrorMode@4") = SetErrorMode;
#else
UINT (WINAPI *__MINGW_IMP_SYMBOL(SetErrorMode))(UINT uMode) __asm__("__imp_SetErrorMode") = SetErrorMode;
#endif
