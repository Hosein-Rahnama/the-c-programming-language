/* This program reads date from input given in two possible formats. */

#include <stdio.h>

#define MAXLINE 100

int getline(char*, int);

int main() {

    int day, month, year;
    char monthname[20];
    char line[MAXLINE];

    while (getline(line, sizeof(line))) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {
            printf("valid: %s\n", line);
        } else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
            printf("valid: %s\n", line);
        } else {
            printf("invalid: %s\n", line);
        }
    }

    return 0;
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
