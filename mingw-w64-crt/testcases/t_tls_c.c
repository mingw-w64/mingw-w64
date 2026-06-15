#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if __STDC_VERSION__ >= 201112L
#define __threadlocal__ _Thread_local
#else
#define __threadlocal__ __thread
#endif

__threadlocal__ int tvar = 0;

int main (void)
{
  /**
   * Random number to increment `tvar` by.
   */
  int x;

  srand (time (NULL));
  x = rand ();
  tvar += x;

  if (tvar != x) {
    fprintf (stderr, "tvar has value %d when expected %d\n", tvar, x);
    _exit (EXIT_FAILURE);
  }

  return 0;
}
