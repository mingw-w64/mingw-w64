/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>

int __mingw_has_sse (void);

int __mingw_has_sse(void)
{
  int cpuInfo[4],infoType = 1;
  
#ifndef _WIN64
  int o_flag, n_flag;
  
  __asm__ volatile ("pushfl\n\tpopl %0" : "=mr" (o_flag));
  n_flag = o_flag ^ 0x200000;
  __asm__ volatile ("pushl %0\n\tpopfl" : : "g" (n_flag));
  __asm__ volatile ("pushfl\n\tpopl %0" : "=mr" (n_flag));
  if (n_flag == o_flag)
    return 0;
#endif
	
  __asm__ __volatile__ (
    "cpuid"
    : "=a" (cpuInfo[0]), "=b" (cpuInfo[1]), "=c" (cpuInfo[2]),
    "=d" (cpuInfo[3])
    : "a" (infoType));
  if (cpuInfo[3] & 0x2000000)
    return 1;
  return 0;
}

/* 7.6.2.1
   The feclearexcept function clears the supported exceptions
   represented by its argument.  */

int feclearexcept (int excepts)
{
  fenv_t _env;
  int _mxcsr;

  if (excepts == FE_ALL_EXCEPT)
    {
      __asm__ volatile ("fnclex");
    }
  else
    {
      __asm__ volatile ("fnstenv %0" : "=m" (_env));
      _env.__status_word &= ~(excepts & FE_ALL_EXCEPT);
      __asm__ volatile ("fldenv %0" : : "m" (_env));
    }
  if (__mingw_has_sse ())
    {
      __asm__ volatile ("stmxcsr %0" : "=m" (_mxcsr));
      _mxcsr &= ~(((excepts & FE_ALL_EXCEPT)));
      __asm__ volatile ("ldmxcsr %0" : : "m" (_mxcsr));
    }
  return (0);
}
