/* This program removes all occurrences of a specified character from a given string. */

#include <stdio.h>

void squeeze(char s[], char c);

int main() {
    char s[] = "This is a sample string constant.";
    char c = 't';

    squeeze(s, c);
    printf("%s", s);

    return 0;
}

void squeeze(char s[], char c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
