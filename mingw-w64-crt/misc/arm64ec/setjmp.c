/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define _UCRT

#include <setjmp.h>
#include <windef.h>
#include <winbase.h>

static inline UINT fpcsr_to_mxcsr( UINT fpcr, UINT fpsr )
{
    UINT ret = 0;

    if (fpsr & 0x0001) ret |= 0x0001;      /* invalid operation */
    if (fpsr & 0x0002) ret |= 0x0004;      /* zero-divide */
    if (fpsr & 0x0004) ret |= 0x0008;      /* overflow */
    if (fpsr & 0x0008) ret |= 0x0010;      /* underflow */
    if (fpsr & 0x0010) ret |= 0x0020;      /* precision */
    if (fpsr & 0x0080) ret |= 0x0002;      /* denormal */

    if (fpcr & 0x0080000)    ret |= 0x0040;   /* denormals are zero */
    if (!(fpcr & 0x0000100)) ret |= 0x0080;   /* invalid operation mask */
    if (!(fpcr & 0x0000200)) ret |= 0x0200;   /* zero-divide mask */
    if (!(fpcr & 0x0000400)) ret |= 0x0400;   /* overflow mask */
    if (!(fpcr & 0x0000800)) ret |= 0x0800;   /* underflow mask */
    if (!(fpcr & 0x0001000)) ret |= 0x1000;   /* precision mask */
    if (!(fpcr & 0x0008000)) ret |= 0x0100;   /* denormal mask */
    if (fpcr & 0x0400000)    ret |= 0x4000;   /* round up */
    if (fpcr & 0x0800000)    ret |= 0x2000;   /* round down */
    if (fpcr & 0x1000000)    ret |= 0x8000;   /* flush to zero */
    return ret;
}

/* unwind context by one call frame */
static void unwind_one_frame( CONTEXT *context )
{
    void *data;
    ULONG_PTR base, frame, pc = context->Rip - 4;
    RUNTIME_FUNCTION *func = RtlLookupFunctionEntry( pc, &base, NULL );

    RtlVirtualUnwind( UNW_FLAG_NHANDLER, base, pc, func, context, &data, &frame, NULL );
}

/* fixup jump buffer information; helper for _setjmpex */
static int __attribute__((used)) do_setjmpex( _JUMP_BUFFER *buf, UINT fpcr, UINT fpsr )
{
    CONTEXT context = { .ContextFlags = CONTEXT_FULL };

    buf->MxCsr = fpcsr_to_mxcsr( fpcr, fpsr );
    buf->FpCsr = 0x27f;

    /* If the caller is x64, the buffer contains an entry thunk capture.
     * Attempt to unwind it to retrieve the actual x64 context, if applicable. */
    context.Rbx = buf->Rbx;
    context.Rsp = buf->Rsp;
    context.Rbp = buf->Rbp;
    context.Rsi = buf->Rsi;
    context.Rdi = buf->Rdi;
    context.R12 = buf->R12;
    context.R13 = buf->R13;
    context.R14 = buf->R14;
    context.R15 = buf->R15;
    context.Rip = buf->Rip;
    memcpy( &context.Xmm6, &buf->Xmm6, 10 * sizeof(context.Xmm6) );
    unwind_one_frame( &context );
    if (!RtlIsEcCode( context.Rip ))  /* caller is x64, use its context instead of the ARM one */
    {
        buf->Rbx = context.Rbx;
        buf->Rsp = context.Rsp;
        buf->Rbp = context.Rbp;
        buf->Rsi = context.Rsi;
        buf->Rdi = context.Rdi;
        buf->R12 = context.R12;
        buf->R13 = context.R13;
        buf->R14 = context.R14;
        buf->R15 = context.R15;
        buf->Rip = context.Rip;
        memcpy( &buf->Xmm6, &context.Xmm6, 10 * sizeof(context.Xmm6) );
    }
    return 0;
}

int __attribute__((naked)) __intrinsic_setjmpex( jmp_buf buf, void *frame )
{
    asm( ".seh_proc \"#__intrinsic_setjmpex\"\n\t"
         ".seh_endprologue\n\t"
         "stp x1, x27,  [x0]\n\t"          /* jmp_buf->Frame,Rbx */
         "mov x1, sp\n\t"
         "stp x1, x29,  [x0, #0x10]\n\t"   /* jmp_buf->Rsp,Rbp */
         "stp x25, x26, [x0, #0x20]\n\t"   /* jmp_buf->Rsi,Rdi */
         "stp x19, x20, [x0, #0x30]\n\t"   /* jmp_buf->R12,R13 */
         "stp x21, x22, [x0, #0x40]\n\t"   /* jmp_buf->R14,R15 */
         "str x30,      [x0, #0x50]\n\t"   /* jmp_buf->Rip */
         "stp d8, d9,   [x0, #0x80]\n\t"   /* jmp_buf->Xmm8,Xmm9 */
         "stp d10, d11, [x0, #0xa0]\n\t"   /* jmp_buf->Xmm10,Xmm11 */
         "stp d12, d13, [x0, #0xc0]\n\t"   /* jmp_buf->Xmm12,Xmm13 */
         "stp d14, d15, [x0, #0xe0]\n\t"   /* jmp_buf->Xmm14,Xmm15 */
         "mrs x1, fpcr\n\t"
         "mrs x2, fpsr\n\t"
         "b \"#do_setjmpex\"\n\t"
         ".seh_endproc" );
}
