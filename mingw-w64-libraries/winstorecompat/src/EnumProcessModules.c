/*
    Copyright (c) 2018 mingw-w64 project

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

#define EnumProcessModules __EnumProcessModules
#define PSAPI_VERSION 1
#include <windows.h>
#include <psapi.h>
#include <winternl.h>
#include <stddef.h>
#undef EnumProcessModules

WINBOOL WINAPI EnumProcessModules(HANDLE hProcess, HMODULE *lphModule, DWORD cb, LPDWORD lpcbNeeded)
{
    if (hProcess != GetCurrentProcess()) {
        SetLastError(ERROR_ACCESS_DENIED);
        return FALSE;
    }

    // According to documentation, the layout of these structs could change in
    // new windows versions.
    PTEB teb = NtCurrentTeb();
    PPEB peb = teb->ProcessEnvironmentBlock;
    PPEB_LDR_DATA ldr = peb->Ldr;
    PLIST_ENTRY listHead = &ldr->InMemoryOrderModuleList;
    PLIST_ENTRY entry = listHead->Flink;
    int n = 0;
    while (entry != listHead) {
        PLDR_DATA_TABLE_ENTRY dataEntry =
            (PLDR_DATA_TABLE_ENTRY)((BYTE*)entry -
                                    offsetof(LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks));
        if (cb >= sizeof(HMODULE)) {
            lphModule[n] = dataEntry->DllBase;
            cb -= sizeof(HMODULE);
        }
        n++;
        entry = entry->Flink;
    }
    *lpcbNeeded = sizeof(HMODULE) * n;
    return TRUE;
}

WINBOOL WINAPI K32EnumProcessModules(HANDLE hProcess, HMODULE *lphModule, DWORD cb, LPDWORD lpcbNeeded)
{
    return EnumProcessModules(hProcess, lphModule, cb, lpcbNeeded);
}

#ifdef _X86_
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(EnumProcessModules))(HANDLE hProcess, HMODULE *lphModule, DWORD cb, LPDWORD lpcbNeeded) __asm__("__imp__EnumProcessModules@16") = EnumProcessModules;
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(K32EnumProcessModules))(HANDLE hProcess, HMODULE *lphModule, DWORD cb, LPDWORD lpcbNeeded) __asm__("__imp__K32EnumProcessModules@16") = K32EnumProcessModules;
#else
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(EnumProcessModules))(HANDLE hProcess, HMODULE *lphModule, DWORD cb, LPDWORD lpcbNeeded) __asm__("__imp_EnumProcessModules") = EnumProcessModules;
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(K32EnumProcessModules))(HANDLE hProcess, HMODULE *lphModule, DWORD cb, LPDWORD lpcbNeeded) __asm__("__imp_K32EnumProcessModules") = K32EnumProcessModules;
#endif
