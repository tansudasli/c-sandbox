#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include "common_threads.h"



static volatile int counter = 0;

/**
 * Accessing global static data.
 *
 * @param arg
 * @return
 */
void *xyz(void *arg) {
    printf("thread begin=%s \t%d\n", (char *)arg, counter);

    //critical part. many switches and many threading issues
    for (int i = 0; i <= 1e6; i++)
        counter++;

    printf("thread end=%s \t%d\n", (char *)arg, counter);
    return NULL;
}

/**
 * There are 3 critical concepts in threading.
 *    + (1)Reframe the problem to make concurrent and parallel
 *    + (2)Define critical parts
 *    + (3)Define how to communicate each other
 *
 *
 * 2- sync
 *   - locking (mutex)
 *   - signalling (CV)
 * 3- communication
 *   - message passing (sockets, pipes, mq, file ..)
 *   - shared memory
 *
 *
 * @param argc
 * @param argv
 * @return
 */
int main (int argc, char **argv) {
    pthread_t t1, t2;

    printf("main start counter=%d...\n", counter);

    Pthread_create(&t1, NULL, xyz, "t1");
    Pthread_create(&t2, NULL, xyz, "t2");

    //parent has to wait threads execution.
    Pthread_join(t1, NULL);
    Pthread_join(t2, NULL);

    printf("main end counter=%d...\n", counter);

    return EXIT_SUCCESS;
}

