#include <process.h>

intptr_t __cdecl execvp(const char *_Filename,char *const _ArgList[])
{
  return _execvp (_Filename, (const char *const *)_ArgList);
}
