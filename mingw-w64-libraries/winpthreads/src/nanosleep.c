/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <assert.h>
#include <errno.h>
#include <time.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define WINPTHREAD_NANOSLEEP_DECL WINPTHREAD_API

/* public header files */
#include "pthread.h"
#include "pthread_time.h"
/* internal header files */
#include "misc.h"
#include "thread.h"
#include "winpthreads-time.h"

#define POW10_3         1000
#define POW10_4         10000
#define POW10_6         1000000
#define POW10_9         1000000000
#define MAX_SLEEP_IN_MS 4294967294UL

/**
 * Sleep for the specified time.
 * @param  request The desired amount of time to sleep.
 * @param  remain The remain amount of time to sleep.
 * @return If the function succeeds, the return value is 0.
 *         If the function fails, the return value is -1,
 *         with errno set to indicate the error.
 */
int nanosleep64(const struct _timespec64 *request, struct _timespec64 *remain)
{
    /**
     * The nanosleep() function shall fail if:
     *
     * [EINVAL]
     *   The request argument specified a nanosecond value less than zero or
     *   greater than or equal to 1000 million.
     */
    if (request->tv_sec < 0 || request->tv_nsec < 0 || request->tv_nsec >= POW10_9) {
        _set_errno(EINVAL);
        return -1;
    }

    /**
     * Total sleep time in milliseconds.
     */
    unsigned __int64 totalSleepTime = winpthreads_timespec_ms(request);

    if (totalSleepTime == 0) {
        return 0;
    }

    FILETIME startTime;
    FILETIME endTime;

    if (remain != NULL) {
        _pthread_get_system_time_best_as_file_time(&startTime);
    }

    unsigned __int64 remainingSleepTime = totalSleepTime;
    int error_code;

    do {
        /**
         * We can sleep for at most `INFINITE - 1` milliseconds at a time.
         */
        unsigned sleepTime;

        if (remainingSleepTime >= MAX_SLEEP_IN_MS) {
            sleepTime = MAX_SLEEP_IN_MS;
        } else {
            sleepTime = (unsigned) remainingSleepTime;
        }

        remainingSleepTime -= sleepTime;
        error_code          = _pthread_delay_np_ms(sleepTime);
    } while (remainingSleepTime > 0 && likely(error_code == 0));

    /**
     * Currently, function `_pthread_delay_np_ms` always returns zero.
     */
    if (unlikely(error_code != 0)) {
        if (remain != NULL) {
            _pthread_get_system_time_best_as_file_time(&endTime);

            ULARGE_INTEGER start = {
                .HighPart = startTime.dwHighDateTime,
                .LowPart  = startTime.dwLowDateTime
            };
            ULARGE_INTEGER end = {
                .HighPart = endTime.dwHighDateTime,
                .LowPart  = endTime.dwLowDateTime
            };

            remainingSleepTime = 0;

            /**
             * It is possible that system time has been changed while we were
             * sleeping, so we have to check for possible underflow.
             */
            if (likely (start.QuadPart <= end.QuadPart)) {
                unsigned __int64 elapsedSleepTime = (end.QuadPart - start.QuadPart) / POW10_4;

                if (likely (elapsedSleepTime < totalSleepTime)) {
                    remainingSleepTime = totalSleepTime - elapsedSleepTime;
                }
            }

            remain->tv_sec  = (__time64_t) (remainingSleepTime / POW10_3);
            remain->tv_nsec = (long) ((remainingSleepTime % POW10_3) * POW10_6);
        }

        _set_errno(EINTR);
        return -1;
    }

    return error_code;
}

int nanosleep32(const struct _timespec32 *request, struct _timespec32 *remain)
{
    struct _timespec64 request64 = {
        .tv_sec = request->tv_sec,
        .tv_nsec = request->tv_nsec
    };
    struct _timespec64 remain64 = {0};

    int error_code = nanosleep64 (&request64, &remain64);

    if (error_code == -1) {
        if (unlikely (errno == EINTR) && remain != NULL) {
            assert (remain64.tv_sec >= 0 && remain64.tv_sec <= INT_MAX);
            remain->tv_sec = (__time32_t) remain64.tv_sec;
            assert (remain64.tv_nsec >= 0 && remain64.tv_nsec < POW10_9);
            remain->tv_nsec = remain64.tv_nsec;
        }
    }

    return error_code;
}
