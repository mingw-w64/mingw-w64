#include <stdio.h>

void foo (int d) throw (int)
{
  throw (d);
}

int main()
{
  try {
   foo (10);
   printf ("Hmm...\n");
  } catch (int ex)
  {
    printf ("catch %d==10\n", ex);
  }
  printf ("Done.\n");
  return 0;
}

