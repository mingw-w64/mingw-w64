#define _GNU_SOURCE
#include <fenv.h>
#include <internal.h>

int __cdecl fedisableexcept(int excepts)
{
  if (excepts & ~FE_ALL_EXCEPT) return -1;
  int old_excepts = fegetexcept();
  __mingw_controlfp(excepts, excepts);
  return old_excepts;
}
