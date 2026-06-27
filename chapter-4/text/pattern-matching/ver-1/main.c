/* This program finds a specified pattern in a given string. The emphasize is
   on breaking a large programm into smaller pieces by using functions. */

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int lim);
int strindex(char text[], char pattern[]);

int main() {
    char line[MAXLINE];
    char pattern[] = "ould";
    int found = 0;

    while (getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }

    // The environment that calls this program can use the number of matched patterns.
    return found;
}

// Read a line and return its length.
int getline(char line[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';

    return i;
}

// Find the first match of a given pattern within a text.
int strindex(char text[], char pattern[]) {
    int i, j, k;
    for (i = 0; text[i] != '\0'; i++) {
        for (j = i, k = 0; pattern[k] != '\0' && text[j] == pattern[k]; j++, k++);
        if (k > 0 && pattern[k] == '\0') {
            return i;
        }
    }
    return -1;
}
