#ifdef TEST_SETJMPEX
#include <setjmpex.h>
#else
#include <setjmp.h>
#endif
#include <stdio.h>

/* mingw-w64 headers */
#include "libtest.h"

jmp_buf buf;

void __attribute__((noreturn)) call_longjmp (int val)
{
  printf ("Call longjmp with %d\n", val);
  longjmp (buf, val);
}

int main ()
{
  mingw_test_init ();

  for (volatile int in_val = -300; in_val <= 300; in_val++)
    {
      printf ("Call setjmp\n");
      volatile int in_longjmp = 0;
      int out_val = setjmp (buf);
      if ((in_val != 0 && out_val == in_val) || (in_val == 0 && out_val == 1)) /* longjmp (0) cause that setjmp () returns 1 */
        {
          printf ("Caught %d\n", out_val);
        }
      else if (!in_longjmp && out_val == 0)
        {
          in_longjmp = 1;
          call_longjmp (in_val);
          printf ("Should not be reached.\n");
          return 1;
        }
      else
        {
          printf ("Unexpected value %d from %s\n", out_val, in_longjmp ? "longjmp" : "setjmp");
          return 1;
        }
      printf ("\n");
    }

  printf ("SUCCESS\n");
  return 0;
}
