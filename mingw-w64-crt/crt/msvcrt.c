#include <windows.h>

HMODULE __mingw_get_msvcrt_handle(void);
HMODULE __mingw_get_msvcrt_handle(void)
{
    static HANDLE msvcrt_handle;

    if(!msvcrt_handle)
        msvcrt_handle = LoadLibraryW(L"msvcrt.dll");

    return msvcrt_handle;
}
