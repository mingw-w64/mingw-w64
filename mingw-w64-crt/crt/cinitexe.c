#include <stdio.h>
#include <sect_attribs.h>
#include <corecrt_startup.h>

#ifdef _MSC_VER
#pragma comment(linker, "/merge:.CRT=.rdata")
#endif

_CRTALLOC(".CRT$XIA") const _PIFV __xi_a[] = { NULL };
_CRTALLOC(".CRT$XIZ") const _PIFV __xi_z[] = { NULL };
_CRTALLOC(".CRT$XCA") const _PVFV __xc_a[] = { NULL };
_CRTALLOC(".CRT$XCZ") const _PVFV __xc_z[] = { NULL };
