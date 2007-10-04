#include <process.h>

intptr_t __cdecl spawnvpe(int,const char *_Filename,char *const _ArgList[],char *const _Env[])
{
  return _spawnvpe(_Filename,(const char *const *)_ArgList,(const char *const *)_Env);
}
