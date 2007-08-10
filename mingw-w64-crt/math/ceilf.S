	.file	"ceilf.S"
	.code64
	.text
	.align 4
.globl _ceilf
	.def	_ceilf;	.scl	2;	.type	32;	.endef
_ceilf:
	movq %xmm0,8(%rsp)
	flds	8(%rsp)
	subq	$16,%rsp

	fstcw	8(%rsp)			/* store fpu control word */

	/* We use here %edx although only the low 1 bits are defined.
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
	ret
