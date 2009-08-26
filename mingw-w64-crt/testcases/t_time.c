#include <stdio.h>
#include <time.h>

int main()
{
  time_t t;
  __time32_t t32;
  __time64_t t64;
  time (&t);
  _time32 (&t32);
  _time64 (&t64);
  printf ("0x%I64xULL, 0x%I32x, 0x%I64xULL\n",
	(unsigned long long) t, (unsigned int) t32, (unsigned long long) t64);
  return 0;
}
