/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <_mingw_mac.h>

	.file	"remquo.S"
        .text
#ifdef _WIN64
	.align 8
#else
	.align 4
#endif
.globl __MINGW_USYMBOL(remquo)
__MINGW_USYMBOL(remquo):
#ifdef _WIN64
	movsd	%xmm1,-16(%rsp)
	fldl	-16(%rsp)
	movsd	%xmm0,-16(%rsp)
	fldl	-16(%rsp)
1:	fprem1
	fstsw %ax
	sahf
	jp 1b
	fstp %st(1)
	movl %eax, %ecx
	shrl $8, %eax
	shrl $12, %ecx
	andl $4, %ecx
	andl $3, %eax
	orl %eax, %ecx
	movl $0xef2960, %eax
	shrl %cl, %eax
	andl $3, %eax
	movl -12(%rsp), %edx
	movsd %xmm1,-16(%rsp)
	xorl -12(%rsp), %edx
	testl $0x80000000, %edx
	jz 1f
	negl %eax
1:	movl %eax, (%r8)

	fstpl	-16(%rsp)
	movsd	-16(%rsp),%xmm0
	ret
#else
	fldl 4 +8(%esp)
	fldl 4(%esp)
1:	fprem1
	fstsw %ax
	sahf
	jp 1b
	fstp %st(1)
	movl %eax, %ecx
	shrl $8, %eax
	shrl $12, %ecx
	andl $4, %ecx
	andl $3, %eax
	orl %eax, %ecx
	movl $0xef2960, %eax
	shrl %cl, %eax
	andl $3, %eax
	movl 4 +8 +8(%esp), %ecx      
	movl 4 +4(%esp), %edx
	xorl 4 +8 +4(%esp), %edx
	testl $0x80000000, %edx
	jz 1f
	negl %eax
1:	movl %eax, (%ecx)

	ret
#endif
