#include <stdio.h>

//gcc -o out/pointerAndCharArrays src/pointerAndCharArrays.c  && out/pointerAndCharArrays
int main(int argc, char const *argv[])
{
    //minor diff is the memory address value. hexOfPointer=valueOfHex
    char string1[] = "Hello";      //value of string1 is the address of start of char array Hello
    char *string2 = "Hello";       //pointing a char at a memory address

    printf("hexOfPointer        |variableNameOfHex| value\n");
    printf("%p  ==  |%p        | %s\n", &string1, string1, string1);
    printf("%p  !=  |%p         | %s\n", &string2, string2, string2);

//    hexOfPointer  |variableNameOfHex| value
//    e7a3b6ba      |e7a3b6ba        | Hello       hexOfPointer=variableNameOfHex
//    e7a3b6b0      |81c7f52         | Hello

// string2 = string1; is the same result. Because, string1 is the actual address!
//    string2 = &string1;
//    printf("hexOfPointer  |variableNameOfHex| value\n");
//    printf("%x      |%x        | %s\n", &string1, string1, string1);
//    printf("%x      |%x        | %s\n", &string2, string2, string2);

//    hexOfPointer  |variableNameOfHex| value
//    eb0016ba      |eb0016ba        | Hello
//    eb0016b0      |eb0016ba        | Hello

// char arrays or string in C is immutable.
//    string1 = "Goodbye";     //new assignment and it fails. Immutable. const * !!! so we cannot say string1++
    string2 = "Goodbye";       //but no problem for a pointer itself !
    printf("%p      |%p         | %s      | %c\n", &string2, string2, string2,  *string2);

//    hexOfPointer  |variableNameOfHex| value
//    eb3256aa      |eb3256aa        | Hello
//    eb3256a0      |48ddf4a         | Hello
//    eb3256a0      |48ddfac         | Goodbye


    return 0;
}