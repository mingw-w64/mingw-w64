#include "test.h"

enum {
  NUMTHREADS = 10000
};


static long done = 0;

void * func(void * arg)
{
  sched_yield();

  InterlockedIncrement(&done);

  return (void *) 0; 
}
 
int
main()
{
  pthread_t t[NUMTHREADS];
  pthread_attr_t attr;
  int i;
  unsigned int notUnique = 0,
	       totalHandles = 0,
	       reuseMax = 0,
	       reuseMin = NUMTHREADS;

  assert(pthread_attr_init(&attr) == 0);
  assert(pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) == 0);

  for (i = 0; i < NUMTHREADS; i++)
    {
      assert(pthread_create(&t[i], &attr, func, NULL) == 0);
    }

  while (NUMTHREADS > InterlockedExchangeAdd((LPLONG)&done, 0L))
    Sleep(100);

  Sleep(100);

  /*
   * Analyse reuse by computing min and max number of times pthread_create()
   * returned the same pthread_t value.
   */
  for (i = 0; i < NUMTHREADS; i++)
    {
      if (t[i])
        {
          unsigned int j, thisMax;

          thisMax = t[i];

          for (j = i+1; j < NUMTHREADS; j++)
            if (__pth_gpointer_locked (t[i]) == __pth_gpointer_locked (t[j]))
              {
		if (t[i] == t[j])
		  notUnique++;
                if (thisMax < t[j])
                  thisMax = t[j];
                t[j] = 0;
              }

          if (reuseMin > thisMax)
            reuseMin = thisMax;

          if (reuseMax < thisMax)
            reuseMax = thisMax;
        }
    }

  for (i = 0; i < NUMTHREADS; i++)
    if (t[i] != 0)
      totalHandles++;

  /*
   * pthread_t reuse counts start at 0, so we need to add 1
   * to the max and min values derived above.
   */
  printf("For %d total threads:\n", NUMTHREADS);
  printf("Non-unique IDs = %d\n", notUnique);
  printf("Reuse maximum  = %d\n", reuseMax + 1);
  printf("Reuse minimum  = %d\n", reuseMin + 1);
  printf("Total handles  = %d\n", totalHandles);

  return 0;
}
