/* Test corner case for IEEE expm1
 *
 * http://pubs.opengroup.org/onlinepubs/9699919799/functions/expm1.html
 *
 */
#ifndef __USE_MINGW_ANSI_STDIO
#define __USE_MINGW_ANSI_STDIO 1
#endif
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define STR_VALUE(arg) #arg
#define MINUS_ZERO -0.
#define N_TESTS 5

int
main ()
{
  int res = 0;

#define TEST(func, dtype, fmt) do { \
    int i; \
    char fmt_str[20]; \
    dtype input, output, exp; \
    dtype inp_out[N_TESTS][2] = { \
        {0, 0}, \
        {NAN, NAN}, \
        {MINUS_ZERO, MINUS_ZERO}, \
        {-INFINITY, -1}, \
        {INFINITY, INFINITY}, \
    }; \
    sprintf(fmt_str, "%s(%s) = %s\n", STR_VALUE(func), fmt, fmt); \
    for (i=0; i<N_TESTS; i++) { \
        input = inp_out[i][0]; \
        exp = inp_out[i][1]; \
        output = func(input); \
        printf(fmt_str, input, output); \
        if ((output != exp && !isnan(exp)) \
                || (isnan(output) ^ isnan(exp))) \
        { \
            res |= 1; \
            printf("which is bogus!\n"); \
        } \
    } \
} while (0)

  TEST (expm1, double, "%f");
  TEST (expm1f, float, "%f");
  TEST (expm1l, long double, "%lf");
  return res;
}
