/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

/* Undefine __mingw_<printf> macros.  */
#ifdef __USE_MINGW_ANSI_STDIO
#undef fprintf
#undef printf
#undef sprintf
#undef snprintf
#undef vfprintf
#undef vprintf
#undef vsprintf
#undef vsnprintf
#endif

