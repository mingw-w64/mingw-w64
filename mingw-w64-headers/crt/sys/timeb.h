/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _TIMEB_H_
#define _TIMEB_H_

#include <crtdefs.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

_CRT_BEGIN_C_HEADER

#ifndef _TIMEB_DEFINED
#define _TIMEB_DEFINED

  struct __timeb32 {
    __time32_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };

#ifndef	NO_OLDNAMES
  struct timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };
#endif

  struct __timeb64 {
    __time64_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };

#endif

  _CRTIMP void __cdecl _ftime64(struct __timeb64 *_Time);
  _CRTIMP void __cdecl _ftime32(struct __timeb32 *_Time);

/*
 * To prevent ABI issues, the mingw-w64 runtime should not call the
 * _timeb and _ftime functions. Instead it should call the fixed-size variants.
 */
#ifndef _CRTBLD
#ifndef _USE_32BIT_TIME_T
#define _timeb __timeb64
#define _ftime _ftime64
#else
#define _timeb __timeb32
#define _ftime _ftime32
#endif
#endif /* _CRTBLD */

struct _timespec32 {
  __time32_t tv_sec;
  long tv_nsec;
};

struct _timespec64 {
  __time64_t tv_sec;
  long tv_nsec;
};

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
struct timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

struct itimerspec {
  struct timespec  it_interval;  /* Timer period */
  struct timespec  it_value;     /* Timer expiration */
};
#endif

/*
 * To prevent ABI issues, the mingw-w64 runtime should not call the
 * ftime function. Instead it should call the fixed-size variants.
 */
#ifndef _CRTBLD
#if !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#ifndef _USE_32BIT_TIME_T
  int __cdecl ftime (struct timeb *) __MINGW_ASM_CALL(ftime64);
#else
  int __cdecl ftime (struct timeb *) __MINGW_ASM_CALL(ftime32);
#endif /* _USE_32BIT_TIME_T */
#endif
#endif /* _CRTBLD */

_CRT_END_C_HEADER

#include <sec_api/sys/timeb_s.h>
#endif
