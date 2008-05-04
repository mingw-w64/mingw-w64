/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"scalbnf.S"
	.text
	.align 8
.globl _scalbnf
	.def	_scalbnf;	.scl	2;	.type	32;	.endef
_scalbnf:
	movq	%rdx,-16(%rsp)
	fildl	-16(%rsp)
	movss	%xmm0,-16(%rsp)
	flds	-16(%rsp)
	fscale
	fstp	%st(1)
	fstps	-16(%rsp)
	movss	-16(%rsp),%xmm0
	ret

.globl _scalblnf
	.set	_scalblnf,_scalbnf
#else
	.file	"scalbnf.S"
	.text
	.align 4
.globl _scalbnf
	.def	_scalbnf;	.scl	2;	.type	32;	.endef
_scalbnf:
	fildl	8(%esp)
	flds	4(%esp)
	fscale
	fstp	%st(1)
	ret

.globl _scalblnf
	.set	_scalblnf,_scalbnf
#endif
