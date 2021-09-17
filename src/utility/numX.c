#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numDigits(long long v) {

    if (v < 0) return 0;
    if (v < 10) return 1;

    return 1 + numDigits(v / 10);

}

long long concatInteger(long long a, long long b) {

    char *s1 = (char *) calloc(numDigits(a) + numDigits(b), sizeof(char));
    char *s2 = (char *) calloc(numDigits(b), sizeof(char));

    sprintf(s1, "%lld", a);
    sprintf(s2, "%lld", b);

    strcat(s1, s2);
    char *eptr;

    return strtoll(s1, &eptr, 10);
}
