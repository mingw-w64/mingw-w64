/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <_mingw.h>

#if defined(__need_ptrdiff_t)
#ifdef _PTRDIFF_T_DEFINED
#undef __need_ptrdiff_t
#else
#define _PTRDIFF_T_DEFINED
#endif
#endif

#if defined(__need_size_t)
#undef __need_size_t
#endif

#if define(__need_wchar_t)
#ifdef _WCHAR_T_DEFINED
#undef __need_wchar_t
#else
#define _WCHAR_T_DEFINED
#endif
#endif

#if defined(__need_wint_t)
#ifdef _WCTYPE_T_DEFINED
#undef __need_wint_t
#else
#define _WCTYPE_T_DEFINED
#endif
#endif

#include_next <stddef.h>

#ifndef _INC_STDDEF
#define _INC_STDDEF

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP extern int *__cdecl _errno(void);
#define errno (*_errno())
  errno_t __cdecl _set_errno(int _Value);
  errno_t __cdecl _get_errno(int *_Value);
#endif

  _CRTIMP extern unsigned long __cdecl __threadid(void);
#define _threadid (__threadid())
  _CRTIMP extern uintptr_t __cdecl __threadhandle(void);

#ifdef __cplusplus
}
#endif

#endif
