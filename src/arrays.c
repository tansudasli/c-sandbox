#include <stdio.h>
#include <string.h>


//gcc -o out/arrays src/arrays.c  && out/arrays
int main(int argc, char const *argv[]) {
    //

    int intArray[] = {1,2,3,4,5};   //no need to set explicitly intArray[5]. BUT this may effect the null-termination strategy
    double doubleArray[] = {2.1, 2.3, 2.4, 2.5};
    for (int i = 0; i < 5; i++)
        printf("%d ", intArray[i]);   //or, *(intArray+i)

    printf("\n");

    //
    //char arrays ; contains words, sentences. not multi-dimensional
    char charArray[] = {'h', 'e', 'l', 'l', 'o' };   //no need to define \0. This is same as below line !!!
    char charArray2[] = "world where";    //string, and char array! do not think it is a string array due to SPACE
    char *string = "Hello";               //string or char array. mostly same

    //char by char
    for (int i = 0; i < strlen(string); i++)
        printf("%c ", string[i]);  //or, *(string+i)

    printf("\n%s\n", string);

    int i = 0;
    do {
//        printf("%s", charArray2[i]);   not works. it is a char array, not a string array
        printf("%c", charArray2[i]);
        i++;
    } while (charArray2[i] != '\0');

    //
    /**
     * stringArray[0] holds a char*
     * stringArray[1] holds another char*
     * so at vertical we have char*. at horizontal we have names.. this is kind of pointer also.
     */
    char *stringArray[] = {"Abidin", "Denyo", "Veli", "Deli"};    //string Array, **string =  char *string[];

    //char by char
    for (int i = 0; i < 4; i++) {
        char *k = stringArray[i];

        while (*k != '\0') {
            printf("%c", *k);
            k++;
        }
        printf("\t");
    }

    for (int i = 0; i < 4; i++) {
        printf("%s \t", stringArray[i]);
    }


    printf("\n");

    //multi dimension arrays
    int grid[2][5] = {{1,2,3,4,5 },
                      {6,7,8,9,10}};

    //2x5 array/matrix
    for (int i = 0; i < 2; i++) {
        printf("\n");

        for (int j = 0; j < 5; ++j)
            printf("%d  ", grid[i][j]);
    }

    /**
     * 2x3. but h is char*. ello is the following part
     *
     *    o t
     *    l n
     *    l e 7
     *    e g 0
     * 0 |h|a|0
     * 1 |h|y|d
     *    o o o
     *    w u i
     *        n
     *        g
     *
     */
    char *srid[2][3] = {{"hello","agent","007"},
                        {"how","you","doing"}};

    for (int i = 0; i < 2; i++) {
        printf("\n");

//        for (int j = 0; j < 3; ++j) {
//            printf("%s  ", srid[i][j]);
//        }

         //char by char
        for (int j = 0; j < 3; j++) {
            char *z = srid[i][j];

            while (*z != '\0')
                printf("%c", *z++);

            printf(" ");
        }
    }

    char lines[3][255] = {
            {"We are what we repeatedly do. Excellence, then, is not an act, but a habit.\n"},
            {"The whole is more than the sum of its parts.\n"},
            {"Man is by nature a political animal.\n"}
    };


    return 0;
}
