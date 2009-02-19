/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"nearbyintl.S"
	.text
	.align 8
.globl _nearbyintl
	.def	_nearbyintl;	.scl	2;	.type	32;	.endef
_nearbyintl:
	fldt	(%rdx)
	movq	%rcx,%r8
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
	movq	%r8,%rax
	fstpt	(%r8)
	ret
#else
	.file	"nearbyintl.S"
	.text
	.align 4
.globl _nearbyintl
	.def	_nearbyintl;	.scl	2;	.type	32;	.endef
_nearbyintl:
	fldt	4(%esp)
	pushl	%eax
	pushl	%ecx
	fnstcw	(%esp)
	movl	(%esp), %eax
	orl	$0x20, %eax
	movl	%eax, 4(%esp)
	fldcw	4(%esp)
	frndint
	fclex
	fldcw	(%esp)
	popl	%ecx
	popl	%eax
	ret
#endif
