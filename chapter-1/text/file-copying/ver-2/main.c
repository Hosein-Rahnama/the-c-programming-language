/* This program copies standard input to standard output. */

#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    printf("Recieved %d.", c);
}
