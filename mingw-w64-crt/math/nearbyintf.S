/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"nearbyintf.S"
	.text
	.align 8
.globl _nearbyintf
	.def	_nearbyintf;	.scl	2;	.type	32;	.endef
_nearbyintf:
	movss	%xmm0,-12(%rsp)
	flds	-12(%rsp)
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
	fstps	-12(%rsp)
	movss	-12(%rsp),%xmm0
	ret
