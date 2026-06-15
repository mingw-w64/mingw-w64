#include <setjmp.h>
#include <stdio.h>

/* mingw-w64 headers */
#include "libtest.h"

jmp_buf buf;

void __attribute__((noreturn)) foo (void)
{
  printf ("Call longjmp\n");
  longjmp (buf, 1);
}

int main ()
{
  mingw_test_init ();

  if (setjmp (buf))
    {
      printf ("Caught\n");
    }
  else
    {
      foo ();
      printf ("Should not be reached.\n");
      return 1;
    }

  return 0;
}
