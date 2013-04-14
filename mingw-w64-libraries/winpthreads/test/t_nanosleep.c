#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>

#define POW10_3                 1000
#define POW10_6                 1000000

extern int __cdecl getntptimeofday(struct timespec *tp, struct timezone *tz);

__int64 timespec_diff_as_ms(struct timespec *__old, struct timespec *__new)
{
    return (__new->tv_sec - __old->tv_sec) * POW10_3
         + (__new->tv_nsec - __old->tv_nsec) / POW10_6;
}

unsigned __stdcall start_address(void *dummy)
{
    int counter = 0;
    struct timespec request = { 1, 0 }, remain;

    while (counter < 5) {
        int rc = nanosleep(&request, &remain);
        if (rc != 0) {
            printf("nanosleep interrupted, remain %d.%09d sec.\n",
                (int) remain.tv_sec, (int) remain.tv_nsec);
        } else {
            printf("nanosleep succeeded.\n");
        }

        counter ++;
    }

    return 0;
}

void WINAPI usr_apc(ULONG_PTR dwParam)
{
    long *index = (long *) dwParam;
    printf("running apc %ld\n", *index);
}

void test_apc()
{
    long i, rc, data[5];
    HANDLE thread;

    thread = (HANDLE) _beginthreadex(NULL, 0, start_address, NULL, 0, NULL);
    if (thread == NULL) {
        exit(1);
    }

    for (i = 0; i < 5; i++) {
        data[i] = i;
        Sleep(250 + rand() % 250);
        rc = QueueUserAPC(usr_apc, thread, (ULONG_PTR) & data[i]);
        if (rc == 0) {
            printf("QueueUserAPC failed: %ld\n", GetLastError());
            exit(1);
        }
    }

    rc = WaitForSingleObject(thread, INFINITE);
    if (rc != WAIT_OBJECT_0) {
        printf("WaitForSingleObject failed with %ld: %ld\n", rc, GetLastError());
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    int rc;
    struct timespec tp, tp2, request = { 1, 0 }, remain;

    getntptimeofday(&tp, NULL);
    rc = nanosleep(&request, &remain);
    getntptimeofday(&tp2, NULL);

    if (rc != 0) {
        printf("remain: %d.%09d\n", (int) remain.tv_sec, (int) remain.tv_nsec);
    }

    printf("%d.%09d\n", (int) tp.tv_sec, (int) tp.tv_nsec);
    printf("%d.%09d\n", (int) tp2.tv_sec, (int) tp2.tv_nsec);
    printf("sleep %d ms\n\n", (int) timespec_diff_as_ms(&tp, &tp2));

    test_apc();

    return 0;
}
