#include <stdio.h>
#include <stdlib.h>

// build & run with, 
//     gcc -o out/helloworld src/helloworld.c 
//     ./out/helloworld ali veli deli

//char **argv == char *argv[]
int main(int argc, char const **argv)
{
    /* code */
    printf("hello World\n");
    puts("hi, again");

    //access 2 parameters
    for (int i = 0; i < argc; i++) {
        printf("%d, %s \n", i, *argv);
        argv++;
    }
    
    return 0;
}
