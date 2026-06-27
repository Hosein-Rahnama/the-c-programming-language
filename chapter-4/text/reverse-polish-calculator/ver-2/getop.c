#include <ctype.h>
#include <stdio.h>

/* Including this header file is mandatory here as this source file uses
   functions that are declared in it. */
#include "calc.h"

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    // If c is an operator return it.
    if (!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;
    // Collect integer part.
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }
    // Collect fraction part.
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}
