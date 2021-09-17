#include <stdio.h>
#include <string.h>
#include <mm_malloc.h>

#define MAXLENGTH 150


// we can not reassign like (message = message + name; ) to a char[], or any string :)
// also, we cannot reassign a char[].
char * stringOpsWithCharArray(char name[]) {
    char m[MAXLENGTH] = "Hi, "; //native or mandatory initialization

    return strcat(m, name);

//    return m;  m is local var and is created at stack. so creates warning
}

//char*, we need to malloc to use strcat()
char * stringOpsWithCharPointer(char * name) {
    char *r = malloc(MAXLENGTH);  //we had to initialize.
                                  //it is created at heap. so return r; is valid.
    //r[0] = '\0';    //do we really need this?

    strcat(r, "Hi, ");
    strcat(r, name);

//    free(r);  returning a local var, and trying to free. logical mistake

    return r;
}

//only possible with char**.
void stringOpsWithParameter(char** name) {
    char *r =  calloc(MAXLENGTH, sizeof(char));

    strcat(r, *name);
    strcat(r, "Tansu");

    *name = r;  //changes message variable value.

    free(r);
}

void stringOpsWithParameter2(char* z) {
    char *rrr = calloc(MAXLENGTH, sizeof(char)); //use calloc not malloc :)

    strcat(rrr, z);
    strcat(rrr, "Tansu");

    strcpy(z, rrr);  //changes message variable value.

    free(rrr);
}

//it ain't swaps, pass by value
void swap(int x, int y) {
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

//to swap 2 variables, we need their address
void swap2(int* x, int* y) {

    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}


//by value
//if array is huge, it occupies more memory! so not efficient
void display(int b[5], int l) {

    for (int i = 0; i < l; i++)
        printf("%d ", b[i]);
}

//arr is an * [pointer/array]. so we need  ** to reach that
//** is also waits an addr. it is still pointer.
void display2(int* b, int l) {

    for (int i = 0; i < l; i++) {
        printf("%d ", *b);
        b++;
    }
}

//gcc -o out/pointerInFunctions src/pointerInFunctions.c  && out/pointerInFunctions
//gcc -o out/pointerInFunctions src/pointerInFunctions.c  && out/pointerInFunctions abidindenyo
int main(int argc, char *argv[]) {

    //by value, so, returning the new message
    printf("%s\n", stringOpsWithCharArray( "Ali"));
    printf("%s\n", stringOpsWithCharPointer(argc > 1 ? argv[1] : "Veli"));

    //by ref
    char *message = "Hi, ";
    stringOpsWithParameter(&message);  //
    printf("%s\n", message);

    char message2[50] = "Hi, bro "; //
    stringOpsWithParameter2(message2); //&message2=message2. it is an array
    printf("%s\n", message2);


    //
    int a = 20;
    int b = 10;
    printf("original...a=%d   b=%d\n", a, b);
    swap2(&a, &b);
    printf("swapped....a=%d   b=%d", a, b);

    //pass by value, below will copy arr into b[] array.
    printf("\n");
    int arr[] = {11, 22, 33, 44, 55};     //like const pointer. so we can not say arr++ (pointer arithmetic)
    int l = sizeof(arr)/sizeof(arr[0]);
    display(arr, l);

    //it ain't copy the arr into *b. just sent the addr of arr.
    printf("\n");
    display2(arr, l);  //or , display2(&arr[0], l);


    return 0;
}
