#include <stdio.h>
#include <math.h>

double a = M_PI;
double b = INFINITY;

int
main (void)
{
  printf("MSVCRT %%e: %e\n", a);
  __mingw_printf("MINGW  %%e: %e\n", a);
  printf("MSVCRT %%e: %e\n", b);
  __mingw_printf("MINGW  %%e: %e\n", b);
  return 0;
}
