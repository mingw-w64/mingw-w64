/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CTYPE
#define _INC_CTYPE

#include <corecrt_wctype.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Standard C functions.
 */

_CRTIMP int __cdecl isalnum(int _C);
_CRTIMP int __cdecl isalpha(int _C);
_CRTIMP int __cdecl isblank(int _C);
_CRTIMP int __cdecl iscntrl(int _C);
_CRTIMP int __cdecl isdigit(int _C);
_CRTIMP int __cdecl isgraph(int _C);
_CRTIMP int __cdecl islower(int _C);
_CRTIMP int __cdecl isprint(int _C);
_CRTIMP int __cdecl ispunct(int _C);
_CRTIMP int __cdecl isspace(int _C);
_CRTIMP int __cdecl isupper(int _C);
_CRTIMP int __cdecl isxdigit(int _C);

_CRTIMP int __cdecl tolower(int _C);
_CRTIMP int __cdecl toupper(int _C);

/**
 * Locale-specific versions of Standard C functions.
 *
 * They are available since msvcr80.dll.
 */

/* These are also available in msvcrt.dll since Windows Vista. */
#if __MSVCRT_VERSION__ >= 0x0800 || (__MSVCRT_VERSION__ == 0x0600 && _WIN32_WINNT >= 0x0600)
_CRTIMP int __cdecl _isalnum_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _isalpha_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _isblank_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _iscntrl_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _isdigit_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _isgraph_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _islower_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _isprint_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _ispunct_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _isspace_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _isupper_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _isxdigit_l(int _C,_locale_t _Locale);

_CRTIMP int __cdecl _tolower_l(int _C,_locale_t _Locale);
_CRTIMP int __cdecl _toupper_l(int _C,_locale_t _Locale);
#endif

/**
 * POSIX functions.
 */

_CRTIMP int __cdecl __isascii(int _C);
_CRTIMP int __cdecl __toascii(int _C);
_CRTIMP int __cdecl _tolower(int _C);
_CRTIMP int __cdecl _toupper(int _C);

#if !defined(_CTYPE_DISABLE_MACROS) && !defined(__cplusplus)
#define __isascii(_Char) ((unsigned)(_Char) < 0x80)
#define __toascii(_Char) ((_Char) & 0x7f)
#define _tolower(_Char)  ((_Char)-'A'+'a')
#define _toupper(_Char)  ((_Char)-'a'+'A')
#endif /* !_CTYPE_DISABLE_MACROS && !__cplusplus */

#ifndef	NO_OLDNAMES
#if !defined(_CTYPE_DISABLE_MACROS) && !defined(__cplusplus)
#define isascii __isascii
#define toascii __toascii
#else
_CRTIMP int __cdecl isascii(int _C) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
_CRTIMP int __cdecl toascii(int _C) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif /* !_CTYPE_DISABLE_MACROS && !__cplusplus */
#endif /* !NO_OLDNAMES */

/**
 * Microsoft-specific functions.
 */

_CRTIMP int __cdecl _isctype(int _C,int _Type);

_CRTIMP int __cdecl __iscsym(int _C);
_CRTIMP int __cdecl __iscsymf(int _C);

#if !defined(_CTYPE_DISABLE_MACROS) && !defined(__cplusplus)
#define __iscsym(_c)   (isalnum(_c) || ((_c)=='_'))
#define __iscsymf(_c)  (isalpha(_c) || ((_c)=='_'))
#endif /* !_CTYPE_DISABLE_MACROS && !__cplusplus */

#ifndef	NO_OLDNAMES
#if !defined(_CTYPE_DISABLE_MACROS) && !defined(__cplusplus)
#define iscsym __iscsym
#define iscsymf __iscsymf
#else
_CRTIMP int __cdecl iscsym(int _C) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
_CRTIMP int __cdecl iscsymf(int _C) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif /* !_CTYPE_DISABLE_MACROS && !__cplusplus */
#endif /* !NO_OLDNAMES */

/**
 * Locale-specific versions of Microsoft functions.
 *
 * They are available since msvcr80.dll.
 */

/**
 * _iscsym_l and _iscsymf_l are only available as macros in Microsoft headers.
 *
 * We do not expose those macros under following conditions:
 *
 * - when _CTYPE_DISABLE_MACROS is defined; this is what Microsoft headers do
 * - for C++ compilations; this avoids possible clashes with class member names
 *
 * To make them available under above conditions, we provide them as externals.
 */
#if __MSVCRT_VERSION__ >= 0x0800
int __cdecl _iscsym_l(wint_t _C, _locale_t _Locale);
int __cdecl _iscsymf_l(wint_t _C, _locale_t _Locale);

#if !defined(_CTYPE_DISABLE_MACROS) && !defined(__cplusplus)
#define _iscsym_l(_c,_p)  (_isalnum_l(_c,_p) || ((_c)=='_'))
#define _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#endif /* !_CTYPE_DISABLE_MACROS && !__cplusplus */
#endif

/* These are also available in msvcrt.dll since Windows Vista. */
#if __MSVCRT_VERSION__ >= 0x0800 || (__MSVCRT_VERSION__ == 0x0600 && _WIN32_WINNT >= 0x0600)
_CRTIMP int __cdecl _isctype_l(int _C,int _Type,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
