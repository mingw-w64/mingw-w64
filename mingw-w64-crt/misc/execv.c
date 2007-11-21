#include <process.h>

intptr_t __cdecl execv(const char *_Filename,char *const _ArgList[])
{
  return _execv (_Filename, (const char *const *)_ArgList);
}
