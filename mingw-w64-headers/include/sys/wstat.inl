/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WSTAT_INL
#define _INC_WSTAT_INL

#ifdef _USE_32BIT_TIME_T
__CRT_INLINE int __cdecl _wstat(const wchar_t *_Filename,struct _stat *_Stat) {
  return _wstat32(_Filename,(struct _stat32 *)_Stat);
}
#else
__CRT_INLINE int __cdecl _wstat(const wchar_t *_Filename,struct _stat *_Stat) {
  return _wstat64i32(_Filename,(struct _stat64i32 *)_Stat);
}
#endif

#if _INTEGRAL_MAX_BITS >= 64
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE int __cdecl _wstati64(const wchar_t *_Filename,struct _stati64 *_Stat) {
  return _wstat32i64(_Filename,(struct _stat32i64*)_Stat);
}
#else
__CRT_INLINE int __cdecl _wstati64(const wchar_t *_Filename,struct _stati64 *_Stat) {
  return _wstat64(_Filename,(struct _stat64*)_Stat);
}
#endif
#endif
#endif
