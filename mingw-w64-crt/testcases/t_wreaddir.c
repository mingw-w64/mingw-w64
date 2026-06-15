#include <direct.h>
#include <dirent.h>
#include <errno.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  struct _wdirent *di;
  _WDIR *h = _wopendir (L".");

  if (!h)
    return 1;

  while ((di = _wreaddir (h)) != NULL)
    printf ("%ls\n", di->d_name);

  _wclosedir (h);

  return 0;
}
