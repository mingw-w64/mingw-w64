#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void foo (void)
{
  printf ("Call longjmp\n");
  longjmp (buf, 1);
}

int main ()
{
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
