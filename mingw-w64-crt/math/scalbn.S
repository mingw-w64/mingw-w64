/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"scalbn.S"
	.text
	.align 4
.globl _scalbn
	.def	_scalbn;	.scl	2;	.type	32;	.endef
_scalbn:
	movsd	%xmm1,-16(%rsp)
	fildl	-16(%rsp)
	movsd	%xmm0,-16(%rsp)
	fldl	-16(%rsp)
	fscale
	fstp	%st(1)
	fstpl	-16(%rsp)
	movsd	-16(%rsp),%xmm0
	ret

.globl _scalbln
	.set	_scalbln,_scalbn
