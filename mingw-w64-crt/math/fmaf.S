/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

	.file	"fmaf.S"
	.text
#ifdef _WIN64
	.align 8
#else
	.align 2
#endif
	.p2align 4,,15
	.globl __MINGW_USYMBOL(fmaf)
	.def	__MINGW_USYMBOL(fmaf);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(fmaf):
#if defined(_AMD64_) || defined(__x86_64__)
	subq	$56, %rsp
	movss	%xmm0,(%rsp)
	movss	%xmm1,16(%rsp)
	movss	%xmm2,32(%rsp)
	flds	(%rsp)
	fmuls	16(%rsp)
	flds	32(%rsp)
	faddp
	fstps	(%rsp)
	movss	(%rsp),%xmm0
	addq	$56, %rsp
	ret
#elif defined(_ARM_) || defined(__arm__)
	fmacs s2, s0, s1
	fcpys s0, s2
	bx	lr
#elif defined(_X86_) || defined(__i386__)
	flds	4(%esp)
	fmuls	8(%esp)
	flds	12(%esp)
	faddp
	ret
#endif

