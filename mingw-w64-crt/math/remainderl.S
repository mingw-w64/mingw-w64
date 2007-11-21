/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"remainderl.S"
	.text
	.align 8
.globl _remainderl
	.def	_remainderl;	.scl	2;	.type	32;	.endef
_remainderl:
	fldt	(%r8)
	fldt	(%rdx)
1:	fprem1
	fstsw	%ax
	sahf
	jp	1b
	fstp	%st(1)
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret
#else
	.file	"remainderl.S"
	.text
	.align 4
.globl _remainderl
	.def	_remainderl;	.scl	2;	.type	32;	.endef
_remainderl:
	fldt	16(%esp)
	fldt	4(%esp)
1:	fprem1
	fstsw	%ax
	sahf
	jp	1b
	fstp	%st(1)
	ret
#endif
