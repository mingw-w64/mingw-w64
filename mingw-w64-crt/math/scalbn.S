/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
 * Written by J.T. Conklin <jtc@netbsd.org>.
 * Public domain.
 */

	.file	"scalbn.S"
	.text
	.align 4
.globl _scalbn
	.def	_scalbn;	.scl	2;	.type	32;	.endef
_scalbn:
	fildl	12(%esp)
	fldl	4(%esp)
	fscale
	fstp	%st(1)
	ret

.globl _scalbln
	.set	_scalbln,_scalbn
