#include <stdio.h>
#include <stdlib.h>

//gets pointer, returns heap pointer
int* sum4(int* x, int* y) {
    int* c = (int *) calloc(1, sizeof(int ));

    *c =  *x + *y;

    return c;
}


//gets pointer, returns dangling pointer
int* sum3(int* x, int* y) {
    int c = *x + *y;

    return &c;   //it is a dangling pointer. c is local variable. !!!
                 //so we need to return heap address or static variable to overcome this issue !
}

//gets pointer, returns value
int sum2(int* x, int* y) {
    int c = *x + *y;

    return c;
}

// gets the value as input params, returns the value,
int sum(int x, int y) {

    int c = x + y;

    return c;
}

//gcc -o out/pointerToFunctionReturns src/pointerToFunctionReturns.c  && out/pointerToFunctionReturns
int main(int argc, char **argv) {
    /**
     * to overcome returning stack variable address (dangling pointer), use heap memory or global variable
     */

    int a = 3, b = 4;
//    int r = sum(a, b);  printf("%d", r);
//    int r = sum2(&a, &b); printf("%d", r);
//    int* r = sum3(&a, &b); printf("%d", *r);  //dangling pointer !!!
    int* r = sum4(&a, &b); printf("%d", *r);  //heap pointer !!!

    return 0;
}