/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
 #ifdef _WIN64
	.file	"log1pl.S"
	.text
	.align 4
	/* The fyl2xp1 can only be used for values in
	   -1 + sqrt(2) / 2 <= x <= 1 - sqrt(2) / 2
	   0.29 is a safe value.
	 */
limit:	.tfloat 0.29
	/* Please note:	 we use a double value here.  Since 1.0 has
	   an exact representation this does not effect the accuracy
	   but it helps to optimize the code.  */
one:	.double 1.0

/*
 * Use the fyl2xp1 function when the argument is in the range -0.29 to 0.29,
 * otherwise fyl2x with the needed extra computation.
 */
.globl _log1pl; 
	.def	_log1pl;	.scl	2;	.type	32;	.endef
_log1pl:
	fldln2
	fldt	(%rdx)
	fxam
	fnstsw
	fld	%st
	sahf
	jc	3f		// in case x is NaN or ±Inf
4:
	fabs
	fldt	limit
	fcompp
	fnstsw
	sahf
	jnc	2f
	faddl	one
	fyl2x
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret

2:	fyl2xp1
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret

3:	jp	4b		// in case x is ±Inf
	fstp	%st(1)
	fstp	%st(1)
	movq	%rcx,%rax
	fstpt	(%rcx)
	ret
#else
	.file	"log1pl.S"
	.text
	.align 4
	/* The fyl2xp1 can only be used for values in
	   -1 + sqrt(2) / 2 <= x <= 1 - sqrt(2) / 2
	   0.29 is a safe value.
	 */
limit:	.tfloat 0.29
	/* Please note:	 we use a double value here.  Since 1.0 has
	   an exact representation this does not effect the accuracy
	   but it helps to optimize the code.  */
one:	.double 1.0

/*
 * Use the fyl2xp1 function when the argument is in the range -0.29 to 0.29,
 * otherwise fyl2x with the needed extra computation.
 */
.globl _log1pl; 
	.def	_log1pl;	.scl	2;	.type	32;	.endef
_log1pl:
	fldln2
	fldt	4(%esp)
	fxam
	fnstsw
	fld	%st
	sahf
	jc	3f		// in case x is NaN or ±Inf
4:
	fabs
	fldt	limit
	fcompp
	fnstsw
	sahf
	jnc	2f
	faddl	one
	fyl2x
	ret

2:	fyl2xp1
	ret

3:	jp	4b		// in case x is ±Inf
	fstp	%st(1)
	fstp	%st(1)
	ret
#endif