/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"remquof.S"
	.text
	.align 8;
.globl _remquof;
_remquof:     
	movss	%xmm1,-12(%rsp)
	flds -12(%rsp)
	movss	%xmm0,-12(%rsp)
	flds -12(%rsp)
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
	movss %xmm0,-12(%rsp)
	movl -12(%rsp), %edx
	movss %xmm1,-12(%rsp)
	xorl -12(%rsp), %edx
	testl $0x80000000, %edx
	jz 1f
	negl %eax
1:	movl %eax, (%r8)

	fstps	-12(%rsp)
	movss	-12(%rsp),%xmm0
	ret
#else
	.file	"remquo.S"
	.text
	.align 4;
.globl _remquof;
_remquof:     
	flds 4 +4(%esp)
	flds 4(%esp)
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
	movl 4 +4 +4(%esp), %ecx
	movl 4(%esp), %edx
	xorl 4 +4(%esp), %edx
	testl $0x80000000, %edx
	jz 1f
	negl %eax
1:	movl %eax, (%ecx)

	ret
#endif
