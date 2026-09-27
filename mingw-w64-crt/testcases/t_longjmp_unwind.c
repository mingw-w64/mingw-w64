#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <excpt.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

#if defined(__SEH__) && (!defined(__clang__) || __clang_major__ >= 7)
#define SEH_INLINE_ASM
#ifdef __arm__
#define ASM_SEH_UNWIND "%%unwind"
#elif defined(__aarch64__) || defined(__arm64ec__)
#define ASM_SEH_UNWIND "@unwind, @except" /* on arm64 the unwind handler is called when both @unwind and @except are specified */
#else
#define ASM_SEH_UNWIND "@unwind"
#endif
#endif

static int outer_unwind_called = 0;
static int target_unwind_called = 0;
static int inner_unwind_called = 0;
static jmp_buf buf;

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static EXCEPTION_DISPOSITION __cdecl outer_unwind_handler(EXCEPTION_RECORD *ExceptionRecord, PVOID EstablisherFrame __attribute__((unused)), CONTEXT *ContextRecord __attribute__((unused)), PVOID DispatcherContext __attribute__((unused)))
{
  printf("System called outer SEH unwind handler with flags 0x%lx\n", ExceptionRecord->ExceptionFlags);
  if (ExceptionRecord->ExceptionFlags & EXCEPTION_UNWINDING)
    outer_unwind_called++;
  return ExceptionContinueSearch;
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static EXCEPTION_DISPOSITION __cdecl target_unwind_handler(EXCEPTION_RECORD *ExceptionRecord, PVOID EstablisherFrame __attribute__((unused)), CONTEXT *ContextRecord __attribute__((unused)), PVOID DispatcherContext __attribute__((unused)))
{
  printf("System called target SEH unwind handler with flags 0x%lx\n", ExceptionRecord->ExceptionFlags);
  if ((ExceptionRecord->ExceptionFlags & (EXCEPTION_UNWINDING | EXCEPTION_TARGET_UNWIND)) == (EXCEPTION_UNWINDING | EXCEPTION_TARGET_UNWIND))
    target_unwind_called++;
  return ExceptionContinueSearch;
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static EXCEPTION_DISPOSITION __cdecl inner_unwind_handler(EXCEPTION_RECORD *ExceptionRecord, PVOID EstablisherFrame __attribute__((unused)), CONTEXT *ContextRecord __attribute__((unused)), PVOID DispatcherContext __attribute__((unused)))
{
  printf("System called inner SEH unwind handler with flags 0x%lx\n", ExceptionRecord->ExceptionFlags);
  if (ExceptionRecord->ExceptionFlags & EXCEPTION_UNWINDING)
    inner_unwind_called++;
  return ExceptionContinueSearch;
}

#ifdef TEST_NOUNWIND
#if defined(__i386__)
static EXCEPTION_REGISTRATION_RECORD *inner_exception_record_ptr;
static EXCEPTION_REGISTRATION_RECORD inner_exception_record_copy;
#endif
#endif

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif
#if !defined(__i386__) && defined(SEH_INLINE_ASM)
__attribute__((noinline)) /* required for asm .seh_handler directive */
#endif
#if defined(__i386__)
__attribute__((noinline)) /* prevents optimizing out exception_record structure before calling longjmp() */
#endif
static void register_inner_unwind_handler_and_call_longjmp(void)
{
#if defined(__i386__)
  EXCEPTION_REGISTRATION_RECORD inner_exception_record = {
    .Next = (EXCEPTION_REGISTRATION_RECORD *)__readfsdword(0),
    .Handler = (PEXCEPTION_ROUTINE)(INT_PTR)inner_unwind_handler,
  };
  __writefsdword(0, (DWORD)&inner_exception_record);
#ifdef TEST_NOUNWIND
  inner_exception_record_ptr = &inner_exception_record;
  inner_exception_record_copy = inner_exception_record;
#endif
#elif defined(SEH_INLINE_ASM)
  asm volatile (".seh_handler %c0, " ASM_SEH_UNWIND :: "i" (inner_unwind_handler));
#else
  return; /* should not happen; triggers runtime error */
#endif

#if defined(TEST_NOUNWIND) && defined(__i386__)
  printf("Calling longjmp()\n");
#else
  printf("Calling longjmp() and unregistering inner SEH unwind handler\n");
#endif
  longjmp(buf, 1);

  /* NOTE: longjmp does not return and on i386 it unregister all SEH handlers up to the target one */

  printf("Unregistering inner SEH unwind handler\n");
#if defined(__i386__)
  if (__readfsdword(0) != (DWORD)&inner_exception_record) {
    printf("ERROR: Cannot unregister inner SEH unwind handler because of corrupted list of SEH records\n");
    return;
  }
  __writefsdword(0, (DWORD)inner_exception_record.Next);
#endif
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#if !defined(__i386__) && defined(SEH_INLINE_ASM)
__attribute__((noinline)) /* required for asm .seh_handler directive */
#endif
static int register_target_unwind_handler_and_call_setjmp_and_register_inner_unwind_handler_and_call_longjmp(void)
{
#if defined(__i386__)
  EXCEPTION_REGISTRATION_RECORD target_exception_record = {
    .Next = (EXCEPTION_REGISTRATION_RECORD *)__readfsdword(0),
    .Handler = (PEXCEPTION_ROUTINE)(INT_PTR)target_unwind_handler,
  };
  __writefsdword(0, (DWORD)&target_exception_record);
#elif defined(SEH_INLINE_ASM)
  asm volatile (".seh_handler %c0, " ASM_SEH_UNWIND :: "i" (target_unwind_handler));
#else
  return 1; /* should not happen; triggers runtime error */
#endif

  printf("Calling setjmp()\n");

  if (!setjmp(buf)) {
    printf("Registering inner SEH unwind handler\n");
    register_inner_unwind_handler_and_call_longjmp();
    printf("ERROR: longjmp() returned\n");
    return 1;
  }

  printf("setjmp() returned from longjmp()\n");

#ifdef TEST_NOUNWIND
#if defined(__i386__)
  printf("Unregistering inner SEH unwind handler\n");
  if (__readfsdword(0) != (DWORD)inner_exception_record_ptr) {
    printf("ERROR: Cannot unregister inner SEH unwind handler because of corrupted list of SEH records\n");
    return 1;
  }
  __writefsdword(0, (DWORD)inner_exception_record_copy.Next);
#endif
#endif

  printf("Unregistering target SEH unwind handler\n");
#if defined(__i386__)
  if (__readfsdword(0) != (DWORD)&target_exception_record) {
    printf("ERROR: Cannot unregister target SEH unwind handler because of corrupted list of SEH records\n");
    return 1;
  }
  __writefsdword(0, (DWORD)target_exception_record.Next);
#endif
  return 0;
}

#if !defined(__i386__) && defined(SEH_INLINE_ASM)
__attribute__((noinline)) /* required for asm .seh_handler directive */
#endif
static int register_outer_unwind_handler_and_register_target_unwind_handler_and_call_setjmp_and_register_inner_unwind_handler_and_call_longjmp(void)
{
#if defined(__i386__)
  EXCEPTION_REGISTRATION_RECORD outer_exception_record = {
    .Next = (EXCEPTION_REGISTRATION_RECORD *)__readfsdword(0),
    .Handler = (PEXCEPTION_ROUTINE)(INT_PTR)outer_unwind_handler,
  };
  __writefsdword(0, (DWORD)&outer_exception_record);
#elif defined(SEH_INLINE_ASM)
  asm volatile (".seh_handler %c0, " ASM_SEH_UNWIND :: "i" (outer_unwind_handler));
#else
  return 1; /* should not happen; triggers runtime error */
#endif

  printf("Registering target SEH unwind handler\n");
  int ret = register_target_unwind_handler_and_call_setjmp_and_register_inner_unwind_handler_and_call_longjmp();

  printf("Unregistering outer SEH unwind handler\n");
#if defined(__i386__)
  if (__readfsdword(0) != (DWORD)&outer_exception_record) {
    printf("ERROR: Cannot unregister outer SEH unwind handler because of corrupted list of SEH records\n");
    return 1;
  }
  __writefsdword(0, (DWORD)outer_exception_record.Next);
#endif
  return ret;
}

int main(int argc, char **argv)
{
  mingw_test_init();

#ifndef TEST_NOUNWIND
#if !defined(__i386__) && !defined(SEH_INLINE_ASM)
  printf("SKIP: No SEH support\n");
  return 77;
#endif
#endif

#ifdef TEST_NOUNWIND
#if defined(__arm64ec__)
  printf("SKIP: __USE_MINGW_SETJMP_NON_SEH is broken on arm64ec\n");
  return 77;
#endif
#endif

  outer_unwind_called = 0;
  target_unwind_called = 0;
  inner_unwind_called = 0;

  printf("Registering outer SEH unwind handler\n");
  int ret = register_outer_unwind_handler_and_register_target_unwind_handler_and_call_setjmp_and_register_inner_unwind_handler_and_call_longjmp();

  if (outer_unwind_called != 0) {
    printf("ERROR: Outer SEH unwind handler was called\n");
    ret = 1;
  } else {
    printf("OK: Outer SEH unwind handler was not called\n");
  }

#ifndef TEST_NOUNWIND
#ifdef __i386__
  /* i386 fs:0 based SEH does not call the last (target) handler */
  if (target_unwind_called != 0) {
    printf("ERROR: Target SEH unwind handler was called\n");
    ret = 1;
  } else {
    printf("OK: Target SEH unwind handler was not called\n");
  }
#else
  /* non-i386 .pdata based SEH always calls the last target handler with the EXCEPTION_TARGET_UNWIND flag */
  if (target_unwind_called == 0) {
    printf("ERROR: Target SEH unwind handler was not called\n");
    ret = 1;
  } else if (target_unwind_called != 1) {
    printf("ERROR: Target SEH unwind handler was called more times (%d)\n", target_unwind_called);
    ret = 1;
  } else {
    printf("OK: Target SEH unwind handler was called exactly once\n");
  }
#endif
#else
  if (target_unwind_called != 0) {
    printf("ERROR: Target SEH unwind handler was called\n");
    ret = 1;
  } else {
    printf("OK: Target SEH unwind handler was not called\n");
  }
#endif

#ifndef TEST_NOUNWIND
  if (inner_unwind_called == 0) {
    printf("ERROR: Inner SEH unwind handler was not called\n");
    ret = 1;
  } else if (inner_unwind_called != 1) {
    printf("ERROR: Inner SEH unwind handler was called more times (%d)\n", inner_unwind_called);
    ret = 1;
  } else {
    printf("OK: Inner SEH unwind handler was called exactly once\n");
  }
#else
  if (inner_unwind_called != 0) {
    printf("ERROR: Inner SEH unwind handler was called\n");
    ret = 1;
  } else {
    printf("OK: Inner SEH unwind handler was not called\n");
  }
#endif

  return ret;
}
