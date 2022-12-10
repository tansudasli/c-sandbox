#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Search string in an char array.
 *
 * @param search key
 * @param source
 * @return -1 if not found, or index
 */
int searchString(char search[], char source[]) {
    int index = -1;
    char *found;

    found = strstr(source, search);

    if (found != 0) {
        index = (int)((found - source));
    }

    return index;
}