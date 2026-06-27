/* This program sorts the lines of an input text lexiographically. */

#include <stdio.h>

#include "sort.h"

int main() {
    char* lineptr[MAXLINES];
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort.\n");
        return 1;
    }
}
