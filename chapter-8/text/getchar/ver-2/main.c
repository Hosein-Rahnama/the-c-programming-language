/* This program copies standard input to standard output. Here, we implement
   the getchar function the 'read' system call. This second version does input
   in big chunks and hands out the characters one at a time. */

#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 128

int my_getchar(void);

int main() {
    char c;

    while ((c = my_getchar()) != EOF) {
        putchar(c);
    }
    printf("\n");

    return 0;
}

// Simple buffered version.
int my_getchar(void) {
    static char buf[BUFSIZE];
    static char* bufp = buf;
    static int n = 0;

    // Buffer is empty.
    if (n == 0) {
        n = read(0, buf, sizeof(buf));
        bufp = buf;
    }

    return (--n >= 0) ? (unsigned char)(*bufp++) : EOF;
}
