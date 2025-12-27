#define _GNU_SOURCE
#include <fenv.h>
#include <internal.h>

int __cdecl fedisableexcept(int excepts)
{
  return __mingw_controlfp(excepts & FE_ALL_EXCEPT, excepts & FE_ALL_EXCEPT) & FE_ALL_EXCEPT;
}
