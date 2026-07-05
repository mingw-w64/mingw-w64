/* This is simple DLL library which uses CRT onexit callback */

#include <stdio.h>
#include <stdlib.h>

static int *process_detach_var = NULL;

__attribute__((dllexport))
void set_process_detach_var(int *var)
{
  process_detach_var = var;
}

static int __cdecl onexit_callback(void)
{
  if (process_detach_var)
    (*process_detach_var)++;
  return 0;
}

/* Register onexit_callback as CRT onexit callback */
__attribute__((constructor))
static void register_onexit_callback(void)
{
  if (!_onexit(&onexit_callback))
    printf("_onexit() failed\n");
}
