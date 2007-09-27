/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"nearbyint.S"
	.text
	.align 8
.globl _nearbyint
	.def	_nearbyint;	.scl	2;	.type	32;	.endef
_nearbyint:
	movsd	%xmm0,-16(%rsp)
	fldl	-16(%rsp)
	pushq	%rax
	pushq	%rcx
	fnstcw	(%rsp)
	movq	(%rsp), %rax
	orq	$0x20, %rax
	movq	%rax, 8(%rsp)
	fldcw	8(%rsp)
	frndint
	fclex
	fldcw	(%rsp)
	popq	%rcx
	popq	%rax
	fstpl	-16(%rsp)
	movsd	-16(%rsp),%xmm0
	ret
