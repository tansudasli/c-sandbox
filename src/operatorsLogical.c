#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -o out/operatorsLogical src/operatorsLogical.c  && out/operatorsLogical
int main(int argc, char const *argv[]) {

    int age = 0, numberOfChildren = 0;
    double salary = 0.00;
    char *ptr;

    //initialize variable from cmd line
    if (argc > 1) {
        age = atoi(argv[1]);
        numberOfChildren = atoi(argv[2]);
        salary = strtod(argv[3], &ptr ); //to store rest of it
    }
    printf("age= %d, numberOfChildren= %d, salary= %.2f\n", age, numberOfChildren, salary);
    strlen(ptr) > 1 ? printf("rest of params= %s\n", ptr) :  printf("");

    age > 0 && numberOfChildren > 0 ? printf("Excellent\n") : printf("Run w/ age numberOfChildren salary\n");
    age > 65 || numberOfChildren > 5 ? printf("Poor man!") : printf("Free man!");

    return 0;
}

