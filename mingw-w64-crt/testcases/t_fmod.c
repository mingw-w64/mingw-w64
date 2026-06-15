#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* mingw-w64 headers */
#include "libtest.h"

int main()
{
 int res = 0;
 int i;

 mingw_test_init ();

 for (i = 0; i < 5; i++)
   {
     double m;

#define TEST(y) do { \
    m = fmod(1 << i, y); \
    printf ("fmod(%d, "#y") = %.18f\n", 1 << i, m); \
    if (m >= y) \
      { \
        res |= 1; \
        printf ("which is bogus!\n"); \
      } \
  } while (0)

     TEST (0.05);
     TEST (0.1);
     TEST (0.5);
   }

  return res;
}
