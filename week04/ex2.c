#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    for(int i = 0; i < 3; i++) {
        fork();
        sleep(5);
    }
    // during each iteration the function fork() creates a new process for each existing process
    // so in the first time it will be 2 processes
    // in the second - 2+2=4 processes
    // in the third - 4+4=8 processes

    // therefore we can calculate number of processes if we know number of calling fork():
    // y = 2 ^ x
    // if we will call fork() 5 times: y = 2 ^ 5 = 32 processes
}
