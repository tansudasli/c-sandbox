#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//process
int main(int argc, char **argv) {

    printf("pid=%d\n", (int) getpid());

    int rc = fork();
    if (rc < 0) {
        perror("fork failed...\n");
        exit(EXIT_FAILURE);
    }

    if (rc == 0) {
        //child process
        printf("child rc=%d  pid=%d\n", rc, (int) getpid());

    }
    else {
        //parent process
        wait(NULL);

        printf("parent rc=%d  pid=%d\n", rc, (int) getpid());

    }

    return EXIT_SUCCESS;
}

