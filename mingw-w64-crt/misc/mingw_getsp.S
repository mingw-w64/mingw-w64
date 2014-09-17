/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

	.file	"mingw_getsp.S"
	.text
#ifdef _WIN64
	.align 8
#else
	.align 4
#endif
	.globl __MINGW_USYMBOL(mingw_getsp)
	.def	__MINGW_USYMBOL(mingw_getsp);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(mingw_getsp):
#if defined(_AMD64_) || defined(__x86_64__)
	leaq  8(%rsp),%rax
	ret
#elif defined(_X86_) || defined(__i386__)
	lea	4(%esp),%eax
	ret
#elif defined(_ARM_) || defined(__arm__)
	mov	r0, sp
	bx	lr
#endif

/* On ARM:
 * Error: cannot represent BFD_RELOC_32_PCREL relocation in this object file format
 * But anyway, nothing is needed here as libarm32/libmsvcrt.a is exporting longjmp
  ldr ip, 1f
  ldr pc, [pc, ip]
  1: .long __imp_longjmp - (1b + 4)
*/
#if !(defined(_ARM_) || defined(__arm__))
	.globl __MINGW_USYMBOL(longjmp)
	.def	__MINGW_USYMBOL(longjmp);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(longjmp):
#if defined(_AMD64_) || defined(__x86_64__)
#ifndef __SEH__
  xorl %eax,%eax
  movl %eax, (%rcx)
#endif
  leaq __MINGW_IMP_LSYMBOL(longjmp)(%rip), %rax
  jmpq *(%rax)
#elif defined(_X86_) || defined(__i386__)
  jmp *__imp__longjmp
#endif
#endif /* !(defined(_ARM_) || defined(__arm__)) */
