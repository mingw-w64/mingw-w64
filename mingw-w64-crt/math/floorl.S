/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"floorl.S"
	.text
	.align 4
.globl _floorl
	.def	_floorl;	.scl	2;	.type	32;	.endef
_floorl:
	fldt	(%rdx)
	subq	$16,%rsp

	fstcw	8(%rsp)			/* store fpu control word */

	/* We use here %edx although only the low 1 bits are defined.
	   But none of the operations should care and they are faster
	   than the 16 bit operations.  */
	movl	$0x400,%edx		/* round towards -oo */
	orl	8(%rsp),%edx
	andl	$0xf7ff,%edx
	movl	%edx,(%rsp)
	fldcw	(%rsp)			/* load modified control word */

	frndint				/* round */

	fldcw	8(%rsp)			/* restore original control word */

	addq	$16,%rsp
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret
