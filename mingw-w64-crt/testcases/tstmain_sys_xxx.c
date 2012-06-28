/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdio.h>

_CRTIMP char *_sys_errlist[];

int main(int argc, char **argv)
{
  char **s = (char **) _sys_errlist;
  if (s) printf ("Msg 0: %s\n", s[0]);
  else printf ("Error list empty.\n");
  return 0;
}
