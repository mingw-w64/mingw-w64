#define _GNU_SOURCE
#include <fenv.h>
#include <internal.h>

int __cdecl fegetexcept(void)
{
  return __mingw_controlfp(0, 0) & FE_ALL_EXCEPT;
}
