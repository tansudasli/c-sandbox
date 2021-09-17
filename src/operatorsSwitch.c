#include <stdio.h>

//String = char *
char* findCharType(int ch) {
    char* type;

    switch (ch) {
        case 0: type = "Null"; break;              // \0
        case 7: type = "Bell"; break;
        case 8: type = "BackSpace"; break;
        case 9: type = "Tab"; break;               // \t
        case 10: type = "LineFeed"; break;         // \n
        case 13: type = "Carriage Return"; break;  // \r
        case 32: type = "Space"; break;
        case 48 ... 57: type = "Number"; break;    // 0...9
        case 65 ... 90: type = "Uppercase"; break; //a..z
        case 97 ... 122: type = "Lowercase"; break;

        default: type = "Character"; break;
    }

    return type;
}

//gcc -o out/operatorsSwitch src/operatorsSwitch.c  && out/operatorsSwitch
int main(int argc, char **argv) {

    for (int i = 0; i <= 127 ; i++) {
        printf("%d = %c %s \t", i, i, findCharType(i));

    }
}