/* This program concatenates a string to the end of another string, assuming that 
   the latter is big enough to include the former. */

#include <stdio.h>
#define MAXLEN 1000

void my_strcat(char s[], char t[]);

int main() {
    char s[MAXLEN] = "This is sample string.";
    char t[] = "This is the concatenated string.";

    my_strcat(s, t);

    printf("%s", s);

    return 0;
}

void my_strcat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    // Find end of s.
    while (s[i] != '\0') {
        i++;
    }
    // Copy t.
    while ((s[i++] = t[j++]) != '\0');
}
