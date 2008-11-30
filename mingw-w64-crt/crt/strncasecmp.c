#include <string.h>

int
strncasecmp (const char *sz1,const char *sz2,size_t sizeMaxCompare)
{
  return _strnicmp (sz1,sz2,sizeMaxCompare);
}
