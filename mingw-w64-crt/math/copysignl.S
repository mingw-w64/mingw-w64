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
#ifdef _WIN64
	.file	"copysignl.S"
	.text
	.align 8
.globl _copysignl
	.def	_copysignl;	.scl	2;	.type	32;	.endef
_copysignl:
	movq	%rdx,%r9
	movl	8(%rdx),%eax
	movl	8(%r8),%edx
	andl	$0x8000,%edx
	andl	$0x7fff,%eax
	orl	%edx,%eax
	movl	%eax,8(%r9)
	fldt	(%r9)
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret
#else
	.file	"copysignl.S"
	.text
	.align 4
.globl _copysignl
	.def	_copysignl;	.scl	2;	.type	32;	.endef
_copysignl:
	movl	24(%esp),%edx
	movl	12(%esp),%eax
	andl	$0x8000,%edx
	andl	$0x7fff,%eax
	orl	%edx,%eax
	movl	%eax,12(%esp)
	fldt	4(%esp)
	ret
#endif
