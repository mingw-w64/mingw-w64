/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)

#include <setjmp.h>
#include <windows.h>

void __cdecl _global_unwind2(EXCEPTION_REGISTRATION_RECORD *frame);
__MINGW_ATTRIB_NORETURN __attribute__((nothrow)) void __cdecl __msvcrt10_longjmp(jmp_buf buf, int value);

struct msvcrt10_establisher_frame {
  EXCEPTION_REGISTRATION_RECORD ExceptionRecord;
  const void *ScopeTable;
  DWORD TryLevel;
};

__MINGW_ATTRIB_NORETURN
__attribute__((nothrow))
void __cdecl _longjmpex(jmp_buf buf, int value)
{
  _JUMP_BUFFER *bufptr = (void *)buf;

  _Static_assert(sizeof(bufptr->Registration) == sizeof(void *), "_JUMP_BUFFER.Registration has not pointer size");
  _Static_assert(sizeof(bufptr->UnwindFunc) == sizeof(void *), "_JUMP_BUFFER.UnwindFunc has not pointer size");

  /* msvcrt10 longjmp() for non-zero bufptr->Registration is unconditionally
   * calling local_unwind2() with bufptr->Registration as SEH establisher frame
   * and with bufptr->TryLevel as try level.
   *
   * msvcrt10 local_unwind2() is expecting that the passed SEH establisher frame
   * is of the msvcrt10 format, which contains additional fields: scope table and try level.
   * It will do nothing if the SEH establisher frame's try level is -1 or if it is
   * the same as the try level passed as the function argument. Otherwise it will
   * dereference the scope table pointer and call the specified unwind handlers.
   *
   * Therefore the msvcrt10 longjmp() can be called only if the bufptr->Registration
   * is a valid SEH establisher frame in the msvcrt10 format (with additional fields).
   * All SEH handlers registered by mingw-w64 are just standard SEH establisher
   * frame structures without any additional msvcrt10 fields. To prevent using and
   * dereferencing the scope table pointer (which is after the standard SEH
   * establisher frame), set bufptr->TryLevel to the value which msvcrt10
   * local_unwind2() reads from the try level position of the msvcrt10 SEH
   * establisher frame format. It is some value on the stack which does not belong
   * to the SEH establisher frame, but reading it should not cause any memory corruption.
   *
   * As msvcrt10 longjmp() does not support bufptr->Cookie and bufptr->UnwindFunc
   * fields, for the non-zero bufptr->UnwindFunc case, it is needed to do all
   * unwinds manually. msvcrt10 longjmp() is always calling the _global_unwind2(),
   * but the bufptr->UnwindFunc has to be called after _global_unwind2().
   * As _global_unwind2() unregisters SEH handlers (up to the specified one),
   * it is idempotent and so can be called multiple times.
   */

  if (bufptr->Registration != 0 && !IsBadReadPtr(&bufptr->Cookie, sizeof(bufptr->Cookie)) && bufptr->Cookie == 0x56433230) {
    if (bufptr->UnwindFunc != 0) {
      if (bufptr->Registration != __readfsdword(0))
        _global_unwind2((void *)bufptr->Registration);
      ((void(__stdcall*)(const _JUMP_BUFFER *))bufptr->UnwindFunc)(bufptr);
    }
    bufptr->TryLevel = ((struct msvcrt10_establisher_frame *)bufptr->Registration)->TryLevel;
  }

  __msvcrt10_longjmp(buf, value);
}
void (__cdecl *__MINGW_IMP_SYMBOL(_longjmpex))(jmp_buf buf, int value) = _longjmpex;

/* In msvcrt and UCRT the longjmp() function is calling SEH unwind and is aliased to _longjmpex() function. */
#undef longjmp
void __attribute__((alias("_longjmpex"))) __cdecl longjmp(jmp_buf buf, int value);
extern void __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_longjmpex)))))(__cdecl *__MINGW_IMP_SYMBOL(longjmp))(jmp_buf buf, int value);

#endif
