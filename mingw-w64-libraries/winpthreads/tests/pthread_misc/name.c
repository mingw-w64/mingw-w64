#include "test.h"

int
main(int argc, char * argv[])
{
  char buffer[100];

  memset(buffer, 'X', sizeof(buffer));
  assert(pthread_getname_np(pthread_self(), buffer, sizeof(buffer)) == 0);
  printf("pthread_getname_np: %s\n", buffer);
  assert(strcmp(buffer, "") == 0);

  assert(pthread_setname_np(pthread_self(), "my_name") == 0);

  memset(buffer, 'X', sizeof(buffer));
  assert(pthread_getname_np(pthread_self(), buffer, sizeof(buffer)) == 0);
  printf("pthread_getname_np: %s\n", buffer);
  assert(strcmp(buffer, "my_name") == 0);

  assert(pthread_setname_np(pthread_self(), "my_new_name") == 0);

  memset(buffer, 'X', sizeof(buffer));
  assert(pthread_getname_np(pthread_self(), buffer, sizeof(buffer)) == 0);
  printf("pthread_getname_np: %s\n", buffer);
  assert(strcmp(buffer, "my_new_name") == 0);

  return 0;
}
