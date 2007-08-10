/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_UTIME_INL
#define _INC_UTIME_INL
#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[(expr) ]
#endif

#ifdef _USE_32BIT_TIME_T
__CRT_INLINE int __cdecl _utime(const char *_Filename,struct _utimbuf *_Utimbuf) {
  _STATIC_ASSERT(sizeof(struct _utimbuf)==sizeof(struct __utimbuf32));
  return _utime32(_Filename,(struct __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE int __cdecl _futime(int _Desc,struct _utimbuf *_Utimbuf) {
  _STATIC_ASSERT(sizeof(struct _utimbuf)==sizeof(struct __utimbuf32));
  return _futime32(_Desc,(struct __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE int __cdecl _wutime(const wchar_t *_Filename,struct _utimbuf *_Utimbuf) {
  _STATIC_ASSERT(sizeof(struct _utimbuf)==sizeof(struct __utimbuf32));
  return _wutime32(_Filename,(struct __utimbuf32 *)_Utimbuf);
}
#else
__CRT_INLINE int __cdecl _utime(const char *_Filename,struct _utimbuf *_Utimbuf) {
  _STATIC_ASSERT(sizeof(struct _utimbuf)==sizeof(struct __utimbuf64));
  return _utime64(_Filename,(struct __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE int __cdecl _futime(int _Desc,struct _utimbuf *_Utimbuf) {
  _STATIC_ASSERT(sizeof(struct _utimbuf)==sizeof(struct __utimbuf64));
  return _futime64(_Desc,(struct __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE int __cdecl _wutime(const wchar_t *_Filename,struct _utimbuf *_Utimbuf) {
  _STATIC_ASSERT(sizeof(struct _utimbuf)==sizeof(struct __utimbuf64));
  return _wutime64(_Filename,(struct __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE int __cdecl utime(const char *_Filename,struct utimbuf *_Utimbuf) {
  _STATIC_ASSERT(sizeof(struct utimbuf)==sizeof(struct __utimbuf32));
  return _utime32(_Filename,(struct __utimbuf32 *)_Utimbuf);
}
#else
__CRT_INLINE int __cdecl utime(const char *_Filename,struct utimbuf *_Utimbuf) {
  _STATIC_ASSERT(sizeof(struct utimbuf)==sizeof(struct __utimbuf64));
  return _utime64(_Filename,(struct __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif
