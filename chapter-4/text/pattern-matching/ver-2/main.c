/* This program finds a specified pattern in a given string. The emphasize is
   on breaking a large programm into smaller pieces by using functions. Here,
   we have splitted the program into several source files. */

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
