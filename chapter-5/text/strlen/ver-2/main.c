/* This program calculates the length of a string. */

#include <stdio.h>
#include <string.h>

int my_strlen(char* s);

int main() {
    char sample[] = "This is a string constant which is technically an array of characters";

    printf("Library: %d\n", strlen(sample));
    printf("Our Version: %d", my_strlen(sample));

    return 0;
}

int my_strlen(char* s) {
    int n;

    for (n = 0; *s != '\0'; s++) {
        n++;
    }

    return n;
}
