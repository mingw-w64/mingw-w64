#define _GNU_SOURCE /* for feenableexcept and fedisableexcept */
#include <stdio.h>
#include <stdint.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <fenv.h>
#include <pthread.h>

#ifdef _WIN32
#include <process.h>
#include <windows.h>
#endif

#if defined(__i386__)
 #if defined(__SSE__)
  #define has_sse() 1
 #else
  #ifdef _WIN32
   int __mingw_has_sse(void);
   #define has_sse() __mingw_has_sse()
  #else
   #define has_sse() __builtin_cpu_supports("sse")
  #endif
 #endif
#elif defined(__x86_64__)
 #define has_sse() 1
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
 #ifdef __clang__
  /* clang does not support __float80 type and does not support 'x' suffix for floating point constant */
  typedef float __float80 __attribute__((mode(XF)));
  union float80_storage {
    unsigned char bits[10];
    __float80 value;
  };
  static const union float80_storage float80_min = {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00}};
  static const union float80_storage float80_max = {{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F}};
  static const union float80_storage float80_snan = {{0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x7F}};
  #define F80_MIN (float80_min.value)
  #define F80_MAX (float80_max.value)
  #define F80_SNAN (float80_snan.value)
 #else
  /* gcc supports __float80 type and alias it to long double, so 'L' suffix works correctly */
  #define F80_MIN (0x1.0p-16382L)
  #define F80_MAX (0x1.fffffffffffffffep+16383L)
  #define F80_SNAN ((__float80)__builtin_nansl(""))
 #endif
 _Static_assert(sizeof(__float80) >= 10, "__float80 is not 80-bit float");
#endif

#if defined(__GNUC__)
 #define FLOAT_SNAN __builtin_nansf("")
#else
 union float_storage {
   unsigned char bits[4];
   float value;
 };
 static const union float_storage float_snan = {{0x01, 0x00, 0x80, 0x7F}};
 #define FLOAT_SNAN (float_snan.value)
#endif

/* mingw-w64 does not provide sigsetjmp() and siglongjmp() functions, so provide simple implementation */
#ifdef _WIN32
typedef struct {
  jmp_buf buf;
  int sigs_saved;
  void (__cdecl*sigint)(int);
  void (__cdecl*sigill)(int);
  void (__cdecl*sigfpe)(int);
  void (__cdecl*sigsegv)(int);
  void (__cdecl*sigterm)(int);
  void (__cdecl*sigbreak)(int);
  void (__cdecl*sigabrt)(int);
} _SIGJUMP_BUFFER;
typedef _JBTYPE sigjmp_buf[(sizeof(_SIGJUMP_BUFFER) + sizeof(_JBTYPE) + 1) / sizeof(_JBTYPE)];

static void (__cdecl*get_sighandler(int sig))(int)
{
  /* pre-msvcr80 libraries do not support SIG_GET and sets the signal handler to SIG_GET.
   * Detect this behavior and restore the signal handler back. */
  void (__cdecl*handler)(int) = signal(sig, SIG_GET);
  if (signal(sig, SIG_GET) == SIG_GET)
    signal(sig, handler);
  return handler;
}

static void save_jmp_sigs(sigjmp_buf _SigBuf, int _SaveSigs)
{
  _SIGJUMP_BUFFER *sigbuf = (void *)_SigBuf;
  if (_SaveSigs) {
    sigbuf->sigs_saved = 1;
    sigbuf->sigint = get_sighandler(SIGINT);
    sigbuf->sigill = get_sighandler(SIGILL);
    sigbuf->sigfpe = get_sighandler(SIGFPE);
    sigbuf->sigsegv = get_sighandler(SIGSEGV);
    sigbuf->sigterm = get_sighandler(SIGTERM);
    sigbuf->sigbreak = get_sighandler(SIGBREAK);
    sigbuf->sigabrt = get_sighandler(SIGABRT);
  } else {
    sigbuf->sigs_saved = 0;
    sigbuf->sigint = NULL;
    sigbuf->sigill = NULL;
    sigbuf->sigfpe = NULL;
    sigbuf->sigsegv = NULL;
    sigbuf->sigterm = NULL;
    sigbuf->sigbreak = NULL;
    sigbuf->sigabrt = NULL;
  }
}

