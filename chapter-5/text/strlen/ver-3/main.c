/* This program calculates the length of a string. */

#include <stdio.h>
#include <string.h>

size_t my_strlen(char* s);

int main() {
    char sample[] = "This is a string constant which is technically an array of characters";

    printf("Library: %d\n", strlen(sample));
    printf("Our Version: %d", my_strlen(sample));

    return 0;
}

/* The number of characters in the string could be too large to store in an int.
   So, we use size_t for the return type. size_t is the unsigned integer type
   returned by the sizeof operator. size_t is guaranteed to be big enough to
   contain the size of the biggest object the host system can handle. */
size_t my_strlen(char* s) {
    char* p = s;

    while (*p != '\0') {
        p++;
    }

    return p - s;
}
