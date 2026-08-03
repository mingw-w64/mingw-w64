/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_WCONIO_S
#define _INC_WCONIO_S

#include <corecrt_wconio.h>

_CRT_BEGIN_C_HEADER

/**
 * Functions to read/write strings from/to console.
 */

_SECIMP errno_t __cdecl _cgetws_s (wchar_t *_Buffer,size_t _SizeInWords,size_t *_SizeRead);
__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _cgetws_s, wchar_t, _Buffer, size_t*, _SizeRead)

/**
 * Formatted console I/O functions.
 */

_SECIMP int __cdecl _cwprintf_s (const wchar_t *_Format,...);
_SECIMP int __cdecl _cwprintf_s_l (const wchar_t *_Format,_locale_t _Locale,...);
_SECIMP int __cdecl _vcwprintf_s (const wchar_t *_Format,va_list _ArgList);
_SECIMP int __cdecl _vcwprintf_s_l (const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
_CRTIMP int __cdecl _cwscanf_s(const wchar_t *_Format,...);
_CRTIMP int __cdecl _cwscanf_s_l(const wchar_t *_Format,_locale_t _Locale,...);

_CRT_END_C_HEADER

#endif /* _INC_WCONIO_S */
