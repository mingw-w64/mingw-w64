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
#include <stdint.h>
#include <time.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define WINPTHREAD_CLOCK_DECL WINPTHREAD_API

/* public header files */
#include "pthread_time.h"
/* internal header files */
#include "misc.h"

#define POW10_7 10000000
#define POW10_9 1000000000

/**
 * Number of 100ns intervals between the beginning of the Windows epoch
 * (Jan. 1, 1601) and the Unix epoch (Jan. 1, 1970)
 */
#define DELTA_EPOCH_IN_100NS INT64_C(116444736000000000)

/**
 * Get the resolution of the specified clock clock_id and
 * stores it in the struct timespec pointed to by res.
 * @param  clock_id The clock_id argument is the identifier of the particular
 *         clock on which to act. The following clocks are supported:
 * <pre>
 *     CLOCK_REALTIME  System-wide real-time clock. Setting this clock
 *                 requires appropriate privileges.
 *     CLOCK_MONOTONIC Clock that cannot be set and represents monotonic
 *                 time since some unspecified starting point.
 *     CLOCK_PROCESS_CPUTIME_ID High-resolution per-process timer from the CPU.
 *     CLOCK_THREAD_CPUTIME_ID  Thread-specific CPU-time clock.
 * </pre>
 * @param  res The pointer to a timespec structure to receive the time
 *         resolution.
 * @return If the function succeeds, the return value is 0.
 *         If the function fails, the return value is -1,
 *         with errno set to indicate the error.
 */
int clock_getres64 (clockid_t clock_id, struct _timespec64 *res)
{
    /**
     * If `GetSystemTimePreciseAsFileTime` is not available,
     * use `GetSystemTimeAdjustment` to obtain system clock resolution.
     */
    if (clock_id == CLOCK_REALTIME && _pthread_get_system_time_best_as_file_time == GetSystemTimeAsFileTime) {
        clock_id = CLOCK_REALTIME_COARSE;
    }

    switch (clock_id) {
    case CLOCK_REALTIME:
    case CLOCK_MONOTONIC:
        {
            LARGE_INTEGER pf;

            if (!QueryPerformanceFrequency(&pf)) {
                _set_errno(EINVAL);
                return -1;
            }

            res->tv_sec = 0;
            res->tv_nsec = (long) ((POW10_9 + (pf.QuadPart >> 1)) / pf.QuadPart);

            if (res->tv_nsec < 1) {
                res->tv_nsec = 1;
            }

            return 0;
        }

    case CLOCK_REALTIME_COARSE:
    case CLOCK_PROCESS_CPUTIME_ID:
    case CLOCK_THREAD_CPUTIME_ID:
        {
            DWORD timeAdjustment;
            DWORD timeIncrement;
            BOOL  isTimeAdjustmentDisabled;

            /**
             * If call to `GetSystemTimeAdjustment` fails, use 16ms as
             * the default fallback value.
             */
            if (!GetSystemTimeAdjustment(&timeAdjustment, &timeIncrement, &isTimeAdjustmentDisabled)) {
                timeIncrement = 160000;
            }

            res->tv_sec = 0;
            res->tv_nsec = (long) (timeIncrement * 100);

            return 0;
        }
    default:
        break;
    }

    _set_errno(EINVAL);
    return -1;
}

/**
 * Get the time of the specified clock clock_id and stores it in the struct
 * timespec pointed to by tp.
 * @param  clock_id The clock_id argument is the identifier of the particular
 *         clock on which to act. The following clocks are supported:
 * <pre>
 *     CLOCK_REALTIME  System-wide real-time clock. Setting this clock
 *                 requires appropriate privileges.
 *     CLOCK_MONOTONIC Clock that cannot be set and represents monotonic
 *                 time since some unspecified starting point.
 *     CLOCK_PROCESS_CPUTIME_ID High-resolution per-process timer from the CPU.
 *     CLOCK_THREAD_CPUTIME_ID  Thread-specific CPU-time clock.
 * </pre>
 * @param  tp The pointer to a timespec structure to receive the time.
 * @return If the function succeeds, the return value is 0.
 *         If the function fails, the return value is -1,
 *         with errno set to indicate the error.
 */
