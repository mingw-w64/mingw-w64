/*
 * mthr_stub.c
 *
 * Implement Mingw-w64 thread-support.
 *
 * This file is used by if gcc is built with --enable-threads=win32. 
 *
 * Based on version created by Mumit Khan  <khan@nanotech.wisc.edu>
 *
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN
#include <stdlib.h>

BOOL __mingw_TLScallback (HANDLE hDllHandle, DWORD reason, LPVOID reserved);
int ___w64_mingwthr_remove_key_dtor (DWORD key);
int ___w64_mingwthr_add_key_dtor (DWORD key, void (*dtor)(void *));

/* To protect the thread/key association data structure modifications. */
static CRITICAL_SECTION __mingwthr_cs;

typedef struct __mingwthr_key __mingwthr_key_t;

/* The list of threads active with key/dtor pairs. */
struct __mingwthr_key {
  DWORD key;
  void (*dtor)(void *);
  __mingwthr_key_t volatile *next;
};


static __mingwthr_key_t volatile *key_dtor_list;

int
___w64_mingwthr_add_key_dtor (DWORD key, void (*dtor)(void *))
{
  __mingwthr_key_t *new_key;

  new_key = (__mingwthr_key_t *) calloc (1, sizeof (__mingwthr_key_t));
  if (new_key == NULL)
    return -1;
  
  new_key->key = key;
  new_key->dtor = dtor;

  EnterCriticalSection (&__mingwthr_cs);

  new_key->next = key_dtor_list;
  key_dtor_list = new_key;

  LeaveCriticalSection (&__mingwthr_cs);
  return 0;
}

int
___w64_mingwthr_remove_key_dtor (DWORD key)
{
  __mingwthr_key_t volatile *prev_key;
  __mingwthr_key_t volatile *cur_key;

  EnterCriticalSection (&__mingwthr_cs);

  prev_key = NULL;
  cur_key = key_dtor_list;

  while (cur_key != NULL)
    {
      if ( cur_key->key == key)
        {
          if (prev_key == NULL)
            key_dtor_list = cur_key->next;
          else
            prev_key->next = cur_key->next;

          free ((void*)cur_key);
          break;
        }
      prev_key = cur_key;
      cur_key = cur_key->next;
    }

  LeaveCriticalSection (&__mingwthr_cs);
  return 0;
}

static void
__mingwthr_run_key_dtors (void)
{
  __mingwthr_key_t volatile *keyp;

  EnterCriticalSection (&__mingwthr_cs);

  for (keyp = key_dtor_list; keyp; )
    {
      LPVOID value = TlsGetValue (keyp->key);
      if (GetLastError () == ERROR_SUCCESS)
        {
          if (value)
            (*keyp->dtor) (value);
        }
      keyp = keyp->next;
    }

  LeaveCriticalSection (&__mingwthr_cs);
}
  
BOOL
__mingw_TLScallback (HANDLE hDllHandle, DWORD reason, LPVOID reserved)
{
  static int is_init = 0;
 
  switch (reason)
    {
    case DLL_PROCESS_ATTACH:
       if (is_init == 0)
         InitializeCriticalSection (&__mingwthr_cs);
       is_init = 1;
       break;
    case DLL_PROCESS_DETACH:
      if (is_init)
	{
          __mingwthr_run_key_dtors();
          DeleteCriticalSection (&__mingwthr_cs);
          is_init = 0;
	}
      break;
    case DLL_THREAD_ATTACH:
      break;
    case DLL_THREAD_DETACH:
      if (is_init)
        __mingwthr_run_key_dtors();
      break;
    }
  return TRUE;
}
