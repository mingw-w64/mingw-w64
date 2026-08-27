/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WCHAR_S
#define _INC_WCHAR_S

#include <wchar.h>

_CRT_BEGIN_C_HEADER

  _SECIMP errno_t __cdecl _waccess_s (const wchar_t *_Filename,int _AccessMode);
  _SECIMP errno_t __cdecl _wmktemp_s (wchar_t *_TemplateName,size_t _SizeInWords);

#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,const wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t _SizeInWords,int _ErrNum);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wcserror_s, wchar_t, _Buf, int, _ErrNum)
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t _SizeInWords,const wchar_t *_ErrMsg);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, __wcserror_s, wchar_t, _Buffer, const wchar_t *, _ErrMsg)
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t _DstSizeInWords,wchar_t _Val,size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, _wcsnset_s, wchar_t, _Dst, wchar_t, _Val, size_t, _MaxCount)
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t _SizeInWords,wchar_t _Val);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wcsset_s, wchar_t, _Str, wchar_t, _Val)
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wcslwr_s, wchar_t, _Str)
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t _SizeInWords,_locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wcslwr_s_l, wchar_t, _Str, _locale_t, _Locale)
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wcsupr_s, wchar_t, _Str)
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wcsupr_s_l, wchar_t, _Str, _locale_t, _Locale)

  _CRTIMP errno_t __cdecl wcscat_s(wchar_t *_Dst, rsize_t _DstSize, const wchar_t *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, wcscat_s, wchar_t, _Dest, const wchar_t *, _Source)
  _CRTIMP errno_t __cdecl wcscpy_s(wchar_t *_Dst, rsize_t _DstSize, const wchar_t *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, wcscpy_s, wchar_t, _Dest, const wchar_t *, _Source)

  _CRTIMP errno_t __cdecl wcsncat_s(wchar_t *_Dst,size_t _DstSizeInChars,const wchar_t *_Src,size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, wcsncat_s, wchar_t, _Dst, const wchar_t *, _Src, size_t, _MaxCount)
  _CRTIMP errno_t __cdecl _wcsncat_s_l(wchar_t *_Dst,size_t _DstSizeInChars,const wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(errno_t, _wcsncat_s_l, wchar_t, _Dst, const wchar_t *, _Src, size_t, _MaxCount, _locale_t, _Locale)
  _CRTIMP errno_t __cdecl wcsncpy_s(wchar_t *_Dst,size_t _DstSizeInChars,const wchar_t *_Src,size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, wcsncpy_s, wchar_t, _Dst, const wchar_t *, _Src, size_t, _MaxCount)
  _CRTIMP errno_t __cdecl _wcsncpy_s_l(wchar_t *_Dst,size_t _DstSizeInChars,const wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(errno_t, _wcsncpy_s_l, wchar_t, _Dst, const wchar_t *, _Src, size_t, _MaxCount, _locale_t, _Locale)
  _CRTIMP wchar_t *__cdecl _wcstok_s_l(wchar_t *_Str,const wchar_t *_Delim,wchar_t **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsset_s_l(wchar_t *_Str,size_t _SizeInChars,wchar_t _Val,_locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, _wcsset_s_l, wchar_t, _Str, wchar_t, _Val, _locale_t, _Locale)
  _CRTIMP errno_t __cdecl _wcsnset_s_l(wchar_t *_Str,size_t _SizeInChars,wchar_t _Val, size_t _Count,_locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(errno_t, _wcsnset_s_l, wchar_t, _Str, wchar_t, _Val, size_t, _Count, _locale_t, _Locale)

  __forceinline size_t __cdecl wcsnlen_s(const wchar_t * _src, size_t _count) {
    return _src ? wcsnlen(_src, _count) : 0;
  }
#endif

  _SECIMP errno_t __cdecl _wasctime_s (wchar_t *_Buf,size_t _SizeInWords,const struct tm *_Tm);
  _SECIMP errno_t __cdecl _wctime32_s (wchar_t *_Buf,size_t _SizeInWords,const __time32_t *_Time);
  _SECIMP errno_t __cdecl _wstrdate_s (wchar_t *_Buf,size_t _SizeInWords);
  _SECIMP errno_t __cdecl _wstrtime_s (wchar_t *_Buf,size_t _SizeInWords);
  _SECIMP errno_t __cdecl _wctime64_s (wchar_t *_Buf,size_t _SizeInWords,const __time64_t *_Time);

#if !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
  errno_t __cdecl _wctime_s(wchar_t *, size_t, const time_t *);
#ifndef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,const time_t *_Time) { return _wctime64_s(_Buffer,_SizeInWords,_Time); }
#endif
#endif

  _CRTIMP errno_t __cdecl mbsrtowcs_s(size_t *_Retval,wchar_t *_Dst,size_t _SizeInWords,const char **_PSrc,size_t _N,mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t,mbsrtowcs_s,size_t*,_Retval,wchar_t,_Dst,const char**,_PSrc,size_t,_N,mbstate_t,_State)

  _CRTIMP errno_t __cdecl wcrtomb_s(size_t *_Retval,char *_Dst,size_t _SizeInBytes,wchar_t _Ch,mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(errno_t,wcrtomb_s,size_t*,_Retval,char,_Dst,wchar_t,_Ch,mbstate_t,_State)

  _CRTIMP errno_t __cdecl wcsrtombs_s(size_t *_Retval,char *_Dst,size_t _SizeInBytes,const wchar_t **_Src,size_t _Size,mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t,wcsrtombs_s,size_t,_Retval,char,_Dst,const wchar_t**,_Src,size_t,_Size,mbstate_t,_State)

  _SECIMP errno_t __cdecl wmemcpy_s (wchar_t *_dest,size_t _numberOfElements,const wchar_t *_src,size_t _count);
  _SECIMP errno_t __cdecl wmemmove_s(wchar_t *_dest,size_t _numberOfElements,const wchar_t *_src,size_t _count);


_CRT_END_C_HEADER

#endif
