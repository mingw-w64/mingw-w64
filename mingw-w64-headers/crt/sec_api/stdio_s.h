/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#include <stdio.h>

_CRT_BEGIN_C_HEADER

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  #define L_tmpnam_s L_tmpnam
  #define TMP_MAX_S TMP_MAX

  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);

  size_t __cdecl fread_s(void *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);

#ifdef _UCRT
  int __cdecl __stdio_common_vsprintf_s(unsigned __int64 _Options, char *_Str, size_t _Len, const char *_Format, _locale_t _Locale, va_list _ArgList);
  int __cdecl __stdio_common_vsprintf_p(unsigned __int64 _Options, char *_Str, size_t _Len, const char *_Format, _locale_t _Locale, va_list _ArgList);
  int __cdecl __stdio_common_vsnprintf_s(unsigned __int64 _Options, char *_Str, size_t _Len, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
  int __cdecl __stdio_common_vfprintf_s(unsigned __int64 _Options, FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList);
  int __cdecl __stdio_common_vfprintf_p(unsigned __int64 _Options, FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr int __cdecl _vfscanf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_SCANF_SECURECRT, _File, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl vfscanf_s(FILE *_File, const char *_Format, va_list _ArgList)
  {
    return _vfscanf_s_l(_File, _Format, NULL, _ArgList);
  }

  __mingw_ovr int __cdecl _vscanf_s_l(const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vfscanf_s_l(stdin, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl vscanf_s(const char *_Format, va_list _ArgList)
  {
    return _vfscanf_s_l(stdin, _Format, NULL, _ArgList);
  }

  __mingw_ovr int __cdecl _fscanf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfscanf_s_l(_File, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl fscanf_s(FILE *_File, const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vfscanf_s_l(_File, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _scanf_s_l(const char *_Format, _locale_t _Locale ,...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfscanf_s_l(stdin, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl scanf_s(const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vfscanf_s_l(stdin, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vfscanf_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(0, _File, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vscanf_l(const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vfscanf_l(stdin, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _fscanf_l(FILE *_File, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfscanf_l(_File, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _scanf_l(const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfscanf_l(stdin, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vsscanf_s_l(const char *_Src, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Src, (size_t)-1, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl vsscanf_s(const char *_Src, const char *_Format, va_list _ArgList)
  {
    return _vsscanf_s_l(_Src, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _sscanf_s_l(const char *_Src, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsscanf_s_l(_Src, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl sscanf_s(const char *_Src, const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vsscanf_s_l(_Src, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vsscanf_l(const char *_Src, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsscanf(0, _Src, (size_t)-1, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _sscanf_l(const char *_Src, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsscanf_l(_Src, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  /* There is no _vsnscanf_s_l nor _vsnscanf_s */
  __mingw_ovr int __cdecl _snscanf_s_l(const char *_Src, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Src, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _snscanf_s(const char *_Src, size_t _MaxCount, const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Src, _MaxCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  /* There is no _vsnscanf_l */
  __mingw_ovr int __cdecl _snscanf_l(const char *_Src, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(0, _Src, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }


  __mingw_ovr int __cdecl _vfprintf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _File, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl vfprintf_s(FILE *_File, const char *_Format, va_list _ArgList)
  {
    return _vfprintf_s_l(_File, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _vprintf_s_l(const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vfprintf_s_l(stdout, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl vprintf_s(const char *_Format, va_list _ArgList)
  {
    return _vfprintf_s_l(stdout, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _fprintf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfprintf_s_l(_File, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _printf_s_l(const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfprintf_s_l(stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl fprintf_s(FILE *_File, const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vfprintf_s_l(_File, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl printf_s(const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vfprintf_s_l(stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vsnprintf_c_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vsnprintf_c(char *_DstBuf, size_t _MaxCount, const char *_Format, va_list _ArgList)
  {
    return _vsnprintf_c_l(_DstBuf, _MaxCount, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _snprintf_c_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsnprintf_c_l(_DstBuf, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _snprintf_c(char *_DstBuf, size_t _MaxCount, const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vsnprintf_c_l(_DstBuf, _MaxCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vsnprintf_s_l(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsnprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _DstBuf, _DstSize, _MaxCount, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl vsnprintf_s(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, va_list _ArgList)
  {
    return _vsnprintf_s_l(_DstBuf, _DstSize, _MaxCount, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _vsnprintf_s(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, va_list _ArgList)
  {
    return _vsnprintf_s_l(_DstBuf, _DstSize, _MaxCount, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _snprintf_s_l(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsnprintf_s_l(_DstBuf, _DstSize, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _snprintf_s(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vsnprintf_s_l(_DstBuf, _DstSize, _MaxCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vsprintf_s_l(char *_DstBuf, size_t _DstSize, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _DstBuf, _DstSize, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl vsprintf_s(char *_DstBuf, size_t _Size, const char *_Format, va_list _ArgList)
  {
    return _vsprintf_s_l(_DstBuf, _Size, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _sprintf_s_l(char *_DstBuf, size_t _DstSize, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsprintf_s_l(_DstBuf, _DstSize, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl sprintf_s(char *_DstBuf, size_t _DstSize, const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vsprintf_s_l(_DstBuf, _DstSize, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vfprintf_p_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _File, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vfprintf_p(FILE *_File, const char *_Format, va_list _ArgList)
  {
    return _vfprintf_p_l(_File, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _vprintf_p_l(const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vfprintf_p_l(stdout, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vprintf_p(const char *_Format, va_list _ArgList)
  {
    return _vfprintf_p_l(stdout, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _fprintf_p_l(FILE *_File, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _File, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _fprintf_p(FILE *_File, const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vfprintf_p_l(_File, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _printf_p_l(const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfprintf_p_l(stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _printf_p(const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vfprintf_p_l(stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vsprintf_p_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vsprintf_p(char *_Dst, size_t _MaxCount, const char *_Format, va_list _ArgList)
  {
    return _vsprintf_p_l(_Dst, _MaxCount, _Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _sprintf_p_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsprintf_p_l(_DstBuf, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _sprintf_p(char *_Dst, size_t _MaxCount, const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vsprintf_p_l(_Dst, _MaxCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vscprintf_p_l(const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsprintf_p(_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vscprintf_p(const char *_Format, va_list _ArgList)
  {
    return _vscprintf_p_l(_Format, NULL, _ArgList);
  }
  __mingw_ovr int __cdecl _scprintf_p_l(const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vscprintf_p_l(_Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _scprintf_p(const char *_Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = _vscprintf_p_l(_Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vfprintf_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _File, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _vprintf_l(const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vfprintf_l(stdout, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _fprintf_l(FILE *_File, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfprintf_l(_File, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _printf_l(const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vfprintf_l(stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vsnprintf_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsprintf(_CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _snprintf_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsnprintf_l(_DstBuf, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
  __mingw_ovr int __cdecl _vsprintf_l(char *_DstBuf, const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vsnprintf_l(_DstBuf, (size_t)-1, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _sprintf_l(char *_DstBuf, const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vsprintf_l(_DstBuf, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _vscprintf_l(const char *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsprintf(_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
  }
  __mingw_ovr int __cdecl _scprintf_l(const char *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = _vscprintf_l(_Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
#else /* _UCRT */
  int __cdecl fprintf_s(FILE *_File,const char *_Format,...);
  _CRTIMP int __cdecl _fscanf_s_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl fscanf_s(FILE *_File, const char *_Format, ...);
  int __cdecl printf_s(const char *_Format,...);
  _CRTIMP int __cdecl _scanf_l(const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _scanf_s_l(const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl scanf_s(const char *_Format, ...);
  _CRTIMP int __cdecl _snprintf_c(char *_DstBuf,size_t _MaxCount,const char *_Format,...);
  _CRTIMP int __cdecl _vsnprintf_c(char *_DstBuf,size_t _MaxCount,const char *_Format,va_list _ArgList);

  _CRTIMP int __cdecl _fscanf_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _sscanf_l(const char *_Src,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _sscanf_s_l(const char *_Src,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl sscanf_s(const char *_Src,const char *_Format,...);
  _CRTIMP int __cdecl _snscanf_s(const char *_Src,size_t _MaxCount,const char *_Format,...);
  _CRTIMP int __cdecl _snscanf_l(const char *_Src,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _snscanf_s_l(const char *_Src,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  int __cdecl vfprintf_s(FILE *_File,const char *_Format,va_list _ArgList);
  int __cdecl vprintf_s(const char *_Format,va_list _ArgList);

  int __cdecl vsnprintf_s(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,va_list _ArgList);

  _CRTIMP int __cdecl _vsnprintf_s(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,va_list _ArgList);

  _SECIMP int __cdecl vsprintf_s(char *_DstBuf,size_t _Size,const char *_Format,va_list _ArgList);

  _SECIMP int __cdecl sprintf_s(char *_DstBuf,size_t _DstSize,const char *_Format,...);

  _CRTIMP int __cdecl _snprintf_s(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,...);

  _CRTIMP int __cdecl _fprintf_p(FILE *_File,const char *_Format,...);
  _CRTIMP int __cdecl _printf_p(const char *_Format,...);
  _CRTIMP int __cdecl _sprintf_p(char *_Dst,size_t _MaxCount,const char *_Format,...);
  _CRTIMP int __cdecl _vfprintf_p(FILE *_File,const char *_Format,va_list _ArgList);
  _CRTIMP int __cdecl _vprintf_p(const char *_Format,va_list _ArgList);
  _CRTIMP int __cdecl _vsprintf_p(char *_Dst,size_t _MaxCount,const char *_Format,va_list _ArgList);
  _CRTIMP int __cdecl _scprintf_p(const char *_Format,...);
  _SECIMP int __cdecl _vscprintf_p(const char *_Format,va_list _ArgList);
  _CRTIMP int __cdecl _printf_l(const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _printf_p_l(const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vprintf_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _vprintf_p_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _fprintf_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _fprintf_p_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vfprintf_l(FILE *_File,const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _vfprintf_p_l(FILE *_File,const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _sprintf_l(char *_DstBuf,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _sprintf_p_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vsprintf_l(char *_DstBuf,const char *_Format,_locale_t,va_list _ArgList);
  _CRTIMP int __cdecl _vsprintf_p_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _scprintf_l(const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _scprintf_p_l(const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vscprintf_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _vscprintf_p_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _printf_s_l(const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vprintf_s_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _fprintf_s_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vfprintf_s_l(FILE *_File,const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _sprintf_s_l(char *_DstBuf,size_t _DstSize,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vsprintf_s_l(char *_DstBuf,size_t _DstSize,const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _snprintf_s_l(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vsnprintf_s_l(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _snprintf_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _snprintf_c_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  _CRTIMP int __cdecl _vsnprintf_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP int __cdecl _vsnprintf_c_l(char *_DstBuf,size_t _MaxCount,const char *,_locale_t _Locale,va_list _ArgList);
#endif /* !_UCRT */

  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int,vsnprintf_s,char,_DstBuf,size_t,_MaxCount,const char*,_Format,va_list,_ArgList)
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int,_vsnprintf_s,char,_DstBuf,size_t,_MaxCount,const char*,_Format,va_list,_ArgList)
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsprintf_s, char, _DstBuf, const char*, _Format, va_list, _ArgList)
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int,sprintf_s,vsprintf_s,char,_DstBuf,const char*,_Format)
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int,_snprintf_s,_vsnprintf_s,char,_DstBuf,size_t,_MaxCount,const char*,_Format)

  _CRTIMP errno_t __cdecl fopen_s(FILE **_File,const char *_Filename,const char *_Mode);
  _CRTIMP errno_t __cdecl freopen_s(FILE** _File, const char *_Filename, const char *_Mode, FILE *_Stream);

  _CRTIMP char* __cdecl gets_s(char*,rsize_t);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(char*,get_s,char,_DstBuf)

  _CRTIMP errno_t __cdecl tmpfile_s(FILE **_File);

  _CRTIMP errno_t __cdecl tmpnam_s(char*,rsize_t);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t,tmpnam_s,char,_DstBuf)

#endif /* _STDIO_S_DEFINED */

#if __MSVCRT_VERSION__ >= 0x800
  _CRTIMP size_t __cdecl _fread_nolock_s(void *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);
#endif

_CRT_END_C_HEADER

#endif
