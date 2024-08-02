/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <excpt.h>

#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__)
EXCEPTION_DISPOSITION __cdecl
__C_specific_handler(struct _EXCEPTION_RECORD *_ExceptionRecord,
                     void *_EstablisherFrame,
                     struct _CONTEXT *_ContextRecord,
                     struct _DISPATCHER_CONTEXT *_DispatcherContext)
{
  (void)_ExceptionRecord;
  (void)_EstablisherFrame;
  (void)_ContextRecord;
  (void)_DispatcherContext;
  // TODO A more comprehensive implementation. Normally this is only used
  // by the toplevel SEH handler for uncaught exceptions, for calling
  // signal handlers. If signal handling isn't used, this no-op implementation
  // should be ok. Wine does contain a supposedly correct implementation of
  // this for x86_64 at least.
  return ExceptionContinueSearch;
}

EXCEPTION_DISPOSITION
(__cdecl *__MINGW_IMP_SYMBOL(__C_specific_handler))(
    struct _EXCEPTION_RECORD *_ExceptionRecord,
    void *_EstablisherFrame,
    struct _CONTEXT *_ContextRecord,
    struct _DISPATCHER_CONTEXT *_DispatcherContext) = __C_specific_handler;
#endif
