#include <direct.h>
#include <dirent.h>
#include <errno.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  struct dirent *di;
  DIR *h = opendir (".");

  if (!h)
    return 1;

  while ((di = readdir (h)) != NULL)
    printf ("%s\n", di->d_name);

  closedir (h);

  return 0;
}
