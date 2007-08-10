/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <_mingw.h>

#ifndef _INC_TCHAR
#define _INC_TCHAR

#ifdef _STRSAFE_H_INCLUDED_
#error Need to include strsafe.h after tchar.h
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define _ftcscat _tcscat
#define _ftcschr _tcschr
#define _ftcscpy _tcscpy
#define _ftcscspn _tcscspn
#define _ftcslen _tcslen
#define _ftcsncat _tcsncat
#define _ftcsncpy _tcsncpy
#define _ftcspbrk _tcspbrk
#define _ftcsrchr _tcsrchr
#define _ftcsspn _tcsspn
#define _ftcsstr _tcsstr
#define _ftcstok _tcstok

#define _ftcsdup _tcsdup
#define _ftcsnset _tcsnset
#define _ftcsrev _tcsrev
#define _ftcsset _tcsset

#define _ftcscmp _tcscmp
#define _ftcsicmp _tcsicmp
#define _ftcsnccmp _tcsnccmp
#define _ftcsncmp _tcsncmp
#define _ftcsncicmp _tcsncicmp
#define _ftcsnicmp _tcsnicmp

#define _ftcscoll _tcscoll
#define _ftcsicoll _tcsicoll
#define _ftcsnccoll _tcsnccoll
#define _ftcsncoll _tcsncoll
#define _ftcsncicoll _tcsncicoll
#define _ftcsnicoll _tcsnicoll

#define _ftcsclen _tcsclen
#define _ftcsnccat _tcsnccat
#define _ftcsnccpy _tcsnccpy
#define _ftcsncset _tcsncset

#define _ftcsdec _tcsdec
#define _ftcsinc _tcsinc
#define _ftcsnbcnt _tcsnbcnt
#define _ftcsnccnt _tcsnccnt
#define _ftcsnextc _tcsnextc
#define _ftcsninc _tcsninc
#define _ftcsspnp _tcsspnp

#define _ftcslwr _tcslwr
#define _ftcsupr _tcsupr

#define _ftclen _tclen
#define _ftccpy _tccpy
#define _ftccmp _tccmp

#ifndef _CONST_RETURN
#ifdef __cplusplus
#define _CONST_RETURN const
#define _CRT_CONST_CORRECT_OVERLOADS
#else
#define _CONST_RETURN
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifdef _UNICODE

#ifdef __cplusplus
}
#endif

#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WCTYPE_T_DEFINED
#define _WCTYPE_T_DEFINED
  typedef unsigned short wint_t;
  typedef unsigned short wctype_t;
#endif

#ifndef __TCHAR_DEFINED
#define __TCHAR_DEFINED
  typedef wchar_t _TCHAR;
  typedef wchar_t _TSCHAR;
  typedef wchar_t _TUCHAR;
  typedef wchar_t _TXCHAR;
  typedef wint_t _TINT;
#endif

#ifndef _TCHAR_DEFINED
#define _TCHAR_DEFINED
#ifndef	NO_OLDNAMES
  typedef wchar_t TCHAR;
#endif
#endif

#define _TEOF WEOF

#define __T(x) L ## x

#define _tmain wmain
#define _tWinMain wWinMain
#define _tenviron _wenviron
#define __targv __wargv

#define _tprintf wprintf
#define _tprintf_l _wprintf_l
#define _tprintf_s wprintf_s
#define _tprintf_s_l _wprintf_s_l
#define _tprintf_p _wprintf_p
#define _tprintf_p_l _wprintf_p_l
#define _tcprintf _cwprintf
#define _tcprintf_l _cwprintf_l
#define _tcprintf_s _cwprintf_s
#define _tcprintf_s_l _cwprintf_s_l
#define _tcprintf_p _cwprintf_p
#define _tcprintf_p_l _cwprintf_p_l
#define _vtcprintf _vcwprintf
#define _vtcprintf_l _vcwprintf_l
#define _vtcprintf_s _vcwprintf_s
#define _vtcprintf_s_l _vcwprintf_s_l
#define _vtcprintf_p _vcwprintf_p
#define _vtcprintf_p_l _vcwprintf_p_l
#define _ftprintf fwprintf
#define _ftprintf_l _fwprintf_l
#define _ftprintf_s fwprintf_s
#define _ftprintf_s_l _fwprintf_s_l
#define _ftprintf_p _fwprintf_p
#define _ftprintf_p_l _fwprintf_p_l
#define _stprintf _swprintf
#define _stprintf_l __swprintf_l
#define _stprintf_s swprintf_s
#define _stprintf_s_l _swprintf_s_l
#define _stprintf_p _swprintf_p
#define _stprintf_p_l _swprintf_p_l
#define _sctprintf _scwprintf
#define _sctprintf_l _scwprintf_l
#define _sctprintf_p _scwprintf_p
#define _sctprintf_p_l _scwprintf_p_l
#define _sntprintf _snwprintf
#define _sntprintf_l _snwprintf_l
#define _sntprintf_s _snwprintf_s
#define _sntprintf_s_l _snwprintf_s_l
#define _vtprintf vwprintf
#define _vtprintf_l _vwprintf_l
#define _vtprintf_s vwprintf_s
#define _vtprintf_s_l _vwprintf_s_l
#define _vtprintf_p _vwprintf_p
#define _vtprintf_p_l _vwprintf_p_l
#define _vftprintf vfwprintf
#define _vftprintf_l _vfwprintf_l
#define _vftprintf_s vfwprintf_s
#define _vftprintf_s_l _vfwprintf_s_l
#define _vftprintf_p _vfwprintf_p
#define _vftprintf_p_l _vfwprintf_p_l
#define _vstprintf _vswprintf
#define _vstprintf_l _vswprintf_l
#define _vstprintf_s vswprintf_s
#define _vstprintf_s_l _vswprintf_s_l
#define _vstprintf_p _vswprintf_p
#define _vstprintf_p_l _vswprintf_p_l
#define _vsctprintf _vscwprintf
#define _vsctprintf_l _vscwprintf_l
#define _vsctprintf_p _vscwprintf_p
#define _vsctprintf_p_l _vscwprintf_p_l
#define _vsntprintf _vsnwprintf
#define _vsntprintf_l _vsnwprintf_l
#define _vsntprintf_s _vsnwprintf_s
#define _vsntprintf_s_l _vsnwprintf_s_l

#define _tscanf wscanf
#define _tscanf_l _wscanf_l
#define _tscanf_s wscanf_s
#define _tscanf_s_l _wscanf_s_l
#define _tcscanf _cwscanf
#define _tcscanf_l _cwscanf_l
#define _tcscanf_s _cwscanf_s
#define _tcscanf_s_l _cwscanf_s_l
#define _ftscanf fwscanf
#define _ftscanf_l _fwscanf_l
#define _ftscanf_s fwscanf_s
#define _ftscanf_s_l _fwscanf_s_l
#define _stscanf swscanf
#define _stscanf_l _swscanf_l
#define _stscanf_s swscanf_s
#define _stscanf_s_l _swscanf_s_l
#define _sntscanf _snwscanf
#define _sntscanf_l _snwscanf_l
#define _sntscanf_s _snwscanf_s
#define _sntscanf_s_l _snwscanf_s_l

#define _fgettc fgetwc
#define _fgettc_nolock _fgetwc_nolock
#define _fgettchar _fgetwchar
#define _fgetts fgetws
#define _fputtc fputwc
#define _fputtc_nolock _fputwc_nolock
#define _fputtchar _fputwchar
#define _fputts fputws
#define _cputts _cputws
#define _cgetts _cgetws
#define _cgetts_s _cgetws_s
#define _gettc getwc
#define _gettc_nolock _getwc_nolock
#define _gettch _getwch
#define _gettch_nolock _getwch_nolock
#define _gettche _getwche
#define _gettche_nolock _getwche_nolock
#define _gettchar getwchar
#define _gettchar_nolock _getwchar_nolock
#define _getts _getws
#define _getts_s _getws_s
#define _puttc putwc
#define _puttc_nolock _putwc_nolock
#define _puttchar putwchar
#define _puttchar_nolock _putwchar_nolock
#define _puttch _putwch
#define _puttch_nolock _putwch_nolock
#define _putts _putws
#define _ungettc ungetwc
#define _ungettc_nolock _ungetwc_nolock
#define _ungettch _ungetwch
#define _ungettch_nolock _ungetwch_nolock

#define _tcstod wcstod
#define _tcstol wcstol
#define _tcstoul wcstoul
#define _tcstoi64 _wcstoi64
#define _tcstoui64 _wcstoui64
#define _tstof _wtof
#define _tstol _wtol
#define _tstoi _wtoi
#define _tstoi64 _wtoi64
#define _tcstod_l _wcstod_l
#define _tcstol_l _wcstol_l
#define _tcstoul_l _wcstoul_l
#define _tcstoi64_l _wcstoi64_l
#define _tcstoui64_l _wcstoui64_l
#define _tstof_l _wtof_l
#define _tstol_l _wtol_l
#define _tstoi_l _wtoi_l
#define _tstoi64_l _wtoi64_l

#define _itot_s _itow_s
#define _ltot_s _ltow_s
#define _ultot_s _ultow_s
#define _itot _itow
#define _ltot _ltow
#define _ultot _ultow
#define _ttoi _wtoi
#define _ttol _wtol

