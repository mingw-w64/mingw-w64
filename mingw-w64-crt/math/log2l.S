/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"log2l.S"
	.text
	.align 4
one:	.double 1.0
	/* It is not important that this constant is precise.  It is only
	   a value which is known to be on the safe side for using the
	   fyl2xp1 instruction.  */
limit:	.double 0.29

	.text
	.align 4
.globl _log2l
	.def	_log2l;	.scl	2;	.type	32;	.endef
_log2l:
	fldl	one
	fldt	(%rdx)		// x : 1
	fxam
	fnstsw
	fld	%st		// x : x : 1
	sahf
	jc	3f		// in case x is NaN or ±Inf
4:	fsub	%st(2), %st	// x-1 : x : 1
	fld	%st		// x-1 : x-1 : x : 1
	fabs			// |x-1| : x-1 : x : 1
	fcompl	limit		// x-1 : x : 1
	fnstsw			// x-1 : x : 1
	andb	$0x45, %ah
	jz	2f
	fstp	%st(1)		// x-1 : 1
	fyl2xp1			// log(x)
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret

2:	fstp	%st(0)		// x : 1
	fyl2x			// log(x)
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret

3:	jp	4b		// in case x is ±Inf
	fstp	%st(1)
	fstp	%st(1)
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret
