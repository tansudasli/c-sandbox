#include <stdio.h>
#include <stdlib.h>

//gcc -o out/pointerToIntegerArray src/pointerToIntegerArray.c  && out/pointerToIntegerArray
int main(int argc, char **argv) {

    int k[] = {1, 2, 3, 4, '\0'};   //if we dont put \0, below while (*o[i] != '\0') does not work properly!!!!
    int l[] = {2, 4, 6, 8, '\0'};
    int m[] = {1, 8, 27, 64, '\0'};


    int *o[3];   //if we define int **o, then we can not initialize properly.
                 //think of z[3][4]. it will have 3 pointers, and every pointer has kind of array
                 //as it is seen below, it creates 12 items for every row !!!

    o[0] = k;  //1 2 3 4 -515139872 32766 -1857290203 -261192148 -515139872 32766 540878369 32767
    o[1] = l;  //2 4 6 8 1 2 3 4 -515139872 32766 -1857290203 -261192148
    o[2] = m;  //1 8 27 64 2 4 6 8 1 2 3 4

    //below is also works like above. but we cannot use pointer arithmetic !!!
    // on the other side, C holds [][] as 1 2 3 4 2 4 6 8 1 8 27 64 1 8 27 64  format. not below!
//    int o[3][4]  = {{1, 2, 3, 4},
//                    {2, 4, 6, 8},
//                    {1, 8, 27, 64}
//                    };

    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 12; j++)
           while (*o[i] != '\0')
            printf("%d ", *o[i]++);


        printf("\n");
    }


    return 0;
}
