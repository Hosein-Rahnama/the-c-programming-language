/* This program compares two strings lexiographically. */

#include <stdio.h>

int my_strcmp(char* s, char* t);

int main() {
    char* t = "This is a sample string.";
    char* s = "This is another string.";
    int flag = my_strcmp(s, t);

    if (flag > 0) {
        printf("s is greater than t.");
    } else if (flag < 0) {
        printf("s is less than t.");
    } else {
        printf("s and t are equal.");
    }

    return 0;
}

int my_strcmp(char* s, char* t) {
    int i;

    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }
    }

    return s[i] - t[i];
}
