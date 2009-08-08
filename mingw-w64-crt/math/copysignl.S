/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
 * Written by J.T. Conklin <jtc@netbsd.org>.
 * Changes for long double by Ulrich Drepper <drepper@cygnus.com>
 * Public domain.
 */
#include <_mingw_mac.h>

	.file	"copysignl.S"
	.text
#ifdef _WIN64
	.align 8
#else
	.align 4
#endif

.globl __MINGW_USYMBOL(copysignl)
	.def	__MINGW_USYMBOL(copysignl);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(copysignl):
#ifdef _WIN64
	movq	%rdx,%r9
	movl	8(%rdx),%eax
	movl	8(%r8),%edx
	andl	$0x8000,%edx
	andl	$0x7fff,%eax
	orl	%edx,%eax
	fldt	(%r9)
	movq	$0,8(%rcx)
	fstpt	(%rcx)
	movl	%eax,8(%rcx)
	movq	%rcx,%rax
	ret
#else
	movl	24(%esp),%edx
	movl	12(%esp),%eax
	andl	$0x8000,%edx
	andl	$0x7fff,%eax
	orl	%edx,%eax
	movl	%eax,12(%esp)
	fldt	4(%esp)
	ret
#endif
