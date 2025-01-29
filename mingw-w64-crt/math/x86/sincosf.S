/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

	.file	"sincosf.S"
	.text
	.p2align 4
	.globl __MINGW_USYMBOL(sincosf)
	.def	__MINGW_USYMBOL(sincosf);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(sincosf):
#ifdef __x86_64__
	pushq	%rsi
	pushq	%rdi
	subq	$56, %rsp
	movaps	%xmm6, 32(%rsp)
	movq	%r8, %rsi
	movq	%rdx, %rdi
	movaps	%xmm0, %xmm6
	call	sinf
	movss	%xmm0, (%rdi)
	movaps	%xmm6, %xmm0
	call	cosf
	movss	%xmm0, (%rsi)
	movaps	32(%rsp), %xmm6
	addq	$56, %rsp
	popq	%rdi
	popq	%rsi
	retq
#else
	subl	$28, %esp
	flds	32(%esp)
	fstps	(%esp)
	call	_sinf
	movl	36(%esp), %eax
	fstps	(%eax)
	flds	32(%esp)
	fstps	(%esp)
	call	_cosf
	movl	40(%esp), %eax
	fstps	(%eax)
	addl	$28, %esp
	ret
#endif
