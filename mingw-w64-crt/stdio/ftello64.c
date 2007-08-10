#include <stdio.h>

_off64_t
ftello64 (FILE * stream)
{
  return (_off64_t) _ftelli64(stream);
}
