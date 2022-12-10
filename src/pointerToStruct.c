#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef
struct employee {
    int id;

    char name[50];
    char surname[50];
    char birthPlace[25];
    double salary;
} EMPLOYEE;

void display(EMPLOYEE x) {

    printf("%d \t%s \n", x.id, x.name);
}

void display2(EMPLOYEE *x) {

    printf("%d \t%s \n", x->id, x->name);
}

//gcc -o out/pointerToStruct src/pointerToStruct.c  && out/pointerToStruct
int main(int argc, char **argv) {

    //define & initialize
    EMPLOYEE e = {1, "Abidin"};

    display2(&e); //    display(e);

    //stats
    printf("sizeof=%lu, %lu\n", sizeof(e), sizeof(EMPLOYEE));
    printf("%p == %p +=4 %p\n", &e, &(e.id), &(e.name));

    return 0;
}