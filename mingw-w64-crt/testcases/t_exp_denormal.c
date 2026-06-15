#include <math.h>
#include <stdio.h>

/* mingw-w64 headers */
#include "libtest.h"

int main()
{
  mingw_test_init ();
  printf ("%g\n", exp (-709.));
  return 0;
}
