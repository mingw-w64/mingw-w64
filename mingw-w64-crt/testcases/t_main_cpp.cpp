/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdio.h>
#include <stdlib.h>

// mingw-w64 headers
#include "libtest.h"

int main(int argc, char **argv)
{
  mingw_test_init ();
  printf ("Hallo world!\n");
  return 0;
}
