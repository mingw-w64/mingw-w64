//  By aaronwl 2003-01-28 for mingw-msvcrt
//  Public domain: all copyrights disclaimed, absolutely no warranties */

#include <stdarg.h>
#include <stdio.h>

int vfscanf(FILE * __restrict__ stream, const char * __restrict__ format, va_list arg) {
  int ret;

  __asm__(

    /* allocate stack (esp += frame - arg3 - (8[arg1,2] + 12)) */
    "movq	%%rsp, %%r10\n\t"
    "lea	0xFFFFFFD8(%%rsp, %6), %%rsp\n\t"
    "subq	%5, %%rsp\n\t"

    // set up stack
    "movq	%1, 0x18(%%rsp)\n\t"  // stream
    "movq	%2, 0x20(%%rsp)\n\t"  // format
    "lea	0x28(%%rsp), %%rdi\n\t"
    "movq	%%rdi, (%%rsp)\n\t"  // memcpy dest
    "movq	%5, 0x8(%%rsp)\n\t"  // memcpy src
    "movq	%5, 0x10(%%rsp)\n\t"
    "subq	%6, 0x10(%%rsp)\n\t"  // memcpy len
    "call	_memcpy\n\t"
    "addq	$24, %%rsp\n\t"

    // call fscanf
    "call	_fscanf\n\t"

    // restore stack
    "movq	%%r10, %%rsp\n\t"

    : "=a"(ret), "=c"(stream), "=d"(format)
    : "1"(stream), "2"(format), "S"(arg),
      "a"(&ret)
    : "r10", "rdi");

  return ret;
}
