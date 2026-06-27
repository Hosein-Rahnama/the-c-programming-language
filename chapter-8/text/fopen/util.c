#include <string.h>
#include <unistd.h>

#include "util.h"

void itoa(int n, char* s) {
    int i = 0, sign = n;

    // Make n positive if it is negative.
    if (sign < 0) {
        n = -n;
    }
    // Genrate digits in reverse order.
    do {
        s[i++] = n % 10 + '0';
        n /= 10;
    } while (n > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char* s) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void print(char* message) {
    write(1, message, strlen(message));
}
