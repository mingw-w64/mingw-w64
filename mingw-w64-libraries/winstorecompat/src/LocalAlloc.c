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

#define LocalAlloc __LocalAlloc
#include <windef.h>
#include <winbase.h>
#undef LocalAlloc


HLOCAL WINAPI LocalAlloc(UINT uFlags, SIZE_T uBytes)
{
    if( uFlags & LMEM_MOVEABLE )
    {
        SetLastError(ERROR_ACCESS_DENIED);
        return NULL;
    }
    return HeapAlloc(GetProcessHeap(), (uFlags & LMEM_ZEROINIT) ? HEAP_ZERO_MEMORY : 0, uBytes);
}

#ifdef _X86_
HLOCAL (WINAPI *__MINGW_IMP_SYMBOL(LocalAlloc))(UINT uFlags, SIZE_T uByte) __asm__("__imp__LocalAlloc@8") = LocalAlloc;
#else
HLOCAL (WINAPI *__MINGW_IMP_SYMBOL(LocalAlloc))(UINT uFlags, SIZE_T uByte) __asm__("__imp_LocalAlloc") = LocalAlloc;
#endif
