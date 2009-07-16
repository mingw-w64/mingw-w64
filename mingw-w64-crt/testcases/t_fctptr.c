#include <stdlib.h>
#include <malloc.h>

void *(*my_malloc)(size_t) = malloc;
void (*my_free)(void *) = free;

int main()
{
  void *p = (*my_malloc) (1024);
  if (!p) abort();
  (*my_free)(p);
  return 0;
}

