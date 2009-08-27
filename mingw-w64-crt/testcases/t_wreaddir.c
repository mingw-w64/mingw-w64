#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <io.h>
#include <direct.h>
#include <dirent.h>

int main(int argc, char **argv)
{
  struct _wdirent *di;
  _WDIR *h = _wopendir (L".");
  if (!h)
    return 1;
  while ((di = _wreaddir (h)) != NULL)
    printf ("%ws\n", di->d_name);
  _wclosedir (h);
  return 0;
}

