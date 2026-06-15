/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* mingw-w64 headers */
#include "libtest.h"

int main(int argc, char **argv)
{
  mingw_test_init ();
  assert (argc >= 1);
  assert (argv != NULL);
  assert (argv[0] != NULL);
  return 0;
}
