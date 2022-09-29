/*
    Copyright (c) 2016 mingw-w64 project

    Contributing authors: Steve Lhomme, Hugo Beauzée-Luyssen

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
#define _WIN32_WINNT 0x602
#endif

#define CryptAcquireContextW __CryptAcquireContextW
#define CryptAcquireContextA __CryptAcquireContextA
#define CryptReleaseContext __CryptReleaseContext
#define CryptGenRandom __CryptGenRandom
#define COBJMACROS
#define INITGUID
#include <windef.h>
#include <windows.h>
#include <windows.security.cryptography.h>
#include <windows.storage.streams.h>
#include <winstring.h>
#include <roapi.h>
#undef CertOpenSystemStore
#undef CryptGenRandom
#undef CryptReleaseContext
#undef CryptAcquireContextA
#undef CryptAcquireContextW

#define HCRYPTPROV __x_ABI_CWindows_CSecurity_CCryptography_CICryptographicBufferStatics*

BOOL WINAPI CryptAcquireContextW(HCRYPTPROV *phProv, LPCTSTR pszContainer, LPCTSTR pszProvider, DWORD dwProvType, DWORD dwFlags)
{
    static const WCHAR *className = L"Windows.Security.Cryptography.CryptographicBuffer";
    const UINT32 clen = wcslen(className);

    HSTRING hClassName = NULL;
    HSTRING_HEADER header;
    HRESULT hr = WindowsCreateStringReference(className, clen, &header, &hClassName);
    if (FAILED(hr)) {
        WindowsDeleteString(hClassName);
        return FALSE;
    }

    // Note; this fails if run early in the process init (e.g. while running
    // DLL constructors); it succeeds if called later on, when the runtime
    // has started up properly.
    __x_ABI_CWindows_CSecurity_CCryptography_CICryptographicBufferStatics *cryptoStatics = NULL;
    hr = RoGetActivationFactory(hClassName, &IID___x_ABI_CWindows_CSecurity_CCryptography_CICryptographicBufferStatics, (void**)&cryptoStatics);
    WindowsDeleteString(hClassName);

    if (FAILED(hr))
        return FALSE;

    *phProv = cryptoStatics;

    return TRUE;
}

BOOL WINAPI CryptAcquireContextA(HCRYPTPROV *phProv, LPCTSTR pszContainer, LPCTSTR pszProvider, DWORD dwProvType, DWORD dwFlags)
{
    // The implementation of CryptAcquireContextW above disregards
    // the pszContainer and pszProvider parameters anyway, so don't bother
    // to convert them, just pass NULL.
    return CryptAcquireContextW(phProv, NULL, NULL, dwProvType, dwFlags);
}

BOOL WINAPI CryptReleaseContext(HCRYPTPROV phProv, DWORD dwFlags)
{
    HRESULT hr = __x_ABI_CWindows_CSecurity_CCryptography_CICryptographicBufferStatics_Release(phProv);
    return SUCCEEDED(hr) && dwFlags==0;
}

BOOL WINAPI CryptGenRandom(HCRYPTPROV phProv, DWORD dwLen, BYTE *pbBuffer)
{
    __x_ABI_CWindows_CStorage_CStreams_CIBuffer *buffer = NULL;
    HRESULT hr = __x_ABI_CWindows_CSecurity_CCryptography_CICryptographicBufferStatics_GenerateRandom(phProv, dwLen, &buffer);
    if (FAILED(hr)) {
        return FALSE;
    }

    UINT32 olength;
    unsigned char *rnd = NULL;
    hr = __x_ABI_CWindows_CSecurity_CCryptography_CICryptographicBufferStatics_CopyToByteArray(phProv, buffer, &olength, (BYTE**)&rnd);
    if (FAILED(hr)) {
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer_Release(buffer);
        return FALSE;
    }
    memcpy(pbBuffer, rnd, dwLen);

    __x_ABI_CWindows_CStorage_CStreams_CIBuffer_Release(buffer);
    return TRUE;
}

#ifdef _X86_
BOOL (WINAPI *__MINGW_IMP_SYMBOL(CryptAcquireContextW))(HCRYPTPROV*, LPCTSTR, LPCTSTR, DWORD, DWORD) __asm__("__imp__CryptAcquireContextW@20") = CryptAcquireContextW;
BOOL (WINAPI *__MINGW_IMP_SYMBOL(CryptAcquireContextA))(HCRYPTPROV*, LPCTSTR, LPCTSTR, DWORD, DWORD) __asm__("__imp__CryptAcquireContextA@20") = CryptAcquireContextA;
BOOL (WINAPI *__MINGW_IMP_SYMBOL(CryptReleaseContext))(HCRYPTPROV, DWORD) __asm__("__imp__CryptReleaseContext@8") = CryptReleaseContext;
BOOL (WINAPI *__MINGW_IMP_SYMBOL(CryptGenRandom))(HCRYPTPROV, DWORD, BYTE*) __asm__("__imp__CryptGenRandom@12") = CryptGenRandom;
#else
BOOL (WINAPI *__MINGW_IMP_SYMBOL(CryptAcquireContextW))(HCRYPTPROV*, LPCTSTR, LPCTSTR, DWORD, DWORD) __asm__("__imp_CryptAcquireContextW") = CryptAcquireContextW;
BOOL (WINAPI *__MINGW_IMP_SYMBOL(CryptAcquireContextA))(HCRYPTPROV*, LPCTSTR, LPCTSTR, DWORD, DWORD) __asm__("__imp_CryptAcquireContextA") = CryptAcquireContextA;
BOOL (WINAPI *__MINGW_IMP_SYMBOL(CryptReleaseContext))(HCRYPTPROV, DWORD) __asm__("__imp_CryptReleaseContext") = CryptReleaseContext;
BOOL (WINAPI *__MINGW_IMP_SYMBOL(CryptGenRandom))(HCRYPTPROV, DWORD, BYTE*) __asm__("__imp_CryptGenRandom") = CryptGenRandom;
#endif
