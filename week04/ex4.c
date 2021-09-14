#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    char command[100];
    bool exit = false;
    printf("MAX LENGTH 100 symbols\n");
    char* arg[10] = {};
    char* s;
    int i = 0;
    pid_t PID;

    while(!exit) {
        scanf("%[^\n]%*c", command);
        if(strcmp(command, "^C") == 0)
            exit = true;
        else {
            s = strtok(command, " \n");
            while (s != NULL) {
                arg[i] = s;
                s = strtok(NULL, " \n");
                i++;
            }
            PID = fork();
            if(PID == 0) {
                execvp(arg[0], arg);
            }
            i = 0;
        }
    }
}
