/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#include <crtdefs.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  typedef unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  typedef long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
  __MINGW_EXTENSION typedef __int64 __time64_t;
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  typedef __time32_t time_t;
#else
  typedef __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  typedef long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef unsigned __int64 size_t;
#else
  typedef unsigned int size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef __int64 ssize_t;
#else
  typedef int ssize_t;
#endif
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

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT int _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT char * _tzname[2];

  _CRTIMP errno_t __cdecl _get_daylight(int *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *_ReturnValue,char *_Buffer,size_t _SizeInBytes,int _Index);
  char *__cdecl asctime(const struct tm *_Tm) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  char *__cdecl _ctime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  clock_t __cdecl clock(void);
  double __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  struct tm *__cdecl _gmtime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  struct tm *__cdecl _localtime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  size_t __cdecl strftime(char * __restrict__ _Buf,size_t _SizeInBytes,const char * __restrict__ _Format,const struct tm * __restrict__ _Tm);
  _CRTIMP size_t __cdecl _strftime_l(char * __restrict__ _Buf,size_t _Max_size,const char * __restrict__ _Format,const struct tm * __restrict__ _Tm,_locale_t _Locale);
  _CRTIMP char *__cdecl _strdate(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *__cdecl _strtime(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __time32_t __cdecl _time32(__time32_t *_Time);
  __time32_t __cdecl _mktime32(struct tm *_Tm);
  __time32_t __cdecl _mkgmtime32(struct tm *_Tm);
#if defined (_POSIX_) || defined(__GNUC__)
  void __cdecl tzset(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif
#if !defined (_POSIX_)
  _CRTIMP void __cdecl _tzset(void);
#endif

  double __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP char *__cdecl _ctime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP struct tm *__cdecl _gmtime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP struct tm *__cdecl _localtime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP __time64_t __cdecl _mktime64(struct tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(struct tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
  unsigned __cdecl _getsystime(struct tm *_Tm);
  unsigned __cdecl _setsystime(struct tm *_Tm,unsigned _MilliSec);

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(const struct tm *_Tm);
  wchar_t *__cdecl _wctime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  size_t __cdecl wcsftime(wchar_t * __restrict__ _Buf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,const struct tm * __restrict__ _Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t * __restrict__ _Buf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,const struct tm * __restrict__ _Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _wctime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

#if !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
  wchar_t *__cdecl _wctime(const time_t *) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef __CRT__NO_INLINE
#ifndef _USE_32BIT_TIME_T
  __CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { return _wctime64(_Time); }
#else
  __CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { return _wctime32(_Time); }
#endif
#endif /* __CRT__NO_INLINE */
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
double __cdecl difftime(time_t _Time1,time_t _Time2);
char *__cdecl ctime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
struct tm *__cdecl gmtime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
struct tm *__cdecl localtime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

#ifdef _POSIX
#ifdef __GNUC__ /* FIXME: Other compilers that these macros work with? */
#ifndef localtime_r
#define localtime_r(_Time, _Tm)	({ struct tm *___tmp_tm =		\
						localtime((_Time));	\
						if (___tmp_tm) {	\
						  *(_Tm) = *___tmp_tm;	\
						  ___tmp_tm = (_Tm);	\
						}			\
						___tmp_tm;	})
#endif
#ifndef gmtime_r
#define gmtime_r(_Time,_Tm)	({ struct tm *___tmp_tm =		\
						gmtime((_Time));	\
						if (___tmp_tm) {	\
						  *(_Tm) = *___tmp_tm;	\
						  ___tmp_tm = (_Tm);	\
						}			\
						___tmp_tm;	})
#endif
#ifndef ctime_r
#define ctime_r(_Time,_Str)	({ char *___tmp_tm = ctime((_Time));	\
						if (___tmp_tm)		\
						 ___tmp_tm =		\
						   strcpy((_Str),___tmp_tm); \
						___tmp_tm;	})
#endif
#ifndef asctime_r
#define asctime_r(_Tm, _Buf)	({ char *___tmp_tm = asctime((_Tm));	\
						if (___tmp_tm)		\
						 ___tmp_tm =		\
						   strcpy((_Buf),___tmp_tm);\
						___tmp_tm;	})
#endif
#else /* NOT GCC: */
      /* FIXME: These are more generic but call the main function twice! */
#ifndef localtime_r
#define localtime_r(_Time, _Tm) (localtime ((_Time)) ? *(_Tm) = *localtime ((_Time),(_Tm)) : 0)
#endif
#ifndef gmtime_r
#define gmtime_r(_Time,_Tm) (gmtime ((_Time)) ? (*(_Tm) = *gmtime (_Time),(_Tm)) : 0)
#endif
#ifndef ctime_r
#define ctime_r(_Time,_Str) (ctime ((_Time)) ? (strcpy((_Str),ctime ((_Time))),(_Str)) : 0)
#endif
#endif /* __GNUC__ */
#endif /* _POSIX */

time_t __cdecl mktime(struct tm *_Tm);
time_t __cdecl _mkgmtime(struct tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifndef __CRT__NO_INLINE
#if !defined(_USE_32BIT_TIME_T)
__CRT_INLINE double __cdecl difftime(time_t _Time1,time_t _Time2)
  { return _difftime64(_Time1,_Time2); }
__CRT_INLINE char *__cdecl ctime(const time_t *_Time) { return _ctime64(_Time); }
__CRT_INLINE struct tm *__cdecl gmtime(const time_t *_Time) { return _gmtime64(_Time); }
__CRT_INLINE struct tm *__cdecl localtime(const time_t *_Time) { return _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(struct tm *_Tm) { return _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(struct tm *_Tm) { return _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { return _time64(_Time); }
#else
__CRT_INLINE double __cdecl difftime(time_t _Time1,time_t _Time2)
  { return _difftime32(_Time1,_Time2); }
__CRT_INLINE char *__cdecl ctime(const time_t *_Time) { return _ctime32(_Time); }
__CRT_INLINE struct tm *__cdecl localtime(const time_t *_Time) { return _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(struct tm *_Tm) { return _mktime32(_Tm); }
__CRT_INLINE struct tm *__cdecl gmtime(const time_t *_Time) { return _gmtime32(_Time); }
__CRT_INLINE time_t __cdecl _mkgmtime(struct tm *_Tm) { return _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { return _time32(_Time); }
#endif /* !_USE_32BIT_TIME_T */
#endif /* !__CRT__NO_INLINE */
#endif /* !RC_INVOKED */

#if !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  _CRTIMP extern int daylight;
  _CRTIMP extern long timezone;
  _CRTIMP extern char *tzname[2];
  void __cdecl tzset(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif

#include <_timeval.h>

#ifndef _TIMEZONE_DEFINED /* also in sys/time.h */
#define _TIMEZONE_DEFINED
struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

  extern int __cdecl mingw_gettimeofday (struct timeval *p, struct timezone *z);
#endif /* _TIMEZONE_DEFINED */

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/time_s.h>

/* Adding timespec definition.  */
#include <sys/timeb.h>

/* POSIX 2008 says clock_gettime and timespec are defined in time.h header,
   but other systems - like Linux, Solaris, etc - tend to declare such
   recent extensions only if the following guards are met.  */
#if !defined(IN_WINPTHREAD) && \
	((!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX)) || \
	 (_POSIX_C_SOURCE > 2) || defined(__EXTENSIONS__))
#include <pthread_time.h>
#endif

#endif /* End _TIME_H_ */