#define _ttoi64 _wtoi64
#define _i64tot_s _i64tow_s
#define _ui64tot_s _ui64tow_s
#define _i64tot _i64tow
#define _ui64tot _ui64tow

#define _tcscat wcscat
#define _tcscat_s wcscat_s
#define _tcschr wcschr
#define _tcscpy wcscpy
#define _tcscpy_s wcscpy_s
#define _tcscspn wcscspn
#define _tcslen wcslen
#define _tcsnlen wcsnlen
#define _tcsncat wcsncat
#define _tcsncat_s wcsncat_s
#define _tcsncat_l _wcsncat_l
#define _tcsncat_s_l _wcsncat_s_l
#define _tcsncpy wcsncpy
#define _tcsncpy_s wcsncpy_s
#define _tcsncpy_l _wcsncpy_l
#define _tcsncpy_s_l _wcsncpy_s_l
#define _tcspbrk wcspbrk
#define _tcsrchr wcsrchr
#define _tcsspn wcsspn
#define _tcsstr wcsstr
#define _tcstok wcstok
#define _tcstok_s wcstok_s
#define _tcstok_l _wcstok_l
#define _tcstok_s_l _wcstok_s_l
#define _tcserror _wcserror
#define _tcserror_s _wcserror_s
#define __tcserror __wcserror
#define __tcserror_s __wcserror_s

#define _tcsdup _wcsdup
#define _tcsnset _wcsnset
#define _tcsnset_s _wcsnset_s
#define _tcsnset_l _wcsnset_l
#define _tcsnset_s_l _wcsnset_s_l
#define _tcsrev _wcsrev
#define _tcsset _wcsset
#define _tcsset_s _wcsset_s
#define _tcsset_l _wcsset_l
#define _tcsset_s_l _wcsset_s_l

#define _tcscmp wcscmp
#define _tcsicmp _wcsicmp
#define _tcsicmp_l _wcsicmp_l
#define _tcsnccmp wcsncmp
#define _tcsncmp wcsncmp
#define _tcsncicmp _wcsnicmp
#define _tcsncicmp_l _wcsnicmp_l
#define _tcsnicmp _wcsnicmp
#define _tcsnicmp_l _wcsnicmp_l

#define _tcscoll wcscoll
#define _tcscoll_l _wcscoll_l
#define _tcsicoll _wcsicoll
#define _tcsicoll_l _wcsicoll_l
#define _tcsnccoll _wcsncoll
#define _tcsnccoll_l _wcsncoll_l
#define _tcsncoll _wcsncoll
#define _tcsncoll_l _wcsncoll_l
#define _tcsncicoll _wcsnicoll
#define _tcsncicoll_l _wcsnicoll_l
#define _tcsnicoll _wcsnicoll
#define _tcsnicoll_l _wcsnicoll_l

#define _texecl _wexecl
#define _texecle _wexecle
#define _texeclp _wexeclp
#define _texeclpe _wexeclpe
#define _texecv _wexecv
#define _texecve _wexecve
#define _texecvp _wexecvp
#define _texecvpe _wexecvpe

#define _tspawnl _wspawnl
#define _tspawnle _wspawnle
#define _tspawnlp _wspawnlp
#define _tspawnlpe _wspawnlpe
#define _tspawnv _wspawnv
#define _tspawnve _wspawnve
#define _tspawnvp _wspawnvp
#define _tspawnvp _wspawnvp
#define _tspawnvpe _wspawnvpe

#define _tsystem _wsystem

#define _tasctime _wasctime
#define _tctime _wctime
#define _tctime32 _wctime32
#define _tctime64 _wctime64
#define _tstrdate _wstrdate
#define _tstrtime _wstrtime
#define _tutime _wutime
#define _tutime32 _wutime32
#define _tutime64 _wutime64
#define _tcsftime wcsftime
#define _tcsftime_l _wcsftime_l

#define _tasctime_s _wasctime_s
#define _tctime_s _wctime_s
#define _tctime32_s _wctime32_s
#define _tctime64_s _wctime64_s
#define _tstrdate_s _wstrdate_s
#define _tstrtime_s _wstrtime_s

#define _tchdir _wchdir
#define _tgetcwd _wgetcwd
#define _tgetdcwd _wgetdcwd
#define _tgetdcwd_nolock _wgetdcwd_nolock
#define _tmkdir _wmkdir
#define _trmdir _wrmdir

#define _tfullpath _wfullpath
#define _tgetenv _wgetenv
#define _tgetenv_s _wgetenv_s
#define _tdupenv_s _wdupenv_s
#define _tmakepath _wmakepath
#define _tmakepath_s _wmakepath_s
#define _tpgmptr _wpgmptr
#define _get_tpgmptr _get_wpgmptr
#define _tputenv _wputenv
#define _tputenv_s _wputenv_s
#define _tsearchenv _wsearchenv
#define _tsearchenv_s _wsearchenv_s
#define _tsplitpath _wsplitpath
#define _tsplitpath_s _wsplitpath_s

#define _tfdopen _wfdopen
#define _tfsopen _wfsopen
#define _tfopen _wfopen
#define _tfopen_s _wfopen_s
#define _tfreopen _wfreopen
#define _tfreopen_s _wfreopen_s
#define _tperror _wperror
#define _tpopen _wpopen
#define _ttempnam _wtempnam
#define _ttmpnam _wtmpnam
#define _ttmpnam_s _wtmpnam_s

#define _taccess _waccess
#define _taccess_s _waccess_s
#define _tchmod _wchmod
#define _tcreat _wcreat
#define _tfindfirst _wfindfirst
#define _tfindfirst32 _wfindfirst32
#define _tfindfirst64 _wfindfirst64
#define _tfindfirsti64 _wfindfirsti64
#define _tfindfirst32i64 _wfindfirst32i64
#define _tfindfirst64i32 _wfindfirst64i32
#define _tfindnext _wfindnext
#define _tfindnext32 _wfindnext32
#define _tfindnext64 _wfindnext64
#define _tfindnexti64 _wfindnexti64
#define _tfindnext32i64 _wfindnext32i64
#define _tfindnext64i32 _wfindnext64i32
#define _tmktemp _wmktemp
#define _tmktemp_s _wmktemp_s
#define _topen _wopen
#define _tremove _wremove
#define _trename _wrename
#define _tsopen _wsopen
#define _tsopen_s _wsopen_s
#define _tunlink _wunlink

#define _tfinddata_t _wfinddata_t
#define _tfinddata32_t _wfinddata32_t
#define _tfinddata64_t _wfinddata64_t
#define _tfinddatai64_t _wfinddatai64_t
#define _tfinddata32i64_t _wfinddata32i64_t
#define _tfinddata64i32_t _wfinddata64i32_t

#define _tstat _wstat
#define _tstat32 _wstat32
#define _tstat32i64 _wstat32i64
#define _tstat64 _wstat64
#define _tstat64i32 _wstat64i32
#define _tstati64 _wstati64

#define _tsetlocale _wsetlocale

#define _tcsclen wcslen
#define _tcscnlen wcsnlen
#define _tcsclen_l(_String,_Locale) wcslen(_String)
#define _tcscnlen_l(_String,_Max_count,_Locale) wcsnlen_l((_String),(_Max_count))
#define _tcsnccat wcsncat
#define _tcsnccat_s wcsncat_s
#define _tcsnccat_l _wcsncat_l
#define _tcsnccat_s_l _wcsncat_s_l
#define _tcsnccpy wcsncpy
#define _tcsnccpy_s wcsncpy_s
#define _tcsnccpy_l _wcsncpy_l
#define _tcsnccpy_s_l _wcsncpy_s_l
#define _tcsncset _wcsnset

#define _tcsdec _wcsdec
#define _tcsinc _wcsinc
#define _tcsnbcnt _wcsncnt
#define _tcsnccnt _wcsncnt
#define _tcsnextc _wcsnextc
#define _tcsninc _wcsninc
#define _tcsspnp _wcsspnp

#define _tcslwr _wcslwr
#define _tcslwr_l _wcslwr_l
#define _tcslwr_s _wcslwr_s
#define _tcslwr_s_l _wcslwr_s_l
#define _tcsupr _wcsupr
#define _tcsupr_l _wcsupr_l
#define _tcsupr_s _wcsupr_s
#define _tcsupr_s_l _wcsupr_s_l
#define _tcsxfrm wcsxfrm
#define _tcsxfrm_l _wcsxfrm_l

#if __STDC__
#define _tclen(_pc) (1)
#define _tccpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#define _tccmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))
#else
  __CRT_INLINE size_t __cdecl _tclen(const wchar_t *_Cpc) {
    (void *)_Cpc;
    return 1;
  }
  __CRT_INLINE void __cdecl _tccpy(wchar_t *_Pc1,const wchar_t *_Cpc2) { *_Pc1 = (wchar_t)*_Cpc2; }
  __CRT_INLINE int __cdecl _tccmp(const wchar_t *_Cpc1,const wchar_t *_Cpc2) { return (int) ((*_Cpc1)-(*_Cpc2)); }
#endif

#define _istalnum iswalnum
#define _istalnum_l _iswalnum_l
#define _istalpha iswalpha
#define _istalpha_l _iswalpha_l
#define _istascii iswascii
#define _istcntrl iswcntrl
#define _istcntrl_l _iswcntrl_l
#define _istdigit iswdigit
#define _istdigit_l _iswdigit_l
#define _istgraph iswgraph
#define _istgraph_l _iswgraph_l
#define _istlower iswlower
#define _istlower_l _iswlower_l
#define _istprint iswprint
#define _istprint_l _iswprint_l
#define _istpunct iswpunct
#define _istpunct_l _iswpunct_l
#define _istspace iswspace
#define _istspace_l _iswspace_l
#define _istupper iswupper
#define _istupper_l _iswupper_l
#define _istxdigit iswxdigit
#define _istxdigit_l _iswxdigit_l

