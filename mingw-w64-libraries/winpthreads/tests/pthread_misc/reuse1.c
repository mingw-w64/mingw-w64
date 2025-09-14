#include "test.h"

enum {
	NUMTHREADS = 100
};

static int washere = 0;

void * func(void * arg)
{
  washere = 1;
  return arg; 
}
 
int
main()
{
  pthread_t t, last_t;
  void *tp, *last_tp;
  pthread_attr_t attr;
  void * result = NULL;
  int i;

  assert(pthread_attr_init(&attr) == 0);;
  assert(pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE) == 0);

  washere = 0;
  assert(pthread_create(&t, &attr, func, NULL) == 0);
  assert(pthread_join(t, &result) == 0);;
  assert(result == NULL);
  assert(washere == 1);
  last_t = t;
  last_tp = __pth_gpointer_locked (t);

  for (i = 1; i < NUMTHREADS; i++)
    {
      washere = 0;
      assert(pthread_create(&t, &attr, func, (void *) (intptr_t) i) == 0);
      pthread_join(t, &result);
      assert((intptr_t) result == (intptr_t) i);
      assert(washere == 1);
      /* thread IDs should be unique */
      assert(!pthread_equal(t, last_t));
      /* thread struct pointers should be the same */
      tp = __pth_gpointer_locked(t);
      assert(tp == last_tp);
      last_t = t;
      last_tp = tp;
    }

  return 0;
}
