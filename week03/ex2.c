#include <stdio.h>
#include <string.h>
#define size 5
void bubble_sort(int arr[]) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 1; j < size-i; j++) {
            if(arr[j-1] > arr[j]) {
                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
int main() {
    int arr[100];
    int k = 0;
    printf("Enter your array of size %d:\n", size);
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    bubble_sort(arr);
    printf("Sorted array after using Bubble Sort algorithm:\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
