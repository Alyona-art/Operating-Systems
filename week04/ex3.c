#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    char *s;
    bool exit = false;
    s = malloc(sizeof(char)*100);
    printf("MAX LENGTH 100 symbols\n");
    while(!exit) {
        scanf("%s", s);
        if(strcmp(s, "^C") == 0)
            exit = true;
        system(s);
    }
}
