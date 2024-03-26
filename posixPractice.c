#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define SUMMATION 1000000000

int sum = 0;

int thread_summation = SUMMATION / NUM_THREADS;

void *add(void *threadid) {
    long tid;
    tid = (long)threadid;
    int start = tid * thread_summation + 1;
    int end = (tid + 1) * thread_summation;
    int local_sum = 0;
    for (int i = start; i <= end; i++) {
        local_sum += i;
    }
    sum += local_sum;
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, add, (void *)i);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    printf("Summation of 1 to %d is %d\n", SUMMATION, sum);
    pthread_exit(NULL);
    return 0;
}