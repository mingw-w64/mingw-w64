#include "test.h"

void *
func(void * arg)
{
	pthread_exit(arg);

	/* Never reached. */
	assert(0);

	return NULL;
}

int
main(int argc, char * argv[])
{
	pthread_t id[4];
	int i;

	/* Create a few threads and then exit. */
	for (i = 0; i < 4; i++)
	  {
	    assert(pthread_create(&id[i], NULL, func, ((void *) (size_t) i)) == 0);
	  }

	Sleep(1000);

	/* Success. */
	return 0;
}
