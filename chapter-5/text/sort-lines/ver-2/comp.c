/* There is a qsort declared in stdlib.h. So, we had to rename our sorting
   function to my_qsort to prevent conflicts. */
#include <stdlib.h>

#include "sort.h"

// Compare two strings numerically.
int numcmp(char* s1, char* s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

// Compare two strings lexiographically.
int my_strcmp(char* s1, char* s2) {
    for (NULL; *s1 == *s2; s1++, s2++) {
        if (*s1 == '\0') {
            return 0;
        }
    }

    return *s1 - *s2;
}
