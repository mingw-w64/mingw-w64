/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __FP_SIGNBIT  0x0200
int __signbitf (float x);

typedef union __mingw_flt_type_t {
  float x;
  unsigned int val;
} __mingw_flt_type_t;

int __signbitf (float x)
{
#ifdef __x86_64__
    __mingw_flt_type_t hlp;
    hlp.x = x;
    return ((hlp.val & 0x80000000) != 0);
#else
  unsigned short sw;
  __asm__ __volatile__ ("fxam; fstsw %%ax;"
	   : "=a" (sw)
	   : "t" (x) );
  return (sw & __FP_SIGNBIT) != 0;
#endif
}
int __attribute__ ((alias ("__signbitf"))) signbitf (float);
