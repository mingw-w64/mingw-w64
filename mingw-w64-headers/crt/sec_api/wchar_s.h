/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WCHAR_S
#define _INC_WCHAR_S

#include <wchar.h>

_CRT_BEGIN_C_HEADER

  _CRTIMP errno_t __cdecl mbsrtowcs_s(size_t *_Retval,wchar_t *_Dst,size_t _SizeInWords,const char **_PSrc,size_t _N,mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t,mbsrtowcs_s,size_t*,_Retval,wchar_t,_Dst,const char**,_PSrc,size_t,_N,mbstate_t,_State)

  _CRTIMP errno_t __cdecl wcrtomb_s(size_t *_Retval,char *_Dst,size_t _SizeInBytes,wchar_t _Ch,mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(errno_t,wcrtomb_s,size_t*,_Retval,char,_Dst,wchar_t,_Ch,mbstate_t,_State)

  _CRTIMP errno_t __cdecl wcsrtombs_s(size_t *_Retval,char *_Dst,size_t _SizeInBytes,const wchar_t **_Src,size_t _Size,mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t,wcsrtombs_s,size_t,_Retval,char,_Dst,const wchar_t**,_Src,size_t,_Size,mbstate_t,_State)

  _SECIMP errno_t __cdecl wmemcpy_s (wchar_t *_dest,size_t _numberOfElements,const wchar_t *_src,size_t _count);
  _SECIMP errno_t __cdecl wmemmove_s(wchar_t *_dest,size_t _numberOfElements,const wchar_t *_src,size_t _count);


_CRT_END_C_HEADER

#endif
