/* This program copies a string. */

#include <stdio.h>

#define SIZE 1000

void my_strcpy(char* s, char* t);

int main() {
    char* t = "This is a sample string.";
    char s[SIZE];

    printf("Address of t: %p\n", t);
    printf("%s\n", t);

    my_strcpy(s, t);
    printf("Address of s: %p\n", s);
    printf("%s", s);

    return 0;
}

void my_strcpy(char* s, char* t) {
    int i;

    i = 0;
    while (*s++ = *t++);
}