#define _totupper towupper
#define _totupper_l _towupper_l
#define _totlower towlower
#define _totlower_l _towlower_l

#define _istlegal(_Char) (1)
#define _istlead(_Char) (0)
#define _istleadbyte(_Char) (0)
#define _istleadbyte_l(_Char,_Locale) (0)

#if __STDC__
#define _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? NULL : (_cpc2)-1)
#define _wcsinc(_pc) ((_pc)+1)
#define _wcsnextc(_cpc) ((unsigned int) *(_cpc))
#define _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP size_t __cdecl __wcsncnt(const wchar_t *_Str,size_t _MaxCount);
#define _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#define _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? NULL : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : NULL))
#define _wcsncpy_l(_Destination,_Source,_Count,_Locale) (wcsncpy(_Destination,_Source,_Count))
#define _wcsncat_l(_Destination,_Source,_Count,_Locale) (wcsncat(_Destination,_Source,_Count))
#define _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#define _wcstok_s_l(_String,_Delimiters,_Current_position,_Locale) (wcstok_s(_String,_Delimiters,_Current_position))
#define _wcsnset_l(_Destination,_Value,_Count,_Locale) (_wcsnset(_Destination,_Value,_Count))
#define _wcsnset_s_l(_Destination,_Destination_size_chars,_Value,_Count,_Locale) (_wcsnset_s(_Destination,_Destination_size_chars,_Value,_Count))
#define _wcsset_l(_Destination,_Value,_Locale) (_wcsset(_Destination,_Value))
#define _wcsset_s_l(_Destination,_Destination_size_chars,_Value,_Locale) (_wcsset_s(_Destination,_Destination_size_chars,_Value))
#else
  __CRT_INLINE wchar_t *__cdecl _wcsdec(const wchar_t *_Cpc1,const wchar_t *_Cpc2) { return (wchar_t *)((_Cpc1)>=(_Cpc2) ? NULL : ((_Cpc2)-1)); }
  __CRT_INLINE wchar_t *__cdecl _wcsinc(const wchar_t *_Pc) { return (wchar_t *)(_Pc+1); }
  __CRT_INLINE unsigned int __cdecl _wcsnextc(const wchar_t *_Cpc) { return (unsigned int)*_Cpc; }
  __CRT_INLINE wchar_t *__cdecl _wcsninc(const wchar_t *_Pc,size_t _Sz) { return (wchar_t *)(_Pc+_Sz); }
  __CRT_INLINE size_t __cdecl _wcsncnt(const wchar_t *_String,size_t _Cnt) {
    size_t n = _Cnt;
    wchar_t *cp = (wchar_t *)_String;
    while(n-- && *cp) cp++;
    return _Cnt - n - 1;
  }
  __CRT_INLINE wchar_t *__cdecl _wcsspnp(const wchar_t *_Cpc1,const wchar_t *_Cpc2) {
    return (!_Cpc1 ? NULL : ((*(_Cpc1 += wcsspn(_Cpc1,_Cpc2))!='\0') ? (wchar_t*)_Cpc1 : NULL));
  }
  __CRT_INLINE wchar_t *__cdecl _wcsncpy_l(wchar_t *_Destination,const wchar_t *_Source,size_t _Count,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return wcsncpy(_Destination,_Source,_Count);
  }
  __CRT_INLINE wchar_t *__cdecl _wcsncat_l(wchar_t *_Destination,const wchar_t *_Source,size_t _Count,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return wcsncat(_Destination,_Source,_Count);
  }
  __CRT_INLINE wchar_t *_wcstok_l(wchar_t *_String,const wchar_t *_Delimiters,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return wcstok(_String,_Delimiters);

  }
  __CRT_INLINE wchar_t *_wcstok_s_l(wchar_t *_String,const wchar_t *_Delimiters,wchar_t **_Current_position,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return wcstok_s(_String,_Delimiters,_Current_position);
  }
  __CRT_INLINE wchar_t *__cdecl _wcsnset_l(wchar_t *_Destination,wchar_t _Value,size_t _Count,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return _wcsnset(_Destination,_Value,_Count);

  }
  __CRT_INLINE errno_t _wcsnset_s_l(wchar_t *_Destination,size_t _Destination_size_chars,wchar_t _Value,size_t _Count,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return _wcsnset_s(_Destination,_Destination_size_chars,_Value,_Count);
  }
  __CRT_INLINE wchar_t *__cdecl _wcsset_l(wchar_t *_Destination,wchar_t _Value,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return _wcsset(_Destination,_Value);
  }

  __CRT_INLINE errno_t _wcsset_s_l(wchar_t *_Destination,size_t _Destination_size_chars,wchar_t _Value,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return _wcsset_s(_Destination,_Destination_size_chars,_Value);
  }
#endif

  /* dirent structures and functions */
#define _tdirent	_wdirent
#define _TDIR 		_WDIR
#define _topendir	_wopendir
#define _tclosedir	_wclosedir
#define _treaddir	_wreaddir
#define _trewinddir	_wrewinddir
#define _ttelldir	_wtelldir
#define _tseekdir	_wseekdir

#else

#ifdef __cplusplus
}
#endif

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _TEOF EOF

#define __T(x) x

#define _tmain main
#define _tWinMain WinMain
#ifdef _POSIX_
#define _tenviron environ
#else
#define _tenviron _environ
#endif
#define __targv __argv

#define _tprintf printf
#define _tprintf_l _printf_l
#define _tprintf_s printf_s
#define _tprintf_s_l _printf_s_l
#define _tprintf_p _printf_p
#define _tprintf_p_l _printf_p_l
#define _tcprintf _cprintf
#define _tcprintf_l _cprintf_l
#define _tcprintf_s _cprintf_s
#define _tcprintf_s_l _cprintf_s_l
#define _tcprintf_p _cprintf_p
#define _tcprintf_p_l _cprintf_p_l
#define _vtcprintf _vcprintf
#define _vtcprintf_l _vcprintf_l
#define _vtcprintf_s _vcprintf_s
#define _vtcprintf_s_l _vcprintf_s_l
#define _vtcprintf_p _vcprintf_p
#define _vtcprintf_p_l _vcprintf_p_l
#define _ftprintf fprintf
#define _ftprintf_l _fprintf_l
#define _ftprintf_s fprintf_s
#define _ftprintf_s_l _fprintf_s_l
#define _ftprintf_p _fprintf_p
#define _ftprintf_p_l _fprintf_p_l
#define _stprintf sprintf
#define _stprintf_l _sprintf_l
#define _stprintf_s sprintf_s
#define _stprintf_s_l _sprintf_s_l
#define _stprintf_p _sprintf_p
#define _stprintf_p_l _sprintf_p_l
#define _sctprintf _scprintf
#define _sctprintf_l _scprintf_l
#define _sctprintf_p _scprintf_p
#define _sctprintf_p_l _scprintf_p_l
#define _sntprintf _snprintf
#define _sntprintf_l _snprintf_l
#define _sntprintf_s _snprintf_s
#define _sntprintf_s_l _snprintf_s_l
#define _vtprintf vprintf
#define _vtprintf_l _vprintf_l
#define _vtprintf_s vprintf_s
#define _vtprintf_s_l _vprintf_s_l
#define _vtprintf_p _vprintf_p
#define _vtprintf_p_l _vprintf_p_l
#define _vftprintf vfprintf
#define _vftprintf_l _vfprintf_l
#define _vftprintf_s vfprintf_s
#define _vftprintf_s_l _vfprintf_s_l
#define _vftprintf_p _vfprintf_p
#define _vftprintf_p_l _vfprintf_p_l
#define _vstprintf vsprintf
#define _vstprintf_l _vsprintf_l
#define _vstprintf_s vsprintf_s
#define _vstprintf_s_l _vsprintf_s_l
#define _vstprintf_p _vsprintf_p
#define _vstprintf_p_l _vsprintf_p_l
#define _vsctprintf _vscprintf
#define _vsctprintf_l _vscprintf_l
#define _vsctprintf_p _vscprintf_p
#define _vsctprintf_p_l _vscprintf_p_l
#define _vsntprintf _vsnprintf
#define _vsntprintf_l _vsnprintf_l
#define _vsntprintf_s _vsnprintf_s
#define _vsntprintf_s_l _vsnprintf_s_l

#define _tscanf scanf
#define _tscanf_l _scanf_l
#define _tscanf_s scanf_s
#define _tscanf_s_l _scanf_s_l
#define _tcscanf _cscanf
#define _tcscanf_l _cscanf_l
#define _tcscanf_s _cscanf_s
#define _tcscanf_s_l _cscanf_s_l
#define _ftscanf fscanf
#define _ftscanf_l _fscanf_l
#define _ftscanf_s fscanf_s
#define _ftscanf_s_l _fscanf_s_l
#define _stscanf sscanf
#define _stscanf_l _sscanf_l
#define _stscanf_s sscanf_s
#define _stscanf_s_l _sscanf_s_l
#define _sntscanf _snscanf
#define _sntscanf_l _snscanf_l
#define _sntscanf_s _snscanf_s
#define _sntscanf_s_l _snscanf_s_l

