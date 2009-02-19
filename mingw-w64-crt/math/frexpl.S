/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

/*
 * frexpl(long double x, int* expnt) extracts the exponent from x.
 * It returns an integer power of two to expnt and the significand
 * between 0.5 and 1 to y.  Thus  x = y * 2**expn.
 */ 
#ifdef _WIN64
.align 2
.globl _frexpl
_frexpl:
	pushq %rbp
	movq %rsp,%rbp
	subq $24,%rsp
	pushq %rsi
	pushq %rbx
	fldt (%rdx)
	movq %r8,%rbx
	movq %rcx,%r9
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
	movq	%r9,%rax
	fstpt	(%r9)
	leave
	ret
#else
/*
 * frexpl(long double x, int* expnt) extracts the exponent from x.
 * It returns an integer power of two to expnt and the significand
 * between 0.5 and 1 to y.  Thus  x = y * 2**expn.
 */ 
	.align 2
.globl _frexpl
_frexpl:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	pushl %esi
	pushl %ebx
	fldt 8(%ebp)
	movl 20(%ebp),%ebx
	fld %st(0)
	fstpt -12(%ebp)
	leal -4(%ebp),%ecx
	movw -4(%ebp),%dx
	andl $32767,%edx
	jne L25
	fldz
	fucompp
	fnstsw %ax
	andb $68,%ah
	xorb $64,%ah
	jne L21
	movl $0,(%ebx)
	fldz
	jmp L24
	.align 2,0x90
	.align 2,0x90
L21:
	fldt -12(%ebp)
	fadd %st(0),%st
	fstpt -12(%ebp)
	decl %edx
	movw (%ecx),%si
	andl $32767,%esi
	jne L22
	cmpl $-66,%edx
	jg L21
L22:
	addl %esi,%edx
	jmp L19
	.align 2,0x90
L25:
	fstp %st(0)
L19:
	addl $-16382,%edx
	movl %edx,(%ebx)
	movw (%ecx),%ax
	andl $-32768,%eax
	orl $16382,%eax
	movw %ax,(%ecx)
	fldt -12(%ebp)
L24:
	leal -32(%ebp),%esp
	popl %ebx
	popl %esi
	leave
	ret
#endif
