/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <_mingw_mac.h>

	.file	"nearbyintf.S"
	.text
#ifdef _WIN64
	.align 8
#else
	.align 4
#endif
.globl __MINGW_USYMBOL(nearbyintf)
	.def	__MINGW_USYMBOL(nearbyintf);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(nearbyintf):
#ifdef _WIN64
	movss	%xmm0,-12(%rsp)
	flds	-12(%rsp)
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
	fstps	-12(%rsp)
	movss	-12(%rsp),%xmm0
	ret
#else
	flds	4(%esp)
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
