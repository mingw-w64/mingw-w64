/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if !defined(__i386__)

#include <windows.h>
#include <setjmp.h>

#if defined(__x86_64__)
#define IP Rip
#elif defined(__arm__)
#define IP Pc
#elif defined(__aarch64__)
#define IP Lr
#else
#error Unknown platform
#endif

#undef longjmp
__MINGW_ATTRIB_NORETURN __attribute__((nothrow))
void __cdecl longjmp(jmp_buf buf, int value)
{
    if (value == 0) value = 1;
#if defined(__x86_64__) && !defined(__arm64ec__)
    /* only amd64 longjmp fallback to no-SEH unwind variant when SEH frame is NULL */
    if (__builtin_expect(((_JUMP_BUFFER *)buf)->Frame == 0, 0)) {
        asm volatile (
            "movq    0x08(%%rcx),%%rbx\n\t"      /* jmp_buf->Rbx */
            "movq    0x18(%%rcx),%%rbp\n\t"      /* jmp_buf->Rbp */
            "movq    0x20(%%rcx),%%rsi\n\t"      /* jmp_buf->Rsi */
            "movq    0x28(%%rcx),%%rdi\n\t"      /* jmp_buf->Rdi */
            "movq    0x30(%%rcx),%%r12\n\t"      /* jmp_buf->R12 */
            "movq    0x38(%%rcx),%%r13\n\t"      /* jmp_buf->R13 */
            "movq    0x40(%%rcx),%%r14\n\t"      /* jmp_buf->R14 */
            "movq    0x48(%%rcx),%%r15\n\t"      /* jmp_buf->R15 */
            "ldmxcsr 0x58(%%rcx)\n\t"            /* jmp_buf->MxCsr */
            "fnclex\n\t"
            "fldcw   0x5c(%%rcx)\n\t"            /* jmp_buf->FpCsr */
            "movdqa  0x60(%%rcx),%%xmm6\n\t"     /* jmp_buf->Xmm6 */
            "movdqa  0x70(%%rcx),%%xmm7\n\t"     /* jmp_buf->Xmm7 */
            "movdqa  0x80(%%rcx),%%xmm8\n\t"     /* jmp_buf->Xmm8 */
            "movdqa  0x90(%%rcx),%%xmm9\n\t"     /* jmp_buf->Xmm9 */
            "movdqa  0xa0(%%rcx),%%xmm10\n\t"    /* jmp_buf->Xmm10 */
            "movdqa  0xb0(%%rcx),%%xmm11\n\t"    /* jmp_buf->Xmm11 */
            "movdqa  0xc0(%%rcx),%%xmm12\n\t"    /* jmp_buf->Xmm12 */
            "movdqa  0xd0(%%rcx),%%xmm13\n\t"    /* jmp_buf->Xmm13 */
            "movdqa  0xe0(%%rcx),%%xmm14\n\t"    /* jmp_buf->Xmm14 */
            "movdqa  0xf0(%%rcx),%%xmm15\n\t"    /* jmp_buf->Xmm15 */
            "movq    0x50(%%rcx),%%rdx\n\t"      /* jmp_buf->Rip */
            "movq    0x10(%%rcx),%%rsp\n\t"      /* jmp_buf->Rsp */
            "jmp     *%%rdx"
            :
            : "a" (value), "c" (buf)
            : "memory"
        );
        __builtin_unreachable();
    }
#endif
    EXCEPTION_RECORD rec;
    rec.ExceptionCode = STATUS_LONGJUMP;
    rec.ExceptionFlags = 0;
    rec.ExceptionRecord = NULL;
    rec.ExceptionAddress = NULL;
    rec.NumberParameters = 1;
    rec.ExceptionInformation[0] = (ULONG_PTR)buf;
    RtlUnwind((PVOID)((_JUMP_BUFFER *)buf)->Frame, (PVOID)((_JUMP_BUFFER *)buf)->IP, &rec, (PVOID)(ULONG_PTR)(value));
    __builtin_unreachable();
}
void (__cdecl *__MINGW_IMP_SYMBOL(longjmp))(jmp_buf, int) = longjmp;

#endif
