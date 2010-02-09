/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

	.file	"ilogbf.S"
	.text
#ifdef _WIN64
	.align 8
#else
	.align 4
#endif
.globl __MINGW_USYMBOL(ilogbf)
	.def	__MINGW_USYMBOL(ilogbf);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(ilogbf):
#ifdef _WIN64
	subq	$24, %rsp
	movss	%xmm0,(%rsp)
	flds	(%rsp)
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

	addq	$24, %rsp
	ret

1:	fstp	%st
	movl	$0x7fffffff, %eax
	addq	$24, %rsp
	ret
#else
	flds	4(%esp)
/* I added the following ugly construct because ilogb(+-Inf) is
   required to return INT_MAX in ISO C99.
   -- jakub@redhat.com.  */
	fxam			/* Is NaN or +-Inf?  */
	fstsw   %ax
	movb    $0x45, %dh
	andb    %ah, %dh
	cmpb    $0x05, %dh
	je      1f		/* Is +-Inf, jump.  */

	fxtract
	pushl	%eax
	fstp	%st

	fistpl	(%esp)
	fwait
	popl	%eax

	ret

1:	fstp	%st
	movl	$0x7fffffff, %eax
	ret
#endif
