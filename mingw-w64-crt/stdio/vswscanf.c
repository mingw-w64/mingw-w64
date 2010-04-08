/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
//  By aaronwl 2003-01-28 for mingw-msvcrt
//  Public domain: all copyrights disclaimed, absolutely no warranties */

#include <stdarg.h>
#include <wchar.h>

#define QUOTE_(x) #x
#define QUOTE(x) QUOTE_(x)

int vswscanf(const wchar_t * __restrict__ s, const wchar_t * __restrict__ format,
  va_list arg)
{
  int ret;

#ifdef _WIN64
  __asm__ __volatile__ (

    // allocate stack (esp += frame - arg3 - (8[arg1,2] + 12))
    "movq	%%rsp, %%rbx\n\t"
    "lea	0xFFFFFFFFFFFFFFD8(%%rsp, %6), %%rsp\n\t"
    "subq	%5, %%rsp\n\t"

    // set up stack
    "movq	%1, 0x18(%%rsp)\n\t"  // s
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

    // call sscanf
    "movq   0x18(%%rsp), %%r9\n\t"
    "movq   0x10(%%rsp), %%r8\n\t"
    "movq   0x8(%%rsp), %%rdx\n\t"
    "movq   (%%rsp),  %%rcx\n\t"
    "call	" QUOTE(__MINGW_USYMBOL(swscanf)) "\n\t"

    // restore stack
    "movq	%%rbx, %%rsp\n\t"

    : "=a"(ret), "=c"(s), "=d"(format)
    : "1"(s), "2"(format), "S"(arg),
      "a"(&ret)
    : "rbx", "rdi");
#else
  __asm__ __volatile__ (

    // allocate stack (esp += frame - arg3 - (8[arg1,2] + 12))
    "movl	%%esp, %%ebx\n\t"
    "lea	0xFFFFFFEC(%%esp, %6), %%esp\n\t"
    "subl	%5, %%esp\n\t"

    // set up stack
    "movl	%1, 0xC(%%esp)\n\t"  // s
    "movl	%2, 0x10(%%esp)\n\t"  // format
    "lea	0x14(%%esp), %%edi\n\t"
    "movl	%%edi, (%%esp)\n\t"  // memcpy dest
    "movl	%5, 0x4(%%esp)\n\t"  // memcpy src
    "movl	%5, 0x8(%%esp)\n\t"
    "subl	%6, 0x8(%%esp)\n\t"  // memcpy len
    "call	" QUOTE(__MINGW_USYMBOL(memcpy)) "\n\t"
    "addl	$12, %%esp\n\t"

    // call sscanf
    "call	" QUOTE(__MINGW_USYMBOL(swscanf)) "\n\t"

    // restore stack
    "movl	%%ebx, %%esp\n\t"

    : "=a"(ret), "=c"(s), "=d"(format)
    : "1"(s), "2"(format), "S"(arg),
      "a"(&ret)
    : "ebx", "edi");
#endif
  return ret;
}
