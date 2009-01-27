/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <internal.h>
#include <math.h>

int __defaultmatherr = 1;

int __CRTDECL
_matherr (struct _exception *pexcept)
{
  /* Make compiler happy.  */
  pexcept = pexcept;
  return 0;
}
