#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 3

int main (int argc, char **argv) {
    int i;
    int n = !argv[1] ?  MAX_LENGTH : atoi(argv[1]);
    int *a = (int*) calloc(n, sizeof(int));  //to initialize a pointer, use either &int[], or malloc/calloc !!
                                                  //count is not important in IDE (somehow) but It is critical on shell :)
                                                  //initialize w/ 0

    printf("Enter %d numbers:\n",n);
    for( i=0 ; i < n ; i++ ) {
        scanf("%d", &a[i]);
    }

    printf("The numbers entered are: ");
    for( i=0 ; i < n ; i++ ) {
        printf("%d ", a[i]);
    }
    free( a );

    return(0);
}