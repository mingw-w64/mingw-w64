/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"fmaf.S"
	.text
	.align 2
	.p2align 4,,15
.globl _fmaf
	.def	_fmaf;	.scl	2;	.type	32;	.endef
_fmaf:
	movss	%xmm0,-12(%rsp)
	movss	%xmm1,-20(%rsp)
	movss	%xmm2,-28(%rsp)
	flds	-12(%rsp)
	fmuls	-20(%rsp)
	flds	-28(%rsp)
	faddp
	fstps	-12(%rsp)
	movss	-12(%rsp),%xmm0
	ret
