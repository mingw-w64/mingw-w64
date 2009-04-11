/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"scalbnl.S"
	.text
	.align 4
.globl _scalbnl
	.def	_scalbnl;	.scl	2;	.type	32;	.endef
_scalbnl:
	movq	%r8, 24(%rsp)
	fildl	24(%rsp)
	fldt	(%rdx)
	fscale
	fstp	%st(1)
	movq	%rcx,%rax
	movq	$0,8(%rcx)
	fstpt	(%rcx)
	ret

.globl _scalblnl
	.set	_scalblnl,_scalbnl
#else
	.file	"scalbnl.S"
	.text
	.align 4
.globl _scalbnl
	.def	_scalbnl;	.scl	2;	.type	32;	.endef
_scalbnl:
	fildl	16(%esp)
	fldt	4(%esp)
	fscale
	fstp	%st(1)
	ret

.globl _scalblnl
	.set	_scalblnl,_scalbnl
#endif
