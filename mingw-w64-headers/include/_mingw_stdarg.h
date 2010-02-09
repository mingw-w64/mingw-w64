/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_STDARG
#define _INC_STDARG

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#include <vadefs.h>

#ifndef va_start
#define va_start _crt_va_start
#endif
#ifndef va_arg
#define va_arg _crt_va_arg
#endif
#ifndef va_end
#define va_end _crt_va_end
#endif

#endif /* not _INC_STDARG */

