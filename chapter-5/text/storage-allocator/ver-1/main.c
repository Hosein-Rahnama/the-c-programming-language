/* This program manages a contiguous memory with a limited stack-oriented
   appoarch. A more general version is given in Chapter 8. */

#include <stdio.h>
#include <string.h>

#include "alloc.h"

int main() {
    int i, n;
    char* s;

    s = "I am learning C.";
    n = strlen(s);
    char* p = memalloc(n + 1);
    if (p == NULL) {
        printf("Not enough space for storing p.\n");
    } else {
        for (i = 0; i < n; i++) {
            p[i] = s[i];
        }
        p[i] = '\0';
        puts(p);
    }

    s = "Awesome!";
    n = strlen(s);
    char* q = memalloc(n + 1);
    if (q == NULL) {
        printf("Not enough space for storing q.\n");
    } else {
        for (i = 0; i < n; i++) {
            q[i] = s[i];
        }
        q[i] = '\0';
        puts(q);
    }

    // The order of freeing should be opposite to that of allocating.
    printf("Available space is %d bytes.\n", freespace());
    memfree(q);
    printf("Available space is %d bytes.\n", freespace());
    memfree(p);
    printf("Available space is %d bytes.\n", freespace());

    return 0;
}
