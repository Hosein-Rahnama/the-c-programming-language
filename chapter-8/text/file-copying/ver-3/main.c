/* This program copies standard input to standard output. */

#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 128

int main() {
    char buf[BUFSIZE];
    int n;

    while ((n = read(0, buf, BUFSIZE)) > 0) {
        write(1, buf, n);
    }
    printf("\n");

    return 0;
}
