/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#include <corecrt_wstdio.h>

_CRT_BEGIN_C_HEADER

#pragma push_macro("snprintf")
#undef snprintf
#pragma push_macro("vsnprintf")
#undef vsnprintf
#pragma push_macro("snwprintf")
#undef snwprintf
#pragma push_macro("vsnwprintf")
#undef vsnwprintf

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#ifdef _UCRT
#define _IOB_ENTRIES 3
#else
#define _IOB_ENTRIES 20
#endif
#define EOF (-1)

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#else
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#ifdef _UCRT
#define L_tmpnam 260
#else
#define L_tmpnam (sizeof(_P_tmpdir) + 12)
#endif

#ifdef _POSIX_
#define L_ctermid 9
#define L_cuserid 32
#endif

#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0

#define	STDIN_FILENO	0
#define	STDOUT_FILENO	1
#define	STDERR_FILENO	2

#define FILENAME_MAX 260
#define FOPEN_MAX 20
#define _SYS_OPEN 20
#ifdef _UCRT
#define TMP_MAX 2147483647
#else
#define TMP_MAX 32767
#endif

#include <_mingw_off_t.h>

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#if (!defined(NO_OLDNAMES) || defined(__GNUC__))
  __MINGW_EXTENSION typedef __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#else
  __MINGW_EXTENSION typedef long long fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#endif

#endif

#define _IOFBF 0x0000
#define _IOLBF 0x0040
#define _IONBF 0x0004

#ifndef _UCRT
#define _IOREAD 0x0001
#define _IOWRT 0x0002
#define _IOMYBUF 0x0008
#define _IOEOF 0x0010
#define _IOERR 0x0020
#define _IOSTRG 0x0040
#define _IORW 0x0080
#ifdef _POSIX_
#define _IOAPPEND 0x0200
#endif
#endif

/* used with _set_output_format which is not present in ucrt */
#ifndef _UCRT
#define _TWO_DIGIT_EXPONENT 0x1
#endif

extern
  __MINGW_GNU_SCANF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_sscanf(const char * __restrict__ _Src,const char * __restrict__ _Format,...);
extern
  __MINGW_GNU_SCANF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vsscanf (const char * __restrict__ _Str,const char * __restrict__ Format,va_list argp);
extern
  __MINGW_GNU_SCANF(1, 2) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_scanf(const char * __restrict__ _Format,...);
extern
  __MINGW_GNU_SCANF(1, 0) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_vscanf(const char * __restrict__ Format, va_list argp);
extern
  __MINGW_GNU_SCANF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
extern
  __MINGW_GNU_SCANF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vfscanf (FILE * __restrict__ fp, const char * __restrict__ Format,va_list argp);

extern
  __MINGW_GNU_PRINTF(3, 0) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __mingw_vsnprintf(char * __restrict__ _DstBuf,size_t _MaxCount,const char * __restrict__ _Format,
                               va_list _ArgList);
extern
  __MINGW_GNU_PRINTF(3, 4) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __mingw_snprintf(char * __restrict__ s, size_t n, const char * __restrict__  format, ...);
extern
  __MINGW_GNU_PRINTF(1, 2) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_printf(const char * __restrict__ , ... ) __MINGW_NOTHROW;
extern
  __MINGW_GNU_PRINTF(1, 0) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_vprintf (const char * __restrict__ , va_list) __MINGW_NOTHROW;
extern
  __MINGW_GNU_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_fprintf (FILE * __restrict__ , const char * __restrict__ , ...) __MINGW_NOTHROW;
extern
  __MINGW_GNU_PRINTF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vfprintf (FILE * __restrict__ , const char * __restrict__ , va_list) __MINGW_NOTHROW;
extern
  __MINGW_GNU_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_sprintf (char * __restrict__ , const char * __restrict__ , ...) __MINGW_NOTHROW;
extern
  __MINGW_GNU_PRINTF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vsprintf (char * __restrict__ , const char * __restrict__ , va_list) __MINGW_NOTHROW;
extern
  __MINGW_GNU_PRINTF(2, 3) __attribute__((nonnull (1,2)))
  int __cdecl __mingw_asprintf(char ** __restrict__ , const char * __restrict__ , ...) __MINGW_NOTHROW;
extern
  __MINGW_GNU_PRINTF(2, 0) __attribute__((nonnull (1,2)))
  int __cdecl __mingw_vasprintf(char ** __restrict__ , const char * __restrict__ , va_list) __MINGW_NOTHROW;

