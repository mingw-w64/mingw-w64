/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"tanl.S"
	.text
	.align 8
.globl _tanl
	.def	_tanl;	.scl	2;	.type	32;	.endef
_tanl:
	fldt	(%rdx)
	fptan
	fnstsw	%ax
	testl	$0x400,%eax
	jnz	1f
	fstp	%st(0)
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret
1:	fldpi
	fadd	%st(0)
	fxch	%st(1)
2:	fprem1
	fstsw	%ax
	testl	$0x400,%eax
	jnz	2b
	fstp	%st(1)
	fptan
	fstp	%st(0)
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret
#else
	.file	"tanl.S"
	.text
	.align 4
.globl _tanl
	.def	_tanl;	.scl	2;	.type	32;	.endef
_tanl:
	fldt	4(%esp)
	fptan
	fnstsw	%ax
	testl	$0x400,%eax
	jnz	1f
	fstp	%st(0)
	ret
1:	fldpi
	fadd	%st(0)
	fxch	%st(1)
2:	fprem1
	fstsw	%ax
	testl	$0x400,%eax
	jnz	2b
	fstp	%st(1)
	fptan
	fstp	%st(0)
	ret
#endif