#define _fgettc fgetc
#define _fgettc_nolock _fgetc_nolock
#define _fgettchar _fgetchar
#define _fgetts fgets
#define _fputtc fputc
#define _fputtc_nolock _fputc_nolock
#define _fputtchar _fputchar
#define _fputts fputs
#define _cputts _cputs
#define _gettc getc
#define _gettc_nolock _getc_nolock
#define _gettch _getch
#define _gettch_nolock _getch_nolock
#define _gettche _getche
#define _gettche_nolock _getche_nolock
#define _gettchar getchar
#define _gettchar_nolock _getchar_nolock
#define _getts gets
#define _getts_s gets_s
#define _cgetts _cgets
#define _cgetts_s _cgets_s
#define _puttc putc
#define _puttc_nolock _putc_nolock
#define _puttchar putchar
#define _puttchar_nolock _putchar_nolock
#define _puttch _putch
#define _puttch_nolock _putch_nolock
#define _putts puts
#define _ungettc ungetc
#define _ungettc_nolock _ungetc_nolock
#define _ungettch _ungetch
#define _ungettch_nolock _ungetch_nolock

#define _tcstod strtod
#define _tcstol strtol
#define _tcstoul strtoul
#define _tstof atof
#define _tstol atol
#define _tstoi atoi
#define _tstoi64 _atoi64
#define _tcstod_l _strtod_l
#define _tcstol_l _strtol_l
#define _tcstoul_l _strtoul_l
#define _tstof_l _atof_l
#define _tstol_l _atol_l
#define _tstoi_l _atoi_l
#define _tstoi64_l _atoi64_l

#define _itot_s _itoa_s
#define _ltot_s _ltoa_s
#define _ultot_s _ultoa_s
#define _itot _itoa
#define _ltot _ltoa
#define _ultot _ultoa
#define _ttoi atoi
#define _ttol atol

#define _ttoi64 _atoi64
#define _tcstoi64 _strtoi64
#define _tcstoi64_l _strtoi64_l
#define _tcstoui64 _strtoui64
#define _tcstoui64_l _strtoui64_l
#define _i64tot_s _i64toa_s
#define _ui64tot_s _ui64toa_s
#define _i64tot _i64toa
#define _ui64tot _ui64toa

#define _tcscat strcat
#define _tcscat_s strcat_s
#define _tcscpy strcpy
#define _tcscpy_s strcpy_s
#define _tcsdup _strdup
#define _tcslen strlen
#define _tcsnlen strnlen
#define _tcsxfrm strxfrm
#define _tcsxfrm_l _strxfrm_l
#define _tcserror strerror
#define _tcserror_s strerror_s
#define __tcserror _strerror
#define __tcserror_s _strerror_s

#define _texecl _execl
#define _texecle _execle
#define _texeclp _execlp
#define _texeclpe _execlpe
#define _texecv _execv
#define _texecve _execve
#define _texecvp _execvp
#define _texecvpe _execvpe

#define _tspawnl _spawnl
#define _tspawnle _spawnle
#define _tspawnlp _spawnlp
#define _tspawnlpe _spawnlpe
#define _tspawnv _spawnv
#define _tspawnve _spawnve
#define _tspawnvp _spawnvp
#define _tspawnvpe _spawnvpe

#define _tsystem system

#define _tasctime asctime
#define _tctime ctime
#define _tctime32 _ctime32
#define _tctime64 _ctime64
#define _tstrdate _strdate
#define _tstrtime _strtime
#define _tutime _utime
#define _tutime32 _utime32
#define _tutime64 _utime64
#define _tcsftime strftime
#define _tcsftime_l _strftime_l

#define _tasctime_s asctime_s
#define _tctime_s ctime_s
#define _tctime32_s _ctime32_s
#define _tctime64_s _ctime64_s
#define _tstrdate_s _strdate_s
#define _tstrtime_s _strtime_s

#define _tchdir _chdir
#define _tgetcwd _getcwd
#define _tgetdcwd _getdcwd
#define _tgetdcwd_nolock _getdcwd_nolock
#define _tmkdir _mkdir
#define _trmdir _rmdir

#define _tfullpath _fullpath
#define _tgetenv getenv
#define _tgetenv_s getenv_s
#define _tdupenv_s _dupenv_s
#define _tmakepath _makepath
#define _tmakepath_s _makepath_s
#define _tpgmptr _pgmptr
#define _get_tpgmptr _get_pgmptr
#define _tputenv _putenv
#define _tputenv_s _putenv_s
#define _tsearchenv _searchenv
#define _tsearchenv_s _searchenv_s
#define _tsplitpath _splitpath
#define _tsplitpath_s _splitpath_s

#ifdef _POSIX_
#define _tfdopen fdopen
#else
#define _tfdopen _fdopen
#endif
#define _tfsopen _fsopen
#define _tfopen fopen
#define _tfopen_s fopen_s
#define _tfreopen freopen
#define _tfreopen_s freopen_s
#define _tperror perror
#define _tpopen _popen
#define _ttempnam _tempnam
#define _ttmpnam tmpnam
#define _ttmpnam_s tmpnam_s

#define _tchmod _chmod
#define _tcreat _creat
#define _tfindfirst _findfirst
#define _tfindfirst32 _findfirst32
#define _tfindfirst64 _findfirst64
#define _tfindfirsti64 _findfirsti64
#define _tfindfirst32i64 _findfirst32i64
#define _tfindfirst64i32 _findfirst64i32
#define _tfindnext _findnext
#define _tfindnext32 _findnext32
#define _tfindnext64 _findnext64
#define _tfindnexti64 _findnexti64
#define _tfindnext32i64 _findnext32i64
#define _tfindnext64i32 _findnext64i32
#define _tmktemp _mktemp
#define _tmktemp_s _mktemp_s

#ifdef _POSIX_
#define _topen open
#define _taccess access
#else
#define _topen _open
#define _taccess _access
#define _taccess_s _access_s
#endif

#define _tremove remove
#define _trename rename
#define _tsopen _sopen
#define _tsopen_s _sopen_s
#define _tunlink _unlink

#define _tfinddata_t _finddata_t
#define _tfinddata32_t _finddata32_t
#define _tfinddata64_t __finddata64_t
#define _tfinddatai64_t _finddatai64_t
#define _tfinddata32i64_t _finddata32i64_t
#define _tfinddata64i32_t _finddata64i32_t

#define _istascii __isascii
#define _istcntrl iscntrl
#define _istcntrl_l _iscntrl_l
#define _istxdigit isxdigit
#define _istxdigit_l _isxdigit_l

#define _tstat _stat
#define _tstat32 _stat32
#define _tstat32i64 _stat32i64
#define _tstat64 _stat64
#define _tstat64i32 _stat64i32
#define _tstati64 _stati64

#define _tsetlocale setlocale

#ifdef _MBCS

#ifdef __cplusplus
}
#endif

#include <mbstring.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __TCHAR_DEFINED
  typedef char _TCHAR;
  typedef signed char _TSCHAR;
  typedef unsigned char _TUCHAR;
  typedef unsigned char _TXCHAR;
  typedef unsigned int _TINT;
#define __TCHAR_DEFINED
#endif

#ifndef _TCHAR_DEFINED
#ifndef	NO_OLDNAMES
  typedef char TCHAR;
#endif
#define _TCHAR_DEFINED
#endif

#ifdef _MB_MAP_DIRECT

#define _tcschr _mbschr
#define _tcscspn _mbscspn
#define _tcsncat _mbsnbcat
#define _tcsncat_s _mbsnbcat_s
#define _tcsncat_l _mbsnbcat_l
#define _tcsncat_s_l _mbsnbcat_s_l
#define _tcsncpy _mbsnbcpy
#define _tcsncpy_s _mbsnbcpy_s
#define _tcsncpy_l _mbsnbcpy_l
#define _tcsncpy_s_l _mbsnbcpy_s_l
#define _tcspbrk _mbspbrk
#define _tcsrchr _mbsrchr
#define _tcsspn _mbsspn
#define _tcsstr _mbsstr
#define _tcstok _mbstok
#define _tcstok_s _mbstok_s
#define _tcstok_l _mbstok_l
#define _tcstok_s_l _mbstok_s_l

#define _tcsnset _mbsnbset
#define _tcsnset_l _mbsnbset_l
#define _tcsnset_s _mbsnbset_s
#define _tcsnset_s_l _mbsnbset_s_l
#define _tcsrev _mbsrev
#define _tcsset _mbsset
#define _tcsset_s _mbsset_s
#define _tcsset_l _mbsset_l
#define _tcsset_s_l _mbsset_s_l

#define _tcscmp _mbscmp
#define _tcsicmp _mbsicmp
#define _tcsicmp_l _mbsicmp_l
#define _tcsnccmp _mbsncmp
#define _tcsncmp _mbsnbcmp
#define _tcsncicmp _mbsnicmp
#define _tcsncicmp_l _mbsnicmp_l
#define _tcsnicmp _mbsnbicmp
#define _tcsnicmp_l _mbsnbicmp_l

