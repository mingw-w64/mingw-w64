/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

	.file	"ilogb.S"
	.text
	.align 8
.globl _ilogb
	.def	_ilogb;	.scl	2;	.type	32;	.endef
_ilogb:
	movsd	%xmm0,-16(%rsp)
	fldl	-16(%rsp)
	fxam			/* Is NaN or +-Inf?  */
	fstsw   %ax
	movb    $0x45, %dh
	andb    %ah, %dh
	cmpb    $0x05, %dh
	je      1f		/* Is +-Inf, jump.  */

	fxtract
	pushq	%rax
	fstp	%st

	fistpl	(%rsp)
	fwait
	popq	%rax

	ret

1:	fstp	%st
	movl	$0x7fffffff, %eax
	ret
