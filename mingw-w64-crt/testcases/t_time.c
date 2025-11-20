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
  time_t t, t_;
  __time32_t t32, t32_;
  __time64_t t64, t64_;
  struct timeb tb;
  struct _timeb tb_;
  struct __timeb32 tb32;
  struct __timeb64 tb64;
  struct tm *htm;
  struct tm tm1;
  struct tm tm2;
  struct tm tm3;
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

  const time_t times[] = {
    1700000000 /* Tue Nov 14 22:13:20 UTC 2023 */,
    1600000000 /* Sun Sep 13 12:26:40 UTC 2020 */,
  };
  for (size_t i = 0; i < sizeof(times)/sizeof(*times); i++) {
    t = times[i];
    htm = localtime (&t);
    tm1 = *htm;
    printf ("localtime(%lld):    sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
        (long long)t, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
    t_ = mktime (htm);
    printf ("mktime(): %lld      sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
        (long long)t_, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
    assert (t_ == t);
    assert (memcmp (htm, &tm1, sizeof(tm1)) == 0);

    t32 = t;
    htm = _localtime32 (&t32);
    tm2 = *htm;
    printf ("_localtime32(%d): sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
        t32, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
    t32_ = _mktime32 (htm);
    printf ("_mktime32(): %d   sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
        t32_, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
    assert (t32_ == t32);
    assert (memcmp (htm, &tm2, sizeof(tm2)) == 0);

    t64 = t;
    htm = _localtime64 (&t64);
    tm3 = *htm;
    printf ("_localtime64(%lld): sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
        t64, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
    t64_ = _mktime64 (htm);
    printf ("_mktime64(): %lld   sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
        t64_, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
    assert (t64_ == t64);
    assert (memcmp (htm, &tm3, sizeof(tm3)) == 0);

    assert (memcmp (&tm1, &tm2, sizeof(tm1)) == 0);
    assert (memcmp (&tm2, &tm3, sizeof(tm2)) == 0);
  }

  /* following tests are explicitly for Pacific Time Zone */
  putenv ("TZ=PST8PDT");
  _dstbias = -3600; /* tzset() does not change _dstbias when TZ= env is nonempty */
  tzset ();
  const struct {
    __time64_t time;
    int year; int mon; int day;
    int hour; int min; int sec;
    int dst;
  } pt_times[] = {
    { 1112520600, 2005,  4,  3, 1, 30, 0, 0 }, /* Sun Apr  3 09:30:00 UTC 2005 == Sun Apr  3 01:30:00 PST 2005 */
    { 1112524200, 2005,  4,  3, 3, 30, 0, 1 }, /* Sun Apr  3 10:30:00 UTC 2005 == Sun Apr  3 03:30:00 PDT 2005 */
    { 1130657400, 2005, 10, 30, 0, 30, 0, 1 }, /* Sun Oct 30 07:30:00 UTC 2005 == Sun Oct 30 00:30:00 PDT 2005 */
    { 1130661000, 2005, 10, 30, 1, 30, 0, 1 }, /* Sun Oct 30 08:30:00 UTC 2005 == Sun Oct 30 01:30:00 PDT 2005 */
    { 1130664600, 2005, 10, 30, 1, 30, 0, 0 }, /* Sun Oct 30 09:30:00 UTC 2005 == Sun Oct 30 01:30:00 PST 2005 */
    { 1130668200, 2005, 10, 30, 2, 30, 0, 0 }, /* Sun Oct 30 10:30:00 UTC 2005 == Sun Oct 30 02:30:00 PST 2005 */
    { 1130671800, 2005, 10, 30, 3, 30, 0, 0 }, /* Sun Oct 30 11:30:00 UTC 2005 == Sun Oct 30 03:30:00 PST 2005 */
  };
  for (size_t i = 0; i < sizeof(pt_times)/sizeof(*pt_times); i++) {
    int skip_mktime_check = 0;

    if (pt_times[i].time <= INT_MAX) {
      t32 = pt_times[i].time;
      htm = _localtime32 (&t32);
      tm2 = *htm;
      printf ("pacific _localtime32(%d): sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
          t32, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
      assert (pt_times[i].year == htm->tm_year + 1900);
      assert (pt_times[i].mon  == htm->tm_mon + 1);
      assert (pt_times[i].day  == htm->tm_mday);
      assert (pt_times[i].hour == htm->tm_hour);
      assert (pt_times[i].min  == htm->tm_min);
      assert (pt_times[i].sec  == htm->tm_sec);
      assert (pt_times[i].dst  == htm->tm_isdst);
      t32_ = _mktime32 (htm);
      printf ("pacific _mktime32(): %d   sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
          t32_, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
#if __MSVCRT_VERSION__ < 0x800
      /* Versioned msvcrt libraries older than msvcr80 (and some system msvcrt version too)
       * have broken native 32-bit mktime function for timestamps around the DST change.
       * If the native 32-bit mktime function is broken then skip tests for 64-bit mktime function.
       */
      if (t32_ != t32)
        skip_mktime_check = 1;
#endif
      if (!skip_mktime_check) {
        assert (t32_ == t32);
        assert (memcmp (htm, &tm2, sizeof(tm2)) == 0);
      } else {
        printf ("Skipping _mktime32 assert because of broken CRT library\n");
      }
    }

    if (sizeof(t) >= 8 || pt_times[i].time <= INT_MAX) {
      t = pt_times[i].time;
      htm = localtime (&t);
      tm1 = *htm;
      printf ("pacific localtime(%lld):    sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
          (long long)t, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
      assert (pt_times[i].year == htm->tm_year + 1900);
      assert (pt_times[i].mon  == htm->tm_mon + 1);
      assert (pt_times[i].day  == htm->tm_mday);
      assert (pt_times[i].hour == htm->tm_hour);
      assert (pt_times[i].min  == htm->tm_min);
      assert (pt_times[i].sec  == htm->tm_sec);
      assert (pt_times[i].dst  == htm->tm_isdst);
      t_ = mktime (htm);
      printf ("pacific mktime(): %lld      sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
          (long long)t_, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
      if (!skip_mktime_check) {
        assert (t_ == t);
        assert (memcmp (htm, &tm1, sizeof(tm1)) == 0);
      } else {
        printf ("Skipping mktime assert because of broken CRT library\n");
      }
    }

    t64 = pt_times[i].time;
    htm = _localtime64 (&t64);
    tm3 = *htm;
    printf ("pacific _localtime64(%lld): sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
        t64, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
    assert (pt_times[i].year == htm->tm_year + 1900);
    assert (pt_times[i].mon  == htm->tm_mon + 1);
    assert (pt_times[i].day  == htm->tm_mday);
    assert (pt_times[i].hour == htm->tm_hour);
    assert (pt_times[i].min  == htm->tm_min);
    assert (pt_times[i].sec  == htm->tm_sec);
    assert (pt_times[i].dst  == htm->tm_isdst);
    t64_ = _mktime64 (htm);
    printf ("pacific _mktime64(): %lld   sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
        t64_, htm->tm_sec, htm->tm_min, htm->tm_hour, htm->tm_mday, htm->tm_mon, htm->tm_year, htm->tm_wday, htm->tm_yday, htm->tm_isdst);
    if (!skip_mktime_check) {
      assert (t64_ == t64);
      assert (memcmp (htm, &tm3, sizeof(tm3)) == 0);
    } else {
      printf ("Skipping _mktime64 assert because of broken CRT library\n");
    }

    if (sizeof(t) >= 8 || pt_times[i].time <= INT_MAX)
      assert (memcmp (&tm1, &tm3, sizeof(tm1)) == 0);

    if (pt_times[i].time <= INT_MAX)
      assert (memcmp (&tm1, &tm2, sizeof(tm1)) == 0);

    if (pt_times[i].time <= INT_MAX)
      assert (memcmp (&tm2, &tm3, sizeof(tm2)) == 0);
  }

  /* ctime, localtime and mktime returns time string in local timezone, so set local timezone to UTC to have test timezone independent */
  putenv ("TZ=UTC0");
  _dstbias = 0; /* tzset() does not change _dstbias when TZ= env is nonempty */
  tzset ();

  t64 = 1ULL << 33;
  str = _ctime64 ( &t64 );
  printf ("_ctime64(1<<33):  %s", str);
  assert (strcmp (str, "Wed Mar 16 12:56:32 2242\n") == 0);

  t64 = 1ULL << 33;
  wstr = _wctime64 ( &t64 );
  printf ("_wctime64(1<<33): %ls", wstr);
  assert (wcscmp (wstr, L"Wed Mar 16 12:56:32 2242\n") == 0);

  t64 = 1ULL << 33;
  htm = _localtime64( &t64 );
  printf ("_localtime64(1<<33): sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
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

  t64 = _mktime64 (htm);
  printf ("_mktime64(): 0x%I64x sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
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
  t64 = _mktime64 (htm);
  printf ("_mktime64(): 0x%I64x sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d yday=%d isdst=%d\n",
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

  return 0;
}
