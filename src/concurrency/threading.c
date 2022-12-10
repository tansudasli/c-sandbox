#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include "common_threads.h"

void *xyz(void *arg) {
    printf("thread=%s\n", (char *)arg);

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

    printf("parent start...\n");

    Pthread_create(&t1, NULL, xyz, "t1");
    Pthread_create(&t2, NULL, xyz, "t2");

    //parent has to wait threads execution.
    Pthread_join(t1, NULL);
    Pthread_join(t2, NULL);

    printf("parent end...\n");

    return EXIT_SUCCESS;
}

