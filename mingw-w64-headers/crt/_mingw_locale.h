/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_MINGW_LOCALE
#define _INC_MINGW_LOCALE

#include <corecrt.h>

/**
 * This header file contains declarations which belong to both locale.h and
 * wchar.h; it allows to avoid duplicating declarations in multiple headers.
 *
 * This header file is similar to corecrt_*.h header files used by MSVC,
 * but since there is no corecrt_wlocale.h, we name it _mingw_locale.h instead.
 */

#ifdef __cplusplus
extern "C" {
#endif

_CRTIMP wchar_t *__cdecl _wsetlocale(int _Category,const wchar_t *_Locale);

#if __MSVCRT_VERSION__ >= 0xB00
_CRTIMP _locale_t __cdecl _wcreate_locale(int _Category, const wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _INC_MINGW_LOCALE */
