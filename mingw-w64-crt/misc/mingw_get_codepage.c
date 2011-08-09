#include <windows.h>
#include <locale.h>

#include "mb_wc_common.h"

static unsigned int *msvcrt__lc_codepage;
static unsigned int __cdecl msvcrt__lc_codepage_func(void)
{
    return *msvcrt__lc_codepage;
}

static unsigned int __cdecl setlocale_codepage_hack(void)
{
    /* locale :: "lang[_country[.code_page]]" | ".code_page"  */
    const char *cp_str = strchr (setlocale(LC_CTYPE, NULL), '.');
    return cp_str ? atoi(cp_str + 1) : 0;
}

HANDLE __mingw_get_msvcrt_handle(void);

static unsigned int __cdecl init_codepage_func(void)
{
    HMODULE msvcrt = __mingw_get_msvcrt_handle();

    if(msvcrt) {
        __mingw_get_codepage = (void*)GetProcAddress(msvcrt, "___lc_codepage_func");
        if(__mingw_get_codepage)
            return __mingw_get_codepage();

        msvcrt__lc_codepage = (unsigned int*)GetProcAddress(msvcrt, "__lc_codepage");
        if(msvcrt__lc_codepage)
            return (__mingw_get_codepage = msvcrt__lc_codepage_func)();
    }

    return (__mingw_get_codepage = setlocale_codepage_hack)();
}

unsigned int (__cdecl *__mingw_get_codepage)(void) = init_codepage_func;
