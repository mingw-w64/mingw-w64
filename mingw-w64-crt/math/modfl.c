/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>
#include <math.h>
#include <errno.h>
#define FE_ROUNDING_MASK \
  (FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO)

long double
modfl (long double value, long double* iptr)
{
  long double int_part = 0.0L;
  /* truncate */
#ifdef _WIN64
  asm ("subq $8, %%rsp\n"
    "fnstcw 4(%%rsp)\n"
    "movzwl 4(%%rsp), %%eax\n"
    "orb $12, %%ah\n"
    "movw %%ax, (%%rsp)\n"
    "fldcw (%%rsp)\n"
    "frndint\n"
    "fldcw 4(%%rsp)\n"
    "addq $8, %%rsp\n" : "=t" (int_part) : "0" (value)); /* round */
#else
  asm ("push %%eax\n\tsubl $8, %%esp\n"
    "fnstcw 4(%%esp)\n"
    "movzwl 4(%%esp), %%eax\n"
    "orb $12, %%ah\n"
    "movw %%ax, (%%esp)\n"
    "fldcw (%%esp)\n"
    "frndint\n"
    "fldcw 4(%%esp)\n"
    "addl $8, %%esp\n\tpop %%eax\n" : "=t" (int_part) : "0" (value)); /* round */
#endif
  if (iptr)
    *iptr = int_part;
  return (isinf (value) ?  0.0L : value - int_part);
}