extern
  __MINGW_MS_SCANF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_sscanf(const char * __restrict__ _Src,const char * __restrict__ _Format,...)
  __MINGW_UCRT_ASM_CALL(sscanf);
extern
  __MINGW_MS_SCANF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_vsscanf(const char * __restrict__ _Str,const char * __restrict__ _Format,va_list argp)
  __MINGW_ASM_CALL(vsscanf);
extern
  __MINGW_MS_SCANF(1, 2) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __ms_scanf(const char * __restrict__ _Format,...)
  __MINGW_UCRT_ASM_CALL(scanf);
extern
  __MINGW_MS_SCANF(1, 0) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __ms_vscanf(const char * __restrict__ _Format,va_list argp)
  __MINGW_ASM_CALL(vscanf);
extern
  __MINGW_MS_SCANF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...)
  __MINGW_UCRT_ASM_CALL(fscanf);
extern
  __MINGW_MS_SCANF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_vfscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,va_list argp)
  __MINGW_ASM_CALL(vfscanf);

extern
  __MINGW_MS_PRINTF(1, 2) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __ms_printf(const char * __restrict__ , ... )
  __MINGW_UCRT_ASM_CALL(printf) __MINGW_NOTHROW;
extern
  __MINGW_MS_PRINTF(1, 0) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __ms_vprintf (const char * __restrict__ , va_list)
  __MINGW_UCRT_ASM_CALL(vprintf) __MINGW_NOTHROW;
extern
  __MINGW_MS_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_fprintf (FILE * __restrict__ , const char * __restrict__ , ...)
  __MINGW_UCRT_ASM_CALL(fprintf) __MINGW_NOTHROW;
extern
  __MINGW_MS_PRINTF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_vfprintf (FILE * __restrict__ , const char * __restrict__ , va_list)
  __MINGW_UCRT_ASM_CALL(vfprintf) __MINGW_NOTHROW
;
extern
  __MINGW_MS_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_sprintf (char * __restrict__ , const char * __restrict__ , ...)
  __MINGW_UCRT_ASM_CALL(sprintf) __MINGW_NOTHROW;
extern
  __MINGW_MS_PRINTF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_vsprintf (char * __restrict__ , const char * __restrict__ , va_list)
  __MINGW_UCRT_ASM_CALL(vsprintf) __MINGW_NOTHROW;
extern
  __MINGW_MS_PRINTF(3, 4) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __ms_snprintf (char * __restrict__ , size_t , const char * __restrict__ , ...)
  __MINGW_UCRT_ASM_CALL(snprintf) __MINGW_NOTHROW;
extern
  __MINGW_MS_PRINTF(3, 0) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __ms_vsnprintf (char * __restrict__ , size_t , const char * __restrict__ , va_list)
  __MINGW_UCRT_ASM_CALL(vsnprintf) __MINGW_NOTHROW;

#ifdef _UCRT
  int __cdecl __stdio_common_vsprintf(unsigned __int64 options, char *str, size_t len, const char *format, _locale_t locale, va_list valist);
  int __cdecl __stdio_common_vfprintf(unsigned __int64 options, FILE *file, const char *format, _locale_t locale, va_list valist);
  int __cdecl __stdio_common_vsscanf(unsigned __int64 options, const char *input, size_t length, const char *format, _locale_t locale, va_list valist);
  int __cdecl __stdio_common_vfscanf(unsigned __int64 options, FILE *file, const char *format, _locale_t locale, va_list valist);
#endif

#undef __MINGW_PRINTF_FORMAT
#undef __MINGW_SCANF_FORMAT

#if defined(__clang__)
#define __MINGW_PRINTF_FORMAT __printf__
#define __MINGW_SCANF_FORMAT  __scanf__
#elif defined(_UCRT) || __USE_MINGW_ANSI_STDIO
#define __MINGW_PRINTF_FORMAT __gnu_printf__
#define __MINGW_SCANF_FORMAT  __gnu_scanf__
#else
#define __MINGW_PRINTF_FORMAT __ms_printf__
#define __MINGW_SCANF_FORMAT  __ms_scanf__
#endif

#if __USE_MINGW_ANSI_STDIO && !defined(_CRTBLD)
/*
 * User has expressed a preference for C99 conformance...
 */

#ifdef _GNU_SOURCE
__MINGW_GNU_PRINTF(2, 3) __attribute__((nonnull (1,2)))
int asprintf(char **__ret, const char *__format, ...)
__MINGW_ASM_CALL(__mingw_asprintf);

