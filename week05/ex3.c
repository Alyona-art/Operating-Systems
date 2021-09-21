#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#define N 100
int count = 0;
time_t start;
int i = 0;
pthread_mutex_t M;
pthread_cond_t condCon, condPro;

void *producer(void *ptr) {
 while (1) {
  pthread_mutex_lock(&M);

  if (count == N) {
   pthread_cond_wait(&condPro, &M);
  }
  count = count + 1;
  time_t end = time(NULL);
  if(end - start > i*60){
   printf("%d\n", i);
   i++;
  }

  if (count == 1) {
   pthread_cond_signal(&condCon);
   pthread_mutex_unlock(&M);
  }
 }
}

void *consumer(void *ptr) {
 while (1) {
  pthread_mutex_lock(&M);

  if (count == 0) {
    pthread_cond_wait(&condCon, &M);
  }
  count = count - 1;
  if (count == N - 1){
   pthread_cond_signal(&condPro);
   pthread_mutex_unlock(&M);
  }
 }
}

int main() {

 start = time(NULL);
 pthread_t pro, con;
 pthread_mutex_init(&M, NULL);
 pthread_cond_init(&condCon, NULL);
 pthread_cond_init(&condPro, NULL);
 pthread_create(&con, NULL, consumer, NULL);
 pthread_create(&pro, NULL, producer, NULL);
 pthread_join(pro, NULL);
 pthread_join(con, NULL);
 pthread_cond_destroy(&condCon);
 pthread_cond_destroy(&condPro);
 pthread_mutex_destroy(&M);
 
 return 0;

}