static void restore_jmp_sigs(sigjmp_buf _SigBuf)
{
  _SIGJUMP_BUFFER *sigbuf = (void *)_SigBuf;
  if (sigbuf->sigs_saved) {
    signal(SIGINT, sigbuf->sigint);
    signal(SIGILL, sigbuf->sigill);
    signal(SIGFPE, sigbuf->sigfpe);
    signal(SIGSEGV, sigbuf->sigsegv);
    signal(SIGTERM, sigbuf->sigterm);
    signal(SIGBREAK, sigbuf->sigbreak);
    signal(SIGABRT, sigbuf->sigabrt);
  }
}

/*
 * setjmp() needs to be called directly from the user calling function
 * due to stack inspection, so the sigsetjmp() cannot be defined as normal
 * function and needs to be inlined. So define it as a simple macro.
 */
#define sigsetjmp(SIGBUF, savesigs) ( \
  save_jmp_sigs((SIGBUF), (savesigs)), \
  setjmp(((_SIGJUMP_BUFFER *)(SIGBUF))->buf) \
)

#define siglongjmp(SIGBUF, value) ( \
  restore_jmp_sigs((SIGBUF)), \
  longjmp(((_SIGJUMP_BUFFER *)(SIGBUF))->buf, (value)) \
)
#endif

typedef void (*sighandler_t)(int);

#if defined(_WIN32)
static DWORD main_threadid;
#endif

static sigjmp_buf buf;
#ifdef _WIN32
static int last_fpenum;
#endif

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
#ifdef __GNUC__
__attribute__((noreturn))
#endif
static void catch_sigfpe(int signum
#ifdef _WIN32
/*
 * Windows for SIGFPE handler provides additional fpenum argument which
 * contains the FPU error code, same what is stored in _fpecode variable.
 */
, int fpenum
#endif
)
{
  printf("SIGFPE exception caught\n");
  assert(signum == SIGFPE);
#ifdef _WIN32
  /* FIXME: fpenum and _fpecode are broken for main thread */
  if (main_threadid != GetCurrentThreadId())
  assert(fpenum == _fpecode);
  last_fpenum = fpenum;
#endif
  siglongjmp(buf, 1);
}
#ifdef _WIN32
#define catch_sigfpe ((sighandler_t)(void(*)(void))catch_sigfpe)
#endif

static void clear_x87_stack(void)
{
  /* On x86, every cdecl function must clear the x87 stack, callers expect it.
   * If the FPU exception happens then the SEH handler is called and it gives
   * control to the SIGFPE signal handler function, with the x87 stack is in
   * the state as it was during the FPU exception. Then the SIGFPE signal
   * handler calls the longjmp() function which result that setjmp() function
   * returns back to its original caller. And the x87 stack is in the state
   * as it was during FPU execution. It is not cleared as it is expected
   * from cdecl function, which setjmp() is.
   *
   * So if the x87 stack is full and some other function (after setjmp()
   * returns), tries to use it (because it properly expect that is free),
   * the new x87 FPU stack overflow is triggered. To prevent this problem,
   * always call this function after setjmp() returns non-zero value.
   */
#if defined(__GNUC__) && (defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__)))
  asm volatile (
    ".rept 8\n\t"
    "ffree %%st(0)\n\t"
    "fincstp\n\t"
    ".endr\n\t"
    ::: "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)"
  );
#endif
}

static void deliver_x87_exception(void)
{
  /* On Win9x is CR0.NE set to 0 which cause that x87 exceptions are delivered asynchronously.
   * To stop executing of x86 instructions until the pending x87 exception is processed
   * it is needed to explicitly call fwait instruction.
   */
#if defined(_WIN32) && defined(__GNUC__) && defined(__i386__)
  asm volatile ("fwait" ::: "memory");
#endif
}

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
#if defined(__clang__)
__attribute__((target("no-sse")))
#elif defined(__GNUC__)
__attribute__((target("no-sse,fpmath=387")))
#endif
#endif
static int float_div_zero(void)
{
  puts("\nprepare: unmask FE_DIVBYZERO");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_DIVBYZERO);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float 100 / 0");
    volatile float a = 100;
    volatile float b = 0;
    volatile float c = a / b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_ZERODIVIDE)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_DIVBYZERO);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}

