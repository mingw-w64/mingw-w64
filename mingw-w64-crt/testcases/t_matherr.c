#include <math.h>
#include <stdio.h>

/* mingw-w64 headers */
#include "libtest.h"

int _MINGW_INSTALL_DEBUG_MATHERR = 1;

int main()
{
  mingw_test_init ();
  printf ("sqrt(-1)=%g\n", sqrt (-1.0));
  return 0;
}
