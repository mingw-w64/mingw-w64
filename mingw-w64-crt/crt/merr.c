/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <internal.h>
#include <math.h>
#include <stdio.h>

int __defaultmatherr = 0;

int __CRTDECL
_matherr (struct _exception *pexcept)
{
  /* Make compiler happy.  */
  pexcept = pexcept;
  printf ("_matherr\n");
  return 0;
}
