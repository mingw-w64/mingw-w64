/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"scalbnl.S"
	.text
	.align 4
.globl _scalbnl
	.def	_scalbnl;	.scl	2;	.type	32;	.endef
_scalbnl:
	fildl	(%r8)
	fldt	(%rdx)
	fscale
	fstp	%st(1)
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret

.globl _scalblnl
	.set	_scalblnl,_scalbnl
