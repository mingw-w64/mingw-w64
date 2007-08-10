#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <errno.h>
#include <windows.h>

#define FILETIME_1970 11644473600ull /* seconds between 1/1/1601 and 1/1/1970 */
#define HECTONANOSEC_PER_SEC 10000000ull

int getntptimeofday (struct timespec *tp, struct timezone *z)
{
  int res = 0;
  //	struct _timeb timebuffer;
  ULARGE_INTEGER fti;
  TIME_ZONE_INFORMATION  TimeZoneInformation;
  DWORD tzi;

  if (z != NULL)
    {
      if ((tzi = GetTimeZoneInformation(&TimeZoneInformation)) != TIME_ZONE_ID_INVALID) {
	z->tz_minuteswest = TimeZoneInformation.Bias;
	if (tzi == TIME_ZONE_ID_DAYLIGHT)
	  z->tz_dsttime = 1;
	else
	  z->tz_dsttime = 0;
      }
    else
      {
	z->tz_minuteswest = 0;
	z->tz_dsttime = 0;
      }
    }

  if (tp != NULL) {
    GetSystemTimeAsFileTime ((LPFILETIME) &fti);	 /* 100-nanoseconds since 1-1-1601 */
    /* The actual accuracy on XP seems to be 125,000 nanoseconds = 125 microseconds = 0.125 milliseconds */
    fti.QuadPart -= FILETIME_1970;	/* 100 nano-seconds since 1-1-1970 */
    tp->tv_sec = fti.QuadPart / HECTONANOSEC_PER_SEC;	/* seconds since 1-1-1970 */
    tp->tv_nsec = (long) (fti.QuadPart % HECTONANOSEC_PER_SEC) * 100; /* nanoseconds */
  }
  return res;
}

#if 0

int __cdecl gettimeofday (struct timeval *p, struct timezone *z)
{
  struct timespec tp;

  if (getntptimeofday (&tp, z))
    return -1;
  p->tv_sec=tp.tv_sec;
  p->tv_usec=(tp.tv_nsec/1000);
  return 0;
}

#endif
