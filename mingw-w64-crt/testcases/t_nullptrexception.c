#include <stdio.h>

int main()
{
  char *p = NULL;

  printf ("Raise uncaught NULL pointer exception...\n");
  *p = 0;
  return 0;
}

