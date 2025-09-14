#include "test.h"
#include <sys/timeb.h>

static pthread_cond_t cv;
static pthread_mutex_t mutex;
static int shared = 0;

enum {
  NUMTHREADS = 2         /* Including the primary thread. */
};

void *
mythread(void * arg)
{
  int result = 0;

  assert(pthread_mutex_lock(&mutex) == 0);
  shared++;
  assert(pthread_mutex_unlock(&mutex) == 0);

  if ((result = pthread_cond_signal(&cv)) != 0)
    {
      printf("Error = %s\n", error_string[result]);
    }
  assert(result == 0);


  return (void *) 0;
}

int
main()
{
  pthread_t t[NUMTHREADS];
  struct timespec abstime = { 0, 0 };
  struct _timeb currSysTime;
  const DWORD NANOSEC_PER_MILLISEC = 1000000;

  assert((t[0] = pthread_self()) != 0);
  assert(pthread_gethandle (t[0]) != NULL);

  assert(pthread_cond_init(&cv, NULL) == 0);

  assert(pthread_mutex_init(&mutex, NULL) == 0);

  assert(pthread_mutex_lock(&mutex) == 0);

  /* get current system time */
  _ftime(&currSysTime);

  abstime.tv_sec = currSysTime.time;
  abstime.tv_nsec = NANOSEC_PER_MILLISEC * currSysTime.millitm;

  assert(pthread_create(&t[1], NULL, mythread, (void *) 1) == 0);

  abstime.tv_sec += 5;

  while (! (shared > 0))
    assert(pthread_cond_timedwait(&cv, &mutex, &abstime) == 0);

  assert(shared > 0);

  assert(pthread_mutex_unlock(&mutex) == 0);

  assert(pthread_join(t[1], NULL) == 0);

  assert(pthread_cond_destroy(&cv) == 0);

  return 0;
}
