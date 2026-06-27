/* This program extracts a specified number of contiguous bits from a given integer. */

#include <limits.h>
#include <stdio.h>

unsigned int getbits(unsigned int x, unsigned int p, unsigned int n);
void putbits(unsigned int x);
int getbit(unsigned int x, unsigned int i);

int main() {
    unsigned int bits = getbits(2023, 6, 4);
    putbits(2023);
    putbits(bits);

    return 0;
}

unsigned int getbits(unsigned x, unsigned int p, unsigned int n) {
    return (x >> (p - n + 1)) & ~(~0 << n);
}

void putbits(unsigned int x) {
    unsigned int max = sizeof(x) * CHAR_BIT;
    // Try making this into an unsigned int. What happens?
    int i;

    for (i = max - 1; i >= 0; i--) {
        putchar('0' + getbit(x, i));
    }
    printf("\n");
}

int getbit(unsigned int x, unsigned int i) {
    return (x >> i) & 1;
}
