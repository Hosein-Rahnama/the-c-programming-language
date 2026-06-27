#include <ctype.h>
#include <stdio.h>

#include "util.h"

/* A word is either a string of letters and digits beginning with a letter, or
   a single non-white space character. */
int getword(char* word, int lim) {
    int c;
    char* w = word;

    while (isspace(c = getch()));
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (NULL; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}
