/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

/* Define __mingw_<printf> macros.  */
#if defined(__USE_MINGW_ANSI_STDIO) && defined (_INC_STDIO)
#define fprintf		__mingw_fprintf
#define printf		__mingw_printf
#define sprintf		__mingw_sprintf
#define snprintf	__mingw_snprintf
#define vfprintf	__mingw_vfprintf
#define vprintf		__mingw_vprintf
#define vsprintf	__mingw_vsprintf
#define vsnprintf	__mingw_vsnprintf
#endif

