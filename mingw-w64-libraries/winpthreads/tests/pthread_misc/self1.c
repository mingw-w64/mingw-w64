#include "test.h"
#include <setjmp.h>


int
main(int argc, char * argv[])
{
  assert(pthread_gethandle (pthread_self()) != NULL);

  return 0;
}
