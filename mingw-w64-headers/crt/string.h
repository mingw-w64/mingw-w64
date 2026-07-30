/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#include <crtdefs.h>
#include <corecrt_memory.h>
#include <corecrt_wstring.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
/* Tell libstdc++ and libc++ we have provided the correct ISO C++ overloads */
#define __CORRECT_ISO_CPP_STRING_H_PROTO
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef NULL
#ifdef __cplusplus
#ifndef _WIN64
#define NULL 0
#else
#define NULL 0LL
#endif  /* W64 */
#else
#define NULL ((void *)0)
#endif
#endif

  char * __cdecl _strset(char *_Str,int _Val) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  char * __cdecl _strset_l(char *_Str,int _Val,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  char * __cdecl strcpy(char * __restrict__ _Dest,const char * __restrict__ _Source);
  char * __cdecl strcat(char * __restrict__ _Dest,const char * __restrict__ _Source);
  int __cdecl strcmp(const char *_Str1,const char *_Str2);
  size_t __cdecl strlen(const char *_Str);
  size_t __cdecl strnlen(const char *_Str,size_t _MaxCount);
  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_strdup")
#undef _strdup
#endif
  _CRTIMP char *__cdecl _strdup(const char *_Src);
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_strdup")
#endif
#if !defined(__STRICT_ANSI__) || defined(_GNU_SOURCE) || __STDC_VERSION__ + 0 >= 202311L || _POSIX_C_SOURCE + 0 >= 200809L || _XOPEN_SOURCE + 0 >= 600
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("strdup")
#undef strdup
#endif
  char *__cdecl strdup(const char *_Src);
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("strdup")
#endif
#endif
#if !defined(__STRICT_ANSI__) || defined(_GNU_SOURCE) || __STDC_VERSION__ + 0 >= 202311L || _POSIX_C_SOURCE + 0 >= 200809L || _XOPEN_SOURCE + 0 >= 700
  char *__cdecl strndup(const char *_Src,size_t _MaxCount);
#endif
  _CONST_RETURN char *__cdecl strchr(const char *_Str,int _Val);
  _CRTIMP int __cdecl _stricmp(const char *_Str1,const char *_Str2);
  _CRTIMP int __cdecl _strcmpi(const char *_Str1,const char *_Str2);
  _CRTIMP int __cdecl _stricmp_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl strcoll(const char *_Str1,const char *_Str2);
  _CRTIMP int __cdecl _strcoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _stricoll(const char *_Str1,const char *_Str2);
  _CRTIMP int __cdecl _stricoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _strncoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _strncoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP int __cdecl _strnicoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _strnicoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t __cdecl strcspn(const char *_Str,const char *_Control);
  _CRTIMP char *__cdecl _strerror(const char *_ErrMsg) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *__cdecl strerror(int) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *__cdecl _strlwr(char *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  char *strlwr_l(char *_String,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  char *__cdecl strncat(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl strncmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _strnicmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _strnicmp_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  char *strncpy(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *__cdecl _strnset(char *_Str,int _Val,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *__cdecl _strnset_l(char *str,int c,size_t count,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CONST_RETURN char *__cdecl strpbrk(const char *_Str,const char *_Control);
  _CONST_RETURN char *__cdecl strrchr(const char *_Str,int _Ch);
  _CRTIMP char *__cdecl _strrev(char *_Str);
  size_t __cdecl strspn(const char *_Str,const char *_Control);
  _CONST_RETURN char *__cdecl strstr(const char *_Str,const char *_SubStr);
  _CRTIMP char *__cdecl strtok(char * __restrict__ _Str,const char * __restrict__ _Delim) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#pragma push_macro("strtok_r")
#undef strtok_r
  char *strtok_r(char * __restrict__ _Str, const char * __restrict__ _Delim, char ** __restrict__ __last);
#pragma pop_macro("strtok_r")
  _CRTIMP char *__cdecl _strupr(char *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *_strupr_l(char *_String,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP size_t __cdecl strxfrm(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _strxfrm_l(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);

#ifndef	NO_OLDNAMES
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("strdup")
#undef strdup
#endif
  char *__cdecl strdup(const char *_Src) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("strdup")
#endif
  int __cdecl strcmpi(const char *_Str1,const char *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl stricmp(const char *_Str1,const char *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  char *__cdecl strlwr(char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl strnicmp(const char *_Str1,const char *_Str,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl strncasecmp (const char *, const char *, size_t);
  int __cdecl strcasecmp (const char *, const char *);
  char *__cdecl strnset(char *_Str,int _Val,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  char *__cdecl strrev(char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  char *__cdecl strset(char *_Str,int _Val) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  char *__cdecl strupr(char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif

#ifdef __cplusplus
}
#endif

#ifdef __CORRECT_ISO_CPP_STRING_H_PROTO
extern "C++" {
  inline char* strchr(char* __s, int __n)
  { return const_cast<char*>(strchr(const_cast<const char*>(__s), __n)); }

  inline char* strpbrk(char* __s1, const char* __s2)
  { return const_cast<char*>(strpbrk(const_cast<const char*>(__s1), __s2)); }

  inline char* strrchr(char* __s, int __n)
  { return const_cast<char*>(strrchr(const_cast<const char*>(__s), __n)); }

  inline char* strstr(char* __s1, const char* __s2)
  { return const_cast<char*>(strstr(const_cast<const char*>(__s1), __s2)); }
}
#endif

#include <sec_api/string_s.h>

#if __MINGW_FORTIFY_LEVEL > 0
#ifdef __cplusplus
extern "C" {
#endif

__mingw_bos_declare;

__mingw_bos_extern_ovr
void * memcpy(void * __restrict__ __dst, const void * __restrict__ __src, size_t __n)
{
  return __builtin___memcpy_chk(__dst, __src, __n, __mingw_bos(__dst, 0));
}

__mingw_bos_extern_ovr
void * memset(void * __dst, int __val, size_t __n)
{
  return __builtin___memset_chk(__dst, __val, __n, __mingw_bos(__dst, 0));
}

__mingw_bos_extern_ovr
void * memmove(void * __dst, const void * __src, size_t __n)
{
  return __builtin___memmove_chk(__dst, __src, __n, __mingw_bos(__dst, 0));
}

#ifdef _GNU_SOURCE
__mingw_bos_extern_ovr
void * mempcpy(void * __dst, const void * __src, size_t __n)
{
  return __builtin___mempcpy_chk(__dst, __src, __n, __mingw_bos(__dst, 0));
}
#endif /* _GNU_SOURCE */

__mingw_bos_extern_ovr
char * strcpy(char * __restrict__ __dst, const char * __restrict__ __src)
{
  return __builtin___strcpy_chk(__dst, __src, __mingw_bos(__dst, 1));
}

__mingw_bos_extern_ovr
char * strcat(char * __restrict__ __dst, const char * __restrict__ __src)
{
  return __builtin___strcat_chk(__dst, __src, __mingw_bos(__dst, 1));
}

__mingw_bos_extern_ovr
char * strncpy(char * __restrict__ __dst, const char * __restrict__ __src, size_t __n)
{
  return __builtin___strncpy_chk(__dst, __src, __n, __mingw_bos(__dst, 1));
}

__mingw_bos_extern_ovr
char * strncat(char * __restrict__ __dst, const char * __restrict__ __src, size_t __n)
{
  return __builtin___strncat_chk(__dst, __src, __n, __mingw_bos(__dst, 1));
}

_SECIMP errno_t __cdecl __mingw_call_memcpy_s(void *, size_t, const void *, size_t) __MINGW_ASM_CRT_CALL(memcpy_s);
wchar_t * __cdecl __mingw_call_wcscpy(wchar_t * __restrict__, const wchar_t * __restrict__) __MINGW_ASM_CALL(wcscpy);
wchar_t * __cdecl __mingw_call_wcscat(wchar_t * __restrict__, const wchar_t * __restrict__) __MINGW_ASM_CALL(wcscat);

__mingw_bos_extern_ovr
errno_t memcpy_s(void * __dst, size_t __os, const void * __src, size_t __n)
{
  __mingw_bos_ptr_chk_warn(__dst, __os, 0);
  return __mingw_call_memcpy_s(__dst, __os, __src, __n);
}

__mingw_bos_extern_ovr
wchar_t * wcscpy(wchar_t * __restrict__ __dst, const wchar_t * __restrict__ __src)
{
  if (__mingw_bos_known(__dst)) {
    __mingw_bos_cond_chk(!wcscpy_s(__dst, __mingw_bos(__dst, 1) / sizeof(wchar_t), __src));
    return __dst;
  }
  return __mingw_call_wcscpy(__dst, __src);
}

__mingw_bos_extern_ovr
wchar_t * wcscat(wchar_t * __restrict__ __dst, const wchar_t * __restrict__ __src)
{
  if (__mingw_bos_known(__dst)) {
    __mingw_bos_cond_chk(!wcscat_s(__dst, __mingw_bos(__dst, 1) / sizeof(wchar_t), __src));
    return __dst;
  }
  return __mingw_call_wcscat(__dst, __src);
}

#ifdef __cplusplus
}
#endif
#endif /* __MINGW_FORTIFY_LEVEL > 0 */

#endif
