/* This program converts an uppercase character to a lowercase character. */

#include <ctype.h>
#include <stdio.h>

int main() {
    char c;

    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }

    return 0;
}
