/**
 * Testcase for https://github.com/mingw-w64/mingw-w64/issues/181:
 * "Global constructors run twice when linking against -lgcc (since c3da0827)".
 *
 * This file is self-contained and can be built standalone:
 *
 *   gcc -o t_global_ctors.exe t_global_ctors.c
 *     -> PASSED (global constructors run exactly once)
 *
 *   gcc -o t_global_ctors.exe t_global_ctors.c -lgcc -static
 *     -> FAILED (global constructors run twice) -- reproduces the issue
 *
 * The trigger is the LINK ORDER: an explicit -lgcc placed AFTER this object
 * file (but before the implicit -lmingw32) pulls in libgcc's __main.o, which
 * provides its own __do_global_ctors / __do_global_dtors runners alongside the
 * mingw-w64 runtime's __mingw_do_global_ctors / __mingw_do_global_dtors.  Both
 * walk __CTOR_LIST__ (and __DTOR_LIST__) with their own static cursors, so
 * every global constructor (and destructor) is executed twice.  Putting -lgcc
 * BEFORE the object file does not reproduce the issue.
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

/* Counts how many times global constructors have been invoked. */
static int ctor_count = 0;

/* Counts how many times global destructors have been invoked. */
static int dtor_count = 0;

__attribute__((constructor))
static void
ctor (void)
{
  ctor_count++;
}

__attribute__((destructor))
static void
dtor (void)
{
  dtor_count++;
  if (dtor_count > 1) {
    /* Global destructors were invoked more than once; abort() so that this is
     * reported as a test failure (the exit code of main() has already been
     * determined by the time global destructors run). */
    fprintf (stderr, "FAILED: global destructors were invoked %d times, expected 1\n",
             dtor_count);
    abort ();
  }
}

int
main (void)
{
  mingw_test_init ();

  if (ctor_count != 1) {
    printf ("FAILED: global constructors were invoked %d times, expected 1\n",
            ctor_count);
    return 1;
  }

  printf ("PASSED: global constructors were invoked exactly once\n");
  return 0;
}
