/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <_mingw_mac.h>

	.file	"scalbn.S"
	.text
#ifdef _WIN64
	.align 8
#else
	.align 4
#endif
.globl __MINGW_USYMBOL(scalbn)
	.def	__MINGW_USYMBOL(scalbn);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(scalbn):
#ifdef _WIN64
	movq	%rdx,-16(%rsp)
	fildl	-16(%rsp)
	movsd	%xmm0,-16(%rsp)
	fldl	-16(%rsp)
	fscale
	fstp	%st(1)
	fstpl	-16(%rsp)
	movsd	-16(%rsp),%xmm0
	ret

#else
	fildl	12(%esp)
	fldl	4(%esp)
	fscale
	fstp	%st(1)
	ret
#endif

.globl __MINGW_USYMBOL(scalbln)
	.set	__MINGW_USYMBOL(scalbln),__MINGW_USYMBOL(scalbn)

