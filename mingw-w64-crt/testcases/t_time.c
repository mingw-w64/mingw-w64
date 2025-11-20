#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>
#include <assert.h>

int __cdecl ftime32(struct __timeb32 *tb32);
int __cdecl ftime64(struct __timeb64 *tb64);

int main()
{
  time_t t;
  __time32_t t32;
  __time64_t t64;
  struct timeb tb;
  struct _timeb tb_;
  struct __timeb32 tb32;
  struct __timeb64 tb64;
  struct tm *htm;
  int ret1, ret2, ret3;
  const char *str;
  const wchar_t *wstr;

  time (&t);
  _time32 (&t32);
  _time64 (&t64);
  printf ("time:      0x%I64xULL\n_time32:   0x%I32x\n_time64:   0x%I64xULL\n",
	(unsigned long long) t, (unsigned int) t32, (unsigned long long) t64);
  htm = _localtime32 (&t32);
  if (!htm) printf ("Failed _localtime32\n");
  else printf ("_localtime32: %s", asctime (htm));
  htm = localtime (&t);
  if (!htm) printf ("Failed localtime\n");
  else printf ("localtime:    %s", asctime (htm));

  htm = _localtime64 (&t64);
  if (!htm) printf ("Failed _localtime64\n");
  else printf ("_localtime64: %s", asctime (htm));

  _ftime (&tb_);
  _ftime32 (&tb32);
  _ftime64 (&tb64);
  printf ("_ftime:    0x%I64xULL.0x%x\n", (unsigned long long)tb_.time, (unsigned)tb_.millitm);
  printf ("_ftime32:  0x%I32x   .0x%x\n", tb32.time, (unsigned)tb32.millitm);
  printf ("_ftime64:  0x%I64xULL.0x%x\n", tb64.time, (unsigned)tb64.millitm);

  ret1 = ftime (&tb);
  ret2 = ftime32 (&tb32);
  ret3 = ftime64 (&tb64);
  printf ("ftime:   %d 0x%I64xULL.0x%x\n", ret1, (unsigned long long)tb.time, (unsigned)tb.millitm);
  printf ("ftime32: %d 0x%I32x   .0x%x\n", ret2, tb32.time, (unsigned)tb32.millitm);
  printf ("ftime64: %d 0x%I64xULL.0x%x\n", ret3, tb64.time, (unsigned)tb64.millitm);

  t64 = 1ULL << 33;
  htm = _gmtime64( &t64 );
  printf ("_gmtime64(1<<33): sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
      htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
  assert (htm->tm_sec == 32);
  assert (htm->tm_min == 56);
  assert (htm->tm_hour == 12);
  assert (htm->tm_mday == 16);
  assert (htm->tm_mon == 2);
  assert (htm->tm_year == 342);
  assert (htm->tm_wday == 3);
  assert (htm->tm_yday == 74);
  assert (htm->tm_isdst == 0);

  t64 = _mkgmtime64 (htm);
  printf ("_mkgmtime64(): 0x%I64x sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
      t64, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
  assert (t64 == (1ULL << 33));
  assert (htm->tm_sec == 32);
  assert (htm->tm_min == 56);
  assert (htm->tm_hour == 12);
  assert (htm->tm_mday == 16);
  assert (htm->tm_mon == 2);
  assert (htm->tm_year == 342);
  assert (htm->tm_wday == 3);
  assert (htm->tm_yday == 74);
  assert (htm->tm_isdst == 0);

  htm->tm_min = 66; /* change 56 to 66 -> + 10 minutes */
  t64 = _mkgmtime64 (htm);
  printf ("_mkgmtime64(): 0x%I64x sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
      t64, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
  assert (t64 == (1ULL << 33) + 10*60); /* + 10 minutes */
  assert (htm->tm_sec == 32);
  assert (htm->tm_min == 6); /* 66 is changed to 6 */
  assert (htm->tm_hour == 13); /* 12 is changed to 13 */
  assert (htm->tm_mday == 16);
  assert (htm->tm_mon == 2);
  assert (htm->tm_year == 342);
  assert (htm->tm_wday == 3);
  assert (htm->tm_yday == 74);
  assert (htm->tm_isdst == 0);

  /* ctime returns time string in local timezone, so set local timezone to UTC to have test timezone independent */
  putenv ("TZ=UTC");
  tzset ();

  t64 = 1ULL << 33;
  str = _ctime64 ( &t64 );
  printf ("_ctime64(1<<33):  %s", str);
  assert (strcmp (str, "Wed Mar 16 12:56:32 2242\n") == 0);

  t64 = 1ULL << 33;
  wstr = _wctime64 ( &t64 );
  printf ("_wctime64(1<<33): %ls", wstr);
  assert (wcscmp (wstr, L"Wed Mar 16 12:56:32 2242\n") == 0);

  return 0;
}
