#include <stdio.h>

/* Including this header file is optional here but we did this to
   ensure that the functions declarations match their definitions. */
#include "calc.h"

#define BUFSIZE 100

/* Declaing these external varialbes as static limits their scope to the
   rest of this source file. */
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
