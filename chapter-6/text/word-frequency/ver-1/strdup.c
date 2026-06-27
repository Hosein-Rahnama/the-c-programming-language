#include <stdlib.h>
#include <string.h>

#include "util.h"

// Make a duplicate of s.
char* my_strdup(char* s) {
    char* p;
    // +1 for '\0' at the end of a string.
    p = (char*)(malloc(strlen(s) + 1));
    if (p != NULL) {
        strcpy(p, s);
    }

    return p;
}
