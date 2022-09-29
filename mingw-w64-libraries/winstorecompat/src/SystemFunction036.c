/*
    Copyright (c) 2022 mingw-w64 project

    Contributing authors: Martin Storsjo

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

#define SystemFunction036 __SystemFunction036
#include <windows.h>
#include <ntsecapi.h>
#include <wincrypt.h>
#undef SystemFunction036

// This is the underlying function name for the RtlGenRandom function.
// Since 10.0.18362.0, this function is available to link against and allowed.
BOOLEAN WINAPI SystemFunction036(PVOID RandomBuffer, ULONG RandomBufferLength)
{
    // Emulate RtlGenRandom with CryptGenRandom; that function in itself
    // isn't allowed either, but is also wrapped by winstorecompat.
    HCRYPTPROV crypt;
    BOOLEAN ret = FALSE;

    if (CryptAcquireContextW(&crypt, NULL, NULL, PROV_RSA_FULL,
                             CRYPT_VERIFYCONTEXT | CRYPT_SILENT)) {
        ret = CryptGenRandom(crypt, RandomBufferLength, RandomBuffer);
        CryptReleaseContext(crypt, 0);
    }
    return ret;
}

#ifdef _X86_
BOOLEAN (WINAPI *__MINGW_IMP_SYMBOL(SystemFunction036))(PVOID RandomBuffer, ULONG RandomBufferLength) __asm__("__imp__SystemFunction036@8") = SystemFunction036;
#else
BOOLEAN (WINAPI *__MINGW_IMP_SYMBOL(SystemFunction036))(PVOID RandomBuffer, ULONG RandomBufferLength) __asm__("__imp_SystemFunction036") = SystemFunction036;
#endif
