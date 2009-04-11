/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"sinl.S"
	.text
	.align 8
.globl _sinl
	.def	_sinl;	.scl	2;	.type	32;	.endef
_sinl:
	fldt	(%rdx)
	fsin
	fnstsw	%ax
	testl	$0x400,%eax
	jnz	1f
	movq	%rcx,%rax
        movq	$0,8(%rcx)
	fstpt	(%rcx)
	ret
1:	fldpi
	fadd	%st(0)
	fxch	%st(1)
2:	fprem1
	fnstsw	%ax
	testl	$0x400,%eax
	jnz	2b
	fstp	%st(1)
	fsin
	movq	%rcx,%rax
	movq	$0,8(%rcx)
	fstpt	(%rcx)
	ret
#else
	.file	"sinl.S"
	.text
	.align 4
.globl _sinl
	.def	_sinl;	.scl	2;	.type	32;	.endef
_sinl:
	fldt	4(%esp)
	fsin
	fnstsw	%ax
	testl	$0x400,%eax
	jnz	1f
	ret
1:	fldpi
	fadd	%st(0)
	fxch	%st(1)
2:	fprem1
	fnstsw	%ax
	testl	$0x400,%eax
	jnz	2b
	fstp	%st(1)
	fsin
	ret
#endif
