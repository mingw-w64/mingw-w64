/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WSTDLIB
#define _INC_CORECRT_WSTDLIB

#include <corecrt.h>

#if __USE_MINGW_ANSI_STDIO && !defined (__USE_MINGW_STRTOX) && !defined(_CRTBLD)
#define __USE_MINGW_STRTOX 1
#endif

_CRT_BEGIN_C_HEADER

  _CRTIMP wchar_t *__cdecl _itow(int _Value,wchar_t *_Dest,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _ltow(long _Value,wchar_t *_Dest,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long _Value,wchar_t *_Dest,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

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
  long double __cdecl wcstold(const wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP double __cdecl _wcstod_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,_locale_t _Locale);
  _CRTIMP float __cdecl _wcstof_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,_locale_t _Locale);
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
  __MINGW_EXTENSION _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wtoi64(const wchar_t *_Str);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wtoi64_l(const wchar_t *_Str,_locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wcstoi64(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wcstoi64_l(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix,_locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix,_locale_t _Locale);

  _CRTIMP int __cdecl _wputenv(const wchar_t *_EnvString);

#ifndef _POSIX_
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
  _CRTIMP void __cdecl _wsearchenv(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP void __cdecl _wsplitpath(const wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif

#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_wdupenv_s")
#undef _wdupenv_s
#endif
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *_BufferSizeInWords,const wchar_t *_VarName);
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_wdupenv_s")
#endif

  _CRTIMP errno_t __cdecl _itow_s (int _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t,_itow_s,int,_Val,wchar_t,_DstBuf,int,_Radix)

  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t,_ltow_s,long,_Val,wchar_t,_DstBuf,int,_Radix)

  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t,_ultow_s,unsigned long,_Val,wchar_t,_DstBuf,int,_Radix)

  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t _DstSizeInWords,const wchar_t *_VarName);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t,_wgetenv_s,size_t*,_ReturnSize,wchar_t,_DstBuf,const wchar_t*,_VarName)

  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);

  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t _SizeInWords,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(errno_t,_wmakepath_s,wchar_t,_PathResult,const wchar_t*,_Drive,const wchar_t*,_Dir,const wchar_t*,_Filename,const wchar_t*,_Ext)

  _CRTIMP errno_t __cdecl _wputenv_s(const wchar_t *_Name,const wchar_t *_Value);

  _CRTIMP errno_t __cdecl _wsearchenv_s(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath,size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0(errno_t,_wsearchenv_s,const wchar_t*,_Filename,const wchar_t*,_EnvVar,wchar_t,_ResultPath)

  _CRTIMP errno_t __cdecl _wsplitpath_s(const wchar_t *_FullPath,wchar_t *_Drive,size_t _DriveSizeInWords,wchar_t *_Dir,size_t _DirSizeInWords,wchar_t *_Filename,size_t _FilenameSizeInWords,wchar_t *_Ext,size_t _ExtSizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(errno_t,_wsplitpath_s,wchar_t,_Dest)

_CRT_END_C_HEADER

#endif /* _INC_CORECRT_WSTDLIB */

