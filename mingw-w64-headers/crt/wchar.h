/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#include <corecrt.h>
#include <corecrt_stdio_config.h>
#include <corecrt_wstdlib.h>
#include <corecrt_wctype.h>

#if __USE_MINGW_ANSI_STDIO && !defined (__USE_MINGW_STRTOX) && !defined(_CRTBLD)
#define __USE_MINGW_STRTOX 1
#endif

#if defined(__LIBMSVCRT__)
/* When building mingw-w64, this should be blank.  */
#define _SECIMP
#else
#ifndef _SECIMP
#define _SECIMP __declspec(dllimport)
#endif /* _SECIMP */
#endif /* defined(__LIBMSVCRT__) */

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WCHAR_MIN  /* also in stdint.h */
#define WCHAR_MIN 0U
#define WCHAR_MAX 0xffffU
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
  };
  typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

_CRTIMP FILE *__cdecl __acrt_iob_func(unsigned index);
#ifndef _STDIO_DEFINED
  _CRTIMP FILE *__cdecl __iob_func(void);
#define _iob __iob_func()
#endif

#ifndef _STDSTREAM_DEFINED
#define stdin (__acrt_iob_func(0))
#define stdout (__acrt_iob_func(1))
#define stderr (__acrt_iob_func(2))
#define _STDSTREAM_DEFINED
#endif

#ifndef _FSIZE_T_DEFINED
  typedef unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
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
/* #endif */

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

#define _WFINDDATA_T_DEFINED
#endif

