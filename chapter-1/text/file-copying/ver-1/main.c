/* This program copies standard input to standard output. */

#include <stdio.h>

int main() {
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    printf("Recieved %d.", c);
}
