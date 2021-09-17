#include <stdio.h>
#include <stdlib.h>
#include <string.h> 



//gcc -o out/userInput src/userInput.c  && out/userInput 12 
void usingCommandLineParametersAndCasting(int argc, char const *argv[]) {
    int i;

    // get param from command line 
    for (int j = 1; j < argc; j++)
    {
        /* code */
        i = atoi(argv[j]);
        i == 0 ? printf("Enter numeric value \n") : printf("Got from commandline= %d \n", i);
    }
}

//gcc -o out/userInput src/userInput.c  && out/userInput tansuyyyyyyyyy manr
void usingCommandLineParameters(int argc, char const *argv[]) {
    const char *name;
    char lastname[5]; //char[5] (array). we can initialize, but we can not assign later.
                              // so use,  const char *, or strcpy or memcopy

    // get param from command line 
    if (argc > 1)
    {
        /* code */
        name = argv[1];  //gets unlimited char
        strcpy(lastname, argv[2]); //todo: if value >4, then creates error. so use char* and malloc

        printf("Got from commandline= %s, %s \n", name, lastname);
    }
}

//gcc -o out/userInput src/userInput.c  && out/userInput 
void usingGetAndCasting() {
    char iString[5];
    int i;

    //get something from user, unsafe and definitely string!!, and cast it to a int
    printf("Enter a number: "); 

    gets(iString);
    i = atoi(iString);  //if gets non integer, returns 0. So if it is 0, give error message
    i == 0 ? printf("Enter numeric value \n") : printf("Got from screen= %d \n", i);
}

//gcc -o out/userInput src/userInput.c  && out/userInput 
void usingGet() {
    char name[5];
    char lastname[5];

    printf("Enter name= ");
    gets(name);

    printf("Enter lastname= ");
    gets(lastname);

    printf("Got from screen= %s, %s", name, lastname);
}

//gcc -o out/userInput src/userInput.c  && out/userInput 
//gcc -o out/userInput src/userInput.c  && out/userInput 12 
//gcc -o out/userInput src/userInput.c  && out/userInput tansuyyyyyyyyy manr
int main(int argc, char const *argv[])
{

    // usingGetAndCasting();
    // usingCommandLineParametersAndCasting(argc, argv);

    /**
     * Getting name as char*, and lastname as char[5].
     * name gets unlimited char, while lastname gets max 4 char.
     * So what is the desired behaviour, is important. For relational dbs/tabbed-files especially. In case of such, 
     *    custom flushing the buffer and using fgets may be a better way. But it has own fallbacks :)!
     */
     usingCommandLineParameters(argc, argv);

    /**
     * if you enter more than 5 char, it still works!! not truncate
     * furthermore, if you set [5] for name, and [5] for lastname, it gets more unreliable.
     *   treat as 10, if you enter more than 5 char in lastname, and deletes content in firstname even.
     */ 
//    usingGet();

    return 0;
}
