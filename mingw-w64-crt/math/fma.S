/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"fma.S"
	.text
	.align 2
	.p2align 4,,15
.globl _fma
	.def	_fma;	.scl	2;	.type	32;	.endef
_fma:
	movsd	%xmm0,-16(%rsp)
	movsd	%xmm1,-24(%rsp)
	movsd	%xmm2,-32(%rsp)
	fldl	-16(%rsp)
	fmull	-24(%rsp)
	fldl	-32(%rsp)
	faddp
	fstpl	-16(%rsp)
	movsd	-16(%rsp),%xmm0
	ret
#else
	.file	"fma.S"
	.text
	.align 2
	.p2align 4,,15
.globl _fma
	.def	_fma;	.scl	2;	.type	32;	.endef
_fma:
	fldl	4(%esp)
	fmull	12(%esp)
	fldl	20(%esp)
	faddp
	ret
#endif
