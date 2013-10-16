#define __CRT__NO_INLINE

#include <string.h>

char * __cdecl __mingw_stpcpy (char * __restrict__ _Dest,const char * __restrict__ _Source)
{
  for (; *_Source; _Source++, _Dest++)
    *_Dest = *_Source;
  *_Dest = '\0';
  return _Dest;
}
