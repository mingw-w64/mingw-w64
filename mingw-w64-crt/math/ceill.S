/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"ceill.S"
	.code64
	.text
	.align 4
.globl _ceill
	.def	_ceill;	.scl	2;	.type	32;	.endef
_ceill:
#ifdef _WIN64
	fldt	(%rdx)
	subq	$16,%rsp

	fstcw	8(%rsp)			/* store fpu control word */

	/* We use here %rdx although only the low 1 bits are defined.
	   But none of the operations should care and they are faster
	   than the 16 bit operations.  */
	movq	$0x0800,%rdx		/* round towards +oo */
	orq	8(%rsp),%rdx
	andq	$0xfbff,%rdx
	movq	%rdx,(%rsp)
	fldcw	(%rsp)			/* load modified control word */

	frndint				/* round */

	fldcw	8(%rsp)			/* restore original control word */

	addq	$16,%rsp
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret
#else
	fldt	4(%esp)
	subl	$8,%esp
	fstcw	4(%esp)
	movl	$0x0800,%edx
	orl	4(%esp),%edx
	andl	$0xfbff,%edx
	movl	%edx,(%esp)
	fldcw	(%esp)
	frndint
	fldcw	4(%esp)
	addl $8,%esp
	ret
#endif
