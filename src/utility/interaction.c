#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/**
 * to read more accurate and robust from user (via stdin)
 *
 * @param s
 * @param maxLength: maximum length except \0 char
 * @return
 */
int readLn(char s[], int maxLength) {
    int len_s;

    fgets(s, maxLength + 1, stdin);
    len_s = strlen(s);
    // if (s[len_s - 1] == '\n') {
    // 	s[len_s - 1] = '\0';
    // 	len_s -= 1;
    // }

    rewind(stdin); // This flushes the keyboard buffer (on Windows anyway!)

    return len_s;
}

/**
 * to read the most accurate and robust from user (via stdin)
 *
 * @param s
 * @param maxLength
 * @return
 */
int readChar(char s[], int maxLength) {
    char ch;
    bool remainingChars = true;

    int counter = 0;
    while (remainingChars) {
        ch = getchar();

        if ((ch == '\n') || (ch == EOF)) {
            remainingChars = false;
        } else if (counter < maxLength) {
            //go on building string
            s[counter] = ch;
            counter++;
        }
    }
    s[counter] = '\0';

    return counter;
}