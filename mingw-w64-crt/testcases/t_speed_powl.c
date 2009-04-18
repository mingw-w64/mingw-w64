#include <windows.h>
#include <stdio.h>
#include <math.h>

int main()
{
  DWORD start_ticks = GetTickCount();
  int i;
  long double ld, sum;
  sum = 0.0L;
  ld = 1.0L;

  for (i = 0;i < 0x1fffff ; i++) { sum += powl (ld, 0.5L); ld+=0.03; }

  __mingw_printf ("Loop %d times with result %Lg\n", i, ld);
  start_ticks = GetTickCount() - start_ticks;
  printf ("Used aabout %u ms\n", start_ticks);
  return 0;
}

