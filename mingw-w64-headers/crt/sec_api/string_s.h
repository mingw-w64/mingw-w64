/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#include <string.h>

_CRT_BEGIN_C_HEADER

  _CRTIMP errno_t __cdecl _strset_s(char *_Dst,size_t _DstSize,int _Value);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strset_s, char, _Dst, int, _Value)
  _CRTIMP errno_t __cdecl _strerror_s(char *_Buf,size_t _SizeInBytes,const char *_ErrMsg);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strerror_s, char, _Buf, const char *, _ErrMsg)
  _SECIMP errno_t __cdecl strerror_s(char *_Buf,size_t _SizeInBytes,int _ErrNum);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strerror_s, char, _Buf, int, _ErrNum)
  _CRTIMP errno_t __cdecl _strlwr_s(char *_Str,size_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strlwr_s, char, _Str)
  _CRTIMP errno_t __cdecl _strlwr_s_l(char *_Str,size_t _Size,_locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strlwr_s_l, char, _Str, _locale_t, _Locale)
  _CRTIMP errno_t __cdecl _strnset_s(char *_Str,size_t _Size,int _Val,size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, _strnset_s, char, _Str, int, _Val, size_t, _MaxCount)
  _CRTIMP errno_t __cdecl _strupr_s(char *_Str,size_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strupr_s, char, _Str)
  _CRTIMP errno_t __cdecl _strupr_s_l(char *_Str,size_t _Size,_locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strupr_s_l, char, _Str, _locale_t, _Locale)

  _CRTIMP errno_t __cdecl strncat_s(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, strncat_s, char, _Dst, const char *, _Src, size_t, _MaxCount)
  _CRTIMP errno_t __cdecl _strncat_s_l(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount,_locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(errno_t, _strncat_s_l, char, _Dst, const char *, _Src, size_t, _MaxCount, _locale_t, _Locale)
  _CRTIMP errno_t __cdecl strcpy_s(char *_Dst, rsize_t _SizeInBytes, const char *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strcpy_s, char, _Dest, const char *, _Source)
  _CRTIMP errno_t __cdecl strncpy_s(char *_Dst, size_t _DstSizeInChars, const char *_Src, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, strncpy_s, char, _Dest, const char *, _Source, size_t, _MaxCount)
  _CRTIMP errno_t __cdecl _strncpy_s_l(char *_Dst, size_t _DstSizeInChars, const char *_Src, size_t _MaxCount, _locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(errno_t, _strncpy_s_l, char, _Dest, const char *, _Source, size_t, _MaxCount, _locale_t, _Locale)
  _CRTIMP char *__cdecl strtok_s(char *_Str,const char *_Delim,char **_Context);
  _CRTIMP char *__cdecl _strtok_s_l(char *_Str,const char *_Delim,char **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl strcat_s(char *_Dst, rsize_t _SizeInBytes, const char * _Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strcat_s, char, _Dest, const char *, _Source)

  __forceinline size_t __cdecl strnlen_s(const char * _src, size_t _count) {
    return _src ? strnlen(_src, _count) : 0;
  }

  _SECIMP errno_t __cdecl memmove_s(void *_dest,size_t _numberOfElements,const void *_src,size_t _count);

_CRT_END_C_HEADER

#endif
