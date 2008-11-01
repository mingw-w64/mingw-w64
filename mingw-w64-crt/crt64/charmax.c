#include <sect_attribs.h>
#include <internal.h>

__declspec(dllimport) int __lconv_init (void);

int mingw_initcharmax = 0;

int _charmax = 255;

static int my_lconv_init(void)
{
  return __lconv_init();
}

_CRTALLOC(".CRT$XIC") _PIFV __mingw_pinit = my_lconv_init;