int clock_gettime64 (clockid_t clock_id, struct _timespec64 *tp)
{
    switch (clock_id) {
    case CLOCK_REALTIME:
        {
            FILETIME fileTime;

            _pthread_get_system_time_best_as_file_time(&fileTime);

            ULARGE_INTEGER value = {
                .HighPart = fileTime.dwHighDateTime,
                .LowPart  = fileTime.dwLowDateTime
            };

            tp->tv_sec = (__time64_t) ((value.QuadPart - DELTA_EPOCH_IN_100NS) / POW10_7);
            tp->tv_nsec = (long) ((value.QuadPart % POW10_7) * 100);

            return 0;
        }

    case CLOCK_REALTIME_COARSE:
        {
            FILETIME fileTime;

            GetSystemTimeAsFileTime(&fileTime);

            ULARGE_INTEGER value = {
                .HighPart = fileTime.dwHighDateTime,
                .LowPart  = fileTime.dwLowDateTime
            };

            tp->tv_sec = (__time64_t) ((value.QuadPart - DELTA_EPOCH_IN_100NS) / POW10_7);
            tp->tv_nsec = (long) ((value.QuadPart % POW10_7) * 100);

            return 0;
        }

    case CLOCK_MONOTONIC:
        {
            LARGE_INTEGER pf;
            LARGE_INTEGER pc;

            if (!QueryPerformanceFrequency(&pf)) {
                _set_errno(EINVAL);
                return -1;
            }

            if (!QueryPerformanceCounter(&pc)) {
                _set_errno(EINVAL);
                return -1;
            }

            tp->tv_sec = (__time64_t) (pc.QuadPart / pf.QuadPart);
            tp->tv_nsec = (long) (((pc.QuadPart % pf.QuadPart) * POW10_9 + (pf.QuadPart >> 1)) / pf.QuadPart);

            if (tp->tv_nsec >= POW10_9) {
                tp->tv_sec++;
                tp->tv_nsec -= POW10_9;
            }

            return 0;
        }

    case CLOCK_PROCESS_CPUTIME_ID:
        {
            FILETIME creationTime;
            FILETIME exitTime;
            FILETIME kernelTime;
            FILETIME userTime;

            /**
             * Function `GetProcessTimes` is available on Win9x systems,
             * but it always fails.
             *
             * `ENOTSUP` is the most fitting error code, although this error
             * condition is not specified by POSIX.
             */
            if (!GetProcessTimes(GetCurrentProcess(), &creationTime, &exitTime, &kernelTime, &userTime)) {
                _set_errno(ENOTSUP);
                return -1;
            }

            ULARGE_INTEGER kernelValue = {
                .HighPart = kernelTime.dwHighDateTime,
                .LowPart  = kernelTime.dwLowDateTime
            };
            ULARGE_INTEGER userValue = {
                .HighPart = userTime.dwHighDateTime,
                .LowPart  = userTime.dwLowDateTime
            };
            ULONGLONG value = kernelValue.QuadPart + userValue.QuadPart;

            tp->tv_sec = (__time64_t)  (value / POW10_7);
            tp->tv_nsec = (long) ((value % POW10_7) * 100);

            return 0;
        }

    case CLOCK_THREAD_CPUTIME_ID:
        {
            FILETIME creationTime;
            FILETIME exitTime;
            FILETIME kernelTime;
            FILETIME userTime;

            /**
             * Function `GetThreadTimes` is available on Win9x systems,
             * but it always fails.
             *
             * `ENOTSUP` is the most fitting error code, although this error
             * condition is not specified by POSIX.
             */
            if (!GetThreadTimes(GetCurrentThread(), &creationTime, &exitTime, &kernelTime, &userTime)) {
                _set_errno(ENOTSUP);
                return -1;
            }

            ULARGE_INTEGER kernelValue = {
                .HighPart = kernelTime.dwHighDateTime,
                .LowPart  = kernelTime.dwLowDateTime
            };
            ULARGE_INTEGER userValue = {
                .HighPart = userTime.dwHighDateTime,
                .LowPart  = userTime.dwLowDateTime
            };
            ULONGLONG value = kernelValue.QuadPart + userValue.QuadPart;

            tp->tv_sec = (__time64_t) (value / POW10_7);
            tp->tv_nsec = (long) ((value % POW10_7) * 100);

            return 0;
        }

    default:
        break;
    }

    _set_errno(EINVAL);
    return -1;
}

/**
 * Sleep for the specified time.
 * @param  clock_id This argument should always be CLOCK_REALTIME (0).
 * @param  flags 0 for relative sleep interval, others for absolute waking up.
 * @param  request The desired sleep interval or absolute waking up time.
 * @param  remain The remain amount of time to sleep.
 *         The current implemention just ignore it.
 * @return If the function succeeds, the return value is 0.
 *         If the function fails, the return value is -1,
 *         with errno set to indicate the error.
 */
