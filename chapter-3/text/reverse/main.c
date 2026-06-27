/* This program reverses a string in place. This shows an application
   of the comma operator whitin a for loop. */

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main() {
    char s[] = "This is a sample string.";

    reverse(s);
    printf("%s", s);

    return 0;
}

void reverse(char s[]) {
    int c, i, j;

    // Using the comma operator, we can have several expressions in each part of the for loop.
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
