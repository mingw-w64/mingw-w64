#include <math.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

/* mingw-w64 headers */
#include "libtest.h"

static int has_matherr_except;
static struct _exception matherr_except;

int __cdecl _matherr(struct _exception *pexcept)
{
  matherr_except = *pexcept;
  has_matherr_except = 1;
  /* change return value to 42.0 and return 1 to report successful recovery */
  pexcept->retval = 42.0;
  return 1;
}

int main()
{
  mingw_test_init ();
  errno = 0;
  double retval = sqrt (-1.0);
  int matherr_errno = errno;
  printf ("sqrt(-1)=%g\n", retval);
  printf ("errno=%d\n", matherr_errno);
  if (has_matherr_except) {
    const char *type;
    static char type_buf[20];
    static const char *const types[] = {
      [_DOMAIN] = "Argument domain error (DOMAIN)",
      [_SING] = "Argument singularity (SIGN)",
      [_OVERFLOW] = "Overflow range error (OVERFLOW)",
      [_UNDERFLOW] = "The result is too small to be represented (UNDERFLOW)",
      [_TLOSS] = "Total loss of significance (TLOSS)",
      [_PLOSS] = "Partial loss of significance (PLOSS)",
    };
    if (matherr_except.type >= 0 && matherr_except.type < (int)(sizeof (types) / sizeof (types[0]))) {
      type = types[matherr_except.type];
    } else {
      sprintf (type_buf, "Unknown error (%d)", matherr_except.type);
      type = type_buf;
    }
    fprintf (stderr, "_matherr(): %s in %s(%g)  (retval: orig=%g, changed=%g)\n",
             type, matherr_except.name, matherr_except.arg1, matherr_except.retval, retval);
  }
  assert (matherr_errno == 0);
  assert (retval == 42.0);
  assert (has_matherr_except);
  assert (matherr_except.type == _DOMAIN);
  assert (strcmp(matherr_except.name, "sqrt") == 0);
  assert (matherr_except.arg1 == -1.0);
  assert (isnan(matherr_except.retval));
  return 0;
}
