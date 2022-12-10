#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../header/numX.h"

//gcc -o out/concat src/test/concat.c src/utility/numX.c  && out/concat  123456 7000
int main(int argc, char **argv) {

    assert(numDigits(10008) == 5);
    assert(numDigits(133333335) == 9);
    assert(numDigits(1004413) == 7);

    assert(concatInteger(100, 300) == 100300);


    printf("%lld\n", concatInteger(argc > 1 ? atoll(argv[1]) : 444,
                                   argc > 1 ? atoll(argv[2]) : 555));


    return 0;
}