/*
 * Written by J.T. Conklin <jtc@netbsd.org>.
 * Public domain.
 *
 * Adaptedfor use as nearbyint by Ulrich Drepper <drepper@cygnus.com>.
 *
 * Removed header file dependency for use in libmingwex.a by
 *   Danny Smith <dannysmith@users.sourceforge.net>
 */

	.file	"nearbyintl.S"
	.text
	.align 4
.globl _nearbyintl
	.def	_nearbyintl;	.scl	2;	.type	32;	.endef
_nearbyintl:
	fldt	4(%rsp)
	pushq	%rax
	pushq	%rcx
	fnstcw	(%rsp)
	movq	(%rsp), %rax
	orq	$0x20, %rax
	movq	%rax, 8(%rsp)
	fldcw	8(%rsp)
	frndint
	fclex
	fldcw	(%esp)
	popq	%rcx
	popq	%rax
	ret
