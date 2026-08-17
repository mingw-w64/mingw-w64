/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WDIRECT
#define _INC_CORECRT_WDIRECT

#include <corecrt.h>

_CRT_BEGIN_C_HEADER

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

_CRT_END_C_HEADER

#endif /* _INC_CORECRT_WDIRECT */
