#include <stdio.h>
#include <stdlib.h>
#include "header/interaction.h"


//gcc src/getInput.c src/utility/interaction.c -o out/getInput  && out/getInput
int main(int argc, char const *argv[])
{
    /* code */
	char *m = malloc(STRLEN);

	printf("Enter a string: ");

//	readLn(m, STRLEN);
	readChar(m, STRLEN);  //more accurate

	printf("lengthOfInput=%d, maxLength=%d => truncatedInput=%s", STRLEN, STRLEN, m);
    
    return 0;
}