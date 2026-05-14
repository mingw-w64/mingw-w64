/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)
#include <windows.h>

struct illegal_instruction_establisher_frame {
  EXCEPTION_REGISTRATION_RECORD exception_record;
  BOOL illegal_instruction_occured;
};

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static EXCEPTION_DISPOSITION __cdecl
illegal_instruction_handler(EXCEPTION_RECORD *ExceptionRecord,
                            PVOID EstablisherFrame,
                            CONTEXT *ContextRecord,
                            PVOID DispatcherContext __attribute__ ((unused)))
{

  if (!(ExceptionRecord->ExceptionFlags & EXCEPTION_UNWINDING) &&
      !(ExceptionRecord->ExceptionFlags & EXCEPTION_NONCONTINUABLE) &&
      ExceptionRecord->ExceptionCode == STATUS_ILLEGAL_INSTRUCTION)
    {
      ((struct illegal_instruction_establisher_frame *)EstablisherFrame)->illegal_instruction_occured = TRUE;
      ContextRecord->Eip += 3; /* skip "movaps %%xmm0, %%xmm0" */
      return ExceptionContinueExecution;
    }

  return ExceptionContinueSearch;
}

int __mingw_has_sse (void);
static int __has_sse = -1;

int __mingw_has_sse(void)
{
  int cpuInfo[4], infoType = 1;
  int o_flag, n_flag;

  if (__has_sse != -1)
    return __has_sse;

  __asm__ volatile ("pushfl\n\tpopl %0" : "=mr" (o_flag));
  n_flag = o_flag ^ 0x200000;
  __asm__ volatile ("pushl %0\n\tpopfl" : : "g" (n_flag));
  __asm__ volatile ("pushfl\n\tpopl %0" : "=mr" (n_flag));
  if (n_flag == o_flag)
    {
      __has_sse = 0;
      return 0;
    }

  __asm__ __volatile__ (
    "cpuid"
    : "=a" (cpuInfo[0]), "=b" (cpuInfo[1]), "=c" (cpuInfo[2]),
    "=d" (cpuInfo[3])
    : "a" (infoType));
  if (!(cpuInfo[3] & 0x2000000))
    {
      __has_sse = 0;
      return 0;
    }

  /* Pre-Win2k systems do not have to enable CR4.OSFXSR and then
   * SSE instructions cannot be used even when CPU has SSE support.
   * So these systems has to be marked as without SSE support.
   * Try to execute SSE nop "movaps %%xmm0, %%xmm0" and check if system
   * throws SEH exception STATUS_ILLEGAL_INSTRUCTION or not.
   * Note that IsProcessorFeaturePresent(PF_XMMI_INSTRUCTIONS_AVAILABLE)
   * cannot be used as PF_XMMI_INSTRUCTIONS_AVAILABLE flag is not returned
   * on pre-Win2k systems, even when system properly enabled CR4.OSFXSR.
   */
  struct illegal_instruction_establisher_frame establisher_frame = {
    .exception_record = {
      .Next = (EXCEPTION_REGISTRATION_RECORD *)__readfsdword (0),
      .Handler = (PEXCEPTION_ROUTINE)(INT_PTR)illegal_instruction_handler,
    },
    .illegal_instruction_occured = FALSE,
  };
  __writefsdword (0, (DWORD)&establisher_frame);
  __asm__ volatile ("movaps %%xmm0, %%xmm0" :);
  __writefsdword (0, (DWORD)establisher_frame.exception_record.Next);
  if (establisher_frame.illegal_instruction_occured)
    {
      __has_sse = 0;
      return 0;
    }

  __has_sse = 1;
  return 1;
}
#endif  /* __i386__ */
