/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WSTAT_INL
#define _INC_WSTAT_INL
#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[(expr) ]
#endif

#ifdef _USE_32BIT_TIME_T
__CRT_INLINE int __cdecl _wstat(const wchar_t *_Filename,struct _stat *_Stat) {
  _STATIC_ASSERT(sizeof(struct _stat)==sizeof(struct _stat32));
  return _wstat32(_Filename,(struct _stat32 *)_Stat);
}
#else
__CRT_INLINE int __cdecl _wstat(const wchar_t *_Filename,struct _stat *_Stat) {
  _STATIC_ASSERT(sizeof(struct _stat)==sizeof(struct _stat64i32));
  return _wstat64i32(_Filename,(struct _stat64i32 *)_Stat);
}
#endif

#if _INTEGRAL_MAX_BITS >= 64
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE int __cdecl _wstati64(const wchar_t *_Filename,struct _stati64 *_Stat) {
  _STATIC_ASSERT(sizeof(struct _stati64)==sizeof(struct _stat32i64));
  return _wstat32i64(_Filename,(struct _stat32i64*)_Stat);
}
#else
__CRT_INLINE int __cdecl _wstati64(const wchar_t *_Filename,struct _stati64 *_Stat) {
  _STATIC_ASSERT(sizeof(struct _stati64)==sizeof(struct _stat64));
  return _wstat64(_Filename,(struct _stat64*)_Stat);
}
#endif
#endif
#endif
