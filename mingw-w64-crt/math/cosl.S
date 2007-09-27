/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"cosl.S"
	.text
	.align 8
.globl _cosl
	.def	_cosl;	.scl	2;	.type	32;	.endef
_cosl:
	fldt	(%rdx)
	fcos
	fnstsw	%ax
	testl	$0x400,%eax
	jz	1f
	fldpi
	fadd	%st(0)
	fxch	%st(1)
2:	fprem1
	fnstsw	%ax
	testl	$0x400,%eax
	jnz	2b
	fstp	%st(1)
	fcos
1:	movq %rcx,%rax
	fstpt (%rcx)
	ret
