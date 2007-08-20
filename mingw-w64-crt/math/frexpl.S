/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
  Cephes Math Library Release 2.7:  May, 1998
  Copyright 1984, 1987, 1988, 1992, 1998 by Stephen L. Moshier

  Extracted from floorl.387 for use in libmingwex.a by
  Danny Smith <dannysmith@users.sourceforge.net>
  2002-06-20
*/

/*
 * frexpl(long double x, int* expnt) extracts the exponent from x.
 * It returns an integer power of two to expnt and the significand
 * between 0.5 and 1 to y.  Thus  x = y * 2**expn.
 */ 
	.align 2
.globl _frexpl
_frexpl:
	pushq %rbp
	movq %rsp,%rbp
	subq $24,%rsp
	pushq %rsi
	pushq %rbx
	fldt 16(%rbp)
	movq 40(%rbp),%rbx
	fld %st(0)
	fstpt -24(%rbp)
	leaq -8(%rbp),%rcx
	movw -8(%rbp),%dx
	andq $32767,%rdx
	jne L25
	fldz
	fucompp
	fnstsw %ax
	andb $68,%ah
	xorb $64,%ah
	jne L21
	movq $0,(%rbx)
	fldz
	jmp L24
	.align 2,0x90
	.align 2,0x90
L21:
	fldt -24(%rbp)
	fadd %st(0),%st
	fstpt -24(%rbp)
	decq %rdx
	movw (%rcx),%si
	andq $32767,%rsi
	jne L22
	cmpq $-66,%rdx
	jg L21
L22:
	addq %rsi,%rdx
	jmp L19
	.align 2,0x90
L25:
	fstp %st(0)
L19:
	addq $-16382,%rdx
	movq %rdx,(%rbx)
	movw (%rcx),%ax
	andq $-32768,%rax
	orq $16382,%rax
	movw %ax,(%rcx)
	fldt -24(%rbp)
L24:
	leaq -40(%rbp),%rsp
	popq %rbx
	popq %rsi
	leave
	ret
