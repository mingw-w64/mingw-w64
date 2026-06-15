#define __MINGW_USE_ANSI_STDIO 1
#include <math.h>
#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int main()
{
  long double ld = 1.0L;
  long double sum = 0.0L;

  DWORD synch_ticks = GetTickCount();
  DWORD start_ticks = synch_ticks;

  while (start_ticks == synch_ticks)
    start_ticks = GetTickCount ();

  int i;
  for (i = 0; i < 0x3fffff * 19; i++) {
    sum += powl (ld, 0.5L);
    ld += 0.03;
  }

  start_ticks = GetTickCount() - start_ticks;

  printf ("Loop %d times with result %Lg\n", i, ld);
  printf ("Has %g calculations / ms\n", (double) i / (double) start_ticks);

  (void)sum;
  return 0;
}
