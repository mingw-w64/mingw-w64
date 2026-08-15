/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SYS_UTIME
#define _INC_SYS_UTIME

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#include <crtdefs.h>

_CRT_BEGIN_C_HEADER

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  struct _utimbuf {
    time_t actime;
    time_t modtime;
  };

  struct __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

  struct __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };

#ifndef	NO_OLDNAMES
  struct utimbuf {
    time_t actime;
    time_t modtime;
  };

  struct utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP int __cdecl _utime32(const char *_Filename,struct __utimbuf32 *_Time);
  _CRTIMP int __cdecl _futime32(int _FileDes,struct __utimbuf32 *_Time);
  _CRTIMP int __cdecl _wutime32(const wchar_t *_Filename,struct __utimbuf32 *_Time);
  _CRTIMP int __cdecl _utime64(const char *_Filename,struct __utimbuf64 *_Time);
  _CRTIMP int __cdecl _futime64(int _FileDes,struct __utimbuf64 *_Time);
  _CRTIMP int __cdecl _wutime64(const wchar_t *_Filename,struct __utimbuf64 *_Time);

#ifndef RC_INVOKED

/*
 * To prevent ABI issues, the mingw-w64 runtime should not call these
 * functions. Instead it should call the fixed-size variants.
 */
#ifndef _CRTBLD
#ifdef _USE_32BIT_TIME_T
  int __cdecl _utime(const char *_Filename,struct _utimbuf *_Utimbuf) __MINGW_ASM_CALL(_utime32);
  int __cdecl _futime(int _Desc,struct _utimbuf *_Utimbuf) __MINGW_ASM_CALL(_futime32);
  int __cdecl _wutime(const wchar_t *_Filename,struct _utimbuf *_Utimbuf) __MINGW_ASM_CALL(_wutime32);
#else
  int __cdecl _utime(const char *_Filename,struct _utimbuf *_Utimbuf) __MINGW_ASM_CALL(_utime64);
  int __cdecl _futime(int _Desc,struct _utimbuf *_Utimbuf) __MINGW_ASM_CALL(_futime64);
  int __cdecl _wutime(const wchar_t *_Filename,struct _utimbuf *_Utimbuf) __MINGW_ASM_CALL(_wutime64);
#endif
#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
  int __cdecl utime(const char *, struct utimbuf *) __MINGW_ASM_CALL(_utime32);
#else
  int __cdecl utime(const char *, struct utimbuf *) __MINGW_ASM_CALL(_utime64);
#endif
#endif
#endif /* _CRTBLD */

#endif

_CRT_END_C_HEADER

#endif
