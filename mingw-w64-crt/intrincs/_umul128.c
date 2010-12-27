#include <_mingw.h>

#ifdef _WIN64
#ifndef __SIZEOF_INT128__
typedef unsigned int __uint128 __attribute__ ((__mode__ (TI)));
#else
typedef unsigned __int128 __uint128;
#endif

unsigned __int64 _umul128(unsigned __int64, unsigned __int64, unsigned __int64 *);

unsigned __int64 _umul128(unsigned __int64 a, unsigned __int64 b, unsigned __int64 *hi)
{
  union { __uint128 v; unsigned __int64 sv[2]; } var;
  var.v = ((__uint128) a) * ((__uint128) b);
  if (hi) *hi = var.sv[1];
  return var.sv[0];
}

#endif /* _WIN64 */


