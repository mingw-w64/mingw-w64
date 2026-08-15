/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WIO
#define _INC_CORECRT_WIO

#include <corecrt.h>

_CRT_BEGIN_C_HEADER

  typedef unsigned long _fsize_t;

  struct _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  struct _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __MINGW_EXTENSION __int64 size;
    wchar_t name[260];
  };

  struct _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  struct _wfinddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __MINGW_EXTENSION __int64 size;
    wchar_t name[260];
  };

/*
 * To prevent ABI issues, the mingw-w64 runtime should not call these
 * functions. Instead it should call the fixed-size variants.
 */
#ifndef _CRTBLD
#ifdef _USE_32BIT_TIME_T
#define _wfinddata_t _wfinddata32_t
#define _wfinddatai64_t _wfinddata32i64_t

#define _wfindfirst _wfindfirst32
#define _wfindnext _wfindnext32
#define _wfindfirst32i64 _wfindfirsti64
#define _wfindnext32i64 _wfindnexti64
#else
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif
#endif /* _CRTBLD */

  _CRTIMP int __cdecl _waccess(const wchar_t *_Filename,int _AccessMode);
  _CRTIMP int __cdecl _wchmod(const wchar_t *_Filename,int _Mode);
  _CRTIMP int __cdecl _wcreat(const wchar_t *_Filename,int _PermissionMode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,struct _wfinddata32_t *_FindData);
  _CRTIMP int __cdecl _wfindnext32(intptr_t _FindHandle,struct _wfinddata32_t *_FindData);
  _CRTIMP int __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP int __cdecl _wrename(const wchar_t *_OldFilename,const wchar_t *_NewFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,struct _wfinddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,struct _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,struct _wfinddata64_t *_FindData);
  _CRTIMP int __cdecl _wfindnext32i64(intptr_t _FindHandle,struct _wfinddata32i64_t *_FindData);
  _CRTIMP int __cdecl _wfindnext64i32(intptr_t _FindHandle,struct _wfinddata64i32_t *_FindData);
  _CRTIMP int __cdecl _wfindnext64(intptr_t _FindHandle,struct _wfinddata64_t *_FindData);
  _CRTIMP errno_t __cdecl _wsopen_s(int *_FileHandle,const wchar_t *_Filename,int _OpenFlag,int _ShareFlag,int _PermissionFlag);
  _CRTIMP int __cdecl _wopen(const wchar_t *_Filename,int _OpenFlag,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _wsopen(const wchar_t *_Filename,int _OpenFlag,int _ShareFlag,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _SECIMP errno_t __cdecl _waccess_s(const wchar_t *_Filename,int _AccessMode);
  _SECIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t _SizeInWords);

#if __MINGW_FORTIFY_LEVEL > 0 && __MINGW_FORTIFY_VA_ARG

#define _O_CREAT 0x0100

_CRTIMP int __cdecl __mingw_call__wopen(const wchar_t *, int, ...) __MINGW_ASM_CRT_CALL(_wopen);
_CRTIMP int __cdecl __mingw_call__wopen_warn_toomany(const wchar_t *, int, ...) __MINGW_ASM_CRT_CALL(_wopen)
  __attribute__((__warning__("_wopen(): too many arguments")));
_CRTIMP int __cdecl __mingw_call__wopen_warn_missing(const wchar_t *, int, ...) __MINGW_ASM_CRT_CALL(_wopen)
  __attribute__((__warning__("_wopen(..._O_CREAT...): missing argument")));

__mingw_bos_extern_ovr
int _wopen(const wchar_t * __filename, int __flags, ...)
{
  if (__builtin_va_arg_pack_len() > 1)
    return __mingw_call__wopen_warn_toomany(__filename, __flags, __builtin_va_arg_pack());
  if (__builtin_va_arg_pack_len() < 1 && __builtin_constant_p(__flags & _O_CREAT) && (__flags & _O_CREAT))
    return __mingw_call__wopen_warn_missing(__filename, __flags, 0);
  if (__builtin_va_arg_pack_len() < 1)
    return __mingw_call__wopen(__filename, __flags, 0);
  return __mingw_call__wopen(__filename, __flags, __builtin_va_arg_pack());
}

_CRTIMP int __cdecl __mingw_call__wsopen(const wchar_t *, int, int, ...) __MINGW_ASM_CRT_CALL(_wsopen);
_CRTIMP int __cdecl __mingw_call__wsopen_warn_toomany(const wchar_t *, int, int, ...) __MINGW_ASM_CRT_CALL(_wsopen)
  __attribute__((__warning__("_wsopen(): too many arguments")));
_CRTIMP int __cdecl __mingw_call__wsopen_warn_missing(const wchar_t *, int, int, ...) __MINGW_ASM_CRT_CALL(_wsopen)
  __attribute__((__warning__("_wsopen(..._O_CREAT...): missing argument")));

__mingw_bos_extern_ovr
int _wsopen(const wchar_t * __filename, int __flags, int __share, ...)
{
  if (__builtin_va_arg_pack_len() > 1)
    return __mingw_call__wsopen_warn_toomany(__filename, __flags, __share, __builtin_va_arg_pack());
  if (__builtin_va_arg_pack_len() < 1 && __builtin_constant_p(__flags & _O_CREAT) && (__flags & _O_CREAT))
    return __mingw_call__wsopen_warn_missing(__filename, __flags, __share, 0);
  if (__builtin_va_arg_pack_len() < 1)
    return __mingw_call__wsopen(__filename, __flags, __share, 0);
  return __mingw_call__wsopen(__filename, __flags, __share, __builtin_va_arg_pack());
}

#endif /* __MINGW_FORTIFY_LEVEL > 0 && __MINGW_FORTIFY_VA_ARG */

_CRT_END_C_HEADER

#endif /* _INC_CORECRT_WIO */