#define _tcscoll _mbscoll
#define _tcscoll_l _mbscoll_l
#define _tcsicoll _mbsicoll
#define _tcsicoll_l _mbsicoll_l
#define _tcsnccoll _mbsncoll
#define _tcsnccoll_l _mbsncoll_l
#define _tcsncoll _mbsnbcoll
#define _tcsncoll_l _mbsnbcoll_l
#define _tcsncicoll _mbsnicoll
#define _tcsncicoll_l _mbsnicoll_l
#define _tcsnicoll _mbsnbicoll
#define _tcsnicoll_l _mbsnbicoll_l

#define _tcsclen _mbslen
#define _tcscnlen _mbsnlen
#define _tcsclen_l _mbslen_l
#define _tcscnlen_l _mbsnlen_l
#define _tcsnccat _mbsncat
#define _tcsnccat_s _mbsncat_s
#define _tcsnccat_l _mbsncat_l
#define _tcsnccat_s_l _mbsncat_s_l
#define _tcsnccpy _mbsncpy
#define _tcsnccpy_s _mbsncpy_s
#define _tcsnccpy_l _mbsncpy_l
#define _tcsnccpy_s_l _mbsncpy_s_l
#define _tcsncset _mbsnset
#define _tcsncset_s _mbsnset_s
#define _tcsncset_l _mbsnset_l
#define _tcsncset_s_l _mbsnset_s_l

#define _tcsdec _mbsdec
#define _tcsinc _mbsinc
#define _tcsnbcnt _mbsnbcnt
#define _tcsnccnt _mbsnccnt
#define _tcsnextc _mbsnextc
#define _tcsninc _mbsninc
#define _tcsspnp _mbsspnp

#define _tcslwr _mbslwr
#define _tcslwr_l _mbslwr_l
#define _tcslwr_s _mbslwr_s
#define _tcslwr_s_l _mbslwr_s_l
#define _tcsupr _mbsupr
#define _tcsupr_l _mbsupr_l
#define _tcsupr_s _mbsupr_s
#define _tcsupr_s_l _mbsupr_s_l

#define _tclen _mbclen
#define _tccpy _mbccpy
#define _tccpy_l _mbccpy_l
#define _tccpy_s _mbccpy_s
#define _tccpy_s_l _mbccpy_s_l
#else

