/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
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
#ifdef _WIN64
	movss	%xmm0,-12(%rsp)
	movss	%xmm1,-20(%rsp)
	movss	%xmm2,-28(%rsp)
	flds	-12(%rsp)
	fmuls	-20(%rsp)
	flds	-28(%rsp)
	faddp
	fstps	-12(%rsp)
	movss	-12(%rsp),%xmm0
	ret
#else
	flds	4(%esp)
	fmuls	8(%esp)
	flds	12(%esp)
	faddp
	ret
#endif

