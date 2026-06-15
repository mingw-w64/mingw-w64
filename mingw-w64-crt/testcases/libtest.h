/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_LIBTEST_H
#define __MINGW_LIBTEST_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This function should be called at the beginning of every test program.
 *
 * Currently, this function:
 *
 * 1. Calls `SetErrorMode`
 * 2. Sets `errno` to zero, so that tests can assume it to be zero upon entry
 *   to main()
 * 3. Sets invalid parameter handler which terminates the process by calling
 *   `abort` (instead of default behavior to invoke Dr. Watson)
 * 4. Disables buffering on `stdout` and `stderr` to ensure that all output
 *   is written to log files
 * 5. Calls `_set_abort_behavior` so that `abort` does not pop up a message box
 *   and does not invoke Dr. Watson
 * 6. Calls `_set_error_mode` so that `abort` and failed `assert` does not
 *   pop up a message box
 */
void mingw_test_init (void);

#ifdef __cplusplus
}
#endif

#endif /* __MINGW_LIBTEST_H */
