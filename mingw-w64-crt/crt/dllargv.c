#ifdef CRTDLL
#undef CRTDLL
#endif

#include <internal.h>

#ifdef WPRFLAG
int __CRTDECL
_wsetargv (void)
#else
int __CRTDECL
_setargv (void)
#endif
{
  return 0;
}
