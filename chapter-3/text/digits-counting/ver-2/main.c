/* This program counts the number of digits, white spaces and other characters in 
   the input. This is a second version of the program given in Chapter 1. */

#include <stdio.h>

int main() {
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                ndigit[c - '0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }

    for (i = 0; i < 10; i++) {
        printf("Occurrences of %d: ", i);
        printf(" %d\n", ndigit[i]);
    }
    printf("White Space: %d\n", nwhite);
    printf("Other: %d\n", nother);

    return 0;
}
