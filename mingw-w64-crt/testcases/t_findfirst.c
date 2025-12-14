#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <io.h>

#define A(x) x
#define W(x) L##x

#define DEFINE_TEST(T, F, NAME, FINDDATA, FINDFIRST, FINDNEXT) \
static int NAME(void) \
{ \
  fflush (stdout); \
  fflush (stderr); \
  printf ("\nTest name: %s\n", #NAME); \
  struct FINDDATA d; \
  intptr_t handle = FINDFIRST (T("*"), &d); \
  if (handle == -1) { \
    fprintf (stderr, "Error: Function %s failed: errno=%d (%s)\n", #FINDFIRST, errno, strerror (errno)); \
    return 1; \
  } \
  printf (F "\n", d.name); \
  while (FINDNEXT (handle, &d) == 0) { \
    printf (F "\n", d.name); \
  } \
  if (errno != ENOENT) { \
    fprintf (stderr, "Error: Function %s failed: errno=%d (%s)\n", #FINDNEXT, errno, strerror (errno)); \
    return 1; \
  } \
  _findclose (handle); \
  fprintf (stderr, "Test %s passed\n", #NAME); \
  return 0; \
}

DEFINE_TEST(A, "%s",  test,       _finddata_t,       _findfirst,       _findnext)
DEFINE_TEST(A, "%s",  testi64,    _finddatai64_t,    _findfirsti64,    _findnexti64)
DEFINE_TEST(A, "%s",  test32,     _finddata32_t,     _findfirst32,     _findnext32)
DEFINE_TEST(A, "%s",  test32i64,  _finddata32i64_t,  _findfirst32i64,  _findnext32i64)
DEFINE_TEST(A, "%s",  test64i32,  _finddata64i32_t,  _findfirst64i32,  _findnext64i32)
DEFINE_TEST(A, "%s",  test64,     __finddata64_t,    _findfirst64,     _findnext64)

DEFINE_TEST(W, "%ls", wtest,      _wfinddata_t,      _wfindfirst,      _wfindnext)
DEFINE_TEST(W, "%ls", wtesti64,   _wfinddatai64_t,   _wfindfirsti64,   _wfindnexti64)
DEFINE_TEST(W, "%ls", wtest32,    _wfinddata32_t,    _wfindfirst32,    _wfindnext32)
DEFINE_TEST(W, "%ls", wtest32i64, _wfinddata32i64_t, _wfindfirst32i64, _wfindnext32i64)
DEFINE_TEST(W, "%ls", wtest64i32, _wfinddata64i32_t, _wfindfirst64i32, _wfindnext64i32)
DEFINE_TEST(W, "%ls", wtest64,    _wfinddata64_t,    _wfindfirst64,    _wfindnext64)

int main(int argc, char **argv)
{
  int ret = 0;
  ret |= test ();
  ret |= testi64 ();
  ret |= test32 ();
  ret |= test32i64 ();
  ret |= test64i32 ();
  ret |= test64 ();
  ret |= wtest ();
  ret |= wtesti64 ();
  ret |= wtest32 ();
  ret |= wtest32i64 ();
  ret |= wtest64i32 ();
  ret |= wtest64 ();
  return ret;
}
