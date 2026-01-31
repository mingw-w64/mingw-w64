/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)

#include <setjmp.h>
#include <windows.h>

void __cdecl _global_unwind2(EXCEPTION_REGISTRATION_RECORD *frame);
void __cdecl _local_unwind2(EXCEPTION_REGISTRATION_RECORD *frame, int trylevel);
__MINGW_ATTRIB_NORETURN __attribute__((nothrow)) void __cdecl __crtdll_longjmp(jmp_buf buf, int value);

__MINGW_ATTRIB_NORETURN
__attribute__((nothrow))
void __cdecl _longjmpex(jmp_buf buf, int value)
{
  _JUMP_BUFFER *bufptr = (void *)buf;

  _Static_assert(sizeof(bufptr->Registration) == sizeof(void *), "_JUMP_BUFFER.Registration has not pointer size");
  _Static_assert(sizeof(bufptr->UnwindFunc) == sizeof(void *), "_JUMP_BUFFER.UnwindFunc has not pointer size");

  /* crtdll longjmp() completely ignores Registration, TryLevel and UnwindFunc fields.
   * So do all unwinds manually before calling the real crtdll longjmp().
   */

  if (bufptr->Registration != __readfsdword(0))
    _global_unwind2((void *)bufptr->Registration);

  if (bufptr->Registration != 0) {
    if (!IsBadReadPtr(&bufptr->Cookie, sizeof(bufptr->Cookie)) && bufptr->Cookie == 0x56433230) {
      if (bufptr->UnwindFunc != 0)
        ((void(__stdcall*)(const _JUMP_BUFFER *))bufptr->UnwindFunc)(bufptr);
    } else {
      _local_unwind2((void *)bufptr->Registration, bufptr->TryLevel);
    }
  }

  __crtdll_longjmp(buf, value);
}
void (__cdecl *__MINGW_IMP_SYMBOL(_longjmpex))(jmp_buf buf, int value) = _longjmpex;

/* In msvcrt and UCRT the longjmp() function is calling SEH unwind and is aliased to _longjmpex() function. */
#undef longjmp
void __attribute__((alias("_longjmpex"))) __cdecl longjmp(jmp_buf buf, int value);
extern void __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_longjmpex)))))(__cdecl *__MINGW_IMP_SYMBOL(longjmp))(jmp_buf buf, int value);

#endif
