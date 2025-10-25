#include <stdio.h>
#include <windows.h>

char *p = NULL;

int main()
{
  SetErrorMode(SetErrorMode(0) | SEM_NOGPFAULTERRORBOX);
  printf ("Raise uncaught NULL pointer exception...\n");
  *p = 0;
  return 0;
}

