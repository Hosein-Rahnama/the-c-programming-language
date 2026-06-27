/* This program is the recursive version of itoa given in Chapter 3. A slight
   difference is that we only print the digits and do not store them in a
   character array. */

#include <stdio.h>

void printd(int n);

int main() {
    int n = -42325;
    printd(n);

    return 0;
}

void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}
