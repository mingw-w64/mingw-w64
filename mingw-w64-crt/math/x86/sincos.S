/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

	.file	"sincos.S"
	.text
	.p2align 4
	.globl __MINGW_USYMBOL(sincos)
	.def	__MINGW_USYMBOL(sincos);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(sincos):
#ifdef __x86_64__
	pushq	%rsi
	pushq	%rdi
	subq	$56, %rsp
	movaps	%xmm6, 32(%rsp)
	movq	%r8, %rsi
	movq	%rdx, %rdi
	movaps	%xmm0, %xmm6
	call	sin
	movsd	%xmm0, (%rdi)
	movaps	%xmm6, %xmm0
	call	cos
	movsd	%xmm0, (%rsi)
	movaps	32(%rsp), %xmm6
	addq	$56, %rsp
	popq	%rdi
	popq	%rsi
	retq
#else
	subl	$44, %esp
	fldl	48(%esp)
	fstl	(%esp)
	fstpl	24(%esp)
	call	_sin
	movl	56(%esp), %eax
	fstpl	(%eax)
	fldl	24(%esp)
	fstpl	(%esp)
	call	_cos
	movl	60(%esp), %eax
	fstpl	(%eax)
	addl	$44, %esp
	ret
#endif