#if defined(__i386__) || defined(__x86_64__)
#if defined(__clang__)
__attribute__((target("sse")))
#elif defined(__GNUC__)
__attribute__((target("sse,fpmath=sse")))
#endif
static int sse_float_div_zero(void)
{
  puts("\nprepare: unmask FE_DIVBYZERO");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_DIVBYZERO);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: SSE float 100 / 0");
    volatile float a = 100;
    volatile float b = 0;
    volatile float c = a / b;
    (void)c;
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
#if defined(__i386__)
    /* If SSE floating point division by zero occurs then Windows system for 32-bit x86 processes
     * generates SEH exception STATUS_FLOAT_MULTIPLE_TRAPS instead of EXCEPTION_FLT_DIVIDE_BY_ZERO.
     * UCRT library for threads spawned by _beginthread/_beginthreadex in recent versions changes
     * Windows SEH exception STATUS_FLOAT_MULTIPLE_TRAPS to EXCEPTION_FLT_DIVIDE_BY_ZERO.
     * So for non-main threads in UCRT builds accept both FPE codes.
     */
#if defined(_UCRT)
    if (last_fpenum != _FPE_MULTIPLE_TRAPS && (main_threadid == GetCurrentThreadId() || last_fpenum != _FPE_ZERODIVIDE))
#else
    if (last_fpenum != _FPE_MULTIPLE_TRAPS)
#endif
#else
    if (last_fpenum != _FPE_ZERODIVIDE)
#endif
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_DIVBYZERO);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
static int float80_div_zero(void)
{
  puts("\nprepare: unmask FE_DIVBYZERO");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_DIVBYZERO);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float80 100 / 0");
    volatile __float80 a = 100;
    volatile __float80 b = 0;
    volatile __float80 c = a / b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_ZERODIVIDE)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_DIVBYZERO);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
#if defined(__clang__)
__attribute__((target("no-sse")))
#elif defined(__GNUC__)
__attribute__((target("no-sse,fpmath=387")))
#endif
#endif
static int float_invalid(void)
{
  puts("\nprepare: unmask FE_INVALID");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_INVALID);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float SNAN + 1");
    volatile float a = FLOAT_SNAN;
    volatile float b = 1;
    volatile float c = a + b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_INVALID)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_INVALID);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}

#if defined(__i386__) || defined(__x86_64__)
#if defined(__clang__)
__attribute__((target("sse")))
#elif defined(__GNUC__)
__attribute__((target("sse,fpmath=sse")))
#endif
static int sse_float_invalid(void)
{
  puts("\nprepare: unmask FE_INVALID");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_INVALID);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: SSE float SNAN + 1");
    volatile float a = FLOAT_SNAN;
    volatile float b = 1;
    volatile float c = a + b;
    (void)c;
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
#if defined(__i386__)
    /* If SSE floating point invalid operation occurs then Windows system for 32-bit x86 processes
     * generates SEH exception STATUS_FLOAT_MULTIPLE_TRAPS instead of EXCEPTION_FLT_INVALID_OPERATION.
     * UCRT library for threads spawned by _beginthread/_beginthreadex in recent versions changes
     * Windows SEH exception STATUS_FLOAT_MULTIPLE_TRAPS to EXCEPTION_FLT_INVALID_OPERATION.
     * So for non-main threads in UCRT builds accept both FPE codes.
     */
#if defined(_UCRT)
    if (last_fpenum != _FPE_MULTIPLE_TRAPS && (main_threadid == GetCurrentThreadId() || last_fpenum != _FPE_INVALID))
#else
    if (last_fpenum != _FPE_MULTIPLE_TRAPS)
