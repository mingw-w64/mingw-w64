/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

	.file	"floor.S"
	.text
	.p2align 4,,15
.globl __MINGW_USYMBOL(floor)
	.def	__MINGW_USYMBOL(floor);	.scl	2;	.type	32;	.endef
#ifdef _WIN64
	.seh_proc __MINGW_USYMBOL(floor)
#endif
__MINGW_USYMBOL(floor):
#ifdef _WIN64
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 8(%rsp)
	movq	8(%rsp), %rdx
	movq	%rdx, %r9
	movl	%edx, %r10d
	shrq	$32, %r9
	movl	%r9d, %eax
	movl	%r9d, %r11d
	sarl	$20, %eax
	andl	$2047, %eax
	leal	-1023(%rax), %r8d
	cmpl	$51, %r8d
	jle	.L2
	cmpl	$1024, %r8d
	je	.L27
.L3:
	addq	$16, %rsp
	popq	%rbx
	ret
	.p2align 4,,10
.L2:
	cmpl	$19, %r8d
	jg	.L4
	testl	%r8d, %r8d
	js	.L28
	movl	$1048575, %eax
	movl	%r8d, %ecx
	sarl	%cl, %eax
	testl	%edx, %edx
	jne	.L8
	testl	%r9d, %eax
	je	.L3
.L8:
	movsd	.hugeval(%rip), %xmm1
	addsd	%xmm0, %xmm1
	ucomisd	.zeroval(%rip), %xmm1
	jae	.L3
	xorl	%edx, %edx
	testl	%r9d, %r9d
	js	.L29
.L9:
	addl	%edx, %r9d
	notl	%eax
	andl	%r9d, %eax
	salq	$32, %rax
	movq	%rax, 8(%rsp)
	movsd	8(%rsp), %xmm0
	jmp	.L3
	.p2align 4,,10
.L4:
	leal	-1043(%rax), %ecx
	movl	$-1, %ebx
	shrl	%cl, %ebx
	testl	%edx, %ebx
	je	.L3
	movsd	.hugeval(%rip), %xmm1
	addsd	%xmm0, %xmm1
	ucomisd	.zeroval(%rip), %xmm1
	ja	.L3
	testl	%r9d, %r9d
	js	.L30
.L11:
	notl	%ebx
	salq	$32, %r11
	andl	%ebx, %r10d
	orq	%r10, %r11
	movq	%r11, 8(%rsp)
	movsd	8(%rsp), %xmm0
	jmp	.L3
	.p2align 4,,10
.L27:
	addsd	%xmm0, %xmm0
	addq	$16, %rsp
	popq	%rbx
	ret
	.p2align 4,,10
.L28:
	movsd	.hugeval(%rip), %xmm2
	xorpd	%xmm1, %xmm1
	addsd	%xmm0, %xmm2
	ucomisd	%xmm1, %xmm2
	jbe	.L3
	testl	%r9d, %r9d
	js	.L7
	movapd	%xmm1, %xmm0
	jmp	.L3
	.p2align 4,,10
.L29:
	movl	$1048576, %edx
	movl	%r8d, %ecx
	sarl	%cl, %edx
	jmp	.L9
	.p2align 4,,10
.L30:
	cmpl	$20, %r8d
	je	.L25
	movl	$1075, %ecx
	movl	$1, %r10d
	subl	%eax, %ecx
	sall	%cl, %r10d
	addl	%edx, %r10d
	jae	.L11
.L25:
	leal	1(%r9), %r11d
	jmp	.L11
	.p2align 4,,10
.L7:
	andl	$2147483647, %r9d
	orl	%edx, %r9d
	je	.L3
	movabsq	$-4616189618054758400, %rax
	movq	%rax, 8(%rsp)
	movsd	8(%rsp), %xmm0
	jmp	.L3
	.seh_endproc

	.section .rdata,"dr"
	.align 8
.hugeval:
	.long	-2013235812
	.long	2117592124
	.align 8
.zeroval:
	.long	0
	.long	0
#else
	fldl	4(%esp)
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
