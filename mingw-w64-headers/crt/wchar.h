/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#include <corecrt.h>
#include <corecrt_wconio.h>
#include <corecrt_wctype.h>
#include <corecrt_wio.h>
#include <corecrt_wprocess.h>
#include <corecrt_wstdio.h>
#include <corecrt_wstdlib.h>
#include <corecrt_wstring.h>
#include <corecrt_wtime.h>
#include <_mingw_locale.h>

#if __USE_MINGW_ANSI_STDIO && !defined (__USE_MINGW_STRTOX) && !defined(_CRTBLD)
#define __USE_MINGW_STRTOX 1
#endif

_CRT_BEGIN_C_HEADER

#ifndef WCHAR_MIN  /* also in stdint.h */
#define WCHAR_MIN 0U
#define WCHAR_MAX 0xffffU
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_wgetcwd")
#undef _wgetcwd
#pragma push_macro("_wgetdcwd")
#undef _wgetdcwd
#pragma push_macro("_wgetdcwd_nolock")
#undef _wgetdcwd_nolock
#endif
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,int _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(int _Drive,wchar_t *_DstBuf,int _SizeInWords);
#if __MSVCRT_VERSION__ >= 0x800
  wchar_t *__cdecl _wgetdcwd_nolock(int _Drive,wchar_t *_DstBuf,int _SizeInWords);
#endif
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_wgetcwd")
#pragma pop_macro("_wgetdcwd")
#pragma pop_macro("_wgetdcwd_nolock")
#endif
  _CRTIMP int __cdecl _wchdir(const wchar_t *_Path);
  _CRTIMP int __cdecl _wmkdir(const wchar_t *_Path);
  _CRTIMP int __cdecl _wrmdir(const wchar_t *_Path);
#endif

#if !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  typedef unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  typedef unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  typedef unsigned int _dev_t;
#ifndef	NO_OLDNAMES
  typedef unsigned int dev_t;
#endif
#endif

#include <_mingw_off_t.h>
#include <_mingw_stat64.h>

#ifndef _WSTAT_DEFINED
#define _WSTAT_DEFINED

  _CRTIMP int __cdecl _wstat32(const wchar_t *_Name,struct _stat32 *_Stat);
  _CRTIMP int __cdecl _wstat32i64(const wchar_t *_Name,struct _stat32i64 *_Stat);
  _CRTIMP int __cdecl _wstat64i32(const wchar_t *_Name,struct _stat64i32 *_Stat);
  _CRTIMP int __cdecl _wstat64(const wchar_t *_Name,struct _stat64 *_Stat);
