/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"remainder.S"
	.text
	.align 4
.globl _remainder
	.def	_remainder;	.scl	2;	.type	32;	.endef
_remainder:
	movsd	%xmm0,-16(%rsp)
	movsd	%xmm1,-32(%rsp)
	fldl	-32(%rsp)
	fldl	-16(%rsp)
1:	fprem1
	fstsw	%ax
	sahf
	jp	1b
	fstp	%st(1)
	fstpl	-16(%rsp)
	movsd	-16(%rsp),%xmm0
	ret
