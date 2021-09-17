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
    int *bonusHistory;
} EMPLOYEE;

void display(EMPLOYEE x) {

    printf("%d %s %s %s %0.2f (%d, %d)\n", x.id, x.name, x.surname, x.birthPlace, x.salary,
                                           x.bonusHistory[0], x.bonusHistory[1]);
}
void display2(EMPLOYEE *x) {

    printf("%d %s \n", x->id, x->name);
}
void display3(EMPLOYEE *x) {

    while (x->id) {
        printf("%d \t%s \n", x->id, x->name);
        x++;
    }
}

//gcc -o out/structBasics src/structBasics.c  && out/structBasics
int main(int argc, char **argv) {

    /**
     * we dont have to malloc, to access a value.
     * accessing like pointers using . operator, but it is stored as value not a pointer !
     * to initialize, we could use,
     *    e.id = 1;
     *    strcpy(e.name, "Abidin");     //but, we can't say e.name = "Abidin",
     *
     * struct creates a contiguous memory block. but it is tricky to calculate struct's size. so, use sizeof() !!
     */

    //define & initialize
    int h[] = {10000, 15000};
    EMPLOYEE e = {1, "Abidin", "zabid", "bodrum", 1200.00, h};

     display(e);
//    display2(&e);

    //stats
    printf("sizeof=%lu, %lu\n", sizeof(e), sizeof(EMPLOYEE));
    printf("%p == %p +=4 %p\n\n", &e, &(e.id), &(e.name));

    //we can also define an array.
    //same rules valid for arrays here.
    EMPLOYEE employees[30] = {{1, "ali"}, {2, "veli"}, {3, "deli"}};

//    for (int i = 0; i < 3; i++)
//        display2(&employees[i]); //or, display2(employees+i)

    display3(employees);

    printf("sizeof=%lu \n\n", sizeof(employees));  //144*30 = 4320 bytes

    //dynamic array is also possible.
    EMPLOYEE * emp = (EMPLOYEE *) calloc(30, sizeof(EMPLOYEE));
    emp->id = 100; strcpy(emp->name, "hulagu");

    display2(emp);

    free(emp);

    //

    return 0;
}