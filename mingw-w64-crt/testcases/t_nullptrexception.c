#include <stdio.h>

char *p = NULL;

int main()
{
  printf ("Raise uncaught NULL pointer exception...\n");
  *p = 0;
  return 0;
}

