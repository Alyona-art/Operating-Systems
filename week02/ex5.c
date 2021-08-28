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
void rightTriangle (int n) {
    for(int i = 0; i <n; i++) {
        for(int j = 0; j < i + 1; j++)
            printf("*");
        printf("\n");
    }
}
void arrow (int n) {
    for(int i = 0; i <n/2; i++) {
        for(int j = 0; j < i +1; j++)
            printf("*");
        printf("\n");
    }
    if(n%2 == 1) {
        for (int j = 0; j < n/2 + 1; j++)
            printf("*");
        printf("\n");
    }
    for(int i = 0; i <n/2; i++) {
        for(int j = 0; j < n/2 - i; j++)
            printf("*");
        printf("\n");
    }
}
void square (int n) {
    for(int i = 0; i <n; i++) {
        for(int j = 0; j < n; j++)
            printf("*");
        printf("\n");
    }
}

int main() {
    char str[N] = {0};
    int n, x;
    printf("Choose figure by entering a number:\n1) Right-Side-Up Triangle\n2) Right Triangle\n3) Arrow\n4) Square\n");
    scanf("%d", &x);
    if (x < 1 || x > 4)
        printf("Error: wrong value");
    else {
        printf("Enter parameter n for creating a figure:\n");
        scanf("%s", str);
        sscanf(str, "%d", &n);

        switch (x) {
            case 1:
                rightSideUpTriangle(n);
                break;

            case 2:
                rightTriangle(n);
                break;

            case 3:
                arrow(n);
                break;

            case 4:
                square(n);
                break;
        }
    }
    return 0;
}