#endif
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(int _Value,wchar_t *_Dest,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _ltow(long _Value,wchar_t *_Dest,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long _Value,wchar_t *_Dest,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP double __cdecl _wcstod_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,_locale_t _Locale);

  double __cdecl __mingw_wcstod(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr);
  float __cdecl __mingw_wcstof(const wchar_t * __restrict__ nptr, wchar_t ** __restrict__ endptr);
  long double __cdecl __mingw_wcstold(const wchar_t * __restrict__, wchar_t ** __restrict__);

#if defined(__USE_MINGW_STRTOX) && !defined(_UCRT)
  __mingw_ovr
  double __cdecl wcstod(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr){
    return __mingw_wcstod(_Str,_EndPtr);
  }
  __mingw_ovr
  float __cdecl wcstof(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr){
    return __mingw_wcstof(_Str,_EndPtr);
  }
  /* wcstold is already a mingw implementation */
#else
  double __cdecl wcstod(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr);
  float __cdecl wcstof(const wchar_t * __restrict__ nptr, wchar_t ** __restrict__ endptr);
#endif /* !defined(__USE_MINGW_STRTOX) || defined(_UCRT) */
#if !defined __NO_ISOCEXT /* in libmingwex.a */
  long double __cdecl wcstold (const wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix);
  _CRTIMP long __cdecl _wcstol_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(const wchar_t *_VarName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP int __cdecl _wsystem(const wchar_t *_Command);
#endif
  _CRTIMP double __cdecl _wtof(const wchar_t *_Str);
  _CRTIMP double __cdecl _wtof_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP int __cdecl _wtoi(const wchar_t *_Str);
  _CRTIMP int __cdecl _wtoi_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(const wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(const wchar_t *_Str,_locale_t _Locale);

  __MINGW_EXTENSION _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,int _Radix);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wtoi64(const wchar_t *_Str);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wtoi64_l(const wchar_t *_Str,_locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wcstoi64(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wcstoi64_l(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix,_locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix,_locale_t _Locale);
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_wfullpath")
#undef _wfullpath
#endif
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,const wchar_t *_Path,size_t _SizeInWords);
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_wfullpath")
#endif
  _CRTIMP void __cdecl _wmakepath(wchar_t *_ResultPath,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP int __cdecl _wputenv(const wchar_t *_EnvString);
  _CRTIMP void __cdecl _wsearchenv(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP void __cdecl _wsplitpath(const wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif
#endif

#if defined(_UCRT) || defined(__LARGE_MBSTATE_T)
  typedef struct _Mbstatet {
    unsigned long _Wchar;
    unsigned short _Byte, _State;
  } _Mbstatet;
  typedef _Mbstatet mbstate_t;
#else
  typedef int mbstate_t;
#endif
  typedef wchar_t _Wint_t;

  _CRTIMP wint_t __cdecl btowc(int);
  int __cdecl mbsinit(const mbstate_t *ps);
  _CRTIMP size_t __cdecl mbrlen(const char * __restrict__ _Ch,size_t _SizeInBytes,mbstate_t * __restrict__ _State);
  _CRTIMP size_t __cdecl mbrtowc(wchar_t * __restrict__ _DstCh,const char * __restrict__ _SrcCh,size_t _SizeInBytes,mbstate_t * __restrict__ _State);
  _CRTIMP size_t __cdecl mbsrtowcs(wchar_t * __restrict__ _Dest,const char ** __restrict__ _PSrc,size_t _Count,mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP size_t __cdecl wcrtomb(char * __restrict__ _Dest,wchar_t _Source,mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP size_t __cdecl wcsrtombs(char * __restrict__ _Dest,const wchar_t ** __restrict__ _PSource,size_t _Count,mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *s, wchar_t c, size_t n);
  int __cdecl wmemcmp(const wchar_t *s1, const wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t * __restrict__ s1,const wchar_t * __restrict__ s2,size_t n) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  wchar_t * __cdecl wmempcpy (wchar_t *_Dst, const wchar_t *_Src, size_t _Size);
  wchar_t *__cdecl wmemmove(wchar_t *s1, const wchar_t *s2, size_t n) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl fwide(FILE *stream,int mode);
  __MINGW_EXTENSION long long __cdecl wcstoll(const wchar_t * __restrict__ nptr,wchar_t ** __restrict__ endptr, int base);
  __MINGW_EXTENSION unsigned long long __cdecl wcstoull(const wchar_t * __restrict__ nptr,wchar_t ** __restrict__ endptr, int base);

#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
  extern "C++" inline wchar_t* wmemchr(wchar_t* __p, wchar_t __c, size_t __n)
  { return const_cast<wchar_t*>(wmemchr(const_cast<const wchar_t*>(__p), __c, __n)); }
#endif
#endif /* __NO_ISOCEXT */

  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _MaxCount);
  void *__cdecl memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef __CRT__NO_INLINE
  __CRT_INLINE int __cdecl fwide(FILE *_F,int _M) { (void)_F; return (_M); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *_S,wchar_t _C,size_t _N) {
    if (_S) {
      for ( ; 0 < _N; ++_S, --_N)
	if (*_S == _C)
	  return (_CONST_RETURN wchar_t *)(_S);
    }
    return (_CONST_RETURN wchar_t *) NULL;
  }
  __CRT_INLINE int __cdecl wmemcmp(const wchar_t *_S1,const wchar_t *_S2,size_t _N) {
    if (_N == 0 || _S1 == _S2)
      return 0;	/* even for NULL pointers.  */
    if ((_S1 && !(_S2)) || (_S2 && !(_S1)))
      return !(_S2) ? 1 : -1; /* robust.  */
    for ( ; 0 < _N; ++_S1, ++_S2, --_N)
      if (*_S1 != *_S2)
	return (*_S1 < *_S2 ? -1 : +1);
    return 0;
  }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t * __restrict__ _S1,const wchar_t * __restrict__ _S2,size_t _N)
  {
    return (wchar_t *) memcpy (_S1,_S2,_N*sizeof(wchar_t));
  }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,const wchar_t *_S2,size_t _N) { return (wchar_t *)memmove(_S1,_S2,_N*sizeof(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    for (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    return (_S);
  }
#endif /* !__CRT__NO_INLINE */

_CRT_END_C_HEADER

#include <sec_api/wchar_s.h>

#endif /* _INC_WCHAR */
