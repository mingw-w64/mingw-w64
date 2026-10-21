/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
#include <fenv.h>

/* FE_DFL_ENV as fegetenv encodes the state after this _fpreset (x87
   control word 0x027f, MXCSR 0x1f80).  */
const fenv_t __mingw_fe_dfl_env = { 0x3f3f103f, 0 };

#if defined(__i386__)
extern void (__cdecl * const __i386_pre_msvcr80_sse_mxcsr_reset)(void);
#endif
extern void (__cdecl * __MINGW_IMP_SYMBOL(_fpreset))(void);
void __cdecl _fpreset (void);

void __cdecl _fpreset (void)
{
  (* __MINGW_IMP_SYMBOL(_fpreset))();
#if defined(__i386__)
  /* msvcrt _fpreset() on i386 changes the x87 precision to 53-bit,
   * msvcr80+ _fpreset() on i386 resets SSE MXCSR to the default,
   * pre-msvcr80 _fpreset() on i386 does not touch SSE MXCSR at all,
   * so for pre-msvcr80 reset SSE MXCSR */
  if (__i386_pre_msvcr80_sse_mxcsr_reset)
    __i386_pre_msvcr80_sse_mxcsr_reset();
#elif defined(__x86_64__) && !defined(__arm64ec__)
  /* msvcrt _fpreset() on x86-64 does not touch the x87 FPU unit at all,
   * msvcrt _fpreset() on x86-64 always resets SSE MXCSR to the default,
   * so reset x87 FPU unit now and change the x87 precision to 53-bit */
  static const unsigned short cw_53bit = 0x027F;
  __asm__ __volatile__ (
    "fninit\n\t"
    "fldcw %0"
    :
    : "m" (cw_53bit)
  );
#endif
}

#ifdef __GNUC__
void __attribute__ ((alias ("_fpreset"))) __cdecl fpreset(void);
#else
void __cdecl fpreset(void) {
    _fpreset();
}
#endif
