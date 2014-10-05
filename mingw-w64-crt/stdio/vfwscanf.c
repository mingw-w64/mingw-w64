/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
//  By aaronwl 2003-01-28 for mingw-msvcrt.
//  Public domain: all copyrights disclaimed, absolutely no warranties.

#include <stdarg.h>
#include <wchar.h>

#define QUOTE_(x) #x
#define QUOTE(x) QUOTE_(x)

#if defined(__arm__) || defined(_ARM_)
int __ms_vfwscanf_internal(FILE * __restrict__, const char * __restrict__, va_list);
asm("\t.text\n"
    "\t.align 2\n"
    "\t.thumb_func\n"
    "\t.globl __ms_vfwscanf_internal\n"
    "__ms_vfwscanf_internal:\n\t"
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
    "bl " QUOTE(__MINGW_USYMBOL(fwscanf)) "\n\t"
    "add sp, sp, #128\n\t"
    "pop {r4-r7, pc}");
#endif /* defined(__arm__) || defined(_ARM_) */

int __ms_vfwscanf (FILE * __restrict__ stream, const wchar_t * __restrict__ format,
  va_list arg) {

  int ret;

#if defined(_AMD64_) || defined(__x86_64__)
  __asm__ __volatile__ (

    // allocate stack (esp += frame - arg3 - (8[arg1,2] + 12))
    "movq	%%rsp, %%rbx\n\t"
    "lea	0xFFFFFFFFFFFFFFD8(%%rsp, %6), %%rsp\n\t"
    "subq	%5, %%rsp\n\t"

    // set up stack
    "movq	%1, 0x18(%%rsp)\n\t"  // stream
    "movq	%2, 0x20(%%rsp)\n\t"  // format
    "lea	0x28(%%rsp), %%rdi\n\t"
    "movq	%%rdi, (%%rsp)\n\t"  // memcpy dest
    "movq	%5, 0x8(%%rsp)\n\t"  // memcpy src
    "movq	%5, 0x10(%%rsp)\n\t"
    "subq	%6, 0x10(%%rsp)\n\t"  // memcpy len
    "movq   0x10(%%rsp), %%r8\n\t"
    "movq   0x8(%%rsp), %%rdx\n\t"
    "movq   (%%rsp),  %%rcx\n\t"
    "call	" QUOTE(__MINGW_USYMBOL(memcpy)) "\n\t"
    "addq	$24, %%rsp\n\t"

    // call fwscanf
    "movq   0x18(%%rsp), %%r9\n\t"
    "movq   0x10(%%rsp), %%r8\n\t"
    "movq   0x8(%%rsp), %%rdx\n\t"
    "movq   (%%rsp),  %%rcx\n\t"
    "call	" QUOTE(__MINGW_USYMBOL(fwscanf)) "\n\t"

    // restore stack
    "movq	%%rbx, %%rsp\n\t"

    : "=a"(ret), "=c"(stream), "=d"(format)
    : "1"(stream), "2"(format), "S"(arg),
      "a"(&ret)
    : "rbx", "rdi");
#elif defined(_X86_) || defined(__i386__)
  __asm__ __volatile__ (

    // allocate stack (esp += frame - arg3 - (8[arg1,2] + 12))
    "movl	%%esp, %%ebx\n\t"
    "lea	0xFFFFFFEC(%%esp, %6), %%esp\n\t"
    "subl	%5, %%esp\n\t"

    // set up stack
    "movl	%1, 0xC(%%esp)\n\t"  // stream
    "movl	%2, 0x10(%%esp)\n\t"  // format
    "lea	0x14(%%esp), %%edi\n\t"
    "movl	%%edi, (%%esp)\n\t"  // memcpy dest
    "movl	%5, 0x4(%%esp)\n\t"  // memcpy src
    "movl	%5, 0x8(%%esp)\n\t"
    "subl	%6, 0x8(%%esp)\n\t"  // memcpy len
    "call	" QUOTE(__MINGW_USYMBOL(memcpy)) "\n\t"
    "addl	$12, %%esp\n\t"

    // call fscanf
    "call	" QUOTE(__MINGW_USYMBOL(fwscanf)) "\n\t"

    // restore stack
    "movl	%%ebx, %%esp\n\t"

    : "=a"(ret), "=c"(stream), "=d"(format)
    : "1"(stream), "2"(format), "S"(arg),
      "a"(&ret)
    : "ebx", "edi");
#elif defined(_ARM_) || defined(__arm__)
    ret = __ms_vfwscanf_internal(stream, format, arg);
#endif

  return ret;
}
