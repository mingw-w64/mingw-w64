/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
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
#ifdef _WIN64
	leaq  8(%rsp),%rax
#else
	lea	4(%esp),%eax
#endif
	ret

.globl __MINGW_USYMBOL(longjmp)
	.def	__MINGW_USYMBOL(longjmp);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(longjmp):
#ifdef _WIN64
  xorl %eax,%eax
  movl %eax, (%rcx)
  leaq __MINGW_USYMBOL(fctMsvcrtLongJmp)(%rip), %rax
  jmpq *(%rax)
#else
  jmp *__MINGW_USYMBOL(fctMsvcrtLongJmp)
#endif
