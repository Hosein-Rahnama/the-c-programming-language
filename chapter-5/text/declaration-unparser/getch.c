#include <stdio.h>

#include "undcl.h"

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

// Get a (possibly pushed back) character.
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// Push character back on input.
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters");
    } else {
        buf[bufp++] = c;
    }
}
