#include <stdio.h>
#include <string.h>
#define N 100

int main() {
    char str[N] = {0};
    char reverse[N] = {0};
  
    printf("Enter any string to reverse:\n");
    scanf("%s", str);
    for(int i=0; i<strlen(str); i++) {
        reverse[i] = str[strlen(str)-i-1];
    }
    printf("Your reverse string: %s", reverse);
    return 0;
}
