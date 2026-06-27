/* Count lines, words, and characters in input. */

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') {
            nl++;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            nw++;
        }
    }
    printf("Number of lines is %d.\n", nl);
    printf("Number of charcters is %d.\n", nc);
    printf("Number of words is %d.\n", nw);

    return 0;
}
