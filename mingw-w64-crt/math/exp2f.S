/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"exp2f.S"
	.text
	.align 8
.globl _exp2f
	.def	_exp2f;	.scl	2;	.type	32;	.endef
_exp2f:
	movss	%xmm0,-12(%rsp)
	flds	-12(%rsp)
	fxam				/* Is NaN or +-Inf?  */
	fstsw	%ax
	movb	$0x45, %dh
	andb	%ah, %dh
	cmpb	$0x05, %dh
	je	1f			/* Is +-Inf, jump.  */
	fld	%st
	frndint				/* int(x) */
	fsubr	%st,%st(1)		/* fract(x) */
	fxch
	f2xm1				/* 2^(fract(x)) - 1 */
	fld1
	faddp				/* 2^(fract(x)) */
	fscale				/* e^x */
	fstp	%st(1)
	fstps	-12(%rsp)
	movss	-12(%rsp),%xmm0
	ret

1:	testl	$0x200, %eax		/* Test sign.  */
	jz	2f			/* If positive, jump.  */
	fstp	%st
	fldz				/* Set result to 0.  */
2:	fstps	-12(%rsp)
	movss	-12(%rsp),%xmm0
	ret
