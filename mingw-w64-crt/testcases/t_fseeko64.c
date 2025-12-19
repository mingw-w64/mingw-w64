#define _FILE_OFFSET_BITS 64
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <windows.h>

static const char *writebuf = "TESTVECTORSTRING";
#define TMPTMPL "mingw-w64-fseeko64-XXXXXX"
static char szPath[MAX_PATH + sizeof(TMPTMPL)];

static int writefile(const char *path){
  LARGE_INTEGER li = { .QuadPart = 0x100000000ull };
  DWORD dwResult;
  HANDLE fd = CreateFileA(path,GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  if (fd == INVALID_HANDLE_VALUE) return 1;
  if (SetFilePointer(fd, li.LowPart, &li.HighPart, FILE_BEGIN) == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR) {
    printf("writefile: seek failed: winerror=%lu\n", GetLastError());
    CloseHandle(fd);
    return 1;
  }
  if (!WriteFile(fd, writebuf, strlen(writebuf), &dwResult, NULL)) {
    if (GetLastError() == ERROR_DISK_FULL) {
        /* skip the test for DISK FULL error */
        printf("DISK FULL\n");
        CloseHandle(fd);
        return 77;
    }
    printf("writefile: write failed: winerror=%lu\n", GetLastError());
    CloseHandle(fd);
    return 1;
  }
  dwResult = WaitForSingleObject(fd, INFINITE);
  while(dwResult==WAIT_IO_COMPLETION)
  {
    dwResult = WaitForSingleObject(fd, INFINITE);
  }
  CloseHandle(fd);
  return 0;
}

static int testread(const char *path){
  FILE *fd;
  char *readbuff;
  int ret;

  readbuff = calloc(strlen(writebuf) + 1, sizeof(char));
  if (!readbuff) return 1;

  fd = fopen(path, "r+bc");
  if (!fd) {
    printf("fopen failed\n");
    free(readbuff);
    return 1;
  }
  ret = fseeko(fd,0x100000000LL,SEEK_SET);
  if (ret != 0) {
    printf("fseeko failed\n");
    free(readbuff);
    fclose(fd);
    return ret;
  }
  if (fread(readbuff,sizeof(char),strlen(writebuf),fd) != strlen(writebuf)) {
    printf("fread failed\n");
    free(readbuff);
    fclose(fd);
    return 1;
  }
  ret = strncmp(readbuff,writebuf,strlen(writebuf));
  if (ret != 0) {
    printf("strcmp failed\n");
  }
  free(readbuff);
  fclose(fd);
  return ret;
}

int main(){
  int check;
  char *path;
  int fd;
  if (GetTempPathA(MAX_PATH, szPath) == 0) return 1;
#ifdef debugtest
  printf("tmp: %s\n", szPath);
#endif
  path = strcat(szPath, TMPTMPL);
  fd = mkstemp(path);
  if (fd < 0) { printf("mkstemp failed\n"); return 1; }
  close(fd);
#ifdef debugtest
  printf("Path: %s\n", path);
#endif

  check = writefile(path);
  if (check) goto err; /* error creating large file */
  check = testread(path);

  err:
#ifndef debugtest
  DeleteFileA(path); /* Delete anyway */
#endif
  printf ("check: %d\n", check);
  return check;
}
