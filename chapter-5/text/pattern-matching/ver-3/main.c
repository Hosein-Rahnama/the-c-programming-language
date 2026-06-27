/* This program finds a specified pattern in a given string. */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char* line, int max);

int main(int argc, char* argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2) {
        printf("Usage: find pattern");
    } else {
        while (getline(line, MAXLINE) > 0) {
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
        }
    }

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
