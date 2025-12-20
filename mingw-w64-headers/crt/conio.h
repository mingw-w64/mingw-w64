/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#include <crtdefs.h>
#include <corecrt_stdio_config.h>
#include <corecrt_wconio.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

  _CRTIMP char *__cdecl _cgets(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _cputs(const char *_Str);
  _CRTIMP int __cdecl _getch(void);
  _CRTIMP int __cdecl _getche(void);
  _CRTIMP int __cdecl _kbhit(void);

#ifdef _UCRT
  int __cdecl __conio_common_vcprintf(unsigned __int64 _Options, const char *_Format, _locale_t _Locale, va_list _ArgList);
  int __cdecl __conio_common_vcprintf_p(unsigned __int64 _Options, const char *_Format, _locale_t _Locale, va_list _ArgList);
  int __cdecl __conio_common_vcprintf_s(unsigned __int64 _Options, const char *_Format, _locale_t _Locale, va_list _ArgList);
  int __cdecl __conio_common_vcscanf(unsigned __int64 _Options, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr int __cdecl _vcprintf(const char * __restrict__ _Format,va_list _ArgList)
  {
    return __conio_common_vcprintf(0, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _cprintf(const char * __restrict__ _Format,...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vcprintf(_Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _cscanf(const char * __restrict__ _Format,...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcscanf(0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _cscanf_l(const char * __restrict__ _Format,_locale_t _Locale,...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __conio_common_vcscanf(0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vcprintf_p(const char * __restrict__ _Format,va_list _ArgList)
  {
    return __conio_common_vcprintf_p(0, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _cprintf_p(const char * __restrict__ _Format,...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vcprintf_p(_Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _vcprintf_l(const char * __restrict__ _Format,_locale_t _Locale,va_list _ArgList)
  {
    return __conio_common_vcprintf(0, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _cprintf_l(const char * __restrict__ _Format,_locale_t _Locale,...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vcprintf_l(_Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _vcprintf_p_l(const char * __restrict__ _Format,_locale_t _Locale,va_list _ArgList)
  {
    return __conio_common_vcprintf_p(0, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _cprintf_p_l(const char * __restrict__ _Format,_locale_t _Locale,...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vcprintf_p_l(_Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
#else
  _CRTIMP int __cdecl _cprintf(const char * __restrict__ _Format,...);
  _CRTIMP int __cdecl _cscanf(const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _cscanf_l(const char * __restrict__ _Format,_locale_t _Locale,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP int __cdecl _vcprintf(const char * __restrict__ _Format,va_list _ArgList);
  _CRTIMP int __cdecl _cprintf_p(const char * __restrict__ _Format,...);
  _CRTIMP int __cdecl _vcprintf_p(const char * __restrict__ _Format,va_list _ArgList);
  _CRTIMP int __cdecl _cprintf_l(const char * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vcprintf_l(const char * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _cprintf_p_l(const char * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vcprintf_p_l(const char * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
#endif

#if defined(_X86_) && !defined(__x86_64)
  int __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  int __cdecl _outp(unsigned short,int);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP int __cdecl _putch(int _Ch);
  _CRTIMP int __cdecl _ungetch(int _Ch);
#if __MSVCRT_VERSION__ >= 0x800
  _CRTIMP int __cdecl _getch_nolock(void);
  _CRTIMP int __cdecl _getche_nolock(void);
  _CRTIMP int __cdecl _putch_nolock(int _Ch);
  _CRTIMP int __cdecl _ungetch_nolock(int _Ch);
#endif

#ifndef	NO_OLDNAMES
  char *__cdecl cgets(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

#ifdef _UCRT
  __mingw_ovr int __cdecl cprintf(const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_MSVC2005
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vcprintf(_Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl cscanf(const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_MSVC2005
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcscanf(0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
#else
  int __cdecl cprintf(const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl cscanf(const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif
  int __cdecl cputs(const char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl getch(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl getche(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl kbhit(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl putch(int _Ch) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl ungetch(int _Ch) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

#if (defined(_X86_) && !defined(__x86_64))
  int __cdecl inp(unsigned short) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  unsigned short __cdecl inpw(unsigned short) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl outp(unsigned short,int) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  unsigned short __cdecl outpw(unsigned short,unsigned short) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif

    /* __cpuid moved to intrin.h per msdn */
    /* __inbyte moved to intrin.h per msdn */
    /* __inbytestring moved to intrin.h per msdn */
    /* __indword moved to intrin.h per msdn */
    /* __indwordstring moved to intrin.h per msdn */
    /* __inword moved to intrin.h per msdn */
    /* __inwordstring moved to intrin.h per msdn */
    /* __outbyte moved to intrin.h per msdn */
    /* __outbytestring moved to intrin.h per msdn */
    /* __outdword moved to intrin.h per msdn */
    /* __outdwordstring moved to intrin.h per msdn */
    /* __outword moved to intrin.h per msdn */
    /* __outwordstring moved to intrin.h per msdn */
    /* __readcr0 moved to intrin.h per msdn */
    /* __readcr2 moved to intrin.h per msdn */
    /* __readcr3 moved to intrin.h per msdn */
    /* __readcr4 moved to intrin.h per msdn */
    /* __readcr8 moved to intrin.h per msdn */
    /* __readmsr moved to intrin.h per msdn */
    /* __writecr0 moved to intrin.h per msdn */
    /* __writecr2 moved to intrin.h per msdn */
    /* __writecr3 moved to intrin.h per msdn */
    /* __writecr4 moved to intrin.h per msdn */
    /* __writecr8 moved to intrin.h per msdn */
    /* __writemsr moved to intrin.h per msdn */
#endif

#ifdef __cplusplus
}
#endif

#include <sec_api/conio_s.h>

#endif