#if __STDC__
  _CRTIMP _CONST_RETURN char *__cdecl _tcschr(const char *_Str,unsigned int _Val);
  _CRTIMP size_t __cdecl _tcscspn(const char *_Str,const char *_Control);
  _CRTIMP char *__cdecl _tcsncat(char *_Dst,const char *_Src,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsncat_s(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsncat_l(char *_Dst,const char *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsncat_s_l(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsncpy(char *_Dst,const char *_Src,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsncpy_s(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsncpy_l(char *_Dst,const char *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsncpy_s_l(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP _CONST_RETURN char *__cdecl _tcspbrk(const char *_Str,const char *_Control);
  _CRTIMP _CONST_RETURN char *__cdecl _tcsrchr(const char *_Str,unsigned int _Ch);
  _CRTIMP size_t __cdecl _tcsspn(const char *_Str,const char *_Control);
  _CRTIMP _CONST_RETURN char *__cdecl _tcsstr(const char *_Str,const char *_Substr);
  _CRTIMP char *__cdecl _tcstok(char *_Str,const char *_Delim);
  _CRTIMP char *__cdecl _tcstok_s(char *_Str,const char *_Delim,char **_Context);
  _CRTIMP char *__cdecl _tcstok_l(char *_Str,const char *_Delim,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcstok_s_l(char *_Str,const char *_Delim,char **_Context,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsnset(char *_Str,unsigned int _Val,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsrev(char *_Str);
  _CRTIMP char *__cdecl _tcsset(char *_Str,unsigned int _Val);
  _CRTIMP char *__cdecl _tcsset_l(char *_Str,unsigned int _Val,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _tcsset_s(char *_Str,size_t _SizeInChars,unsigned int _Val);
  _CRTIMP errno_t __cdecl _tcsset_s_l(char *_Str,size_t _SizeInChars,unsigned int,_locale_t _Locale);
  _CRTIMP int __cdecl _tcscmp(const char *_Str1,const char *_Str);
  _CRTIMP int __cdecl _tcsicmp(const char *_Str1,const char *_Str2);
  _CRTIMP int __cdecl _tcsicmp_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _tcsnccmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _tcsncmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _tcsncicmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _tcsncicmp_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP int __cdecl _tcsnicmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _tcsnicmp_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP int __cdecl _tcscoll(const char *_Str1,const char *_Str2);
  _CRTIMP int __cdecl _tcscoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _tcsicoll(const char *_Str1,const char *_Str2);
  _CRTIMP int __cdecl _tcsicoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  _CRTIMP int __cdecl _tcsnccoll(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _tcsnccoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP int __cdecl _tcsncoll(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _tcsncoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP int __cdecl _tcsncicoll(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _tcsncicoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP int __cdecl _tcsnicoll(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP int __cdecl _tcsnicoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP size_t __cdecl _tcsclen(const char *_Str);
  _CRTIMP size_t __cdecl _tcscnlen(const char *_Str,size_t _MaxCount);
  _CRTIMP size_t __cdecl _tcsclen_l(const char *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _tcscnlen_l(const char *_Str,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsnccat(char *_Dst,const char *_Src,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsnccat_s(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsnccat_l(char *_Dst,const char *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsnccat_s_l(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsnccpy(char *_Dst,const char *_Src,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsnccpy_s(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsnccpy_l(char *_Dst,const char *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsnccpy_s_l(char *_Dst,size_t _DstSizeInChars,const char *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsncset(char *_Str,unsigned int _Val,size_t _MaxCount);
  _CRTIMP char *__cdecl _tcsdec(const char *_Start,const char *_Pos);
  _CRTIMP char *__cdecl _tcsinc(const char *_Ptr);
  _CRTIMP size_t __cdecl _tcsnbcnt(const char *_Str,size_t _MaxCount);
  _CRTIMP size_t __cdecl _tcsnccnt(const char *_Str,size_t _MaxCount);
  _CRTIMP unsigned int __cdecl _tcsnextc (const char *_Str);
  _CRTIMP char *__cdecl _tcsninc(const char *_Ptr,size_t _Count);
  _CRTIMP char *__cdecl _tcsspnp(const char *_Str1,const char *_Str2);
  _CRTIMP char *__cdecl _tcslwr(char *_Str);
  _CRTIMP char *__cdecl _tcslwr_l(char *_Str,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcslwr_s(char *_Str,size_t _SizeInChars);
  _CRTIMP char *__cdecl _tcslwr_s_l(char *_Str,size_t _SizeInChars,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsupr(char *_Str);
  _CRTIMP char *__cdecl _tcsupr_l(char *_Str,_locale_t _Locale);
  _CRTIMP char *__cdecl _tcsupr_s(char *_Str,size_t _SizeInChars);
  _CRTIMP char *__cdecl _tcsupr_s_l(char *_Str,size_t _SizeInChars,_locale_t _Locale);
  _CRTIMP size_t __cdecl _tclen(const char *_Str);
  _CRTIMP void __cdecl _tccpy(char *_DstCh,const char *_SrcCh);
#else

#define _PUC unsigned char *
#define _CPUC const unsigned char *
#define _PC char *
#define _CRPC _CONST_RETURN char *
#define _CPC const char *
#define _UI unsigned int

  __CRT_INLINE _CRPC _tcschr(_CPC _s1,_UI _c) {return (_CRPC)_mbschr((_CPUC)_s1,_c);}
  __CRT_INLINE size_t _tcscspn(_CPC _s1,_CPC _s2) {return _mbscspn((_CPUC)_s1,(_CPUC)_s2);}
  __CRT_INLINE char *_tcsncat(char *_Destination,const char *_Source,size_t _Count) {
    return (char *)_mbsnbcat((unsigned char *)_Destination,(const unsigned char *)_Source,_Count);
  }
  __CRT_INLINE errno_t _tcsncat_s(char *_Destination,size_t _Destination_size_chars,const char *_Source,size_t _Count) {
    return _mbsnbcat_s((unsigned char *)_Destination,_Destination_size_chars,(const unsigned char *)_Source,_Count);
  }
  __CRT_INLINE char *_tcsncat_l(char *_Destination,const char *_Source,size_t _Count,_locale_t _Locale) {
    return (char *)_mbsnbcat_l((unsigned char *)_Destination,(const unsigned char *)_Source,_Count,_Locale);
  }
  __CRT_INLINE errno_t _tcsncat_s_l(char *_Destination,size_t _Destination_size_chars,const char *_Source,size_t _Count,_locale_t _Locale) {
    return _mbsnbcat_s_l((unsigned char *)_Destination,_Destination_size_chars,(const unsigned char *)_Source,_Count,_Locale);
  }
  __CRT_INLINE char *_tcsncpy(char *_Destination,const char *_Source,size_t _Count) {
    return (char *)_mbsnbcpy((unsigned char *)_Destination,(const unsigned char *)_Source,_Count);
  }
  __CRT_INLINE errno_t _tcsncpy_s(char *_Destination,size_t _Destination_size_chars,const char *_Source,size_t _Count) {
    return _mbsnbcpy_s((unsigned char *)_Destination,_Destination_size_chars,(const unsigned char *)_Source,_Count);
  }
  __CRT_INLINE char *_tcsncpy_l(char *_Destination,const char *_Source,size_t _Count,_locale_t _Locale) {
    return (char *)_mbsnbcpy_l((unsigned char *)_Destination,(const unsigned char *)_Source,_Count,_Locale);
  }
  __CRT_INLINE errno_t _tcsncpy_s_l(char *_Destination,size_t _Destination_size_chars,const char *_Source,size_t _Count,_locale_t _Locale) {
    return _mbsnbcpy_s_l((unsigned char *)_Destination,_Destination_size_chars,(const unsigned char *)_Source,_Count,_Locale);
  }
  __CRT_INLINE _CRPC _tcspbrk(_CPC _s1,_CPC _s2) {return (_CRPC)_mbspbrk((_CPUC)_s1,(_CPUC)_s2);}
  __CRT_INLINE _CRPC _tcsrchr(_CPC _s1,_UI _c) {return (_CRPC)_mbsrchr((_CPUC)_s1,_c);}
  __CRT_INLINE size_t _tcsspn(_CPC _s1,_CPC _s2) {return _mbsspn((_CPUC)_s1,(_CPUC)_s2);}
  __CRT_INLINE _CRPC _tcsstr(_CPC _s1,_CPC _s2) {return (_CRPC)_mbsstr((_CPUC)_s1,(_CPUC)_s2);}
  __CRT_INLINE char *_tcstok(char *_String,const char *_Delimiters) {
    return (char *)_mbstok((unsigned char *)_String,(const unsigned char *)_Delimiters);
  }
  __CRT_INLINE char *_tcstok_s(char *_String,const char *_Delimiters,char **_Current_position) {
    return (char *)_mbstok_s((unsigned char *)_String,(const unsigned char *)_Delimiters,(unsigned char **)_Current_position);
  }
  __CRT_INLINE char *_tcstok_l(char *_String,const char *_Delimiters,_locale_t _Locale) {
    return (char *)_mbstok_l((unsigned char *)_String,(const unsigned char *)_Delimiters,_Locale);
  }
  __CRT_INLINE char *_tcstok_s_l(char *_String,const char *_Delimiters,char **_Current_position,_locale_t _Locale) {
    return (char *)_mbstok_s_l((unsigned char *)_String,(const unsigned char *)_Delimiters,(unsigned char **)_Current_position,_Locale);
  }
  __CRT_INLINE char *_tcsnset(char *_Dst,unsigned int _Value ,size_t _Count) {
    return (char *)_mbsnbset((unsigned char *)_Dst,_Value,_Count);
  }
  __CRT_INLINE char *_tcsnset_l(char *_Dst,unsigned int _Value ,size_t _Count,_locale_t _Locale) {
    return (char *)_mbsnbset_l((unsigned char *)_Dst,_Value,_Count,_Locale);
  }
  __CRT_INLINE errno_t _tcsnset_s(char *_Dst,size_t _SizeInBytes,unsigned int _Value ,size_t _Count) {
    return _mbsnbset_s((unsigned char *)_Dst,_SizeInBytes,_Value,_Count);
  }
  __CRT_INLINE errno_t _tcsnset_s_l(char *_Dst,size_t _SizeInBytes,unsigned int _Value ,size_t _Count,_locale_t _Locale) {
    return _mbsnbset_s_l((unsigned char *)_Dst,_SizeInBytes,_Value,_Count,_Locale);
  }
  __CRT_INLINE _PC _tcsrev(_PC _s1) {return (_PC)_mbsrev((_PUC)_s1);}
  __CRT_INLINE char *_tcsset(char *_Dst,unsigned int _Value) {
    return (char *)_mbsset((unsigned char *)_Dst,_Value);
  }
  __CRT_INLINE char *_tcsset_l(char *_Dst,unsigned int _Value,_locale_t _Locale) {
    return (char *)_mbsset_l((unsigned char *)_Dst,_Value,_Locale);
  }
  __CRT_INLINE errno_t _tcsset_s(char *_Dst,size_t _SizeInBytes,unsigned int _Value) {
    return _mbsset_s((unsigned char *)_Dst,_SizeInBytes,_Value);
  }
  __CRT_INLINE errno_t _tcsset_s_l(char *_Dst,size_t _SizeInBytes,unsigned int _Value,_locale_t _Locale) {
    return _mbsset_s_l((unsigned char *)_Dst,_SizeInBytes,_Value,_Locale);
  }
  __CRT_INLINE int _tcscmp(_CPC _s1,_CPC _s2) {return _mbscmp((_CPUC)_s1,(_CPUC)_s2);}
  __CRT_INLINE int _tcsicmp(const char *_String1,const char *_String2) {
    return _mbsicmp((const unsigned char *)_String1,(const unsigned char *)_String2);
  }
  __CRT_INLINE int _tcsicmp_l(const char *_String1,const char *_String2,_locale_t _Locale) {
    return _mbsicmp_l((const unsigned char *)_String1,(const unsigned char *)_String2,_Locale);
  }
  __CRT_INLINE int _tcsnccmp(_CPC _s1,_CPC _s2,size_t _n) {return _mbsncmp((_CPUC)_s1,(_CPUC)_s2,_n);}
  __CRT_INLINE int _tcsncmp(_CPC _s1,_CPC _s2,size_t _n) {return _mbsnbcmp((_CPUC)_s1,(_CPUC)_s2,_n);}
  __CRT_INLINE int _tcsncicmp(const char *_String1,const char *_String2,size_t _Char_count) {
    return _mbsnicmp((const unsigned char *)_String1,(const unsigned char *)_String2,_Char_count);
  }
  __CRT_INLINE int _tcsncicmp_l(const char *_String1,const char *_String2,size_t _Char_count,_locale_t _Locale) {
    return _mbsnicmp_l((const unsigned char *)_String1,(const unsigned char *)_String2,_Char_count,_Locale);
  }
  __CRT_INLINE int _tcsnicmp(const char *_String1,const char *_String2,size_t _Char_count) {
    return _mbsnbicmp((const unsigned char *)_String1,(const unsigned char *)_String2,_Char_count);
  }
  __CRT_INLINE int _tcsnicmp_l(const char *_String1,const char *_String2,size_t _Char_count,_locale_t _Locale) {
    return _mbsnbicmp_l((const unsigned char *)_String1,(const unsigned char *)_String2,_Char_count,_Locale);
  }
  __CRT_INLINE int _tcscoll(const char *_String1,const char *_String2) {
    return _mbscoll((const unsigned char *)_String1,(const unsigned char *)_String2);
  }
  __CRT_INLINE int _tcscoll_l(const char *_String1,const char *_String2,_locale_t _Locale) {
    return _mbscoll_l((const unsigned char *)_String1,(const unsigned char *)_String2,_Locale);
  }
  __CRT_INLINE int _tcsicoll(const char *_String1,const char *_String2) {
    return _mbsicoll((const unsigned char *)_String1,(const unsigned char *)_String2);
  }
  __CRT_INLINE int _tcsicoll_l(const char *_String1,const char *_String2,_locale_t _Locale) {
    return _mbsicoll_l((const unsigned char *)_String1,(const unsigned char *)_String2,_Locale);
  }
  __CRT_INLINE int _tcsnccoll(const char *_String1,const char *_String2,size_t _Count) {
    return _mbsncoll((const unsigned char *)_String1,(const unsigned char *)_String2,_Count);
  }
  __CRT_INLINE int _tcsnccoll_l(const char *_String1,const char *_String2,size_t _Count,_locale_t _Locale) {
    return _mbsncoll_l((const unsigned char *)_String1,(const unsigned char *)_String2,_Count,_Locale);
  }
  __CRT_INLINE int _tcsncoll(const char *_String1,const char *_String2,size_t _Count) {
    return _mbsnbcoll((const unsigned char *)_String1,(const unsigned char *)_String2,_Count);
  }
  __CRT_INLINE int _tcsncoll_l(const char *_String1,const char *_String2,size_t _Count,_locale_t _Locale) {
    return _mbsnbcoll_l((const unsigned char *)_String1,(const unsigned char *)_String2,_Count,_Locale);
  }
  __CRT_INLINE int _tcsncicoll(const char *_String1,const char *_String2,size_t _Count) {
    return _mbsnicoll((const unsigned char *)_String1,(const unsigned char *)_String2,_Count);
  }
  __CRT_INLINE int _tcsncicoll_l(const char *_String1,const char *_String2,size_t _Count,_locale_t _Locale) {
    return _mbsnicoll_l((const unsigned char *)_String1,(const unsigned char *)_String2,_Count,_Locale);
  }
  __CRT_INLINE int _tcsnicoll(const char *_String1,const char *_String2,size_t _Count) {
    return _mbsnbicoll((const unsigned char *)_String1,(const unsigned char *)_String2,_Count);
  }
  __CRT_INLINE int _tcsnicoll_l(const char *_String1,const char *_String2,size_t _Count,_locale_t _Locale) {
    return _mbsnbicoll_l((const unsigned char *)_String1,(const unsigned char *)_String2,_Count,_Locale);
  }
  __CRT_INLINE size_t _tcsclen(const char *_String) {
    return _mbslen((const unsigned char *)_String);
  }
  __CRT_INLINE size_t _tcscnlen(const char *_String,size_t _Maximum) {
    return _mbsnlen((const unsigned char *)_String,_Maximum);
  }
  __CRT_INLINE size_t _tcsclen_l(const char *_String,_locale_t _Locale) {
    return _mbslen_l((const unsigned char *)_String,_Locale);
  }
  __CRT_INLINE size_t _tcscnlen_l(const char *_String,size_t _Maximum,_locale_t _Locale) {
    return _mbsnlen_l((const unsigned char *)_String,_Maximum,_Locale);
  }
  __CRT_INLINE char *_tcsnccat(char *_Destination,const char *_Source,size_t _Count) {
    return (char *)_mbsncat((unsigned char *)_Destination,(const unsigned char *)_Source,_Count);
  }
  __CRT_INLINE errno_t _tcsnccat_s(char *_Destination,size_t _Destination_size_chars,const char *_Source,size_t _Count) {
    return _mbsncat_s((unsigned char *)_Destination,_Destination_size_chars,(const unsigned char *)_Source,_Count);
  }
  __CRT_INLINE char *_tcsnccat_l(char *_Destination,const char *_Source,size_t _Count,_locale_t _Locale) {
    return (char *)_mbsncat_l((unsigned char *)_Destination,(const unsigned char *)_Source,_Count,_Locale);
  }
  __CRT_INLINE errno_t _tcsnccat_s_l(char *_Destination,size_t _Destination_size_chars,const char *_Source,size_t _Count,_locale_t _Locale) {
    return _mbsncat_s_l((unsigned char *)_Destination,_Destination_size_chars,(const unsigned char *)_Source,_Count,_Locale);
  }
  __CRT_INLINE char *_tcsnccpy(char *_Destination,const char *_Source,size_t _Count) {
    return (char *)_mbsncpy((unsigned char *)_Destination,(const unsigned char *)_Source,_Count);
  }
  __CRT_INLINE errno_t _tcsnccpy_s(char *_Destination,size_t _Destination_size_chars,const char *_Source,size_t _Count) {
    return _mbsncpy_s((unsigned char *)_Destination,_Destination_size_chars,(const unsigned char *)_Source,_Count);
  }
  __CRT_INLINE char *_tcsnccpy_l(char *_Destination,const char *_Source,size_t _Count,_locale_t _Locale) {
    return (char *)_mbsncpy_l((unsigned char *)_Destination,(const unsigned char *)_Source,_Count,_Locale);
  }
  __CRT_INLINE errno_t _tcsnccpy_s_l(char *_Destination,size_t _Destination_size_chars,const char *_Source,size_t _Count,_locale_t _Locale) {
    return _mbsncpy_s_l((unsigned char *)_Destination,_Destination_size_chars,(const unsigned char *)_Source,_Count,_Locale);
  }
  __CRT_INLINE char *_tcsncset(char *_Destination,unsigned int _Value,size_t _Count) {
    return (char *)_mbsnset((unsigned char *)_Destination,_Value,_Count);
  }
  __CRT_INLINE errno_t _tcsncset_s(char *_Destination,size_t _SizeInBytes,unsigned int _Value,size_t _Count) {
    return _mbsnset_s((unsigned char *)_Destination,_SizeInBytes,_Value,_Count);
  }
  __CRT_INLINE char *_tcsncset_l(char *_Destination,unsigned int _Value,size_t _Count,_locale_t _Locale) {
    return (char *)_mbsnset_l((unsigned char *)_Destination,_Value,_Count,_Locale);
  }
  __CRT_INLINE errno_t _tcsncset_s_l(char *_Destination,size_t _SizeInBytes,unsigned int _Value,size_t _Count,_locale_t _Locale) {
    return _mbsnset_s_l((unsigned char *)_Destination,_SizeInBytes,_Value,_Count,_Locale);
  }
  __CRT_INLINE _PC _tcsdec(_CPC _s1,_CPC _s2) {return (_PC)_mbsdec((_CPUC)_s1,(_CPUC)_s2);}
  __CRT_INLINE _PC _tcsinc(_CPC _s1) {return (_PC)_mbsinc((_CPUC)_s1);}
  __CRT_INLINE size_t _tcsnbcnt(_CPC _s1,size_t _n) {return _mbsnbcnt((_CPUC)_s1,_n);}
  __CRT_INLINE size_t _tcsnccnt(_CPC _s1,size_t _n) {return _mbsnccnt((_CPUC)_s1,_n);}
  __CRT_INLINE _PC _tcsninc(_CPC _s1,size_t _n) {return (_PC)_mbsninc((_CPUC)_s1,_n);}
  __CRT_INLINE _PC _tcsspnp(_CPC _s1,_CPC _s2) {return (_PC)_mbsspnp((_CPUC)_s1,(_CPUC)_s2);}
  __CRT_INLINE char *_tcslwr(char *_String) {
    return (char *)_mbslwr((unsigned char *)_String);
  }
  __CRT_INLINE errno_t _tcslwr_s(char *_String,size_t _SizeInBytes) {
    return _mbslwr_s((unsigned char *)_String,_SizeInBytes);
  }
  __CRT_INLINE char *_tcslwr_l(char *_String,_locale_t _Locale) {
    return (char *)_mbslwr_l((unsigned char *)_String,_Locale);
  }
  __CRT_INLINE errno_t _tcslwr_s_l(char *_String,size_t _SizeInBytes,_locale_t _Locale) {
    return _mbslwr_s_l((unsigned char *)_String,_SizeInBytes,_Locale);
  }
  __CRT_INLINE char *_tcsupr(char *_String) {
    return (char *)_mbsupr((unsigned char *)_String);
  }
  __CRT_INLINE errno_t _tcsupr_s(char *_String,size_t _Count) {
    return _mbsupr_s((unsigned char *)_String,_Count);
  }
  __CRT_INLINE char *_tcsupr_l(char *_String,_locale_t _Locale) {
    return (char *)_mbsupr_l((unsigned char *)_String,_Locale);
  }
  __CRT_INLINE errno_t _tcsupr_s_l(char *_String,size_t _Count,_locale_t _Locale) {
    return _mbsupr_s_l((unsigned char *)_String,_Count,_Locale);
  }
  __CRT_INLINE size_t _tclen(_CPC _s1) {return _mbclen((_CPUC)_s1);}
  __CRT_INLINE void _tccpy(char *_Destination,const char *_Source) {
    _mbccpy((unsigned char *)_Destination,(const unsigned char *)_Source);
  }
  __CRT_INLINE void _tccpy_l(char *_Destination,const char *_Source,_locale_t _Locale) {
    _mbccpy_l((unsigned char *)_Destination,(const unsigned char *)_Source,_Locale);
  }
  __CRT_INLINE errno_t _tccpy_s(char *_Destination,size_t _SizeInBytes,int *_PCopied,const char *_Source) {
    return _mbccpy_s((unsigned char *)_Destination,_SizeInBytes,_PCopied,(const unsigned char *)_Source);
  }
  __CRT_INLINE errno_t _tccpy_s_l(char *_Destination,size_t _SizeInBytes,int *_PCopied,const char *_Source,_locale_t _Locale) {
    return _mbccpy_s_l((unsigned char *)_Destination,_SizeInBytes,_PCopied,(const unsigned char *)_Source,_Locale);
  }
  __CRT_INLINE _UI _tcsnextc(_CPC _s1) {
    _UI _n=0;
    if(_ismbblead((_UI)*(_PUC)_s1)) {
      if(_s1[1]!='\0') {
	_n=((_UI)*(_PUC)_s1)<<8;
	_s1++;
      }
    }
    _n+=(_UI)*(_PUC)_s1;
    return(_n);
  }
#endif

#ifdef __cplusplus
#ifndef _CPP_TCHAR_INLINES_DEFINED
#define _CPP_TCHAR_INLINES_DEFINED
  extern "C++" {
    extern inline char *__cdecl _tcschr(char *_S,unsigned int _C) { return ((char *)_tcschr((const char *)_S,_C)); }
    extern inline char *__cdecl _tcspbrk(char *_S,const char *_P) { return ((char *)_tcspbrk((const char *)_S,_P)); }
    extern inline char *__cdecl _tcsrchr(char *_S,unsigned int _C) { return ((char *)_tcsrchr((const char *)_S,_C)); }
    extern inline char *__cdecl _tcsstr(char *_S,const char *_P) { return ((char *)_tcsstr((const char *)_S,_P)); }
  }
#endif
#endif
#endif

#define _tccmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#define _istalnum _ismbcalnum
#define _istalnum_l _ismbcalnum_l
#define _istalpha _ismbcalpha
#define _istalpha_l _ismbcalpha_l
#define _istdigit _ismbcdigit
#define _istdigit_l _ismbcdigit_l
#define _istgraph _ismbcgraph
#define _istgraph_l _ismbcgraph_l
#define _istlegal _ismbclegal
#define _istlegal_l _ismbclegal_l
#define _istlower _ismbclower
#define _istlower_l _ismbclower_l
#define _istprint _ismbcprint
#define _istprint_l _ismbcprint_l
#define _istpunct _ismbcpunct
#define _istpunct_l _ismbcpunct_l
#define _istspace _ismbcspace
#define _istspace_l _ismbcspace_l
#define _istupper _ismbcupper
#define _istupper_l _ismbcupper_l

#define _totupper _mbctoupper
#define _totupper_l _mbctoupper_l
#define _totlower _mbctolower
#define _totlower_l _mbctolower_l

#define _istlead _ismbblead
#define _istleadbyte isleadbyte
#define _istleadbyte_l _isleadbyte_l
#else

#ifndef __TCHAR_DEFINED
  typedef char _TCHAR;
  typedef signed char _TSCHAR;
  typedef unsigned char _TUCHAR;
  typedef char _TXCHAR;
  typedef int _TINT;
#define __TCHAR_DEFINED
#endif

#ifndef _TCHAR_DEFINED
#ifndef	NO_OLDNAMES
  typedef char TCHAR;
#endif
#define _TCHAR_DEFINED
#endif

#define _tcschr strchr
#define _tcscspn strcspn
#define _tcsncat strncat
#define _tcsncat_s strncat_s
#define _tcsncat_l _strncat_l
#define _tcsncat_s_l _strncat_s_l
#define _tcsncpy strncpy
#define _tcsncpy_s strncpy_s
#define _tcsncpy_l _strncpy_l
#define _tcsncpy_s_l _strncpy_s_l
#define _tcspbrk strpbrk
#define _tcsrchr strrchr
#define _tcsspn strspn
#define _tcsstr strstr
#define _tcstok strtok
#define _tcstok_s strtok_s
#define _tcstok_l _strtok_l
#define _tcstok_s_l _strtok_s_l

#define _tcsnset _strnset
#define _tcsnset_s _strnset_s
#define _tcsnset_l _strnset_l
#define _tcsnset_s_l _strnset_s_l
#define _tcsrev _strrev
#define _tcsset _strset
#define _tcsset_s _strset_s
#define _tcsset_s _strset_s
#define _tcsset_s_l _strset_s_l

#define _tcscmp strcmp
#define _tcsicmp _stricmp
#define _tcsicmp_l _stricmp_l
#define _tcsnccmp strncmp
#define _tcsncmp strncmp
#define _tcsncicmp _strnicmp
#define _tcsncicmp_l _strnicmp_l
#define _tcsnicmp _strnicmp
#define _tcsnicmp_l _strnicmp_l

#define _tcscoll strcoll
#define _tcscoll_l _strcoll_l
#define _tcsicoll _stricoll
#define _tcsicoll_l _stricoll_l
#define _tcsnccoll _strncoll
#define _tcsnccoll_l _strncoll_l
#define _tcsncoll _strncoll
#define _tcsncoll_l _strncoll_l
#define _tcsncicoll _strnicoll
#define _tcsncicoll_l _strnicoll_l
#define _tcsnicoll _strnicoll
#define _tcsnicoll_l _strnicoll_l

#define _tcsclen strlen
#define _tcscnlen strnlen
#define _tcsclen_l(_String,_Locale) strlen(_String)
#define _tcscnlen_l(_String,_Max_count,_Locale) strnlen_l((_String),(_Max_count))
#define _tcsnccat strncat
#define _tcsnccat_s strncat_s
#define _tcsnccat_l _strncat_l
#define _tcsnccat_s_l _strncat_s_l
#define _tcsnccpy strncpy
#define _tcsnccpy_s strncpy_s
#define _tcsnccpy_l _strncpy_l
#define _tcsnccpy_s_l _strncpy_s_l
#define _tcsncset _strnset

#define _tcsdec _strdec
#define _tcsinc _strinc
#define _tcsnbcnt _strncnt
#define _tcsnccnt _strncnt
#define _tcsnextc _strnextc
#define _tcsninc _strninc
#define _tcsspnp _strspnp

#define _tcslwr _strlwr
#define _tcslwr_l _strlwr_l
#define _tcslwr_s _strlwr_s
#define _tcslwr_s_l _strlwr_s_l
#define _tcsupr _strupr
#define _tcsupr_l _strupr_l
#define _tcsupr_s _strupr_s
#define _tcsupr_s_l _strupr_s_l
#define _tcsxfrm strxfrm
#define _tcsxfrm_l _strxfrm_l

#define _istlead(_Char) (0)
#define _istleadbyte(_Char) (0)
#define _istleadbyte_l(_Char,_Locale) (0)

#if __STDC__
#define _tclen(_pc) (1)
#define _tccpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#define _tccmp(_cpc1,_cpc2) (((unsigned char)*(_cpc1))-((unsigned char)*(_cpc2)))
#else
  __CRT_INLINE size_t __cdecl _tclen(const char *_cpc) {
    (void *)_cpc;
    return 1;
  }
  __CRT_INLINE void __cdecl _tccpy(char *_pc1,const char *_cpc2) { *_pc1 = *_cpc2; }
  __CRT_INLINE int __cdecl _tccmp(const char *_cpc1,const char *_cpc2) { return (int) (((unsigned char)*_cpc1)-((unsigned char)*_cpc2)); }
#endif

  /* dirent structures and functions */
#define _tdirent	dirent
#define _TDIR 		DIR
#define _topendir	opendir
#define _tclosedir	closedir
#define _treaddir	readdir
#define _trewinddir	rewinddir
#define _ttelldir	telldir
#define _tseekdir	seekdir

#define _istalnum isalnum
#define _istalnum_l _isalnum_l
#define _istalpha isalpha
#define _istalpha_l _isalpha_l
#define _istdigit isdigit
#define _istdigit_l _isdigit_l
#define _istgraph isgraph
#define _istgraph_l _isgraph_l
#define _istlower islower
#define _istlower_l _islower_l
#define _istprint isprint
#define _istprint_l _isprint_l
#define _istpunct ispunct
#define _istpunct_l _ispunct_l
#define _istspace isspace
#define _istspace_l _isspace_l
#define _istupper isupper
#define _istupper_l _isupper_l

#define _totupper toupper
#define _totupper_l _toupper_l
#define _totlower tolower
#define _totlower_l _tolower_l

#define _istlegal(_c) (1)

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif

#if __STDC__
#define _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? NULL : (_cpc2)-1)
#define _strinc(_pc) ((_pc)+1)
#define _strnextc(_cpc) ((unsigned int) *(const unsigned char *)(_cpc))
#define _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP size_t __cdecl __strncnt(const char *_Str,size_t _Cnt);
#define _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#define _strspnp(_cpc1,_cpc2) (!_cpc1 ? NULL : ((*((_cpc1)+strspn(_cpc1,_cpc2))) ? ((_cpc1)+strspn(_cpc1,_cpc2)) : NULL))

#define _strncpy_l(_Destination,_Source,_Count,_Locale) (strncpy(_Destination,_Source,_Count))
#define _strncat_l(_Destination,_Source,_Count,_Locale) (strncat(_Destination,_Source,_Count))
#define _strtok_l(_String,_Delimiters,_Locale) (strtok(_String,_Delimiters))
#define _strnset_l(_Destination,_Value,_Count,_Locale) (_strnset(_Destination,_Value,_Count))
#define _strnset_s_l(_Destination,_Destination_size_chars,_Value,_Count,_Locale) (_strnset_s(_Destination,_Destination_size_chars,_Value,_Count))
#define _strset_l(_Destination,_Value,_Locale) (_strset(_Destination,_Value))
#define _strset_s_l(_Destination,_Destination_size_chars,_Value,_Locale) (_strset_s(_Destination,_Destination_size_chars,_Value))
#else
  __CRT_INLINE char *__cdecl _strdec(const char *_Cpc1,const char *_Cpc2) { return (char *)((_Cpc1)>=(_Cpc2) ? NULL : (_Cpc2-1)); }
  __CRT_INLINE char *__cdecl _strinc(const char *_Pc) { return (char *)(_Pc+1); }
  __CRT_INLINE unsigned int __cdecl _strnextc(const char *_Cpc) { return (unsigned int)*(const unsigned char *)_Cpc; }
  __CRT_INLINE char *__cdecl _strninc(const char *_Pc,size_t _Sz) { return (char *)(_Pc+_Sz); }
  __CRT_INLINE size_t __cdecl _strncnt(const char *_String,size_t _Cnt) {
    size_t n = _Cnt;
    char *cp = (char *)_String;
    while(n-- && *cp) cp++;
    return _Cnt - n - 1;
  }
  __CRT_INLINE char *__cdecl _strspnp(const char *_Cpc1,const char *_Cpc2) {
    return (!_Cpc1 ? NULL : ((*(_Cpc1 += strspn(_Cpc1,_Cpc2))!='\0') ? (char*)_Cpc1 : NULL));
  }
  __CRT_INLINE char *__cdecl _strncpy_l(char *_Destination,const char *_Source,size_t _Count,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return strncpy(_Destination,_Source,_Count);
  }
  __CRT_INLINE char *__cdecl _strncat_l(char *_Destination,const char *_Source,size_t _Count,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return strncat(_Destination,_Source,_Count);
  }
  __CRT_INLINE char *_strtok_l(char *_String,const char *_Delimiters,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return strtok(_String,_Delimiters);
  }
  __CRT_INLINE char *__cdecl _strnset_l(char *_Destination,int _Value,size_t _Count,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return _strnset(_Destination,_Value,_Count);
  }
  __CRT_INLINE errno_t __cdecl _strnset_s_l(char *_Destination,size_t _Destination_size_chars,int _Value,size_t _Count,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return _strnset_s(_Destination,_Destination_size_chars,_Value,_Count);
  }
  __CRT_INLINE char *__cdecl _strset_l(char *_Destination,int _Value,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return _strset(_Destination,_Value);
  }
  __CRT_INLINE errno_t __cdecl _strset_s_l(char *_Destination,size_t _Destination_size_chars,int _Value,_locale_t _Locale) {
    _CRT_UNUSED(_Locale);
    return _strset_s(_Destination,_Destination_size_chars,_Value);
  }
#endif
#endif
#endif

#define _T(x) __T(x)
#define _TEXT(x) __T(x)

#ifdef __cplusplus
}
#endif
#endif
