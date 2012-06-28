/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv)
{
  printf ("Is argc (%d) < 3 ?\n", argc);
  assert (argc < 3);
  printf ("No assert !\n");
  return 0;
}
