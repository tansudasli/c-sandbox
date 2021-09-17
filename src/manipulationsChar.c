#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 200

//    char *string;
char sentence[] = "1 dark night, Follow 2 lights and Embrace 3 shadows which will lead you the way.";

int numberOfLetters,
    numberOfUpperLetters, numberOfLowerLetters,
    numberOfDigits,
    numberOfBlanks,
    numberOfPunctuation,
    numberOfOthers = 0;

void doCharAnalysis() {
    for (int i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            numberOfLetters++;

            isupper(sentence[i]) ? numberOfUpperLetters++ : numberOfLowerLetters++;
        } else if (isdigit(sentence[i])) {
            numberOfDigits++;
        } else if(isblank(sentence[i])) {
            numberOfBlanks++;
        } else if(ispunct(sentence[i])) {
            numberOfPunctuation++;
        } else
            numberOfOthers++;
    }
}

// gcc -o out/manipulationsChar src/manipulationsChar.c  && out/manipulationsChar
int main(int argc, char const *argv[]) {

    doCharAnalysis();

    printf("%d letters (%d upper + %d lower) + %d digits + %d blanks + %d punctuation of %lu letters", numberOfLetters,
           numberOfUpperLetters, numberOfLowerLetters,
           numberOfDigits,
           numberOfBlanks,
           numberOfPunctuation,
           strlen(sentence));

}
