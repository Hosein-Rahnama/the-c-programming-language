/* This program copies standard input to standard output. Here, we implement
   the getchar function by using 'read', a lower level system call. */

#include <stdio.h>
#include <unistd.h>

int my_getchar(void);

int main() {
    char c;

    while ((c = my_getchar()) != EOF) {
        putchar(c);
    }
    printf("\n");

    return 0;
}

// Unbuffered single character input.
int my_getchar(void) {
    // The cast to 'unsigned char' guarantees that no sign extension will occur.
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char)(c) : EOF;
}
