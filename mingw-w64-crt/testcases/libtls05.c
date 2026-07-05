/* This is simple DLL library which uses CRT atexit callback */

#include <stdio.h>
#include <stdlib.h>

static int *process_detach_var = NULL;

__attribute__((dllexport))
void set_process_detach_var(int *var)
{
  process_detach_var = var;
}

static void __cdecl atexit_callback(void)
{
  if (process_detach_var)
    (*process_detach_var)++;
}

/* Register atexit_callback as CRT atexit callback */
__attribute__((constructor))
static void register_atexit_callback(void)
{
  if (atexit(&atexit_callback) != 0)
    printf("atexit() failed\n");
}
