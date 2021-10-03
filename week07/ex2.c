#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int N;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &N);
    arr = malloc(N * sizeof(int));
    for(int i = 0; i<N; i++)
        arr[i] = i;
    for(int i = 0; i<N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
