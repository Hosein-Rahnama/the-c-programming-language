/* This program shows the longest line of an input. */

#include <stdio.h>
#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline(void);
void copy(void);

int main() {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getline()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) {
        printf("The longest line has %d characters and is given below.\n", max);
        printf("%s", longest);
    }

    return 0;
}

// Read a line and return its length.
int getline(void) {
    int c, i;

    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}

// Copy 'line' into 'longest' assuming that 'longest' is big enough.
void copy(void) {
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') {
        i++;
    }
}
