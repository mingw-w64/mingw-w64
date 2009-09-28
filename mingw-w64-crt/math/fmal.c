/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
long double fmal ( long double _x,  long double _y,  long double _z);

long double
fmal ( long double _x,  long double _y,  long double _z)
{
  return ((_x * _y) + _z);
}
