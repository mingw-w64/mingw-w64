/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

long double
fmaxl (long double _x, long double  _y)
{
  return (( isgreaterequal(_x, _y) || __isnanl (_y)) ?  _x : _y );
}
