#include <stdio.h>
#include <time.h>

int main()
{
  time_t t;
  __time32_t t32;
  __time64_t t64;
  struct tm *htm;
  time (&t);
  _time32 (&t32);
  _time64 (&t64);
  printf ("0x%I64xULL, 0x%I32x, 0x%I64xULL\n",
	(unsigned long long) t, (unsigned int) t32, (unsigned long long) t64);
  htm = _localtime32 (&t32);
  if (!htm) printf ("Failed _localtime32\n");
  else printf ("_localtime32: %s", asctime (htm));
  htm = localtime (&t);
  if (!htm) printf ("Failed localtime\n");
  else printf ("localtime: %s", asctime (htm));
  htm = _localtime64 (&t64);
  if (!htm) printf ("Failed _localtime64\n");
  else printf ("_localtime64: %s", asctime (htm));
  return 0;
}
