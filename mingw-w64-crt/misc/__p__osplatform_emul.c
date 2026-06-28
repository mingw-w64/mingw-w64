/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>

static unsigned int get_osplatform_helper(void)
{
    OSVERSIONINFOA osvi;
#ifdef __i386__
    HMODULE kernel32;
    WINBOOL (WINAPI *kernel32_GetVersionExA)(LPOSVERSIONINFOA);
    DWORD raw_ver;
    WORD maj_ver;
    BOOL is_nt;
#endif

    osvi.dwOSVersionInfoSize = sizeof(osvi);

#ifdef __i386__
    /* GetVersionExA is not available on older WinNT and Win32s versions. When
     * it is available, it returns a full 32-bit platform ID (2^32 possible values).
     * GetVersion uses its highest bit to identify whether the system is WinNT
     * and its low 8 bits to return the major OS system version (Win9x starts
     * at 4). So load GetVersionExA dynamically, and on failure fall back to
     * GetVersion.
     */
    kernel32 = GetModuleHandleA("kernel32.dll");
    kernel32_GetVersionExA = kernel32 ? GetProcAddress(kernel32, "GetVersionExA") : NULL;
    if (kernel32_GetVersionExA && kernel32_GetVersionExA(&osvi))
        return osvi.dwPlatformId;

    raw_ver = GetVersion();
    maj_ver = raw_ver & 0xff;
    is_nt = !(raw_ver >> 31);
    if (is_nt)
        return VER_PLATFORM_WIN32_NT;
    else if (maj_ver >= 4)
        return VER_PLATFORM_WIN32_WINDOWS;
    else
        return VER_PLATFORM_WIN32s;
#else
    /* On non-i386 platforms, GetVersionExA is always available.
     * In case of failure, return value 2 (WinNT) which is a sane default.
     * Value 0 (Win32s) is not a sane default as Win32s is i386-only.
     */
    if (GetVersionExA(&osvi))
        return osvi.dwPlatformId;
    else
        return VER_PLATFORM_WIN32_NT;
#endif
}

#ifndef GET_OSPLATFORM_HELPER_ONLY

#undef _osplatform
static unsigned int _osplatform;

unsigned int* __cdecl __p__osplatform(void);
unsigned int* __cdecl __p__osplatform(void)
{
    static long init = 0;
    if (!init)
    {
        (void)InterlockedExchange((long*)&_osplatform, get_osplatform_helper());
        (void)InterlockedExchange(&init, 1);
    }
    return &_osplatform;
}
unsigned int* (__cdecl *__MINGW_IMP_SYMBOL(__p__osplatform))(void) = __p__osplatform;

#endif
