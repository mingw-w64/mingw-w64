/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <_mingw_mac.h>

	.file	"scalbnf.S"
	.text
#ifdef _WIN64
	.align 8
#else
	.align 4
#endif
.globl __MINGW_USYMBOL(scalbnf)
	.def	__MINGW_USYMBOL(scalbnf);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(scalbnf):
#ifdef _WIN664
	movq	%rdx,-16(%rsp)
	fildl	-16(%rsp)
	movss	%xmm0,-16(%rsp)
	flds	-16(%rsp)
	fscale
	fstp	%st(1)
	fstps	-16(%rsp)
	movss	-16(%rsp),%xmm0
	ret
#else
	fildl	8(%esp)
	flds	4(%esp)
	fscale
	fstp	%st(1)
	ret
#endif

.globl __MINGW_USYMBOL(scalblnf)
	.set	__MINGW_USYMBOL(scalblnf),__MINGW_USYMBOL(scalbnf)

