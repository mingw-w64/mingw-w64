/*
 * Written by J.T. Conklin <jtc@netbsd.org>.
 * Public domain.
 * Adapted for use as nearbyint by Ulrich Drepper <drepper@cygnus.com>.
 * 
 * Removed header file dependency for use in libmingwex.a by
 *   Danny Smith <dannysmith@users.sourceforge.net>
 */

	.file	"nearbyintf.S"
	.text
	.align 4
.globl _nearbyintf
	.def	_nearbyintf;	.scl	2;	.type	32;	.endef
_nearbyintf:
	flds	8(%rsp)
	pushq	%rax
	pushq	%rcx
	fnstcw	(%rsp)
	movq	(%rsp), %rax
	orq	$0x20, %rax
	movq	%rax, 8(%rsp)
	fldcw	8(%rsp)
	frndint
	fclex
	fldcw	(%rsp)
	popq	%rcx
	popq	%rax
	ret
