#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 1

sem_t *s;

void *f (void *arg) {

    printf("child started...\n");
    sem_post(s);        //signal that child is done!

    return NULL;
}

//gcc -o out/semaphore src/semaphore.c  && out/semaphore
int main(int argc, char **argv) {

    s = sem_open("/dummy", O_CREAT, 0644, BUFFER_SIZE);

    if (s == SEM_FAILED) {
        perror("semaphore creation error\n");
        exit(-1);
    }

    printf("parent started...\n");

    pthread_t c;
    pthread_create(&c, NULL, f, NULL);
    sem_wait(s);         //wait the child

    printf("parent end...\n");
    return 0;
}