#include <stdio.h>

//gcc -o out/arraysIntvsChar src/arraysIntvsChar.c  && out/arraysIntvsChar
int main(int argc, char *argv[]) {

//    int iArray[] = {1, 2, 3, 7};     //no \0 null-terminator at the end
    int iArray[100] = {1, 2, 3, 7};    // \0 null-terminator implicitly at the end. !!
    char cArray[] = "Abidin";          // \0 null-terminator implicitly at the end !! So we can loop.
                                       // we dont have to say cArray[10] !!
/**
 * so either you should know the array size, or being sure null-pointer to terminate!
 *
 * check also pointerToInteger.c
 */


//    printf("%d", iArray[4]);

    int i = 0;
    while (*(iArray+i) != '\0') {
        printf("%d ", *(iArray+i));

        i++;
    }

    printf("\n");

    int j = 0;
    while (*(cArray+j) != '\0') {
        printf("%c ", *(cArray+j));

        j++;
    }

    return 0;
}