#endif
#else
    if (last_fpenum != _FPE_INVALID)
#endif
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_INVALID);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
static int float80_invalid(void)
{
  puts("\nprepare: unmask FE_INVALID");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_INVALID);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float80 SNAN + 1");
    volatile __float80 a = F80_SNAN;
    volatile __float80 b = 1;
    volatile __float80 c = a + b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_INVALID)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_INVALID);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
#if defined(__clang__)
__attribute__((target("no-sse")))
#elif defined(__GNUC__)
__attribute__((target("no-sse,fpmath=387")))
#endif
#endif
static int float_overflow(void)
{
  puts("\nprepare: unmask FE_OVERFLOW");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_OVERFLOW);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float FLT_MAX * FLT_MAX");
    volatile float a = FLT_MAX;
    volatile float b = FLT_MAX;
    volatile float c = a * b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_OVERFLOW)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_OVERFLOW);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}

#if defined(__i386__) || defined(__x86_64__)
#if defined(__clang__)
__attribute__((target("sse")))
#elif defined(__GNUC__)
__attribute__((target("sse,fpmath=sse")))
#endif
static int sse_float_overflow(void)
{
  puts("\nprepare: unmask FE_OVERFLOW");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_OVERFLOW);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: SSE float FLT_MAX * FLT_MAX");
    volatile float a = FLT_MAX;
    volatile float b = FLT_MAX;
    volatile float c = a * b;
    (void)c;
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
#if defined(__i386__)
    /* If SSE floating point overflow occurs then Windows system for 32-bit x86 processes
     * generates SEH exception STATUS_FLOAT_MULTIPLE_FAULTS instead of EXCEPTION_FLT_OVERFLOW.
     * UCRT library for threads spawned by _beginthread/_beginthreadex in recent versions changes
     * Windows SEH exception STATUS_FLOAT_MULTIPLE_FAULTS to EXCEPTION_FLT_OVERFLOW.
     * So for non-main threads in UCRT builds accept both FPE codes.
     */
#if defined(_UCRT)
    if (last_fpenum != _FPE_MULTIPLE_FAULTS && (main_threadid == GetCurrentThreadId() || last_fpenum != _FPE_OVERFLOW))
#else
    if (last_fpenum != _FPE_MULTIPLE_FAULTS)
#endif
#else
    if (last_fpenum != _FPE_OVERFLOW)
#endif
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_OVERFLOW);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
static int float80_overflow(void)
{
  puts("\nprepare: unmask FE_OVERFLOW");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_OVERFLOW);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float80 F80_MAX * F80_MAX");
    volatile __float80 a = F80_MAX;
    volatile __float80 b = F80_MAX;
    volatile __float80 c = a * b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_OVERFLOW)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_OVERFLOW);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
#if defined(__clang__)
__attribute__((target("no-sse")))
#elif defined(__GNUC__)
__attribute__((target("no-sse,fpmath=387")))
#endif
#endif
static int float_underflow(void)
{
  puts("\nprepare: unmask FE_UNDERFLOW");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_UNDERFLOW);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float FLT_MIN / 1024");
    volatile float a = FLT_MIN;
    volatile float b = 1024; /* must be power of two to prevent FE_INEXACT */
    volatile float c = a / b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_UNDERFLOW)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_UNDERFLOW);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}

#if defined(__i386__) || defined(__x86_64__)
#if defined(__clang__)
__attribute__((target("sse")))
#elif defined(__GNUC__)
__attribute__((target("sse,fpmath=sse")))
#endif
static int sse_float_underflow(void)
{
  puts("\nprepare: unmask FE_UNDERFLOW");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_UNDERFLOW);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: SSE float FLT_MIN / 1024");
    volatile float a = FLT_MIN;
    volatile float b = 1024; /* must be power of two to prevent FE_INEXACT */
    volatile float c = a / b;
    (void)c;
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
#if defined(__i386__)
    /* If SSE floating point underflow occurs then Windows system for 32-bit x86 processes
     * generates SEH exception STATUS_FLOAT_MULTIPLE_FAULTS instead of EXCEPTION_FLT_UNDERFLOW.
     * UCRT library for threads spawned by _beginthread/_beginthreadex in recent versions changes
     * Windows SEH exception STATUS_FLOAT_MULTIPLE_FAULTS to EXCEPTION_FLT_UNDERFLOW.
     * So for non-main threads in UCRT builds accept both FPE codes.
     */
