/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* Link this object to make program startup and fesetenv(FE_DFL_ENV) set
   the x87 precision to 24 bits (single precision).  */

#include <_mingw.h>
#include <fenv.h>
#include <float.h>

/* FE_DFL_ENV as fegetenv encodes the state after this _fpreset (x87
   control word 0x007f, MXCSR 0x1f80).  */
const fenv_t __mingw_fe_dfl_env = { 0x3f3f203f, 0 };

extern void (* __MINGW_IMP_SYMBOL(_fpreset))(void);
void _fpreset (void);

void _fpreset (void)
{
  (* __MINGW_IMP_SYMBOL(_fpreset))();
#if defined(__i386__)
  /* msvcrt _fpreset() on i386 changes the x87 precision to 53-bit,
   * so change it to 24-bit */
  _control87(_PC_24, _MCW_PC);
#elif defined(__x86_64__) && !defined(__arm64ec__)
  /* msvcrt _fpreset() on x86-64 does not touch the x87 FPU unit at all,
   * so reset it now and change the default precision to 24-bit */
  static const unsigned short cw_24bit = 0x007F;
  __asm__ __volatile__ (
    "fninit\n\t"
    "fldcw %0"
    :
    : "m" (cw_24bit)
  );
#endif
}

#ifdef __GNUC__
void __attribute__ ((alias ("_fpreset"))) fpreset(void);
#else
void fpreset(void) {
    _fpreset();
}
#endif
