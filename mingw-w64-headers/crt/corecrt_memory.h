/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_MEMORY
#define _INC_CORECRT_MEMORY

#include <crtdefs.h>

_CRT_BEGIN_C_HEADER

  _CRTIMP void *__cdecl _memccpy(void *_Dst,const void *_Src,int _Val,size_t _MaxCount);
#if !defined(__STRICT_ANSI__) || defined(_GNU_SOURCE) || __STDC_VERSION__ + 0 >= 202311L || _XOPEN_SOURCE + 0 >= 600
  void * __cdecl memccpy(void *_Dst,const void *_Src,int _Val,size_t _Size);
#endif
  _CRTIMP int __cdecl _memicmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  _CRTIMP int __cdecl _memicmp_l(const void *_Buf1,const void *_Buf2,size_t _Size,_locale_t _Locale);
  int __cdecl memcmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  void * __cdecl memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _SECIMP errno_t __cdecl memcpy_s (void *_dest,size_t _numberOfElements,const void *_src,size_t _count);
  void * __cdecl mempcpy (void *_Dst, const void *_Src, size_t _Size);
  void * __cdecl memset(void *_Dst,int _Val,size_t _Size);
#if !defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 202311L
  void * __cdecl memset_explicit(void *_Dst,int _Val,size_t _Size);
#endif

#ifndef	NO_OLDNAMES
  void * __cdecl memccpy(void *_Dst,const void *_Src,int _Val,size_t _Size) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl memicmp(const void *_Buf1,const void *_Buf2,size_t _Size) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif

_CRT_END_C_HEADER

#ifdef __cplusplus
extern "C++" {
  const void* __cdecl memchr(const void*, int, size_t) __MINGW_ASM_CALL(memchr);
  inline void* __cdecl memchr(void* _Buf, int _Val, size_t _MaxCount)
  { return const_cast<void*>(memchr(const_cast<const void*>(_Buf), _Val, _MaxCount)); }
}
#else
  void* __cdecl memchr(const void* _Buf, int _Val, size_t _MaxCount);
#endif

#endif
