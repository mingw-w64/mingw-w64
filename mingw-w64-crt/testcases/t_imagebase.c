#include <stdio.h>

/* mingw-w64 headers */
#include "libtest.h"

extern unsigned int __ImageBase;

int main()
{
  mingw_test_init ();
  printf ("%x\n", __ImageBase);
  return 0;
}
