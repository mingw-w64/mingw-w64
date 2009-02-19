/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"remainderf.S"
	.text
	.align 4
.globl _remainder
	.def	_remainderf;	.scl	2;	.type	32;	.endef
_remainderf:
	movss	%xmm1,-12(%rsp)
	flds	-12(%rsp)
	movss	%xmm0,-12(%rsp)
	flds	-12(%rsp)
1:	fprem1
	fstsw	%ax
	sahf
	jp	1b
	fstp	%st(1)
	fstps	-12(%rsp)
	movss	-12(%rsp),%xmm0
	ret
#else
	.file	"remainderf.S"
	.text
	.align 4
.globl _remainder
	.def	_remainderf;	.scl	2;	.type	32;	.endef
_remainderf:
	flds	8(%esp)
	flds	4(%esp)
1:	fprem1
	fstsw	%ax
	sahf
	jp	1b
	fstp	%st(1)
	ret
#endif