#if defined(_UCRT)
    if (last_fpenum != _FPE_MULTIPLE_FAULTS && (main_threadid == GetCurrentThreadId() || last_fpenum != _FPE_UNDERFLOW))
#else
    if (last_fpenum != _FPE_MULTIPLE_FAULTS)
#endif
#else
    if (last_fpenum != _FPE_UNDERFLOW)
#endif
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_UNDERFLOW);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
static int float80_underflow(void)
{
  puts("\nprepare: unmask FE_UNDERFLOW");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_UNDERFLOW);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float80 F80_MIN / 1024");
    volatile __float80 a = F80_MIN;
    volatile __float80 b = 1024; /* must be power of two to prevent FE_INEXACT */
    volatile __float80 c = a / b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_UNDERFLOW)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_UNDERFLOW);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
#if defined(__clang__)
__attribute__((target("no-sse")))
#elif defined(__GNUC__)
__attribute__((target("no-sse,fpmath=387")))
#endif
#endif
static int float_inexact(void)
{
  puts("\nprepare: unmask FE_INEXACT");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_INEXACT);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float 1 / 3");
    volatile float a = 1;
    volatile float b = 3;
    volatile float c = a / b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_INEXACT)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_INEXACT);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}

#if defined(__i386__) || defined(__x86_64__)
#if defined(__clang__)
__attribute__((target("sse")))
#elif defined(__GNUC__)
__attribute__((target("sse,fpmath=sse")))
#endif
static int sse_float_inexact(void)
{
  puts("\nprepare: unmask FE_INEXACT");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_INEXACT);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: SSE float 1 / 3");
    volatile float a = 1;
    volatile float b = 3;
    volatile float c = a / b;
    (void)c;
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
#if defined(__i386__)
    /* If SSE floating point inexact occurs then Windows system for 32-bit x86 processes
     * generates SEH exception STATUS_FLOAT_MULTIPLE_FAULTS instead of EXCEPTION_FLT_INEXACT_RESULT.
     * UCRT library for threads spawned by _beginthread/_beginthreadex in recent versions changes
     * Windows SEH exception STATUS_FLOAT_MULTIPLE_FAULTS to EXCEPTION_FLT_INEXACT_RESULT.
     * So for non-main threads in UCRT builds accept both FPE codes.
     */
#if defined(_UCRT)
    if (last_fpenum != _FPE_MULTIPLE_FAULTS && (main_threadid == GetCurrentThreadId() || last_fpenum != _FPE_INEXACT))
#else
    if (last_fpenum != _FPE_MULTIPLE_FAULTS)
#endif
#else
    if (last_fpenum != _FPE_INEXACT)
#endif
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_INEXACT);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
static int float80_inexact(void)
{
  puts("\nprepare: unmask FE_INEXACT");
  int ret;
  int oldexcpt = fedisableexcept(FE_ALL_EXCEPT);
  feenableexcept(FE_INEXACT);
  feclearexcept(FE_ALL_EXCEPT);
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: float80 1 / 3");
    volatile __float80 a = 1;
    volatile __float80 b = 3;
    volatile __float80 c = a / b;
    (void)c;
    deliver_x87_exception();
    feclearexcept(FE_ALL_EXCEPT);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    feclearexcept(FE_ALL_EXCEPT);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_INEXACT)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  fedisableexcept(FE_INEXACT);
  signal(SIGFPE, prev_handler);
  feenableexcept(oldexcpt);
  return ret;
}
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
static int ten_x87_fld(void)
{
  puts("\nprepare: unmask x87 Invalid operation");
  int ret;
  unsigned short oldcw, newcw;
  asm volatile ("fnstcw %0" : "=m" (oldcw));
  newcw = oldcw & ~0x1; /* clear mask for Invalid operation interrupt */
  asm volatile ("fnclex" :);
  asm volatile ("fldcw %0" :: "m" (newcw));
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: 10x x87 fld");
    asm volatile (
      ".rept 10\n\t"
      "fldz\n\t"
      ".endr\n\t"
      ::: "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)"
    );
    deliver_x87_exception();
    asm volatile ("fnclex" :);
    clear_x87_stack();
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    asm volatile ("fnclex" :);
    clear_x87_stack();
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_STACKOVERFLOW)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  asm volatile ("fldcw %0" :: "m" (oldcw));
  signal(SIGFPE, prev_handler);
  return ret;
}
#endif

