/* This program removes trailing blanks, tabs, and newlines from a string. */

#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main() {
    char s[] = "This is a sample string with trailing white spaces.  \t   ";

    printf("%s|\n", s);
    trim(s);
    printf("%s|", s);

    return 0;
}

int trim(char s[]) {
    int n;

    for (n = strlen(s) - 1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') {
            break;
        }
    }
    s[n + 1] = '\0';

    return n;
}
