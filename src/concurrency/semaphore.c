#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BINARY 1        //binary semaphore works as mutex

sem_t *mutex;

void *f (void *arg) {

    printf("child started...\n");

    //critical code
    sem_post(mutex);        //signal that child is done!

    printf("child end...\n");

    return NULL;
}

//gcc -o out/semaphore src/semaphore.c  && out/semaphore
//parent works, only after child ends
int main(int argc, char **argv) {

    mutex = sem_open("/dummy", O_CREAT, 0644, BINARY);
    if (mutex == SEM_FAILED) {
        perror("semaphore creation error\n");
        exit(-1);
    }

    printf("parent started...\n");

    pthread_t c;
    pthread_create(&c, NULL, f, NULL);
    sem_wait(mutex);         //wait here for the child... blocking

    //do some parent staff
    printf("parent end...\n");

    return 0;
}