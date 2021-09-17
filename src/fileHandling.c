#include <stdio.h>
#include "header/search.h"

#define MAX_LINE 255
#define MAX_ROW 3
#define FILE_NAME "resources/dummy.txt"

/**
 * Read file
 *
 * @return -1 if error, or line count in read file
 */
int readLines() {

    int lineCount = 0;
    char line[MAX_LINE];

    FILE *file = fopen(FILE_NAME, "r");

    if (!file) {  //if fp is NULL
        printf( "File %s cannot be opened!", FILE_NAME );

        return -1;
    }

    printf("line \tcontent \n");
    while (fgets(line, MAX_LINE, file) != 0)
        printf("%d \t%s", ++lineCount, line);       // fputs(line, stdout);

    fclose(file);

    return lineCount;
}

/**
 * Append new lines to file
 *
 * @return -1 if error, or line count appended to file
 */
int appendLines() {

    char lines[MAX_ROW][MAX_LINE] = {
            {"We are what we repeatedly do. Excellence, then, is not an act, but a habit.\n"},
            {"The whole is more than the sum of its parts.\n"},
            {"Man is by nature a political animal.\n"}
    };

    FILE *file = fopen(FILE_NAME, "a+");

    if (!file) {  //if fp is NULL
        printf( "File %s cannot be opened!", FILE_NAME );

        return -1;
    }

    for (int i = 0; i < MAX_ROW; i++)
        fputs(lines[i], file);

    fclose(file);

    return MAX_ROW;
}

/**
 * Search in file to print count of found.
 *
 * @param fileName - path
 * @param needle - keyword to be searched
 */
void searchInFile(char fileName[], char *needle) {

    int searchCount = 0;
    char line[MAX_LINE];

    //read file line by line
    FILE *file = fopen(fileName, "r");

    if (file != NULL) {

        while (fgets(line, MAX_LINE, file) != 0) {
            //we have line - search
            if (searchString(needle, line) != -1)
                searchCount++;
        }

        printf("needle=%s, found %d times\n", needle, searchCount);

        fclose(file);
    } else {
        printf( "File %s cannot be opened!", FILE_NAME );
    }
}

int main(int argc, char const *argv[]) {

    readLines();
    appendLines();

    searchInFile(FILE_NAME, "the");
    searchInFile(FILE_NAME, "The");

    return 0;

}

