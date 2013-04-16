#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <io.h>

int main(int argc, char **argv)
{
  struct _finddata_t d;
  intptr_t handle = _findfirst ("*", &d);
  if (handle == -1)
    return 1;

  while (_findnext(handle, &d) == 0)
    printf ("%s\n", d.name);

  _findclose (handle);
  return 0;
}

