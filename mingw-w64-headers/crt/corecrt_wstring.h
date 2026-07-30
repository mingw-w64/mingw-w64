/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WSTRING
#define _INC_CORECRT_WSTRING

#include <corecrt.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
/* Tell libstdc++ and libc++ we have provided the correct ISO C++ overloads */
#define __CORRECT_ISO_CPP_WCHAR_H_PROTO
#endif

#define _WSTRING_DEFINED /* Legacy guard */

#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_wcsdup")
#undef _wcsdup
#endif
  _CRTIMP wchar_t *__cdecl _wcsdup(const wchar_t *_Str);
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_wcsdup")
#endif
  wchar_t *__cdecl wcscat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CONST_RETURN wchar_t *__cdecl wcschr(const wchar_t *_Str,wchar_t _Ch);
  int __cdecl wcscmp(const wchar_t *_Str1,const wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  size_t __cdecl wcscspn(const wchar_t *_Str,const wchar_t *_Control);
  size_t __cdecl wcslen(const wchar_t *_Str);
  size_t __cdecl wcsnlen(const wchar_t *_Src,size_t _MaxCount);
  wchar_t *__cdecl wcsncat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl wcsncmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsncpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  wchar_t *__cdecl _wcsncpy_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CONST_RETURN wchar_t *__cdecl wcspbrk(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(const wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(const wchar_t *_Str,const wchar_t *_SubStr);
  _CRTIMP wchar_t *__cdecl wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim,wchar_t ** __restrict__ _Ptr) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#if defined(_CRT_NON_CONFORMING_WCSTOK) && !defined(__cplusplus)
  #define wcstok _wcstok
#endif
#if !defined(_CRT_NO_INLINE_DEPRECATED_WCSTOK) && defined(__cplusplus)
  extern "C++" inline wchar_t *__cdecl wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim) { return _wcstok(_Str, _Delim); }
#endif
  _CRTIMP wchar_t *__cdecl _wcserror(int _ErrNum) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl __wcserror(const wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP int __cdecl _wcsicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _wcsnicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP size_t __cdecl wcsxfrm(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP int __cdecl wcscoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP int __cdecl _wcscoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP int __cdecl _wcsicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _wcsncoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _wcsncoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP int __cdecl _wcsnicoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _wcsnicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#ifndef	NO_OLDNAMES
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("wcsdup")
#undef wcsdup
#endif
  wchar_t *__cdecl wcsdup(const wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("wcsdup")
#endif
#define wcswcs wcsstr
  int __cdecl wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcsrev(wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcslwr(wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcsupr(wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif

#ifdef __cplusplus
}
#endif

/**
 * ISO C++ requires both const and non-const versions of these functions.
 * The const versions have been declared above. The non-const versions are declared here.
 */
#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
extern "C++" {
  inline wchar_t* wcschr(wchar_t* __p, wchar_t __c)
  { return const_cast<wchar_t*>(wcschr(const_cast<const wchar_t*>(__p), __c)); }

  inline wchar_t* wcspbrk(wchar_t* __s1, const wchar_t* __s2)
  { return const_cast<wchar_t*>(wcspbrk(const_cast<const wchar_t*>(__s1), __s2)); }

  inline wchar_t* wcsrchr(wchar_t* __p, wchar_t __c)
  { return const_cast<wchar_t*>(wcsrchr(const_cast<const wchar_t*>(__p), __c)); }

  inline wchar_t* wcsstr(wchar_t* __s1, const wchar_t* __s2)
  { return const_cast<wchar_t*>(wcsstr(const_cast<const wchar_t*>(__s1), __s2)); }
}
#endif

#endif
