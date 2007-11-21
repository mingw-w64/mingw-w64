#include <sect_attribs.h>
#include <internal.h>

int __lconv_init (void);

int mingw_initcharmax = 0;

int _charmax = 255;

_CRTALLOC(".CRT$XIC") static _PIFV pinit = __lconv_init;
