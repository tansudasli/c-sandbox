#include <stdio.h>
#include <stdlib.h>

const static int y = 4;

int main (int argc, char **argv) {

    int x = 3;

    //all virtual memory address spaces!!
    printf("location of ... \n");
    printf("code= %p \theap=%p \tstack=%p \tglobal=%p\n", main,
                                              malloc(10e2),
                                              &x,
                                              &y);


    return EXIT_SUCCESS;
}