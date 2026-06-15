#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

char *p = NULL;

int main()
{
  mingw_test_init ();

  printf ("Raise uncaught NULL pointer exception...\n");
  *p = 0;

  return 0;
}
