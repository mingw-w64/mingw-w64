/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"remquo.S"
        .text
	.align 8;
.globl _remquo;
_remquo:
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
	.file	"remquo.S"
        .text
	.align 4;
.globl _remquo;
_remquo:     
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
