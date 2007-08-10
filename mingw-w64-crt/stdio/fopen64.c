#include <stdio.h>

FILE* fopen64 (const char* filename, const char* mode)
{
  return fopen (filename, mode);
}
