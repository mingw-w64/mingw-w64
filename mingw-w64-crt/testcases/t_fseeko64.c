#define _FILE_OFFSET_BITS 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <shlobj.h>

static const char *writebuf = "TESTVECTORSTRING";
static wchar_t szPath[MAX_PATH];

static int writefile(wchar_t *path){
  OVERLAPPED ov;
  DWORD dwResult;
  memset(&ov,0,sizeof(OVERLAPPED));
  ov.Offset = 0x0;
  ov.OffsetHigh = 0x1;
  HANDLE fd = CreateFileW(path,GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  if (fd == INVALID_HANDLE_VALUE) return 1;
  SetFilePointer (fd, ov.Offset, &ov.OffsetHigh, FILE_BEGIN);
  WriteFile(fd, writebuf, strlen(writebuf), &dwResult, NULL);
  dwResult = WaitForSingleObject(fd, INFINITE);
  while(dwResult==WAIT_IO_COMPLETION)
  {
    dwResult = WaitForSingleObject(fd, INFINITE);
  }
  CloseHandle(fd);
  return 0;
}

static int testread(wchar_t *path){
  FILE *fd;
  char *readbuff;
  int ret;

  readbuff = calloc(sizeof(char),strlen(writebuf) + 1);
  if (!readbuff) return 1;

  fd = _wfopen(path, L"r+bc");
  if (!fd) {
    free(readbuff);
    return 1;
  }
  fseeko(fd,0x100000000LL,SEEK_SET);
  fread(readbuff,sizeof(char),strlen(writebuf),fd);
  ret = strncmp(readbuff,writebuf,strlen(writebuf));
  free(readbuff);
  fclose(fd);
  return ret;
}

int main(int argc, char **argv){
  int check;
  wchar_t *path;
  SHGetFolderPathW(NULL,CSIDL_PERSONAL,NULL,0,szPath);
  path = _wtempnam(szPath, L"mingw-w64-lfs64-test-");
#ifdef debugtest
  wprintf(L"Path: %ws\n", path);
#endif
  if (!path) return 1;

  check = writefile(path);
  if (check) goto err; /* error creating large file */
  check = testread(path);

  err:
#ifndef debugtest
  DeleteFileW(path); /* Delete anyway */
#endif
  free(path);
  printf ("check: %d\n", check);
  return check;
}
