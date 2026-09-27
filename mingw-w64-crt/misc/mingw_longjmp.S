/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

#if defined(_ARM_) || defined(__arm__) || defined(_ARM64_) || defined(__aarch64__)
	.globl __MINGW_USYMBOL(__mingw_setjmp)
	.def	__MINGW_USYMBOL(__mingw_setjmp);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(__mingw_setjmp):
#if defined(_ARM_) || defined(__arm__)
	mov     r1,  #0
	str     r1,  [r0]            /* jmp_buf->Frame */
	str     r4,  [r0, #0x4]      /* jmp_buf->R4 */
	str     r5,  [r0, #0x8]      /* jmp_buf->R5 */
	str     r6,  [r0, #0xc]      /* jmp_buf->R6 */
	str     r7,  [r0, #0x10]     /* jmp_buf->R7 */
	str     r8,  [r0, #0x14]     /* jmp_buf->R8 */
	str     r9,  [r0, #0x18]     /* jmp_buf->R9 */
	str     r10, [r0, #0x1c]     /* jmp_buf->R10 */
	str     r11, [r0, #0x20]     /* jmp_buf->R11 */
	str     sp,  [r0, #0x24]     /* jmp_buf->Sp */
	str     lr,  [r0, #0x28]     /* jmp_buf->Pc */
	vmrs    r2,  fpscr
	str     r2,  [r0, #0x2c]     /* jmp_buf->Fpscr */
	vstr    d8,  [r0, #0x30]     /* jmp_buf->D[0] */
	vstr    d9,  [r0, #0x38]     /* jmp_buf->D[1] */
	vstr    d10, [r0, #0x40]     /* jmp_buf->D[2] */
	vstr    d11, [r0, #0x48]     /* jmp_buf->D[3] */
	vstr    d12, [r0, #0x50]     /* jmp_buf->D[4] */
	vstr    d13, [r0, #0x58]     /* jmp_buf->D[5] */
	vstr    d14, [r0, #0x60]     /* jmp_buf->D[6] */
	vstr    d15, [r0, #0x68]     /* jmp_buf->D[7] */
	mov     r0,  #0
	bx      lr
#elif defined(_ARM64_) || defined(__aarch64__)
	str     xzr, [x0]             /* jmp_buf->Frame */
	stp     x19, x20, [x0, #0x10] /* jmp_buf->X19, X20 */
	stp     x21, x22, [x0, #0x20] /* jmp_buf->X21, X22 */
	stp     x23, x24, [x0, #0x30] /* jmp_buf->X23, X24 */
	stp     x25, x26, [x0, #0x40] /* jmp_buf->X25, X26 */
	stp     x27, x28, [x0, #0x50] /* jmp_buf->X27, X28 */
	stp     x29, x30, [x0, #0x60] /* jmp_buf->Fp,  Lr  */
	mov     x2,  sp
	str     x2,       [x0, #0x70] /* jmp_buf->Sp */
	mrs     x2,  fpcr
	str     w2,       [x0, #0x78] /* jmp_buf->Fpcr */
	mrs     x2,  fpsr
	str     w2,       [x0, #0x7c] /* jmp_buf->Fpsr */
	stp     d8,  d9,  [x0, #0x80] /* jmp_buf->D[0-1] */
	stp     d10, d11, [x0, #0x90] /* jmp_buf->D[2-3] */
	stp     d12, d13, [x0, #0xa0] /* jmp_buf->D[4-5] */
	stp     d14, d15, [x0, #0xb0] /* jmp_buf->D[6-7] */
	mov     x0,  #0
	ret
#endif
#endif

#if defined(__i386__) || defined(_ARM_) || defined(__arm__) || defined(_ARM64_) || defined(__aarch64__)
	.globl __MINGW_USYMBOL(__mingw_longjmp)
	.def	__MINGW_USYMBOL(__mingw_longjmp);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(__mingw_longjmp):
#if defined(__i386__)
	movl    4(%esp),%ecx         /* jmp_buf */
	movl    8(%esp),%eax         /* retval */
	cmpl    $1,%eax              /* check that retval is non-zero */
	adcl    $0,%eax              /* if not then increase by one via CF */
	movl    0(%ecx),%ebp         /* jmp_buf->Ebp */
	movl    4(%ecx),%ebx         /* jmp_buf->Ebx */
	movl    8(%ecx),%edi         /* jmp_buf->Edi */
	movl    12(%ecx),%esi        /* jmp_buf->Esi */
	movl    16(%ecx),%esp        /* jmp_buf->Esp */
	addl    $4,%esp              /* get rid of return address */
	jmpl    *20(%ecx)            /* jmp_buf->Eip */
#elif defined(_ARM_) || defined(__arm__)
	ldr     r4,  [r0, #0x4]      /* jmp_buf->R4 */
	ldr     r5,  [r0, #0x8]      /* jmp_buf->R5 */
	ldr     r6,  [r0, #0xc]      /* jmp_buf->R6 */
	ldr     r7,  [r0, #0x10]     /* jmp_buf->R7 */
	ldr     r8,  [r0, #0x14]     /* jmp_buf->R8 */
	ldr     r9,  [r0, #0x18]     /* jmp_buf->R9 */
	ldr     r10, [r0, #0x1c]     /* jmp_buf->R10 */
	ldr     r11, [r0, #0x20]     /* jmp_buf->R11 */
	ldr     sp,  [r0, #0x24]     /* jmp_buf->Sp */
	ldr     r2,  [r0, #0x28]     /* jmp_buf->Pc */
	ldr     r3,  [r0, #0x2c]     /* jmp_buf->Fpscr */
	vmsr    fpscr, r3
	vldr    d8,  [r0, #0x30]     /* jmp_buf->D[0] */
	vldr    d9,  [r0, #0x38]     /* jmp_buf->D[1] */
	vldr    d10, [r0, #0x40]     /* jmp_buf->D[2] */
	vldr    d11, [r0, #0x48]     /* jmp_buf->D[3] */
	vldr    d12, [r0, #0x50]     /* jmp_buf->D[4] */
	vldr    d13, [r0, #0x58]     /* jmp_buf->D[5] */
	vldr    d14, [r0, #0x60]     /* jmp_buf->D[6] */
	vldr    d15, [r0, #0x68]     /* jmp_buf->D[7] */
	mov     r0,  r1              /* retval */
	cmp     r1,  #1
	it      ls
	movls   r0,  #1
	bx      r2
#elif defined(_ARM64_) || defined(__aarch64__)
	ldp     x19, x20, [x0, #0x10] /* jmp_buf->X19, X20 */
	ldp     x21, x22, [x0, #0x20] /* jmp_buf->X21, X22 */
	ldp     x23, x24, [x0, #0x30] /* jmp_buf->X23, X24 */
	ldp     x25, x26, [x0, #0x40] /* jmp_buf->X25, X26 */
	ldp     x27, x28, [x0, #0x50] /* jmp_buf->X27, X28 */
	ldp     x29, x30, [x0, #0x60] /* jmp_buf->Fp,  Lr  */
	ldr     x2,       [x0, #0x70] /* jmp_buf->Sp */
	mov     sp,  x2
	ldr     w2,       [x0, #0x78] /* jmp_buf->Fpcr */
	msr     fpcr, x2
	ldr     w2,       [x0, #0x7c] /* jmp_buf->Fpsr */
	msr     fpsr, x2
	ldp     d8,  d9,  [x0, #0x80] /* jmp_buf->D[0-1] */
	ldp     d10, d11, [x0, #0x90] /* jmp_buf->D[2-3] */
	ldp     d12, d13, [x0, #0xa0] /* jmp_buf->D[4-5] */
	ldp     d14, d15, [x0, #0xb0] /* jmp_buf->D[6-7] */
	cmp     w1,  #1
	csinc   w0,  w1,  wzr,  hi    /* retval */
	ret
#endif
#endif
