#include <stdio.h>

//gcc -o out/pointerBasics src/pointerBasics.c  && out/pointerBasics
int main(int argc, char **argv) {
    /** In int/char type variables,
     *      - pointer waits an address. & does the job.
     *      - indirection of pointer(*x) means "value at Address".
     *
     *      int x   - variable is x, and holds value
     *      int *y  - variable is y, not *y, and holds an address!!
     *          when we indirect(*y = means value at address), it is not the same operator as in int* !!
     *          & is the address operator of variable
     *          so &x is addr of x. but &y is also an address. but y is an address of something else!!
     */

    //int
    int num = 5;           //assign number or *pointer
    int* numPtr = &num;    //waits a pointer of integer == address, or use malloc to assign something
                           //numPtr = &num;  //valid
    int num2 = *numPtr;    //*pointer = indirection of pointer = value at address of numPtr

    num = 8; //but num2 is still 5. *numPtr is 8 !

    printf("addrOfVar        value               value at addr\n");
    printf("%p        %d                 n/a      int/int*\n", &num, num);
    printf("%p        %p     %d\n", &numPtr, numPtr, *numPtr);  //numPtr's value is the addr of num!
    printf("%p        %d                 n/a\n", &num2, num2);

    printf("\n");

    //char
    char ch = 'H';
    char* chPtr = &ch;
    char* k = "abc"; //valid, it is a string in fact, or array of chars
    //char *z = 'm';  //invalid, cause char* waits an sequence (array) of something

    printf("%p        %c                 n/a      char/char*\n", &ch, ch);
    printf("%p        %p     %c\n", &chPtr, chPtr, *chPtr);

    printf("\n");

    /**
     * In arrays of int/char, array is the address of itself !! special case
     * But, int[] not like char[]. You have to use m[0] or *m to access the value.
     *
     * The difference b/w int[]|char[] and char*|int* is pointing strategy
     *
     * In char[], you have chance to use %c and %s . In int[], you can only use %d, So
     * There is one diff. while accessing to value. %s waits char*, while %c waits char.
     *
     * Array is pointer and has value, But pointer has addr, not value. Value' addr is somewhere in memory.
     */

    //array
    int kkk = 5;
    int m[] = {1,2,3,4,5};
    int* mPtr = m;    //m is same as &m. cause it is array!!!. And points to addr of m[0]
    //mPtr = &kkk;      //valid

    //int *z = {1,2,3,4,5}; //not valid,
    //int *ho = 12345; //not valid and not meaningful as char*="abc" !!!


//    printf("%d %d %p == %p == %p\n", m[0], *m, &m, m, &m[0]);       //array is the address of itself
    printf("%p   ==     %p     %d     int*/int[]\n", &m, m, *m);  //*m==m[0] , m==&m
    printf("%p   !=     %p     %d\n", &mPtr, mPtr, *mPtr);

    printf("\n");
    //
    char msg[] = "Hello";
    char *msg2 = "Mello";

    //msg++;  //invalid. but it was a pointer
    msg2++;   //valid
    printf("%c %c %s %p == %p       char*/char[]\n", *(msg+1), msg[0], msg, &msg, msg);    //array is the address of itself
    printf("%c %s %p != %p\n", *msg2, msg2, &msg2, msg2); //but, Mello's addr. is different from msg2's addr
                                                          //here, is also *msg2 and msg2 usage diff. %c waits char, %s waits char*

    /**
     * char/int and arrays of (int/char..) act different !!
     * char* and char[] has some minor diff.
     */

    return 0;
}