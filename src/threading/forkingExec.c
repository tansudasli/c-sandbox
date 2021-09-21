#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//process
//  cmake --build cmake-build-debug --target forking -- -j 1
//  ./cmake-build-debug/forking "cmake-build-debug/resources/dummy.txt"
int main(int argc, char **argv) {

    printf("pid=%d\n", (int) getpid());

    int rc = fork();
    if (rc < 0) {
        perror("fork failed...\n");
        exit(EXIT_FAILURE);
    }

    printf("arg=%s\n", argv[1]);

    if (rc == 0) {
        //child process
        printf("in child: rc=%d  pid=%d\n", rc, (int) getpid());

        //if you want to execute as a different process
        char *x[3];
        x[0] = strdup("wc");
        x[1] = strdup(argv[1] ? argv[1] : "cmake-build-debug/resources/dummy.txt");
        x[2] = NULL;

        execvp("wc", x);

    }
    else {
        //parent process
        wait(NULL);  //this line is the 1st. either child or parent run first,
                     // we are sure, the child will be the first.

        printf("in parent: rc (child pid)=%d  pid=%d\n", rc, (int) getpid());

    }

    return EXIT_SUCCESS;
}