#ifndef NULL
#ifdef __cplusplus
#ifndef _WIN64
#define NULL 0
#else
#define NULL 0LL
#endif  /* W64 */
#else
#define NULL ((void *)0)
#endif
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

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
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP int __cdecl _waccess(const wchar_t *_Filename,int _AccessMode);
  _CRTIMP int __cdecl _wchmod(const wchar_t *_Filename,int _Mode);
  _CRTIMP int __cdecl _wcreat(const wchar_t *_Filename,int _PermissionMode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,struct _wfinddata32_t *_FindData);
  _CRTIMP int __cdecl _wfindnext32(intptr_t _FindHandle,struct _wfinddata32_t *_FindData);
  _CRTIMP int __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP int __cdecl _wrename(const wchar_t *_OldFilename,const wchar_t *_NewFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,struct _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,struct _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,struct _wfinddata64_t *_FindData);
  _CRTIMP int __cdecl _wfindnext32i64(intptr_t _FindHandle,struct _wfinddata32i64_t *_FindData);
  int __cdecl _wfindnext64i32(intptr_t _FindHandle,struct _wfinddata64i32_t *_FindData);
  _CRTIMP int __cdecl _wfindnext64(intptr_t _FindHandle,struct _wfinddata64_t *_FindData);
  _CRTIMP errno_t __cdecl _wsopen_s(int *_FileHandle,const wchar_t *_Filename,int _OpenFlag,int _ShareFlag,int _PermissionFlag);
  _CRTIMP int __cdecl _wopen(const wchar_t *_Filename,int _OpenFlag,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _wsopen(const wchar_t *_Filename,int _OpenFlag,int _ShareFlag,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(int _Category,const wchar_t *_Locale);
#endif

#if __MSVCRT_VERSION__ >= 0xB00
  _CRTIMP _locale_t __cdecl _wcreate_locale(int _Category, const wchar_t *_Locale);
#endif

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
#ifndef _WEXEC_DEFINED
#define _WEXEC_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
#endif

#ifndef _WSPAWN_DEFINED
#define _WSPAWN_DEFINED
  _CRTIMP intptr_t __cdecl _wspawnl(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
#endif

#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP int __cdecl _wsystem(const wchar_t *_Command);
#endif
#endif /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

#if !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  typedef unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  typedef unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  typedef unsigned int _dev_t;
#ifndef	NO_OLDNAMES
  typedef unsigned int dev_t;
#endif
#endif

#include <_mingw_off_t.h>
#include <_mingw_stat64.h>

#ifndef _WSTAT_DEFINED
#define _WSTAT_DEFINED

  _CRTIMP int __cdecl _wstat32(const wchar_t *_Name,struct _stat32 *_Stat);
  _CRTIMP int __cdecl _wstat32i64(const wchar_t *_Name,struct _stat32i64 *_Stat);
  _CRTIMP int __cdecl _wstat64i32(const wchar_t *_Name,struct _stat64i32 *_Stat);
  _CRTIMP int __cdecl _wstat64(const wchar_t *_Name,struct _stat64 *_Stat);
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wint_t __cdecl _getwch(void);
  _CRTIMP wint_t __cdecl _getwche(void);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP int __cdecl _cputws(const wchar_t *_String);
  _CRTIMP int __cdecl _cwprintf(const wchar_t * __restrict__ _Format,...);
  _CRTIMP int __cdecl _cwscanf(const wchar_t * __restrict__ _Format,...);
  _CRTIMP int __cdecl _cwscanf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vcwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);
  _CRTIMP int __cdecl _cwprintf_p(const wchar_t * __restrict__ _Format,...);
  _CRTIMP int __cdecl _vcwprintf_p(const wchar_t * __restrict__ _Format,va_list _ArgList);

  _CRTIMP int __cdecl _cwprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vcwprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _cwprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vcwprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
#if __MSVCRT_VERSION__ >= 0x800
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(void);
  wint_t __cdecl _getwche_nolock(void);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif
#endif

#ifdef _UCRT
  int __cdecl __stdio_common_vswprintf_p(unsigned __int64 _Options, wchar_t *_Str, size_t _Len, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  int __cdecl __stdio_common_vfwprintf_p(unsigned __int64 _Options, FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

/* __attribute__((__format__ (gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_swscanf(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,...);
/* __attribute__((__format__ (gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vswscanf (const wchar_t * __restrict__ _Str,const wchar_t * __restrict__ Format,va_list argp);
/* __attribute__((__format__ (gnu_wscanf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_wscanf(const wchar_t * __restrict__ _Format,...);
/* __attribute__((__format__ (gnu_wscanf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_vwscanf(const wchar_t * __restrict__ Format, va_list argp);
/* __attribute__((__format__ (gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_fwscanf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
/* __attribute__((__format__ (gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vfwscanf (FILE * __restrict__ fp, const wchar_t * __restrict__ Format,va_list argp);


/* __attribute__((__format__ (gnu_wprintf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_fwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
/* __attribute__((__format__ (gnu_wprintf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_wprintf(const wchar_t * __restrict__ _Format,...);
/* __attribute__((__format__ (gnu_wprintf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vfwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,va_list _ArgList);
/* __attribute__((__format__ (gnu_printf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_vwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);
/* __attribute__((__format__ (gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __mingw_snwprintf (wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, ...);
/* __attribute__((__format__ (gnu_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __mingw_vsnwprintf (wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ , va_list);
/* __attribute__((__format__ (gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __mingw_swprintf(wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ , ...);
/* __attribute__((__format__ (gnu_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __mingw_vswprintf(wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ ,va_list);

/* __attribute__((__format__ (ms_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_swscanf(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,...)
  __MINGW_UCRT_ASM_CALL(swscanf);
/* __attribute__((__format__ (ms_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_vswscanf(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,va_list)
  __MINGW_ASM_CALL(vswscanf);
/* __attribute__((__format__ (ms_wscanf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __ms_wscanf(const wchar_t * __restrict__ _Format,...)
  __MINGW_UCRT_ASM_CALL(wscanf);
/* __attribute__((__format__ (ms_wscanf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __ms_vwscanf(const wchar_t * __restrict__ _Format, va_list)
  __MINGW_ASM_CALL(vwscanf);
/* __attribute__((__format__ (ms_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_fwscanf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...)
  __MINGW_UCRT_ASM_CALL(fwscanf);
/* __attribute__((__format__ (ms_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_vfwscanf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,va_list)
  __MINGW_ASM_CALL(vfwscanf);

/* __attribute__((__format__ (ms_wprintf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_fwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
  /* No __MINGW_UCRT_ASM_CALL for __ms_fwprintf; this is provided as an
   * actual function in the ucrt import libraries. */
/* __attribute__((__format__ (ms_wprintf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __ms_wprintf(const wchar_t * __restrict__ _Format,...)
  __MINGW_UCRT_ASM_CALL(wprintf);
/* __attribute__((__format__ (ms_wprintf, 2, 0))) */__MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_vfwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,va_list _ArgList)
  __MINGW_UCRT_ASM_CALL(vfwprintf);
/*__attribute__((__format__ (ms_wprintf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __ms_vwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList)
  __MINGW_UCRT_ASM_CALL(vwprintf);
/* __attribute__((__format__ (ms_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __ms_swprintf(wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ , ...)
  __MINGW_UCRT_ASM_CALL(swprintf);
/* __attribute__((__format__ (ms_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __ms_vswprintf(wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ ,va_list)
  __MINGW_UCRT_ASM_CALL(vswprintf);
/* __attribute__((__format__ (ms_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __ms_snwprintf(wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ , ...)
  __MINGW_UCRT_ASM_CALL(snwprintf);
/* __attribute__((__format__ (ms_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __ms_vsnwprintf(wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ , va_list)
  __MINGW_UCRT_ASM_CALL(vsnwprintf);

#ifdef _UCRT
  int __cdecl __stdio_common_vswprintf(unsigned __int64 options, wchar_t *str, size_t len, const wchar_t *format, _locale_t locale, va_list valist);
  int __cdecl __stdio_common_vfwprintf(unsigned __int64 options, FILE *file, const wchar_t *format, _locale_t locale, va_list valist);
  int __cdecl __stdio_common_vswscanf(unsigned __int64 options, const wchar_t *input, size_t length, const wchar_t *format, _locale_t locale, va_list valist);
  int __cdecl __stdio_common_vfwscanf(unsigned __int64 options, FILE *file, const wchar_t *format, _locale_t locale, va_list valist);
#endif

#if __USE_MINGW_ANSI_STDIO

/*
 * User has expressed a preference for C99 conformance...
 */
/* __attribute__((__format__ (gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
int swscanf(const wchar_t *__source, const wchar_t *__format, ...)
__MINGW_ASM_CALL(__mingw_swscanf);

/* __attribute__((__format__ (gnu_wscanf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
int wscanf(const wchar_t *__format, ...)
__MINGW_ASM_CALL(__mingw_wscanf);

/* __attribute__((__format__ (gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
int fwscanf(FILE *__stream, const wchar_t *__format, ...)
__MINGW_ASM_CALL(__mingw_fwscanf);

#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
/* __attribute__((__format__ (gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
int vswscanf (const wchar_t *__source, const wchar_t *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vswscanf);

/* __attribute__((__format__ (gnu_wscanf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
int vwscanf(const wchar_t *__format,  __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vwscanf);

/* __attribute__((__format__ (gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
int vfwscanf (FILE *__stream,  const wchar_t *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vfwscanf);
#endif /* __NO_ISOCEXT */



/* __attribute__((__format__ (gnu_wprintf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
int fwprintf (FILE *__stream, const wchar_t *__format, ...)
__MINGW_ASM_CALL(__mingw_fwprintf);

/* __attribute__((__format__ (gnu_wprintf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
int wprintf (const wchar_t *__format, ...)
__MINGW_ASM_CALL(__mingw_wprintf);

/* __attribute__((__format__ (gnu_wprintf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
int vfwprintf (FILE *__stream, const wchar_t *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vfwprintf);

/* __attribute__((__format__ (gnu_wprintf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
int vwprintf (const wchar_t *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vwprintf);

/* __attribute__((__format__ (gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
int swprintf (wchar_t *__stream, size_t __n, const wchar_t *__format, ...)
__MINGW_ASM_CALL(__mingw_swprintf);

/* __attribute__((__format__ (gnu_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
int vswprintf (wchar_t *__stream, size_t __n, const wchar_t *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vswprintf);

#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */

/* __attribute__((__format__ (gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
int snwprintf (wchar_t *__stream, size_t __n, const wchar_t *__format, ...)
__MINGW_ASM_CALL(__mingw_snwprintf);

/* __attribute__((__format__ (gnu_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
int vsnwprintf (wchar_t *__stream, size_t __n, const wchar_t *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vsnwprintf);

#endif /* __NO_ISOCEXT */

#else /* !__USE_MINGW_ANSI_STDIO */

#ifdef _UCRT
  __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl fwscanf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);

  __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl swscanf(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,...);

  __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl wscanf(const wchar_t * __restrict__ _Format,...);

  __MINGW_ATTRIB_NONNULL(2)
  int __cdecl vfwscanf(FILE *__stream,  const wchar_t *__format, va_list __local_argv);

  __MINGW_ATTRIB_NONNULL(2)
  int __cdecl vswscanf(const wchar_t * __restrict__ __source, const wchar_t * __restrict__ __format, va_list __local_argv);

  __MINGW_ATTRIB_NONNULL(1)
  int __cdecl vwscanf(const wchar_t *__format, va_list __local_argv);

  int __cdecl fwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
  int __cdecl wprintf(const wchar_t * __restrict__ _Format,...);
  int __cdecl vfwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,va_list _ArgList);
  int __cdecl vwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);
  int __cdecl swprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,...);
  int __cdecl vswprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,va_list _Args);
