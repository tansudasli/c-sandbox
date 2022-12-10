#include <stdio.h>
#include <string.h>

//gcc -o out/pointerOperators src/pointerOperators.c  && out/pointerOperators
int main(int argc, char const *argv[])
{
    /**
     * int * p vs *p  (both * is different operator !!!
     * *p     --> value at address p
     * **p    --> value at address at (value at address p)
     * &      --> address of variable
     * ++/--  --> this moves pointer's pointing address. not p's address!!. And, it changes p addr value !!.
     * p+1    --> moves not p address, p's pointing address. And not 1 step more, + sizeof(type of p) !! And not updates p addr value
     *
     */
    char string1[] = "Hello";      //hexOfPointer=variableNameOfHex, string1 is the pointer address !
    char *string2 = "Hello";       //pointing addr of string pointer, in reality.

    printf("hexOfPointer  |variableNameOfHex| value\n");
    printf("%p   ==   %p        | %s\n", &string1, string1, string1);
    printf("%p   !=   %p        | %s\n", &string2, string2, string2);

    //char[] mean, it is a pointer and &string1 and string1 is same address..
      // But, we cannot say string1++ (pointer arithmetic). because it is a const char *.
      // so use [] indexes.
    //but, char * is similar but with some minor differences.
      // string2++ is possible. And, [] index-based access is also possible

    //pointer arithmetic
    printf("%c   %p      \n", string2[0], &string2[0]);
    printf("%c   %p = %p \n", string2[1], &string2[1], &string2[0]+1);

//    printf("%s \n", string2);

    int l = 0;
    while (*string2 != '\0')    // l < strlen(string2) is also OK, but string2 != NULL is not valid !!!
        printf("%c ", *string2++);  //prints value then updates pointer addr


    //printf("%x", &string2[0]+16000);     //somewhere in galactica :)

    //string2[5] is '\0'. last value


    return 0;
}
