#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;
unsigned int X = 0;   //initial semaphore value

void * f (void *arg) {

    printf("child started...\n");
    sem_post(&s);        //signal that child is done!

    return NULL;
}

//gcc -o out/semaphore src/semaphore.c  && out/semaphore
int main(int argc, char **argv) {

    sem_init(&s, 0, X);

    printf("parent started...\n");

    pthread_t c;
    pthread_create(&c, NULL, f, NULL);
    sem_wait(&s);         //wait the child

    printf("parent end...\n");
    return 0;
}