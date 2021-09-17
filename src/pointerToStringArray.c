#include <stdio.h>

#define SIZE 3

//gcc -o out/pointerToStringArray src/pointerToStringArray.c  && out/pointerToStringArray
int main(int argc, char **argv) {

    char ch = 'c';   //value
    char *pc;        //pointer                 char pc[]                  or  a word (n length but still 1 word)
    char **ppc;      //pointer to pointer      char *pc[] or  char pc[][] or  a kind of word list

    //init
    char *words[SIZE];   //hold some initial data => w0 w1 w2  => char[][]
                         //char*[] is better than char**. more easy to initialize
                         //           better than char[][]. we are able to use pointer arithmetic

    words[0] = "ali"; words[1] = "veli"; words[2] = "deli";

//    int length = sizeof(words) / sizeof(words[0]);
//    printf("size=%d\n\n", length);

    for (int j = 0; j < SIZE; j++)
        printf("%s\t", words[j]);

    printf("\n");

    //accessing w/ arrays
    ppc = words;  //words is an array so it is an address also

    printf("words\t\t\t ppc\t\t\t pc\n");
    for (int j = 0; j < SIZE; j++) {

        printf("%s(%p)\t %s(%p)\n",words[j],   //*(words+i) is also valid to get value.
                                               // But we can not do words++ type things!
                                   &words[j]   //(words+i) is also possible to get address
                                  ,*ppc
                                  ,ppc);

        ppc++;      // we can also treat **ppc as an array. ppc[j] also works !!
    }


    //accessing w/ pointers
    ppc = words;
    for (int j = 0; j < SIZE; j++) {

//        1st way -
//        pc = *ppc;
//        while ( *pc != 0) {
//            printf("%c\t", *pc);
//            pc++;
//        }

        //2nd way
        while ( **ppc != 0) {
            printf("%c  ", **ppc);
            (*ppc)++;
        }

        printf("\n");

        ppc++;
    }

    return 0;
}