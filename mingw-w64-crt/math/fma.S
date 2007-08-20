/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"fma.S"
	.text
	.align 2
	.p2align 4,,15
.globl _fma
	.def	_fma;	.scl	2;	.type	32;	.endef
_fma:
	movq	%rdx,8(%esp)
	fldl	8(%esp)
	fmull	16(%esp)
	fldl	24(%esp)
	faddp
	ret
