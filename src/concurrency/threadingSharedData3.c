#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include "common_threads.h"

//every thread has its own stack, so to hold some arguments to share among threads
//1- global var (not has to be static !!), or
//2- create var at heap (calloc etc..),  or
//3- use shared memory!!!
typedef
struct args {
    int max;

} ARGS;

static ARGS args;
static volatile int counter = 0;

pthread_mutex_t lock; //= PTHREAD_MUTEX_INITIALIZER;  //init lock
                      //or, dynamically --> int rc = pthread_mutex_init(&lock, NULL); assert(rc == 0);

/**
 * Accessing global static data.
 *
 * @param arg
 * @return
 */
void *xyz(void *arg) {
    printf("thread begin=%s \t%d\n", (char *)arg, counter);

    //lock
    Pthread_mutex_lock(&lock);
    for (int i = 0; i < args.max; i++)
        counter++;                        //critical part
    Pthread_mutex_unlock(&lock);

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

    //global static var
    args.max = argc == 2 ? atoi(argv[1]) : 1e7;
    printf("max=%d\n", args.max);

    //init lock
    Mutex_init(&lock);

    printf("main start counter=%d...\n", counter);

    Pthread_create(&t1, NULL, xyz, "t1");
    Pthread_create(&t2, NULL, xyz, "t2");

    //parent has to wait threads execution.
    Pthread_join(t1, NULL);
    Pthread_join(t2, NULL);

    printf("main end counter=%d...\n", counter);

    assert(counter == args.max * 2);

    //destroy lock
    pthread_mutex_destroy(&lock);

    return EXIT_SUCCESS;
}



