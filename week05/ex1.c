#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    pthread_t thread_id;
    int thread_num;
    char *str;
} thread_info;

void* job(void* args) {
    thread_info *t = (thread_info*)args;
    printf("Hello from thread %d\n", t->thread_num);
    return NULL;
}
int main() {
    thread_info *tinfo;
    int n, ret;
    void *res;
    pthread_t x;

    printf("Enter n:\n");
    scanf("%d", &n);
    tinfo = calloc(n, sizeof(thread_info));

    for(int i = 0; i < n; i++) {
        tinfo[i].thread_num = i;
        printf("Thread %d is created\n", tinfo[i].thread_num);
        ret = pthread_create(&x, NULL, &job, &tinfo[i]);
        tinfo[i].thread_id = x;
        ret = pthread_join(tinfo[i].thread_id, &res);
        free(res);
        printf("Exit of thread %d\n", tinfo[i].thread_num);
    }
    pthread_exit(&ret);
    free(tinfo);
    exit(EXIT_SUCCESS);
}
