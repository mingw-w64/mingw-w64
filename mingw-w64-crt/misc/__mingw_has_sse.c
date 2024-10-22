/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)
int __mingw_has_sse (void);
static int __has_sse = -1;

int __mingw_has_sse(void)
{
  int cpuInfo[4], infoType = 1;
  int o_flag, n_flag;

  if (__has_sse != -1)
    return __has_sse;

  __asm__ volatile ("pushfl\n\tpopl %0" : "=mr" (o_flag));
  n_flag = o_flag ^ 0x200000;
  __asm__ volatile ("pushl %0\n\tpopfl" : : "g" (n_flag));
  __asm__ volatile ("pushfl\n\tpopl %0" : "=mr" (n_flag));
  if (n_flag == o_flag)
    {
      __has_sse = 0;
      return 0;
    }

  __asm__ __volatile__ (
    "cpuid"
    : "=a" (cpuInfo[0]), "=b" (cpuInfo[1]), "=c" (cpuInfo[2]),
    "=d" (cpuInfo[3])
    : "a" (infoType));
  __has_sse = (cpuInfo[3] & 0x2000000);
  return __has_sse;
}
#endif  /* __i386__ */
