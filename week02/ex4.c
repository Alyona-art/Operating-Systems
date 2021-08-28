#include <stdio.h>

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a, b;
    printf("Enter two integers to swap them:\n");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("Swapped integers: %d %d", a, b);
    return 0;
}
