#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//O(2^n)
unsigned long fibonacci(int n) {

    if (n < 0) { perror("not-positive"); return -1; }
    if (n == 0) return 0;
    if (n <= 2) return 1;  //base

    return fibonacci(n-1) + fibonacci(n-2);
}

//O(n) w/ dynamic technics
unsigned long fibonacci2(int n, unsigned long *memo) {


    //base
//    if (n < 0) { perror("not-positive"); return n; }
    if (n == 0) return 0;
    if (n <= 2) { memo[n-1] = 1; return 1; }

    //memoize
    if (memo[n-1] != 0) return memo[n-1];

    unsigned long result = fibonacci2(n-1, memo) + fibonacci2(n-2, memo);

    //save
    memo[n-1] = result;

    return result;
}

//gcc -o out/fibonacci src/fibonacci.c  && out/fibonacci 50
int main(int argc, char const *argv[]) {

    long n = (argc > 1 ? atoi(argv[1]) : 10);

    unsigned long *memoization = (unsigned long *) calloc(n, sizeof(unsigned long));

    printf("fibonacci of %ld = %lu\n", n, fibonacci2(n, memoization));

    //debug
    printf("\n------------\n");
    for (int i = 0; i < n; i++)
        printf("%lu ", *(memoization+i));

    return 0;
}

