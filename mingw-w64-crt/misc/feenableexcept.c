#define _GNU_SOURCE
#include <fenv.h>
#include <internal.h>

int __cdecl feenableexcept(int excepts)
{
  return __mingw_controlfp(0, excepts & FE_ALL_EXCEPT) & FE_ALL_EXCEPT;
}
