#include <stdio.h>


//gcc -o out/pointerIndirection src/pointerIndirection.c  && out/pointerIndirection
int main(int argc, char **argv) {

    int i = 10;   //value
    int *pi;      //pointer                 int pi[]
    int **ppi;    //pointer to pointer      int *pi[] or  int pi[][] or  a kind of list

    int data[] = {0, 1, 2};         //this is not ==> int *data[SIZE] . look for pointerToPointer.c
    int length = sizeof(data) / sizeof(data[0]);

    //
    pi = data;     //data is array, cause it is the pointer & the address !! no need to use &data
    ppi = &pi;     // pi's address and data's address are different !! cause it is not an array !! but acts as array :)

    //data[1] = 5; //it changes both data, pi, and ppi values. they all look at the same address

    printf("data\t\t\t pi\n");
    for (int j = 0; j < length; j++) {

        printf("%d(%p)\t %d(%p)  \n",data[j], &data[j]
                                    ,*pi    , pi );      //pi has addr of data, but &pi is diff. addr


        pi++; //this does not change pi's addr, instead changes pi's pointing addr !!
    }

    return 0;
}