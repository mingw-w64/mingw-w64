/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
#include <fenv.h>
#include <float.h>

/* FE_DFL_ENV as fegetenv encodes the state after this _fpreset (x87
   control word 0x037f, MXCSR 0x1f80).  */
const fenv_t __mingw_fe_dfl_env = { 0x3f3f003f, 0 };

extern void (* __MINGW_IMP_SYMBOL(_fpreset))(void);
void _fpreset (void);

void _fpreset (void)
{
  (* __MINGW_IMP_SYMBOL(_fpreset))();
#if defined(__i386__)
  /* msvcrt _fpreset() on i386 changes the x87 precision to 53-bit,
   * so change it back to 64-bit */
  _control87(_PC_64, _MCW_PC);
#elif defined(__x86_64__) && !defined(__arm64ec__)
  /* msvcrt _fpreset() on x86-64 does not touch the x87 FPU unit at all,
   * so reset it now (the default precision after reset is 64-bit) */
  __asm__ ("fninit");
#endif
}

#ifdef __GNUC__
void __attribute__ ((alias ("_fpreset"))) fpreset(void);
#else
void fpreset(void) {
    _fpreset();
}
#endif
