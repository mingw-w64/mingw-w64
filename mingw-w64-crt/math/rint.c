/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
double rint (double x){
  double retval;
  __asm__ ("frndint;" : "=t" (retval) : "0" (x));
  return retval;
}