int clock_nanosleep64 (clockid_t clock_id, int flags, const struct _timespec64 *request, struct _timespec64 *remain)
{
    /**
     * The clock_nanosleep() function shall fail if:
     *
     * [EINVAL]
     *   The request argument specified a nanosecond value less than zero or
     *   greater than or equal to 1000 million.
     */
    if (request->tv_sec < 0 || request->tv_nsec < 0 || request->tv_nsec >= POW10_9) {
        _set_errno(EINVAL);
        return -1;
    }

    switch (clock_id) {
        /**
         * Currently, only `CLOCK_REALTIME` is supported.
         */
        case CLOCK_REALTIME:
            break;
        case CLOCK_MONOTONIC:
        /**
         * The clock_nanosleep() function shall fail if:
         *
         * [EINVAL]
         *   the clock_id argument does not specify a known clock,
         *   or specifies the CPU-time clock of the calling thread.
         */
        case CLOCK_PROCESS_CPUTIME_ID:
        case CLOCK_THREAD_CPUTIME_ID:
        default:
            _set_errno(EINVAL);
            return -1;
    }

    /**
     * Calling `clock_nanosleep` with `CLOCK_REALTIME` and zero `flags`
     * is the same as calling `nanosleep`.
     */
    if ((flags & TIMER_ABSTIME) == 0) {
        return nanosleep64(request, remain);
    }

    /**
     * Calculate sleep time from the current time and absolute time `request`.
     */
    struct _timespec64 sleepTime;

    clock_gettime64(clock_id, &sleepTime);

    /**
     * Timeout already expired.
     */
    if (sleepTime.tv_sec > request->tv_sec) {
        return 0;
    }

    sleepTime.tv_sec = request->tv_sec - sleepTime.tv_sec;
    sleepTime.tv_nsec = request->tv_nsec - sleepTime.tv_nsec;

    if (sleepTime.tv_nsec < 0) {
        /**
         * Timeout already expired.
         */
        if (sleepTime.tv_sec == 0) {
            return 0;
        }

        sleepTime.tv_nsec += POW10_9;
        sleepTime.tv_sec--;
    }

    return nanosleep64(&sleepTime, remain);
}

/**
 * Set the time of the specified clock clock_id.
 * @param  clock_id This argument should always be CLOCK_REALTIME (0).
 * @param  tp The requested time.
 * @return If the function succeeds, the return value is 0.
 *         If the function fails, the return value is -1,
 *         with errno set to indicate the error.
 */
int clock_settime64 (clockid_t clock_id, const struct _timespec64 *tp)
{
    /**
     * The clock_settime() function shall fail if:
     *
     * [EINVAL]
     *   The tp argument specified a nanosecond value less than zero or
     *   greater than or equal to 1000 million.
     */
    if (tp->tv_sec < 0 || tp->tv_nsec < 0 || tp->tv_nsec >= POW10_9) {
        _set_errno(EINVAL);
        return -1;
    }

    switch (clock_id) {
        case CLOCK_REALTIME:
        case CLOCK_REALTIME_COARSE:
            break;
        /**
         * The clock_settime() function shall fail if:
         *
         * [EINVAL]
         *   The value of the clock_id argument is CLOCK_MONOTONIC.
         */
        case CLOCK_MONOTONIC:
        /**
         * Setting CPU clocks is not supported.
         */
        case CLOCK_PROCESS_CPUTIME_ID:
        case CLOCK_THREAD_CPUTIME_ID:
        /**
         * The clock_settime() function shall fail if:
         *
         * [EINVAL]
         *   The clock_id argument does not specify a known clock.
         */
        default:
            _set_errno(EINVAL);
            return -1;
    }

    ULARGE_INTEGER value = {
        .QuadPart = DELTA_EPOCH_IN_100NS + (tp->tv_sec * POW10_7) + (tp->tv_nsec / 100)
    };
    FILETIME fileTime = {
        .dwHighDateTime = value.HighPart,
        .dwLowDateTime  = value.LowPart
    };
    SYSTEMTIME systemTime;

    if (!FileTimeToSystemTime(&fileTime, &systemTime)) {
        _set_errno(EINVAL);
        return -1;
    }

    if (!SetSystemTime(&systemTime)) {
        _set_errno(EPERM);
        return -1;
    }

    return 0;
}

/**
 * Versions to use with 32-bit time_t (struct _timespec32)
 */

int clock_getres32 (clockid_t clock_id, struct _timespec32 *tp)
{
    struct _timespec64 tp64;

    int error_code = clock_getres64 (clock_id, &tp64);

    if (error_code == 0) {
        tp->tv_sec = (__time32_t) tp64.tv_sec;
        tp->tv_nsec = tp64.tv_nsec;
    }

    return error_code;
}

int clock_gettime32 (clockid_t clock_id, struct _timespec32 *tp)
{
    struct _timespec64 tp64;

    int error_code = clock_gettime64 (clock_id, &tp64);

    if (error_code == 0) {
        if (tp64.tv_sec > INT_MAX) {
            _set_errno (EOVERFLOW);
            return -1;
        }

        tp->tv_sec  = (__time32_t) tp64.tv_sec;
        tp->tv_nsec = tp64.tv_nsec;
    }

    return error_code;
}

int clock_settime32 (clockid_t clock_id, const struct _timespec32 *tp)
{
    struct _timespec64 tp64 = {.tv_sec = tp->tv_sec, .tv_nsec = tp->tv_nsec};
    return clock_settime64 (clock_id, &tp64);
}

int clock_nanosleep32 (clockid_t clock_id, int flags, const struct _timespec32 *request, struct _timespec32 *remain)
{
    struct _timespec64 request64 = {
        .tv_sec = request->tv_sec,
        .tv_nsec = request->tv_nsec
    };
    struct _timespec64 remain64;

    int error_code = clock_nanosleep64 (clock_id, flags, &request64, &remain64);

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
