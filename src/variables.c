#include <stdio.h>
#include "header/variables.h"


void precisionThings() {
    printf("TAX_STANDART = %f, %.3f, TAX_LUX_CONSUPTION = %.3f \n", 
        TAX_STANDART, TAX_STANDART, 
        TAX_LUX_CONSUPTION);      //0.180000, 8 precision digit | 0.180

    //w/o casting it gives crazy something :)
    printf("TAX_STANDART = %d \n", (int)TAX_STANDART); //0
}

void calculateTax() {
    double total = 200.50;

    // int taxAmount = total * TAX_STANDART;           //0
    // int taxAmount = (float)(total * TAX_STANDART);  //36, stil does as float then returns int
    double taxAmount = total * TAX_STANDART;           //36.09
    double grandTotal = total + taxAmount;

    printf("grandTotal=%f (total=%.2f, taxAmount= %.2f) \n", grandTotal, total, taxAmount);

}

/**
 * Build, then Run w/
 *    gcc -o out/variables src/variables.c && ./out/variables 
 */
int main(int argc, char const *argv[])
{
    //precision 
    precisionThings();

    //double/int calculation variations
    calculateTax();

    return 0;
}
