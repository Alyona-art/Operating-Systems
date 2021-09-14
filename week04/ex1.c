#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int n = 7;
	// fork() creates a new process that is an exact copy of the parent one
  // but the child process has a unique process ID
	if (fork() == 0) // fork() returns 0 to the child process after successful completion
		printf("Hello from Child [%d - %d]\n", getpid(), n);
	else
		printf("Hello from Parent [%d - %d]\n", getpid(), n);

	// if we will run it 10 times then only PID will be different in the output
	// because the process ID increases by 1 every time when new process is created
}