static int raise_sigfpe(void)
{
  puts("\nprepare");
  int ret;
  sighandler_t prev_handler = signal(SIGFPE, catch_sigfpe);
  if (!sigsetjmp(buf, 1))
  {
    puts("execute: raise(SIGFPE)");
    raise(SIGFPE);
    puts("result: FAILED, program continued");
    ret = 1;
  }
  else
  {
    puts("result: PASSED, program recovered");
    ret = 0;
#ifdef _WIN32
    /* FIXME: fpenum is broken for main thread */
    if (main_threadid != GetCurrentThreadId())
    if (last_fpenum != _FPE_EXPLICITGEN)
    {
      printf("wrong FPE error detected: 0x%x\n", last_fpenum);
      ret = 1;
    }
#endif
  }
  puts("finish");
  signal(SIGFPE, prev_handler);
  return ret;
}

static int test(void)
{
  int ret = 0;

  /* call two times to ensure that SIGFPE handler can be repeatedly registered */

  ret |= raise_sigfpe();
  ret |= raise_sigfpe();

  /* FIXME: On Windows for arm processes floating point exceptions are not thrown */
#if defined(_WIN32) && (defined(__arm__) || defined(__aarch64__) || defined(__arm64ec__))
  if (ret)
    return ret;
  else
    return 77;
#endif

  ret |= float_div_zero();
  ret |= float_div_zero();

  ret |= float_invalid();
  ret |= float_invalid();

  ret |= float_overflow();
  ret |= float_overflow();

  ret |= float_underflow();
  ret |= float_underflow();

  ret |= float_inexact();
  ret |= float_inexact();

  /* sse is available only on x86 */
#if defined(__i386__) || defined(__x86_64__)
  if (has_sse())
  {
    /* skip SSE tests on Win9x and WinNT4 OS systems (all are pre-Win2k).
     * If SSE floating point exception occurs then these systems generate
     * SEH exception EXCEPTION_ILLEGAL_INSTRUCTION instead of EXCEPTION_FLT_*
     * even when the legal instruction is executed (and with disabled FPE
     * exceptions the SSE instruction works fine). CRT does not handle
     * EXCEPTION_ILLEGAL_INSTRUCTION via SIGFPE signal() handler. */
#if defined(_WIN32) && defined(__i386__)
    if (_winver < _WIN32_WINNT_WIN2K)
    {
      puts("\nsystem reports wrong SEH for SSE, skipping SSE tests");
    }
    else
#endif
    {
#if defined(_WIN32) && defined(__i386__)
#if __MSVCRT_VERSION__ < 0xa00
      /* FIXME: On Windows for 32-bit x86 processes with pre-msvcr100 all SSE floating point exceptions do not trigger SIGFPE for non-main thread and instead crashes process */
      if (main_threadid == GetCurrentThreadId())
#endif
#endif
      {
      ret |= sse_float_div_zero();
      ret |= sse_float_div_zero();

      ret |= sse_float_invalid();
      ret |= sse_float_invalid();

      ret |= sse_float_overflow();
      ret |= sse_float_overflow();

      ret |= sse_float_underflow();
      ret |= sse_float_underflow();

      ret |= sse_float_inexact();
      ret |= sse_float_inexact();
      }
    }
  }
  else
  {
    puts("\nno SSE support, skipping SSE tests");
  }
#endif

  /* 80-bit float is only available via x87 */
#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
  ret |= float80_div_zero();
  ret |= float80_div_zero();

  ret |= float80_invalid();
  ret |= float80_invalid();

  ret |= float80_overflow();
  ret |= float80_overflow();

  ret |= float80_underflow();
  ret |= float80_underflow();

  ret |= float80_inexact();
  ret |= float80_inexact();
#endif

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
  ret |= ten_x87_fld();
  ret |= ten_x87_fld();
#endif

  return ret;
}

