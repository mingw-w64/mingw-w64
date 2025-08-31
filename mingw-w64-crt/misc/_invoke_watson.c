/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <corecrt.h>
#include <windows.h>

#if defined(__i386__)
DECLSPEC_NOINLINE /* decrease chance of modifying caller's registers and/or stack frame */
#endif
static BOOL is_fastfail_available(void)
{
#if defined(__i386__)
    HMODULE module = GetModuleHandleA("kernel32.dll");
    BOOL (WINAPI *func)(DWORD) = module ? (LPVOID)GetProcAddress(module, "IsProcessorFeaturePresent") : (LPVOID)NULL;
    return func ? func(PF_FASTFAIL_AVAILABLE) : FALSE;
#elif defined(__x86_64__)
    return IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE);
#elif defined (__arm__) || defined(__aarch64__)
    /* On ARM is fastfail always available */
    return TRUE;
#else
#error Unsupported platform
#endif
}

/* DECLSPEC_NOINLINE is needed for __builtin_return_address() and __builtin_frame_address() usage */
DECLSPEC_NOINLINE __MINGW_ATTRIB_NORETURN void __cdecl _invoke_watson(const wchar_t * __UNUSED_PARAM(expression), const wchar_t * __UNUSED_PARAM(function_name), const wchar_t * __UNUSED_PARAM(file_name), unsigned int __UNUSED_PARAM(line_number), uintptr_t __UNUSED_PARAM(reserved))
{
    EXCEPTION_RECORD exception_record = { 0, };
    CONTEXT context = { 0, };
    EXCEPTION_POINTERS exception_pointers = { &exception_record, &context };
#if defined(__x86_64__)
    ULONG64 establisher_frame;
    ULONG64 image_base;
    PRUNTIME_FUNCTION function_entry;
    PVOID handler_data;
#endif

    if (is_fastfail_available())
        __fastfail(FAST_FAIL_INVALID_ARG);

    /*
     * RtlCaptureContext() is available since Windows XP.
     * UCRT runtime uses inline assemly on 32-bit x86.
     * For compatibility with UCRT do same thing.
     */
#if defined(__i386__)
    asm volatile(
        "mov %%eax, %0\n\t"
        "mov %%ecx, %1\n\t"
        "mov %%edx, %2\n\t"
        "mov %%ebx, %3\n\t"
        "mov %%esi, %4\n\t"
        "mov %%edi, %5\n\t"
        "movw %%ss, %w6\n\t"
        "movw %%cs, %w7\n\t"
        "movw %%ds, %w8\n\t"
        "movw %%es, %w9\n\t"
        "movw %%fs, %w10\n\t"
        "movw %%gs, %w11\n\t"
        "pushf\n\t"
        "pop %12"
      :
        /* Specify only "m" (memory) to prevent using registers and clobbering their content. */
        "=m" (context.Eax), "=m" (context.Ecx), "=m" (context.Edx),
        "=m" (context.Ebx), "=m" (context.Esi), "=m" (context.Edi),
        "=m" (context.SegSs), "=m" (context.SegCs), "=m" (context.SegDs),
        "=m" (context.SegEs), "=m" (context.SegFs), "=m" (context.SegGs),
        "=m" (context.EFlags)
      :
      :
    );
#else
    RtlCaptureContext(&context);
#endif

    /* Fill additional platform specific fields of the parent (caller) function into context. */
#if defined(__i386__)
    context.ContextFlags = CONTEXT_CONTROL;
    context.Eip = (uintptr_t)__builtin_extract_return_addr(__builtin_return_address(0)); /* msvc uses _ReturnAddress() */
    context.Esp = (uintptr_t)__builtin_frame_address(0); /* msvc uses _AddressOfReturnAddress() */
    context.Ebp = *((uintptr_t *)__builtin_frame_address(0)-1); /* msvc uses *((ULONG *)_AddressOfReturnAddress()-1) */
#elif defined(__x86_64__)
    function_entry = RtlLookupFunctionEntry(context.Rip, &image_base, NULL);
    if (function_entry)
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, image_base, context.Rip, function_entry, &context, &handler_data, &establisher_frame, NULL);
    context.Rip = (uintptr_t)__builtin_extract_return_addr(__builtin_return_address(0)); /* msvc uses _ReturnAddress() */
    context.Rsp = (uintptr_t)__builtin_frame_address(0); /* msvc uses _AddressOfReturnAddress()+8 */
    context.Rbp = *((uintptr_t *)__builtin_frame_address(0)-1); /* not filled filled by msvc */
#endif

    exception_record.ExceptionCode = STATUS_INVALID_CRUNTIME_PARAMETER;
    exception_record.ExceptionFlags = EXCEPTION_NONCONTINUABLE;
    exception_record.ExceptionAddress = __builtin_extract_return_addr(__builtin_return_address(0)); /* msvc uses _ReturnAddress() */

    /* Remove all filters, trigger exception and terminate the process. */
    SetUnhandledExceptionFilter(NULL);
    UnhandledExceptionFilter(&exception_pointers);
    TerminateProcess(GetCurrentProcess(), STATUS_INVALID_CRUNTIME_PARAMETER);
    __builtin_unreachable();
}
__MINGW_ATTRIB_NORETURN void (__cdecl *__MINGW_IMP_SYMBOL(_invoke_watson))(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t) = _invoke_watson;
