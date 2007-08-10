/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STAT_INL
#define _INC_STAT_INL
#include <sys/stat.h>
#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[(expr)]
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE int __cdecl fstat(int _Desc,struct stat *_Stat) {
  _STATIC_ASSERT(sizeof(struct stat)==sizeof(struct _stat32));
  return _fstat32(_Desc,(struct _stat32 *)_Stat);
}
__CRT_INLINE int __cdecl stat(const char *_Filename,struct stat *_Stat) {
  _STATIC_ASSERT(sizeof(struct stat)==sizeof(struct _stat32));
  return _stat32(_Filename,(struct _stat32 *)_Stat);
}
#else
__CRT_INLINE int __cdecl fstat(int _Desc,struct stat *_Stat) {
  _STATIC_ASSERT(sizeof(struct stat)==sizeof(struct _stat64i32));
  return _fstat64i32(_Desc,(struct _stat64i32 *)_Stat);
}
__CRT_INLINE int __cdecl stat(const char *_Filename,struct stat *_Stat) {
  _STATIC_ASSERT(sizeof(struct stat)==sizeof(struct _stat64i32));
  return _stat64i32(_Filename,(struct _stat64i32 *)_Stat);
}
#endif
#endif
#endif