static void *test_from_pthread_create(void *arg)
{
  (void)arg;
  return (void *)(intptr_t)test();
}

#ifdef _WIN32
#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static unsigned __stdcall test_from_beginthreadex(void *arg)
{
  (void)arg;
  return test();
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
#ifdef __GNUC__
__attribute__((noreturn))
#endif
static void __cdecl test_from_beginthread(void *arg)
{
  /* Do not return from _beginthread's startaddress and do not call _endthread()
   * as they invalidate the thread handle returned by _beginthread().
   * The thread handle is used by _beginthread()'s caller which will close it.
   * So the only safe option is to exit this tread via WinAPI ExitThread() function.
   */
  (void)arg;
  ExitThread(test());
}
#endif

#ifdef _WIN32
#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static LONG WINAPI catch_unhandled_seh_exception(EXCEPTION_POINTERS *exception_data)
{
  printf("unhandled SEH exception 0x%08lx caught\n", exception_data->ExceptionRecord->ExceptionCode);
  printf("test failed, exiting\n");
  exit(1);
}
#endif

int main(void)
{
  int ret = 0;
  pthread_t pthread;
#ifdef _WIN32
  HANDLE wthread;
#endif

#if defined(_WIN32)
  main_threadid = GetCurrentThreadId();
#endif

#ifdef _WIN32
  /* On Windows install custom application top-level SEH exception handler.
   * All tests have to pass even with this custom handler. */
  SetUnhandledExceptionFilter(catch_unhandled_seh_exception);
#endif

  puts("==== main thread ====");
  ret |= test();

  /* FIXME: Fix mingw-w64-crt testcases build system to properly link winpthreads */
#ifndef _WIN32
  puts("");

  puts("==== second thread via pthread_create ====");
  if (pthread_create(&pthread, NULL, test_from_pthread_create, NULL) != 0)
  {
    puts("\nfailed to spawn second thread via pthread_create()");
    ret |= 1;
  }
  else
  {
    void *tret;
    if (pthread_join(pthread, &tret) != 0)
      tret = (void *)(intptr_t)1;
    ret |= (int)(intptr_t)tret;
  }
#else
  (void)pthread;
#endif

#ifdef _WIN32
  puts("");

  puts("==== third thread via _beginthreadex ====");
  wthread = (HANDLE)_beginthreadex(NULL, 0, test_from_beginthreadex, NULL, 0, &(unsigned){0} /*out: ThreadId*/);
  if (wthread == NULL)
  {
    puts("\nfailed to spawn third thread via _beginthreadex()");
    ret |= 1;
  }
  else
  {
    DWORD tret;
    WaitForSingleObject(wthread, INFINITE);
    GetExitCodeThread(wthread, &tret);
    CloseHandle(wthread);
    ret |= tret;
  }

  puts("");

  puts("==== fourth thread via _beginthread ====");
  wthread = (HANDLE)_beginthread(test_from_beginthread, 0, NULL);
  if (wthread == INVALID_HANDLE_VALUE)
  {
    puts("\nfailed to spawn fourth thread via _beginthread()");
    ret |= 1;
  }
  else
  {
    DWORD tret;
    WaitForSingleObject(wthread, INFINITE);
    GetExitCodeThread(wthread, &tret);
    CloseHandle(wthread);
    ret |= tret;
  }
#endif

  if (ret)
    puts("\nsome subtests failed");
  else
    puts("\nall subtests passed");
  return ret;
}