#else

  int __cdecl fwscanf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl swscanf(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl wscanf(const wchar_t * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  __MINGW_ATTRIB_NONNULL(2)
  int vfwscanf (FILE *__stream,  const wchar_t *__format, __builtin_va_list __local_argv);

  __MINGW_ATTRIB_NONNULL(2)
   int vswscanf (const wchar_t * __restrict__ __source, const wchar_t * __restrict__ __format, __builtin_va_list __local_argv);

  __MINGW_ATTRIB_NONNULL(1)
  int vwscanf(const wchar_t *__format,  __builtin_va_list __local_argv);
#endif /* __NO_ISOCEXT */

  int __cdecl fwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
  int __cdecl wprintf(const wchar_t * __restrict__ _Format,...);
  int __cdecl vfwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,va_list _ArgList);
  int __cdecl vwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);

  int __cdecl swprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,...);
  int __cdecl vswprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,va_list _Args);
#endif /* _UCRT */
#endif /* __USE_MINGW_ANSI_STDIO */


#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode);
#else
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode,int _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(void);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(void);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t * __restrict__ _Dst,int _SizeInWords,FILE * __restrict__ _File);
  int __cdecl fputws(const wchar_t * __restrict__ _Str,FILE * __restrict__ _File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _putws(const wchar_t *_Str);

  _CRTIMP int __cdecl _scwprintf(const wchar_t * __restrict__ _Format,...);

#ifndef _UCRT
  _CRTIMP int __cdecl _swprintf_l(wchar_t * __restrict__ ,size_t _SizeInWords,const wchar_t * __restrict__ _Format,_locale_t _Locale,... ) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _swprintf_c(wchar_t * __restrict__ _DstBuf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,...);
  _CRTIMP int __cdecl _vswprintf_c(wchar_t * __restrict__ _DstBuf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,va_list _ArgList);
#endif

  _CRTIMP int __cdecl _snwprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _vsnwprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */

#if __USE_MINGW_ANSI_STDIO == 0
#pragma push_macro("snwprintf")
#pragma push_macro("vsnwprintf")
# undef snwprintf
# undef vsnwprintf
  int __cdecl snwprintf (wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, ...);
  int __cdecl vsnwprintf (wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, va_list arg);
#pragma pop_macro ("vsnwprintf")
#pragma pop_macro ("snwprintf")
#endif

#endif /* __NO_ISOCEXT */


#ifdef _UCRT
  __mingw_ovr int __cdecl _vfwscanf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _File, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vwscanf_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vfwscanf_l(stdin, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _fwscanf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfwscanf_l(_File, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _wscanf_l(const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfwscanf_l(stdin, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vsnwscanf_l(const wchar_t *_Src, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Src, _MaxCount, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _snwscanf_l(const wchar_t *_Src, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsnwscanf_l(_Src, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _snwscanf(const wchar_t *_Src, size_t _MaxCount, const wchar_t *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vsnwscanf_l(_Src, _MaxCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vswscanf_l(const wchar_t *_Src, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Src, (size_t)-1, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _swscanf_l(const wchar_t *_Src, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vswscanf_l(_Src, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vfwprintf_p_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _File, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vwprintf_p_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vfwprintf_p_l(stdout, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vfwprintf_p(FILE *_File, const wchar_t *_Format, va_list _ArgList)
  {
    return _vfwprintf_p_l(_File, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _vwprintf_p(const wchar_t *_Format, va_list _ArgList)
  {
    return _vfwprintf_p_l(stdout, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _fwprintf_p_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfwprintf_p_l(_File, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _wprintf_p_l(const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfwprintf_p_l(stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _fwprintf_p(FILE *_File, const wchar_t *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vfwprintf_p_l(_File, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _wprintf_p(const wchar_t *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vfwprintf_p_l(stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vfwprintf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _File, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vwprintf_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vfwprintf_l(stdout, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _fwprintf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfwprintf_l(_File, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _wprintf_l(const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfwprintf_l(stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vswprintf_p_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vswprintf_p(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, va_list _ArgList)
  {
    return _vswprintf_p_l(_DstBuf, _MaxCount, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _swprintf_p_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vswprintf_p_l(_DstBuf, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _swprintf_p(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vswprintf_p_l(_DstBuf, _MaxCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vsnwprintf_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _snwprintf_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsnwprintf_l(_DstBuf, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vscwprintf_p_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vscwprintf_p(const wchar_t *_Format, va_list _ArgList)
  {
    return _vscwprintf_p_l(_Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _scwprintf_p_l(const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vscwprintf_p_l(_Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _scwprintf_p(const wchar_t *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vscwprintf_p_l(_Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vscwprintf_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
  }

  _CRTIMP int __cdecl _vscwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);

  __mingw_ovr int __cdecl _scwprintf_l(const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vscwprintf_l(_Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vswprintf_c_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl __vswprintf_l(wchar_t *_DstBuf, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vswprintf_c_l(_DstBuf, (size_t)-1, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vswprintf_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vswprintf_c_l(_DstBuf, _MaxCount, _Format, _Locale, _ArgList);
  }
  _CRTIMP int __cdecl _vswprintf(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,va_list _Args);
  __mingw_ovr int __cdecl _swprintf_c_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vswprintf_c_l(_DstBuf, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl __swprintf_l(wchar_t *_DstBuf, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vswprintf_c_l(_DstBuf, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  _CRTIMP int __cdecl _swprintf(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,...);
#else /* _UCRT */
  _CRTIMP int __cdecl _fwprintf_p(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
  _CRTIMP int __cdecl _wprintf_p(const wchar_t * __restrict__ _Format,...);
  _CRTIMP int __cdecl _vfwprintf_p(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,va_list _ArgList);
  _CRTIMP int __cdecl _vwprintf_p(const wchar_t * __restrict__ _Format,va_list _ArgList);
  _CRTIMP int __cdecl _swprintf_p(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,...);
  _SECIMP int __cdecl _vswprintf_p(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,va_list _ArgList);
  _CRTIMP int __cdecl _scwprintf_p(const wchar_t * __restrict__ _Format,...);
  _SECIMP int __cdecl _vscwprintf_p(const wchar_t * __restrict__ _Format,va_list _ArgList);
  _CRTIMP int __cdecl _wprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _wprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vwprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _vwprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _fwprintf_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _fwprintf_p_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vfwprintf_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _vfwprintf_p_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _swprintf_c_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _swprintf_p_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vswprintf_c_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _vswprintf_p_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _scwprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _scwprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vscwprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _snwprintf_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vsnwprintf_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _swprintf(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,...);
  _CRTIMP int __cdecl _vswprintf(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,va_list _Args);
  _CRTIMP int __cdecl __swprintf_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,_locale_t _Plocinfo,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _vswprintf_l(wchar_t * __restrict__ _Dest,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl __vswprintf_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,_locale_t _Plocinfo,va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif /* !_UCRT */

#ifndef RC_INVOKED
#include <swprintf.inl>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_wtempnam")
#undef _wtempnam
#endif
  _CRTIMP wchar_t *__cdecl _wtempnam(const wchar_t *_Directory,const wchar_t *_FilePrefix);
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_wtempnam")
#endif

#ifndef _UCRT
  _CRTIMP int __cdecl _vscwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);
  _CRTIMP int __cdecl _vscwprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _fwscanf_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _swscanf_l(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,_locale_t _Locale,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _snwscanf(const wchar_t * __restrict__ _Src,size_t _MaxCount,const wchar_t * __restrict__ _Format,...);
  _CRTIMP int __cdecl _snwscanf_l(const wchar_t * __restrict__ _Src,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _wscanf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif /* !_UCRT */
  _CRTIMP FILE *__cdecl _wfdopen(int _FileHandle ,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(const wchar_t * __restrict__ _Filename,const wchar_t * __restrict__ _Mode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP FILE *__cdecl _wfreopen(const wchar_t * __restrict__ _Filename,const wchar_t * __restrict__ _Mode,FILE * __restrict__ _OldFile) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP FILE *__cdecl _wpopen(const wchar_t *_Command,const wchar_t *_Mode);
#if !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP int __cdecl _wremove(const wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
#if __MSVCRT_VERSION__ >= 0x800
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);
#endif

#undef _CRT_GETPUTWCHAR_NOINLINE

#if !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE) || defined (__CRT__NO_INLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#else
  __CRT_INLINE wint_t __cdecl getwchar() {return (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {return (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#if __MSVCRT_VERSION__ >= 0x800
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#endif /* _WSTDIO_DEFINED */

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(int _Value,wchar_t *_Dest,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _ltow(long _Value,wchar_t *_Dest,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long _Value,wchar_t *_Dest,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP double __cdecl _wcstod_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,_locale_t _Locale);

  double __cdecl __mingw_wcstod(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr);
  float __cdecl __mingw_wcstof(const wchar_t * __restrict__ nptr, wchar_t ** __restrict__ endptr);
  long double __cdecl __mingw_wcstold(const wchar_t * __restrict__, wchar_t ** __restrict__);

#if defined(__USE_MINGW_STRTOX) && !defined(_UCRT)
  __mingw_ovr
  double __cdecl wcstod(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr){
    return __mingw_wcstod(_Str,_EndPtr);
  }
  __mingw_ovr
  float __cdecl wcstof(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr){
    return __mingw_wcstof(_Str,_EndPtr);
  }
  /* wcstold is already a mingw implementation */
#else
  double __cdecl wcstod(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr);
  float __cdecl wcstof(const wchar_t * __restrict__ nptr, wchar_t ** __restrict__ endptr);
#endif /* !defined(__USE_MINGW_STRTOX) || defined(_UCRT) */
#if !defined __NO_ISOCEXT /* in libmingwex.a */
  long double __cdecl wcstold (const wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix);
  _CRTIMP long __cdecl _wcstol_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(const wchar_t *_VarName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP int __cdecl _wsystem(const wchar_t *_Command);
#endif
  _CRTIMP double __cdecl _wtof(const wchar_t *_Str);
  _CRTIMP double __cdecl _wtof_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP int __cdecl _wtoi(const wchar_t *_Str);
  _CRTIMP int __cdecl _wtoi_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(const wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(const wchar_t *_Str,_locale_t _Locale);

  __MINGW_EXTENSION _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,int _Radix);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wtoi64(const wchar_t *_Str);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wtoi64_l(const wchar_t *_Str,_locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wcstoi64(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wcstoi64_l(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix,_locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix,_locale_t _Locale);
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_wfullpath")
#undef _wfullpath
#endif
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,const wchar_t *_Path,size_t _SizeInWords);
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_wfullpath")
#endif
  _CRTIMP void __cdecl _wmakepath(wchar_t *_ResultPath,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP int __cdecl _wputenv(const wchar_t *_EnvString);
  _CRTIMP void __cdecl _wsearchenv(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP void __cdecl _wsplitpath(const wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_wcsdup")
#undef _wcsdup
#endif
  _CRTIMP wchar_t *__cdecl _wcsdup(const wchar_t *_Str);
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_wcsdup")
#endif
  wchar_t *__cdecl wcscat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CONST_RETURN wchar_t *__cdecl wcschr(const wchar_t *_Str,wchar_t _Ch);
  int __cdecl wcscmp(const wchar_t *_Str1,const wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  size_t __cdecl wcscspn(const wchar_t *_Str,const wchar_t *_Control);
  size_t __cdecl wcslen(const wchar_t *_Str);
  size_t __cdecl wcsnlen(const wchar_t *_Src,size_t _MaxCount);
  wchar_t *__cdecl wcsncat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl wcsncmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsncpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  wchar_t *__cdecl _wcsncpy_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CONST_RETURN wchar_t *__cdecl wcspbrk(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(const wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(const wchar_t *_Str,const wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim,wchar_t ** __restrict__ _Ptr) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  wchar_t *__cdecl _wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#if defined(_CRT_NON_CONFORMING_WCSTOK) && !defined(__cplusplus)
  #define wcstok _wcstok
#endif
#if !defined(_CRT_NO_INLINE_DEPRECATED_WCSTOK) && defined(__cplusplus)
  extern "C++" inline wchar_t *__cdecl wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim) { return _wcstok(_Str, _Delim); }
#endif
  _CRTIMP wchar_t *__cdecl _wcserror(int _ErrNum) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl __wcserror(const wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP int __cdecl _wcsicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _wcsnicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  size_t __cdecl wcsxfrm(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);
  int __cdecl wcscoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP int __cdecl _wcscoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP int __cdecl _wcsicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _wcsncoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _wcsncoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP int __cdecl _wcsnicoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _wcsnicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#ifndef	NO_OLDNAMES
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("wcsdup")
#undef wcsdup
#endif
  wchar_t *__cdecl wcsdup(const wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("wcsdup")
#endif
#define wcswcs wcsstr
  int __cdecl wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcsrev(wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcslwr(wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  wchar_t *__cdecl wcsupr(wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(const struct tm *_Tm);
  _SECIMP errno_t __cdecl _wasctime_s (wchar_t *_Buf,size_t _SizeInWords,const struct tm *_Tm);
  wchar_t *__cdecl _wctime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _SECIMP errno_t __cdecl _wctime32_s (wchar_t *_Buf,size_t _SizeInWords,const __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t * __restrict__ _Buf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,const struct tm * __restrict__ _Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t * __restrict__ _Buf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,const struct tm * __restrict__ _Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _SECIMP errno_t __cdecl _wstrdate_s (wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _SECIMP errno_t __cdecl _wstrtime_s (wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wctime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _SECIMP errno_t __cdecl _wctime64_s (wchar_t *_Buf,size_t _SizeInWords,const __time64_t *_Time);

#if !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
  wchar_t *__cdecl _wctime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef __CRT__NO_INLINE
#ifndef _USE_32BIT_TIME_T
  __CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { return _wctime64(_Time); }
#else
  __CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { return _wctime32(_Time); }
#endif
#endif /* __CRT__NO_INLINE */
#endif

#if !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
  errno_t __cdecl _wctime_s(wchar_t *, size_t, const time_t *);
#ifndef __CRT__NO_INLINE
#ifndef _USE_32BIT_TIME_T
  __CRT_INLINE errno_t __cdecl _wctime_s (wchar_t *_Buffer,size_t _SizeInWords,const time_t *_Time) { return _wctime64_s (_Buffer,_SizeInWords,_Time); }
#else
  __CRT_INLINE errno_t __cdecl _wctime_s (wchar_t *_Buffer,size_t _SizeInWords,const time_t *_Time) { return _wctime32_s (_Buffer,_SizeInWords,_Time); }
#endif /* _USE_32BIT_TIME_T */
#endif  /* __CRT__NO_INLINE */
#endif /* !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL) */

#endif

#if defined(_UCRT) || defined(__LARGE_MBSTATE_T)
  typedef struct _Mbstatet {
    unsigned long _Wchar;
    unsigned short _Byte, _State;
  } _Mbstatet;
  typedef _Mbstatet mbstate_t;
#else
  typedef int mbstate_t;
#endif
  typedef wchar_t _Wint_t;

  wint_t __cdecl btowc(int);
  int __cdecl mbsinit(const mbstate_t *ps);
  size_t __cdecl mbrlen(const char * __restrict__ _Ch,size_t _SizeInBytes,mbstate_t * __restrict__ _State);
  size_t __cdecl mbrtowc(wchar_t * __restrict__ _DstCh,const char * __restrict__ _SrcCh,size_t _SizeInBytes,mbstate_t * __restrict__ _State);
  size_t __cdecl mbsrtowcs(wchar_t * __restrict__ _Dest,const char ** __restrict__ _PSrc,size_t _Count,mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  size_t __cdecl wcrtomb(char * __restrict__ _Dest,wchar_t _Source,mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  size_t __cdecl wcsrtombs(char * __restrict__ _Dest,const wchar_t ** __restrict__ _PSource,size_t _Count,mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *s, wchar_t c, size_t n);
  int __cdecl wmemcmp(const wchar_t *s1, const wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t * __restrict__ s1,const wchar_t * __restrict__ s2,size_t n) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  wchar_t * __cdecl wmempcpy (wchar_t *_Dst, const wchar_t *_Src, size_t _Size);
  wchar_t *__cdecl wmemmove(wchar_t *s1, const wchar_t *s2, size_t n) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl fwide(FILE *stream,int mode);
  __MINGW_EXTENSION long long __cdecl wcstoll(const wchar_t * __restrict__ nptr,wchar_t ** __restrict__ endptr, int base);
  __MINGW_EXTENSION unsigned long long __cdecl wcstoull(const wchar_t * __restrict__ nptr,wchar_t ** __restrict__ endptr, int base);
#endif /* __NO_ISOCEXT */

  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _MaxCount);
  void *__cdecl memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef __CRT__NO_INLINE
  __CRT_INLINE int __cdecl fwide(FILE *_F,int _M) { (void)_F; return (_M); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *_S,wchar_t _C,size_t _N) {
    if (_S) {
      for ( ; 0 < _N; ++_S, --_N)
	if (*_S == _C)
	  return (_CONST_RETURN wchar_t *)(_S);
    }
    return (_CONST_RETURN wchar_t *) NULL;
  }
  __CRT_INLINE int __cdecl wmemcmp(const wchar_t *_S1,const wchar_t *_S2,size_t _N) {
    if (_N == 0 || _S1 == _S2)
      return 0;	/* even for NULL pointers.  */
    if ((_S1 && !(_S2)) || (_S2 && !(_S1)))
      return !(_S2) ? 1 : -1; /* robust.  */
    for ( ; 0 < _N; ++_S1, ++_S2, --_N)
      if (*_S1 != *_S2)
	return (*_S1 < *_S2 ? -1 : +1);
    return 0;
  }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t * __restrict__ _S1,const wchar_t * __restrict__ _S2,size_t _N)
  {
    return (wchar_t *) memcpy (_S1,_S2,_N*sizeof(wchar_t));
  }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,const wchar_t *_S2,size_t _N) { return (wchar_t *)memmove(_S1,_S2,_N*sizeof(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    for (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    return (_S);
  }
#endif /* !__CRT__NO_INLINE */

#ifndef __MINGW_MBWC_CONVERT_DEFINED
#define __MINGW_MBWC_CONVERT_DEFINED

/**
 * __mingw_str_wide_utf8
 * Converts a null terminated UCS-2 string to a multibyte (UTF-8) equivalent.
 * Caller is supposed to free allocated buffer with __mingw_str_free().
 * @param[in] wptr Pointer to wide string.
 * @param[out] mbptr Pointer to multibyte string.
 * @param[out] buflen Optional parameter for length of allocated buffer.
 * @return bytes written by WideCharToMultiByte conversion, 0 for failure.
 *
 * WideCharToMultiByte - http://msdn.microsoft.com/en-us/library/dd374130(VS.85).aspx
 */
int __cdecl __mingw_str_wide_utf8 (const wchar_t * const wptr, char **mbptr, size_t * buflen);

/**
 * __mingw_str_utf8_wide
 * Converts a null terminated UTF-8 string to a UCS-2 equivalent.
 * Caller is supposed to free allocated buffer with __mingw_str_free().
 * @param[out] mbptr Pointer to multibyte string.
 * @param[in] wptr Pointer to wide string.
 * @param[out] buflen Optional parameter for length of allocated buffer.
 * @return bytes written by WideCharToMultiByte conversion, 0 for failure.
 *
 * MultiByteToWideChar - http://msdn.microsoft.com/en-us/library/dd319072(VS.85).aspx
 */

int __cdecl __mingw_str_utf8_wide (const char *const mbptr, wchar_t ** wptr, size_t * buflen);

/**
 * __mingw_str_free
 * Frees buffer create by __mingw_str_wide_utf8 and __mingw_str_utf8_wide.
 * @param[in] ptr memory block to free.
 *
 */

void __cdecl __mingw_str_free(void *ptr);

#endif /* __MINGW_MBWC_CONVERT_DEFINED */

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/wchar_s.h>

#endif /* _INC_WCHAR */

