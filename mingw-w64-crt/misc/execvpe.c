#include <process.h>

intptr_t __cdecl execvpe(const char *_Filename,char *const _ArgList[],char *const _Env[])
{
  return _execvpe (_Filename, (const char *const *)_ArgList, (const char *const *)_Env);
}
