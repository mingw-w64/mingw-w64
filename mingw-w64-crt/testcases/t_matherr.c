#include <math.h>
#include <stdio.h>

int _MINGW_INSTALL_DEBUG_MATHERR = 1;

int main()
{
  printf ("sqrt(-1)=%g\n", sqrt (-1.0));
  return 0;
}

