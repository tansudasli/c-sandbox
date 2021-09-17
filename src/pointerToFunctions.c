#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

/** bubble sort
 * how can we make comparison step flexible ?
 * a- copying function for DESC or ASC
 * b- defining a parameter for ASC vs DESC in the same func.
 * c- function pointer
 */
void sort(int *s, int l) {

    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l; j++) {

            //swap otherwise
            if(s[i] > s[j]) {     //this part is comparison step
                int tmp = s[j];

                s[j] = s[i];
                s[i] = tmp;
            }
        }
    }
}

/**
 * Clients compare function.
 *
 * @param x
 * @param y
 * @return
 */
bool compare(int x, int y) {

    return x > y ? true : false;
}

bool compareAbs(int x, int y) {

    return abs(x) > abs(y) ? true : false;
}

/**
 *
 * @param s
 * @param l
 * @param comparison : function pointer to compare
 */
void sort2(int *s, int l, bool (*comparison) (int, int)) {

    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l; j++) {

            //swap otherwise
            if(comparison(s[i], s[j])) {     //this part is comparison step
                int tmp = s[j];

                s[j] = s[i];
                s[i] = tmp;
            }
        }
    }
}

int sum(int a, int b) {

    return a + b;
}

//gcc -o out/pointerToFunctions src/pointerToFunctions.c  && out/pointerToFunctions
int main(int argc, char *argv[]) {
    /**
     * It is good for call backs or event management esp. when in used as function parameters!
     */

    //core concept
    int (*pFunction) (int, int) = sum;     //define and init

    printf("%d \n",  pFunction(5, 7));

    //as in function parameters
    int grades[] = {10, 2, -15, 45, 100, 75, 92, 91, 75, 5};
    int length = sizeof(grades) / sizeof(grades[0]);

    //sort(grades, length);
    //sort2(grades, length, compare);   //send the compare function's addr. as pointer.
                                        //think of compare func is in the client. sort2 is in the library files.

    sort2(grades, length, compareAbs);

    for (int i = 0; i < length; i++)
        printf("%d ", grades[i]);

    return 0;
}