__MINGW_GNU_PRINTF(2, 0) __attribute__((nonnull (1,2)))
int vasprintf(char **__ret, const char *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vasprintf);
#endif /* _GNU_SOURCE */

/* There seems to be a bug about builtins and static overrides of them
   in g++.  So we need to do here some trickery.  */
#ifdef __cplusplus
extern "C++" {
#endif

__MINGW_GNU_SCANF(2, 3) __MINGW_ATTRIB_NONNULL(2)
int sscanf(const char *__source, const char *__format, ...)
__MINGW_ASM_CALL(__mingw_sscanf);

__MINGW_GNU_SCANF(1, 2) __MINGW_ATTRIB_NONNULL(1)
int scanf(const char *__format, ...)
__MINGW_ASM_CALL(__mingw_scanf);

__MINGW_GNU_SCANF(2, 3) __MINGW_ATTRIB_NONNULL(2)
int fscanf(FILE *__stream, const char *__format, ...)
__MINGW_ASM_CALL(__mingw_fscanf);

#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif

__MINGW_GNU_SCANF(2, 0) __MINGW_ATTRIB_NONNULL(2)
int vsscanf (const char *__source, const char *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vsscanf);

__MINGW_GNU_SCANF(1, 0) __MINGW_ATTRIB_NONNULL(1)
int vscanf(const char *__format,  __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vscanf);

__MINGW_GNU_SCANF(2, 0) __MINGW_ATTRIB_NONNULL(2)
int vfscanf (FILE *__stream,  const char *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vfscanf);

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
#endif /* __NO_ISOCEXT */



__MINGW_GNU_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
int fprintf (FILE *__stream, const char *__format, ...)
__MINGW_ASM_CALL(__mingw_fprintf);

__MINGW_GNU_PRINTF(1, 2) __MINGW_ATTRIB_NONNULL(1)
int printf (const char *__format, ...)
__MINGW_ASM_CALL(__mingw_printf);

__MINGW_GNU_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
int sprintf (char *__stream, const char *__format, ...)
__MINGW_ASM_CALL(__mingw_sprintf);

#if __MINGW_FORTIFY_VA_ARG

__mingw_bos_extern_ovr
__MINGW_GNU_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
int sprintf (char *__stream, const char *__format, ...)
{
  if (__mingw_bos_known(__stream)) {
    int __retval = __mingw_snprintf( __stream, __mingw_bos(__stream, 1), __format, __builtin_va_arg_pack() );
    if (__retval >= 0)
      __mingw_bos_ptr_chk(__stream, (size_t)__retval + 1, 1);
    return __retval;
  }
  return __mingw_sprintf( __stream, __format, __builtin_va_arg_pack() );
}

#endif /* __MINGW_FORTIFY_VA_ARG */

__MINGW_GNU_PRINTF(2, 0) __MINGW_ATTRIB_NONNULL(2)
int vfprintf (FILE *__stream, const char *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vfprintf);

__MINGW_GNU_PRINTF(1, 0) __MINGW_ATTRIB_NONNULL(1)
int vprintf (const char *__format, __builtin_va_list __local_argv)
__MINGW_ASM_CALL(__mingw_vprintf);

__mingw_bos_ovr
__MINGW_GNU_PRINTF(2, 0) __MINGW_ATTRIB_NONNULL(2)
int vsprintf (char *__stream, const char *__format, __builtin_va_list __local_argv)
{
#if __MINGW_FORTIFY_LEVEL > 0
  if (__mingw_bos_known(__stream)) {
    int __retval = __mingw_vsnprintf( __stream, __mingw_bos(__stream, 1), __format, __local_argv );
    if (__retval >= 0)
      __mingw_bos_ptr_chk(__stream, (size_t)__retval + 1, 1);
    return __retval;
  }
#endif
  return __mingw_vsprintf( __stream, __format, __local_argv );
}
/* #ifndef __NO_ISOCEXT */  /* externs in libmingwex.a */

__MINGW_GNU_PRINTF(3, 4) __MINGW_ATTRIB_NONNULL(3)
int snprintf (char *__stream, size_t __n, const char *__format, ...)
__MINGW_ASM_CALL(__mingw_snprintf);

#if __MINGW_FORTIFY_VA_ARG

__mingw_bos_extern_ovr
__MINGW_GNU_PRINTF(3, 4) __MINGW_ATTRIB_NONNULL(3)
int snprintf (char *__stream, size_t __n, const char *__format, ...)
{
  __mingw_bos_ptr_chk_warn(__stream, __n, 1);
  return __mingw_snprintf( __stream, __n, __format, __builtin_va_arg_pack() );
}

#endif /* __MINGW_FORTIFY_VA_ARG */

__mingw_bos_ovr
__MINGW_GNU_PRINTF(3, 0) __MINGW_ATTRIB_NONNULL(3)
int vsnprintf (char *__stream, size_t __n, const char *__format, __builtin_va_list __local_argv)
{
#if __MINGW_FORTIFY_LEVEL > 0
  __mingw_bos_ptr_chk_warn(__stream, __n, 1);
#endif
  return __mingw_vsnprintf( __stream, __n, __format, __local_argv );
}

/* Override __builtin_printf-routines ... Kludge for libstdc++ ...*/
#define __builtin_vsnprintf __mingw_vsnprintf
#define __builtin_vsprintf __mingw_vsprintf

/* #endif */ /* __NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#else /* !__USE_MINGW_ANSI_STDIO */

#undef __builtin_vsnprintf
#undef __builtin_vsprintf

/*
 * Default configuration: simply direct all calls to MSVCRT...
 */
#ifdef _UCRT
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl fprintf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl printf(const char * __restrict__ _Format,...);
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl sprintf(char * __restrict__ _Dest,const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl vfprintf(FILE * __restrict__ _File,const char * __restrict__ _Format,va_list _ArgList);
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl vprintf(const char * __restrict__ _Format,va_list _ArgList);
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl vsprintf(char * __restrict__ _Dest,const char * __restrict__ _Format,va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  __attribute__((__format__ (__MINGW_SCANF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
  __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  __attribute__((__format__ (__MINGW_SCANF_FORMAT, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl scanf(const char * __restrict__ _Format,...);
  __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  __attribute__((__format__ (__MINGW_SCANF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl sscanf(const char * __restrict__ _Src,const char * __restrict__ _Format,...);
#ifdef _GNU_SOURCE
  __attribute__ ((__format__ (__MINGW_PRINTF_FORMAT, 2, 0)))
  int __cdecl vasprintf(char ** __restrict__ _Ret,const char * __restrict__ _Format,va_list _Args);
  __attribute__ ((__format__ (__MINGW_PRINTF_FORMAT, 2, 3)))
  int __cdecl asprintf(char ** __restrict__ _Ret,const char * __restrict__ _Format,...);
#endif /*_GNU_SOURCE*/

  __attribute__((__format__ (__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
  int vfscanf (FILE *__stream,  const char *__format, __builtin_va_list __local_argv);

  __attribute__((__format__ (__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
  int vsscanf (const char * __restrict__ __source, const char * __restrict__ __format, __builtin_va_list __local_argv);
  __attribute__((__format__ (__MINGW_SCANF_FORMAT, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
  int vscanf(const char *__format,  __builtin_va_list __local_argv);

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#else
  __MINGW_MS_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl fprintf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
  __MINGW_MS_PRINTF(1, 2) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl printf(const char * __restrict__ _Format,...);
  __MINGW_MS_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl sprintf(char * __restrict__ _Dest,const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  __MINGW_MS_PRINTF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl vfprintf(FILE * __restrict__ _File,const char * __restrict__ _Format,va_list _ArgList);
  __MINGW_MS_PRINTF(1, 0) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl vprintf(const char * __restrict__ _Format,va_list _ArgList);
  __MINGW_MS_PRINTF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl vsprintf(char * __restrict__ _Dest,const char * __restrict__ _Format,va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  __MINGW_MS_SCANF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_MS_SCANF(1, 2) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl scanf(const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_MS_SCANF(2, 3) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl sscanf(const char * __restrict__ _Src,const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef _GNU_SOURCE
  int __cdecl vasprintf(char ** __restrict__ __ret,const char * __restrict__ __format,va_list __ap)  __attribute__ ((format (__MINGW_PRINTF_FORMAT, 2, 0)));
  int __cdecl asprintf(char ** __restrict__ __ret,const char * __restrict__ __format,...) __attribute__ ((format (__MINGW_PRINTF_FORMAT, 2, 3)));
#endif /*_GNU_SOURCE*/
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif

  __MINGW_MS_SCANF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int vfscanf (FILE *__stream,  const char *__format, __builtin_va_list __local_argv);
  __MINGW_MS_SCANF(2, 0) __MINGW_ATTRIB_NONNULL(2)
  int vsscanf (const char * __restrict__ __source, const char * __restrict__ __format, __builtin_va_list __local_argv);
  __MINGW_MS_SCANF(1, 0) __MINGW_ATTRIB_NONNULL(1)
  int vscanf(const char *__format,  __builtin_va_list __local_argv);

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#endif /* __NO_ISOCEXT */
#endif /* _UCRT */
#endif /* __USE_MINGW_ANSI_STDIO */

  _CRTIMP int __cdecl _filbuf(FILE *_File);
  _CRTIMP int __cdecl _flsbuf(int _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(const char *_Filename,const char *_Mode);
#else
  _CRTIMP FILE *__cdecl _fsopen(const char *_Filename,const char *_Mode,int _ShFlag);
#endif
  void __cdecl clearerr(FILE *_File);
  int __cdecl fclose(FILE *_File);
  _CRTIMP int __cdecl _fcloseall(void);
#ifdef _POSIX_
  FILE *__cdecl fdopen(int _FileHandle,const char *_Mode) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#else
  _CRTIMP FILE *__cdecl _fdopen(int _FileHandle,const char *_Mode);
#endif
  int __cdecl feof(FILE *_File);
  int __cdecl ferror(FILE *_File);
  int __cdecl fflush(FILE *_File);
  int __cdecl fgetc(FILE *_File);
  _CRTIMP int __cdecl _fgetchar(void);
  int __cdecl fgetpos(FILE * __restrict__ _File ,fpos_t * __restrict__ _Pos); /* 64bit only, no 32bit version */
  int __cdecl fgetpos64(FILE * __restrict__ _File ,fpos_t * __restrict__ _Pos); /* fgetpos already 64bit */
  char *__cdecl fgets(char * __restrict__ _Buf,int _MaxCount,FILE * __restrict__ _File);
  _CRTIMP int __cdecl _fileno(FILE *_File);
#ifdef _POSIX_
  int __cdecl fileno(FILE *_File) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_tempnam")
#undef _tempnam
#endif
  _CRTIMP char *__cdecl _tempnam(const char *_DirName,const char *_FilePrefix);
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_tempnam")
#endif
  _CRTIMP int __cdecl _flushall(void);
  FILE *__cdecl fopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  FILE *__cdecl fopen64(const char * __restrict__ filename,const char * __restrict__  mode);
  int __cdecl fputc(int _Ch,FILE *_File);
  _CRTIMP int __cdecl _fputchar(int _Ch);
  int __cdecl fputs(const char * __restrict__ _Str,FILE * __restrict__ _File);
  size_t __cdecl fread(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
  FILE *__cdecl freopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode,FILE * __restrict__ _File) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  FILE *__cdecl freopen64(const char * __restrict__ _Filename,const char * __restrict__ _Mode,FILE * __restrict__ _File);
  int __cdecl fsetpos(FILE *_File,const fpos_t *_Pos);
  int __cdecl fsetpos64(FILE *_File,const fpos_t *_Pos); /* fsetpos already 64bit */
  int __cdecl fseek(FILE *_File,long _Offset,int _Origin);
  long __cdecl ftell(FILE *_File);

  _CRTIMP int __cdecl _fseeki64(FILE *_File,__int64 _Offset,int _Origin);
  _CRTIMP __int64 __cdecl _ftelli64(FILE *_File);
#if (defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64))
  int __cdecl fseeko(FILE *_File, _off64_t _Offset, int _Origin) __MINGW_ASM_CALL(fseeko64);
#else
  int __cdecl fseeko(FILE *_File, _off_t _Offset, int _Origin);
#endif
  _CRTIMP int __cdecl fseeko64(FILE *_File, _off64_t _Offset, int _Origin);
#if (defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64))
  _off64_t __cdecl ftello(FILE *_File) __MINGW_ASM_CALL(ftello64);
#else
  _off_t __cdecl ftello(FILE *_File);
#endif
  _CRTIMP _off64_t __cdecl ftello64(FILE *_File);

  size_t __cdecl fwrite(const void * __restrict__ _Str,size_t _Size,size_t _Count,FILE * __restrict__ _File);
  int __cdecl getc(FILE *_File);
  int __cdecl getchar(void);
  _CRTIMP int __cdecl _getmaxstdio(void);
  char *__cdecl gets(char *_Buffer)
#ifndef _CRTBLD
    __attribute__((__warning__("Using gets() is always unsafe - use fgets() instead")))
#endif
;
  int __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  void __cdecl perror(const char *_ErrMsg);
#endif
#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  _CRTIMP int __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(const char *_Command,const char *_Mode);
#if !defined(NO_OLDNAMES) && !defined(popen)
#define popen	_popen
#define pclose	_pclose
#endif
#endif /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */
  int __cdecl putc(int _Ch,FILE *_File);
  int __cdecl putchar(int _Ch);
  int __cdecl puts(const char *_Str);
  _CRTIMP int __cdecl _putw(int _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  int __cdecl remove(const char *_Filename);
  int __cdecl rename(const char *_OldFilename,const char *_NewFilename);
  _CRTIMP int __cdecl _unlink(const char *_Filename);
#ifndef	NO_OLDNAMES
  int __cdecl unlink(const char *_Filename) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif
#endif
  void __cdecl rewind(FILE *_File);
  _CRTIMP int __cdecl _rmtmp(void);
  void __cdecl setbuf(FILE * __restrict__ _File,char * __restrict__ _Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _setmaxstdio(int _Max);
  _CRTIMP unsigned int __cdecl _set_output_format(unsigned int _Format);
  _CRTIMP unsigned int __cdecl _get_output_format(void);
  int __cdecl setvbuf(FILE * __restrict__ _File,char * __restrict__ _Buf,int _Mode,size_t _Size);
#ifdef _UCRT
  __MINGW_ATTRIB_PURE
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
  int __cdecl _scprintf(const char * __restrict__ _Format,...);
  __attribute__((__format__ (__MINGW_SCANF_FORMAT, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl _snscanf(const char * __restrict__ _Src,size_t _MaxCount,const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#else
  __MINGW_ATTRIB_PURE
  __MINGW_MS_PRINTF(1, 2) __MINGW_ATTRIB_NONNULL(1)
  _CRTIMP int __cdecl _scprintf(const char * __restrict__ _Format,...);
  __MINGW_MS_SCANF(3, 4) __MINGW_ATTRIB_NONNULL(3)
  _CRTIMP int __cdecl _snscanf(const char * __restrict__ _Src,size_t _MaxCount,const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif
  __MINGW_ATTRIB_PURE
  __MINGW_MS_PRINTF(1, 0) __MINGW_ATTRIB_NONNULL(1)
  _CRTIMP int __cdecl _vscprintf(const char * __restrict__ _Format,va_list _ArgList);
  FILE *__cdecl tmpfile(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  FILE *__cdecl tmpfile64(void);
  char *__cdecl tmpnam(char *_Buffer);
  int __cdecl ungetc(int _Ch,FILE *_File);

#ifdef _UCRT
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl _vsnprintf(char * __restrict__ _Dest,size_t _Count,const char * __restrict__ _Format,va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl _snprintf(char * __restrict__ _Dest,size_t _Count,const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#else
  __MINGW_MS_PRINTF(3, 4) __MINGW_ATTRIB_NONNULL(3)
  _CRTIMP int __cdecl _snprintf(char * __restrict__ _Dest,size_t _Count,const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_MS_PRINTF(3, 0) __MINGW_ATTRIB_NONNULL(3)
  _CRTIMP int __cdecl _vsnprintf(char * __restrict__ _Dest,size_t _Count,const char * __restrict__ _Format,va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif

#if __MINGW_FORTIFY_LEVEL > 0

char * __cdecl __gets_chk(char *, size_t);
char * __cdecl __mingw_call_gets_warn(char *) __MINGW_ASM_CALL(gets)
  __attribute__((__warning__("Using gets() is always unsafe - use fgets() instead")));
char * __cdecl __mingw_call_fgets(char * __restrict__, int, FILE * __restrict__) __MINGW_ASM_CALL(fgets);
size_t __cdecl __mingw_call_fread(void * __restrict__, size_t, size_t, FILE * __restrict__) __MINGW_ASM_CALL(fread);
char * __cdecl __mingw_call_tmpnam(char *) __MINGW_ASM_CALL(tmpnam);

__mingw_bos_extern_ovr
char * gets(char * __dst)
{
  if (__mingw_bos_known(__dst))
    return __gets_chk(__dst, __mingw_bos(__dst, 1));
  return __mingw_call_gets_warn(__dst);
}

__mingw_bos_extern_ovr
char * fgets(char * __restrict__ __dst, int __n, FILE * __restrict__ __f)
{
  __mingw_bos_ptr_chk_warn(__dst, __n, 1);
  return __mingw_call_fgets(__dst, __n, __f);
}

__mingw_bos_extern_ovr
size_t fread(void * __restrict__ __dst, size_t __sz, size_t __n, FILE * __restrict__ __f)
{
  __mingw_bos_ptr_chk_warn(__dst, __sz * __n, 0);
  return __mingw_call_fread(__dst, __sz, __n, __f);
}

__mingw_bos_extern_ovr
char * tmpnam(char * __dst)
{
  __mingw_bos_ptr_chk_warn(__dst, L_tmpnam, 1);
  return __mingw_call_tmpnam(__dst);
}

#endif /* __MINGW_FORTIFY_LEVEL > 0 */

#if __USE_MINGW_ANSI_STDIO == 0

#ifdef _UCRT
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
  int vsnprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, va_list __local_argv);

  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
  int snprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, ...);

#if __MINGW_FORTIFY_LEVEL > 0

  int __cdecl __mingw_call_vsprintf (char * __restrict__ __stream, const char * __restrict__ __format, va_list __local_argv) __MINGW_ASM_CALL(vsprintf);
  int __cdecl __mingw_call_vsnprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, va_list __local_argv) __MINGW_ASM_CALL(vsnprintf);

  __mingw_bos_extern_ovr
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(3)
  int vsprintf (char * __restrict__ __stream, const char * __restrict__ __format, va_list __local_argv)
  {
    if (__mingw_bos_known(__stream)) {
      int __retval = __mingw_call_vsnprintf (__stream, __mingw_bos(__stream, 1), __format, __local_argv);
      if (__retval >= 0)
        __mingw_bos_ptr_chk(__stream, (size_t)__retval + 1, 1);
      return __retval;
    }
    return __mingw_call_vsprintf(__stream, __format, __local_argv);
  }

  __mingw_bos_extern_ovr
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
  int vsnprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, va_list __local_argv)
  {
    __mingw_bos_ptr_chk_warn(__stream, __n, 1);
    return __mingw_call_vsnprintf (__stream, __n, __format, __local_argv);
  }

#endif /* __MINGW_FORTIFY_LEVEL > 0 */

#if __MINGW_FORTIFY_VA_ARG

  int __cdecl __mingw_call_sprintf (char * __restrict__ __stream, const char * __restrict__ __Format, ...) __MINGW_ASM_CALL(sprintf);
  int __cdecl __mingw_call_snprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, ...) __MINGW_ASM_CALL(snprintf);

  __mingw_bos_extern_ovr
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
  int sprintf (char * __restrict__ __stream, const char * __restrict__ __format, ...)
  {
    if (__mingw_bos_known(__stream)) {
      int __retval = __mingw_call_snprintf (__stream, __mingw_bos(__stream, 1), __format, __builtin_va_arg_pack());
      if (__retval >= 0)
        __mingw_bos_ptr_chk(__stream, (size_t)__retval + 1, 1);
      return __retval;
    }
    return __mingw_call_sprintf (__stream, __format, __builtin_va_arg_pack());
  }

  __mingw_bos_extern_ovr
  __attribute__((__format__ (__MINGW_PRINTF_FORMAT, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
  int snprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, ...)
  {
    __mingw_bos_ptr_chk_warn(__stream, __n, 1);
    return __mingw_call_snprintf (__stream, __n, __format, __builtin_va_arg_pack());
  }

#endif /* __MINGW_FORTIFY_VA_ARG */

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
#else /* !_UCRT */

/* this is here to deal with software defining
 * vsnprintf as _vsnprintf, eg. libxml2.  */

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif

  __mingw_bos_ovr
  __MINGW_MS_PRINTF(3, 0) __MINGW_ATTRIB_NONNULL(3)
  int vsnprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, va_list __local_argv)
  {
#if __MINGW_FORTIFY_LEVEL > 0
    __mingw_bos_ptr_chk_warn(__stream, __n, 1);
#endif
    if (__builtin_constant_p(__n) && __n == 0)
      return _vscprintf(__format, __local_argv);
    return __ms_vsnprintf (__stream, __n, __format, __local_argv);
  }

#ifndef __NO_ISOCEXT
#if __MINGW_FORTIFY_VA_ARG

int snprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, ...) __MINGW_ASM_CALL(__ms_snprintf);

__mingw_bos_extern_ovr
__MINGW_MS_PRINTF(3, 4) __MINGW_ATTRIB_NONNULL(3)
int snprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, ...)
{
  __mingw_bos_ptr_chk_warn(__stream, __n, 1);
  if (__builtin_constant_p(__n) && __n == 0)
    return _scprintf(__format, __builtin_va_arg_pack());
  return __ms_snprintf(__stream, __n, __format, __builtin_va_arg_pack());
}

#else /* !__MINGW_FORTIFY_VA_ARG */

__mingw_ovr
__MINGW_MS_PRINTF(3, 4) __MINGW_ATTRIB_NONNULL(3)
int snprintf (char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, ...)
{
  int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  if (__builtin_constant_p(__n) && __n == 0)
    __retval = _vscprintf(__format, __local_argv);
  else
    __retval = __ms_vsnprintf (__stream, __n, __format, __local_argv);
  __builtin_va_end( __local_argv );
  return __retval;
}

#endif /* !__MINGW_FORTIFY_VA_ARG */
#endif /* !__NO_ISOCEXT */

#if __MINGW_FORTIFY_VA_ARG

int __cdecl __mingw_call_ms_sprintf(char * __restrict__, const char * __restrict__, ...) __MINGW_ASM_CALL(sprintf);

__mingw_bos_extern_ovr
__MINGW_MS_PRINTF(2, 3) __MINGW_ATTRIB_NONNULL(2)
int sprintf (char * __restrict__ __stream, const char * __restrict__ __format, ...)
{
  if (__mingw_bos_known(__stream)) {
    int __retval = __ms_snprintf( __stream, __mingw_bos(__stream, 1), __format, __builtin_va_arg_pack() );
    if (__retval >= 0)
      __mingw_bos_ptr_chk(__stream, (size_t)__retval + 1, 1);
    return __retval;
  }
  return __mingw_call_ms_sprintf( __stream, __format, __builtin_va_arg_pack() );
}

#endif /* __MINGW_FORTIFY_VA_ARG */

#if __MINGW_FORTIFY_LEVEL > 0

int __cdecl __mingw_call_ms_vsprintf(char * __restrict__, const char * __restrict__, va_list) __MINGW_ASM_CALL(vsprintf);

__mingw_bos_extern_ovr
__MINGW_MS_PRINTF(2, 0) __MINGW_ATTRIB_NONNULL(2)
int vsprintf (char * __restrict__ __stream, const char * __restrict__ __format, va_list __local_argv)
{
  if (__mingw_bos_known(__stream)) {
    int __retval = __ms_vsnprintf( __stream, __mingw_bos(__stream, 1), __format, __local_argv );
    if (__retval >= 0)
      __mingw_bos_ptr_chk(__stream, (size_t)__retval + 1, 1);
    return __retval;
  }
  return __mingw_call_ms_vsprintf( __stream, __format, __local_argv );
}

#endif /* __MINGW_FORTIFY_LEVEL > 0 */

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
#endif /* _UCRT */
#endif /* __USE_MINGW_ANSI_STDIO */

  _CRTIMP int __cdecl _set_printf_count_output(int _Value);
  _CRTIMP int __cdecl _get_printf_count_output(void);

  _CRTIMP int __cdecl _fgetc_nolock(FILE *_File);
  _CRTIMP int __cdecl _fputc_nolock(int _Char, FILE *_File);
  _CRTIMP int __cdecl _getc_nolock(FILE *_File);
  _CRTIMP int __cdecl _putc_nolock(int _Char, FILE *_File);
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP void __cdecl _lock_file(FILE *_File);
  _CRTIMP void __cdecl _unlock_file(FILE *_File);
#if __MSVCRT_VERSION__ >= 0x800
  _CRTIMP int __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP int __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
  _CRTIMP int __cdecl _fseek_nolock(FILE *_File,long _Offset,int _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  __MINGW_EXTENSION _CRTIMP int __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,int _Origin);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(const void * __restrict__ _DstBuf,size_t _Size,size_t _Count,FILE * __restrict__ _File);
  _CRTIMP int __cdecl _ungetc_nolock(int _Ch,FILE *_File);
#endif

#if !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("tempnam")
#undef tempnam
#endif
  char *__cdecl tempnam(const char *_Directory,const char *_FilePrefix) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("tempnam")
#endif
  int __cdecl fcloseall(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  FILE *__cdecl fdopen(int _FileHandle,const char *_Format) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl fgetchar(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl fileno(FILE *_File) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl flushall(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl fputchar(int _Ch) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl getw(FILE *_File) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl putw(int _Ch,FILE *_File) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl rmtmp(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif

#pragma pop_macro("snprintf")
#pragma pop_macro("vsnprintf")
#pragma pop_macro("snwprintf")
#pragma pop_macro("vsnwprintf")

_CRT_END_C_HEADER

#include <sec_api/stdio_s.h>

#endif
