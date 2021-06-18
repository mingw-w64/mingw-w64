/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw_mac.h>

        .globl  __MINGW_USYMBOL(longjmp)
        .def    __MINGW_USYMBOL(longjmp); .scl 2; .type 32; .endef

__MINGW_USYMBOL(longjmp):
#if defined(__i386__)
        movl    4(%esp),%ecx         /* jmp_buf */
        movl    8(%esp),%eax         /* retval */
        movl    0(%ecx),%ebp         /* jmp_buf.Ebp */
        movl    4(%ecx),%ebx         /* jmp_buf.Ebx */
        movl    8(%ecx),%edi         /* jmp_buf.Edi */
        movl    12(%ecx),%esi        /* jmp_buf.Esi */
        movl    16(%ecx),%esp        /* jmp_buf.Esp */
        addl    $4,%esp              /* get rid of return address */
        jmp     *20(%ecx)            /* jmp_buf.Eip */
#elif defined(__x86_64__)
        movq    %rdx,%rax            /* retval */
        movq    0x8(%rcx),%rbx       /* jmp_buf->Rbx */
        movq    0x18(%rcx),%rbp      /* jmp_buf->Rbp */
        movq    0x20(%rcx),%rsi      /* jmp_buf->Rsi */
        movq    0x28(%rcx),%rdi      /* jmp_buf->Rdi */
        movq    0x30(%rcx),%r12      /* jmp_buf->R12 */
        movq    0x38(%rcx),%r13      /* jmp_buf->R13 */
        movq    0x40(%rcx),%r14      /* jmp_buf->R14 */
        movq    0x48(%rcx),%r15      /* jmp_buf->R15 */
        ldmxcsr 0x58(%rcx)           /* jmp_buf->MxCsr */
        fnclex
        fldcw   0x5c(%rcx)           /* jmp_buf->FpCsr */
        movdqa  0x60(%rcx),%xmm6     /* jmp_buf->Xmm6 */
        movdqa  0x70(%rcx),%xmm7     /* jmp_buf->Xmm7 */
        movdqa  0x80(%rcx),%xmm8     /* jmp_buf->Xmm8 */
        movdqa  0x90(%rcx),%xmm9     /* jmp_buf->Xmm9 */
        movdqa  0xa0(%rcx),%xmm10    /* jmp_buf->Xmm10 */
        movdqa  0xb0(%rcx),%xmm11    /* jmp_buf->Xmm11 */
        movdqa  0xc0(%rcx),%xmm12    /* jmp_buf->Xmm12 */
        movdqa  0xd0(%rcx),%xmm13    /* jmp_buf->Xmm13 */
        movdqa  0xe0(%rcx),%xmm14    /* jmp_buf->Xmm14 */
        movdqa  0xf0(%rcx),%xmm15    /* jmp_buf->Xmm15 */
        movq    0x50(%rcx),%rdx      /* jmp_buf->Rip */
        movq    0x10(%rcx),%rsp      /* jmp_buf->Rsp */
        jmp     *%rdx
#elif defined(__arm__)
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
        bx      r2
#elif defined(__aarch64__)
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
        mov     x0,  x1               /* retval */
        ret
#endif

        .data
        .globl  __MINGW_IMP_LSYMBOL(longjmp)
__MINGW_IMP_LSYMBOL(longjmp):
#ifdef _WIN64
        .quad   __MINGW_USYMBOL(longjmp)
#else
        .long   __MINGW_USYMBOL(longjmp)
#endif
