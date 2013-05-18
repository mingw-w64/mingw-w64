/*
    Copyright (c) 2013 mingw-w64 project

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

#define _WIN32_WINNT 0x0602 /* CoCreateInstanceFromApp is 8+ */

#define CoCreateInstance __CoCreateInstance
#include <windef.h>
#include <windows.h>
#include <combaseapi.h>
#undef CoCreateInstance

HRESULT WINAPI CoCreateInstance(REFCLSID rclsid,
                                LPUNKNOWN pUnkOuter,
                                DWORD dwClsContext,
                                REFIID riid,
                                LPVOID *ppv);

HRESULT WINAPI CoCreateInstance(REFCLSID rclsid,
                                LPUNKNOWN pUnkOuter,
                                DWORD dwClsContext,
                                REFIID riid,
                                LPVOID *ppv)
{
    MULTI_QI result;
    HRESULT res;

    result.pIID = riid;
    result.pItf = NULL;
    result.hr = 0;

    res = CoCreateInstanceFromApp(rclsid, pUnkOuter, dwClsContext, NULL, 1, &result);

    if( ppv == NULL)
        return E_POINTER;
    else {
        *ppv = result.pItf;
        return res;
    }
}

HRESULT (WINAPI *__MINGW_IMP_SYMBOL(CoCreateInstance))(REFCLSID rclsid,  LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID *ppv) asm("__imp__CoCreateInstance@20") = CoCreateInstance;

