/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdarg.h>
#include <stdio.h>

#if defined(_AMD64_) || defined(__x86_64__) || \
  defined(_X86_) || defined(__i386__)

extern int __ms_vsscanf_internal (
  const char * s,
  const char * format,
  va_list arg,
  int (*func)(const char * __restrict__,  const char * __restrict__, ...))
  asm("__argtos");

#elif defined (__arm__) || defined (_ARM_)

#define QUOTE_(x) #x
#define QUOTE(x) QUOTE_(x)

int __ms_vsscanf_internal (const char * __restrict__,
  const char * __restrict__, va_list);
asm("\t.text\n"
    "\t.align 2\n"
    "\t.thumb_func\n"
    "\t.globl __ms_vsscanf_internal\n"
    "__ms_vsscanf_internal:\n\t"
    "push {r4-r7, lr}\n\t"
    "mov r4, sp\n\t"
    "sub r4, r4, #128\n\t"

    "ldr r5, [r2]\n\t"
    "add r2, r2, #4\n\t"
    "ldr r6, [r2]\n\t"
    "add r2, r2, #4\n\t"

    "mov r3, #116\n\t"
    "1: ldr r7, [r2]\n\t"
    "add r2, r2, #4\n\t"
    "str r7, [r4]\n\t"
    "add r4, r4, #4\n\t"
    "sub r3, r3, #4\n\t"
    "cmp r3, #0\n\t"
    "bne 1b\n\t"

    "sub sp, sp, #128\n\t"
    "mov r2, r5\n\t"
    "mov r3, r6\n\t"
    "bl " QUOTE(__MINGW_USYMBOL(sscanf)) "\n\t"
    "add sp, sp, #128\n\t"
    "pop {r4-r7, pc}");

#endif /* defined (__arm__) || defined (_ARM_) */

int __ms_vsscanf (const char * __restrict__ s,
  const char * __restrict__ format, va_list arg)
{
  int ret;

#if defined(_AMD64_) || defined(__x86_64__) || \
  defined(_X86_) || defined(__i386__)
  ret = __ms_vsscanf_internal (s, format, arg, sscanf);
#elif defined (_ARM_) || defined (__arm__)
  ret = __ms_vsscanf_internal (s, format, arg);
#else
#error "unknown platform"
#endif

  return ret;
}
