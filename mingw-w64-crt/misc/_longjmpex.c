/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)

#include <setjmp.h>
#include <windows.h>

__MINGW_ATTRIB_NORETURN
__attribute__((nothrow))
void __cdecl _longjmpex(jmp_buf buf, int value)
{
  _JUMP_BUFFER *bufptr = (void *)buf;

  _Static_assert(sizeof(bufptr->Registration) == sizeof(void *), "_JUMP_BUFFER.Registration has not pointer size");
  _Static_assert(sizeof(bufptr->UnwindFunc) == sizeof(void *), "_JUMP_BUFFER.UnwindFunc has not pointer size");

  if (bufptr->Registration != __readfsdword(0)) {
    /* Call: global_unwind2((void *)bufptr->Registration);
     * Function global_unwind2() is just calling the function RtlUnwind().
     * Function RtlUnwind() cannot be called easily from C source code
     * because it does not return via the return address placed on the stack
     * but it returns to the address in the second function argument on the stack.
     * It also clobbers 3 additional callee-saved registers: ebx, esi and edi.
     * So call the RtlUnwind((void *)bufptr->Registration, ret_addr, NULL, NULL);
     * via the inline assembly.
     */
    asm volatile(
      "pushl $0\n\t"
      "pushl $0\n\t"
      "pushl $1f\n\t" /* label after calll */
      "pushl %%eax\n\t"
      "calll _RtlUnwind@16\n\t"
      "1:"
      :
      : "a" (bufptr->Registration) /* cannot be passed as esp-relative memory reference */
      : "ecx", "edx", /* additional stdcall clobbered registers */
        "ebx", "esi", "edi", /* additional RtlUnwind clobbered registers */
        "cc", "memory"
    );
  }

  if (bufptr->Registration != 0) {
    if (!IsBadReadPtr(&bufptr->Cookie, sizeof(bufptr->Cookie)) && bufptr->Cookie == 0x56433230) {
      if (bufptr->UnwindFunc != 0)
        ((void(__stdcall*)(const _JUMP_BUFFER *))bufptr->UnwindFunc)(bufptr);
    } else {
      /* Call _local_unwind2((void *)bufptr->Registration, bufptr->TryLevel);
       * TODO: mingw-w64 does not provide _local_unwind2() implementation yet.
       */
    }
  }

  if (value == 0) value = 1;
  asm volatile(
    "movl 0(%%ecx),%%ebp\n\t"  /* jmp_buf->Ebp */
    "movl 4(%%ecx),%%ebx\n\t"  /* jmp_buf->Ebx */
    "movl 8(%%ecx),%%edi\n\t"  /* jmp_buf->Edi */
    "movl 12(%%ecx),%%esi\n\t" /* jmp_buf->Esi */
    "movl 16(%%ecx),%%esp\n\t" /* jmp_buf->Esp */
    "addl $4,%%esp\n\t"        /* get rid of return address */
    "jmpl *20(%%ecx)"          /* jmp_buf->Eip */
    :
    : "a" (value), "c" (buf)
    : "memory"
  );
  __builtin_unreachable();
}
void (__cdecl *__MINGW_IMP_SYMBOL(_longjmpex))(jmp_buf buf, int value) = _longjmpex;

/* In msvcrt and UCRT the longjmp() function is calling SEH unwind and is aliased to _longjmpex() function. */
#undef longjmp
void __attribute__((alias("_longjmpex"))) __cdecl longjmp(jmp_buf buf, int value);
extern void __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_longjmpex)))))(__cdecl *__MINGW_IMP_SYMBOL(longjmp))(jmp_buf buf, int value);

#endif
