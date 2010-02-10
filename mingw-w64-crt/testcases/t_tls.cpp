/*
 * tls.cpp
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <process.h>


int __thread tls_value = 0;

unsigned __stdcall thread_fn(void*)
{
	++tls_value;
	return 0;
}

// This is derived from the jig that I setup to explore the problems with
// MT exception handling - you could probably just as easily set processors to
// some value rather than tying it to the actual # of cores...
int main()
{
	// Get the number of processors available to use
	SYSTEM_INFO si;
	GetSystemInfo(&si);
	const unsigned processors = si.dwNumberOfProcessors;

	// Make a thread for every processor and assign the thread to it
    HANDLE threads[processors];
    unsigned i;
    for (i=0;i<processors;i++) {
    	threads[i] = (HANDLE)_beginthreadex(0, 0, thread_fn, 0, CREATE_SUSPENDED, 0);
    	SetThreadAffinityMask(threads[i], 1 << i);
    }
    // Restart all the threads
    for (i=0;i<processors;i++)
    	ResumeThread(threads[i]);
    // Rejoin those threads
	WaitForMultipleObjects(processors, threads, 1, INFINITE);
	for (i=0;i<processors;i++)
		CloseHandle(threads[i]);

	std::cout << "How is it possible that tls_value is "
          << tls_value << " != 0 ?" << std::endl;

	return 0;
}
