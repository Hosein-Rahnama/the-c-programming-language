/* This program counts the number 1-bits in a given integer. */

#include <stdio.h>

int bitcount(unsigned int x);

int main() {
    printf("%d", bitcount(2023));

    return 0;
}

int bitcount(unsigned int x) {
    int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }

    return b;
}
