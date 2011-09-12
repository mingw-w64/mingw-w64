#include <_mingw.h>

#ifdef _WIN64
#ifndef __SIZEOF_INT128__
typedef signed int __xint128 __attribute__ ((__mode__ (TI)));
#else
typedef signed __int128 __xint128;
#endif

__int64 _mul128(__int64, __int64, __int64 *);

__int64 _mul128(__int64 a, __int64 b, __int64 *hi)
{
  union { __xint128 v; __int64 sv[2]; } var;
  var.v = ((__xint128) a) * ((__xint128) b);
  if (hi) *hi = var.sv[1];
  return var.sv[0];
}

#endif /* _WIN64 */


