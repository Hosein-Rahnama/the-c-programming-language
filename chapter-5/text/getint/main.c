/* This program converts a free-format input, which is a string containing
   integers, to several integers. More specifically, getint returns one of
   the integers per call. As an example, given the string
   "    14151 -1515+2352 2351-123 13  " as input, the program returns the
   numbers 14151, -1515, 2352, 2351, -123, 13. */

#include <ctype.h>
#include <stdio.h>

#define SIZE 100

int getint(int*);
int getch(void);
void ungetch(int);

int main() {
    int n, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
        printf("Integer %d: %d\n", n, array[n]);
    }

    return 0;
}

/* Get next integer from input into *pn. Returns EOF for end of file, zero if
   the next input is not a number, and a positive value if the input contains
   a valid number. */
int getint(int* pn) {
    int c, sign;

    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

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
