#include <stdlib.h>
#include <stdio.h>
#include<string.h>

void *myRealloc(void *ptr, size_t size, size_t new_size) {

    // ptr is NULL
    if(size == 0) {
        printf("ptr = NULL\n");
        return malloc(new_size);
    }
    // new size is equal to zero
    else if(new_size == 0) {
        free(ptr);
        return ptr;
    }
    // else we return new pointer to the array with new size
    // but with unchanged content in this range
    else {
        void *tmp = malloc(new_size);
        memcpy(tmp, ptr, new_size);
        free(ptr);
        return tmp;
    }

}

int main(){
	return 0;
}


