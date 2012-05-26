/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
 #include <_mingw_mac.h>

	.file	"floorf.S"
	.text
	.p2align 4,,15
.globl __MINGW_USYMBOL(floorf)
	.def	__MINGW_USYMBOL(floorf);	.scl	2;	.type	32;	.endef
#ifdef _WIN64
	.seh_proc __MINGW_USYMBOL(floorf)
#endif
__MINGW_USYMBOL(floorf):
#ifdef _WIN64
	subq	$24, %rsp
	.seh_stackalloc	24
	.seh_endprologue
	movd	%xmm0, 12(%rsp)
	movl	12(%rsp), %eax
	movl	%eax, %ecx
	movl	%eax, %edx
	sarl	$23, %ecx
	andl	$255, %ecx
	subl	$127, %ecx
	cmpl	$22, %ecx
	jg	.l3
	testl	%ecx, %ecx
	js	.l4
	movl	$8388607, %r8d
	sarl	%cl, %r8d
	testl	%eax, %r8d
	je	.retval
	addss	.hugeval(%rip), %xmm0
	ucomiss	.zeroval(%rip), %xmm0
	jbe	.l2
	testl	%eax, %eax
	jle	.l1
	movl	$8388608, %eax
	sarl	%cl, %eax
	addl	%eax, %edx
.l1:
	movl	%r8d, %eax
	notl	%eax
	andl	%edx, %eax
.l2:
	movl	%eax, 8(%rsp)
	movss	8(%rsp), %xmm0
.retval:
	addq	$24, %rsp
	ret
	.p2align 4,,10
.l3:
	addl	$-128, %ecx
	jne	.retval
	addss	%xmm0, %xmm0
	addq	$24, %rsp
	ret
	.p2align 4,,10
.l4:
	addss	.hugeval(%rip), %xmm0
	ucomiss	.zeroval(%rip), %xmm0
	jbe	.islesseqval
	testl	%eax, %eax
	js	.l5
	movl	$1065353216, %edx
	cmovne	%edx, %eax
.islesseqval:
	movl	%eax, 8(%rsp)
	movss	8(%rsp), %xmm0
	addq	$24, %rsp
	ret
	.p2align 4,,10
.l5:
	movl	$-2147483648, 8(%rsp)
	movss	8(%rsp), %xmm0
	addq	$24, %rsp
	ret
	.seh_endproc

	.section .rdata,"dr"
	.align 4
.hugeval:
	.long	1900671690
	.align 4
.zeroval:
	.long	0
#else
	flds	4(%esp)
	subl	$8,%esp

	fstcw	4(%esp)			/* store fpu control word */

	/* We use here %edx although only the low 1 bits are defined.
	   But none of the operations should care and they are faster
	   than the 16 bit operations.  */
	movl	$0x400,%edx		/* round towards -oo */
	orl	4(%esp),%edx
	andl	$0xf7ff,%edx
	movl	%edx,(%esp)
	fldcw	(%esp)			/* load modified control word */

	frndint				/* round */

	fldcw	4(%esp)			/* restore original control word */

	addl	$8,%esp
	ret
#endif
