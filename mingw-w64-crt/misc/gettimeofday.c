/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <time.h>
#include <sys/time.h>
#include <windows.h>

#define FILETIME_1970 116444736000000000ull /* seconds between 1/1/1601 and 1/1/1970 */
#define HECTONANOSEC_PER_SEC 10000000ull

int __cdecl mingw_gettimeofday(struct timeval* __restrict__ _Tv, struct timezone* __restrict__ _Tz)
{
  union {
    unsigned long long ns100; /*time since 1 Jan 1601 in 100ns units */
    FILETIME ft;
  }  _now;
  TIME_ZONE_INFORMATION TimeZoneInformation;
  DWORD tzi;

  if (_Tz != NULL)
    {
      if ((tzi = GetTimeZoneInformation(&TimeZoneInformation)) != TIME_ZONE_ID_INVALID) {
	_Tz->tz_minuteswest = TimeZoneInformation.Bias;
	if (tzi == TIME_ZONE_ID_DAYLIGHT)
	  _Tz->tz_dsttime = 1;
	else
	  _Tz->tz_dsttime = 0;
      }
      else
	{
	  _Tz->tz_minuteswest = 0;
	  _Tz->tz_dsttime = 0;
	}
    }

  if (_Tv != NULL) {
    typedef void (WINAPI * GetSystemTimeAsFileTime_t)(LPFILETIME);
    static GetSystemTimeAsFileTime_t GetSystemTimeAsFileTime_p /* = 0 */;

    /* Set function pointer during first call */
    GetSystemTimeAsFileTime_t get_time =
      __atomic_load_n (&GetSystemTimeAsFileTime_p, __ATOMIC_RELAXED);
    if (get_time == NULL) {
      /* Use GetSystemTimePreciseAsFileTime() if available (Windows 8 or later) */
      get_time = (GetSystemTimeAsFileTime_t)(intptr_t) GetProcAddress (
        GetModuleHandle ("kernel32.dll"),
        "GetSystemTimePreciseAsFileTime"); /* <1us precision on Windows 10 */
      if (get_time == NULL)
        get_time = GetSystemTimeAsFileTime; /* >15ms precision on Windows 10 */
      __atomic_store_n (&GetSystemTimeAsFileTime_p, get_time, __ATOMIC_RELAXED);
    }

    get_time (&_now.ft);	/* 100 nano-seconds since 1-1-1601 */
    _now.ns100 -= FILETIME_1970;	/* 100 nano-seconds since 1-1-1970 */
    _Tv->tv_sec = _now.ns100 / HECTONANOSEC_PER_SEC;	/* seconds since 1-1-1970 */
    _Tv->tv_usec = (long) (_now.ns100 % HECTONANOSEC_PER_SEC) / 10; /* 100ns -> 1us */
  }
  return 0;
}

int __cdecl gettimeofday(struct timeval* __restrict__ _Tv, void* __restrict__ _Tz)
{
  return mingw_gettimeofday(_Tv, (struct timezone*)_Tz);
}
