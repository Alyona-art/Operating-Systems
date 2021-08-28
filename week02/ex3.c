#include <stdio.h>
#define N 100

void rightSideUpTriangle (int n) {
    for(int i = 0; i <n; i++) {
        for(int j = 0; j < n-i; j++)
            printf(" ");
        for(int j = 0; j < 2*i+1; j++)
            printf("*");
        printf("\n");
    }
}

int main() {
    char str[N] = {0};
    int n;
    printf("Enter parameter n for creating a triangle:\n");
    scanf("%s", str);
    sscanf(str, "%d", &n);
    rightSideUpTriangle(n);
    return 0;
}
