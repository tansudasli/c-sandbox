#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 200

//    char *string;
char sentence[] = "On the dark night, Follow the light and Embrace the shadow which will lead you the way.";
char tens[]     = "        10        20        30        40        50        60   65";
char nums[]     = "123456789012345678901234567890123456789012345678901234567890123456";

char subSentence[MAX_STRING_LENGTH]; //initialized
char *subSentence2;                  //not-initialized

/**
 * Returns index (zero based). If not found, return -1
 *
 * @param source
 * @param searchString
 * @return -1 or index
 */
int searchString(char source[], char searchString[]) {

    char *foundAt = strstr(source, searchString);
    int index = (int) (foundAt - source);

    if (foundAt == NULL)
        index = -1;

    return index;
}

// gcc -o out/manipulationsString src/manipulationsString.c  && out/manipulationsString
int main(int argc, char const *argv[]) {

    //printf("%lu \t%lu\n", strlen(sentence), strlen(tens));

    //print string and indexes
    printf("%s\n%s \n%s\n", sentence, tens, nums);

    //or calculate pointer addr. => sentence + searchString(sentence, "night")
    printf("%s\n", &sentence[searchString(sentence, "night")]);
    printf("%s\n", &sentence[searchString(sentence, "will")]);

    //copy char[] (implicitly initialized) and char* (we need to initialize w/ malloc)
    strncpy(subSentence, sentence, 6);
    printf("subSentence=%s\n", subSentence);

    subSentence2 = malloc(MAX_STRING_LENGTH);
    strncpy(subSentence2, sentence, 6);
    printf("subSentence2=%s\n", subSentence2);

    //concat
    strncat(subSentence, "#####", 5);
    printf("subSentence=%s\n", subSentence);

    strncat(subSentence2, "#####", 5);
    printf("subSentence2=%s\n", subSentence2);

    return 0;
}
