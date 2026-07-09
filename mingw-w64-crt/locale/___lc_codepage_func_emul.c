/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdlib.h>
#include <string.h>
#include <locale.h>

unsigned int __cdecl ___lc_codepage_func(void)
{
    /* locale :: "lang[_country[.code_page]]" | ".code_page"  */
    const char *cp_str = strchr(setlocale(LC_CTYPE, NULL), '.');
    return cp_str ? atoi(cp_str + 1) : 0;
}
unsigned int (__cdecl *__MINGW_IMP_SYMBOL(___lc_codepage_func))(void) = ___lc_codepage_func;
