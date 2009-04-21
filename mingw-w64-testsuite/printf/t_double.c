#include <stdio.h>
#include <math.h>

double a = M_PI;
double b = INFINITY;

int
main (void)
{
  printf("MSVCRT %%g: %g\n", a);
  __mingw_printf("MINGW  %%g: %g\n", a);
  printf("MSVCRT %%g: %g\n", b);
  __mingw_printf("MINGW  %%g: %g\n", b);
  return 0;
}
