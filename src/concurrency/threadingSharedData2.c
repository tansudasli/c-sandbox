#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include "common_threads.h"

typedef
struct ret {
    int x;
} RETURN_T;


void *xyz(void *arg) {
    RETURN_T *return_t = (RETURN_T *) calloc(1, sizeof(RETURN_T));

    //do some staffs

    //adjust values for waiting
    return_t->x = 1;

    return (void *)return_t;
}

int main (int argc, char **argv) {
    pthread_t pthread;
    RETURN_T *return_t;

    pthread_create(&pthread, NULL, xyz, "t1");
    pthread_join(pthread, (void * *) &return_t);

    printf("Returned %d", return_t->x);

    free(return_t);


    return EXIT_SUCCESS;
}

