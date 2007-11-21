/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"remquol.S"
        .text
	.align 4;
.globl _remquol;
 _remquol:
 	pushq	%rcx
        fldt (%r8)
        fldt (%rdx)
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
        movl 8(%rdx), %edx
        xorl 8(%r8), %edx
        testl $0x8000, %edx
        jz 1f
        negl %eax
1:	movl %eax, (%r9)

	popq %rcx
	movq %rcx,%rax
	fstpt	(%rcx)
        ret
#else
	.file	"remquol.S"
        .text
	.align 4;
.globl _remquol;
 _remquol:
        fldt 4 +12(%esp)
        fldt 4(%esp)
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
        movl 4 +12 +12(%esp), %ecx      
        movl 4 +8(%esp), %edx
        xorl 4 +12 +8(%esp), %edx
        testl $0x8000, %edx
        jz 1f
        negl %eax
1:	movl %eax, (%ecx)
      
        ret
#endif
