/* This program sorts the lines of an input text numerically or lexiographically. */

#include <stdio.h>
#include <string.h>

#include "sort.h"

int main(int argc, char* argv[]) {
    char* lineptr[MAXLINES];
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        my_qsort((void**)(lineptr), 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : my_strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort.\n");
        return 1;
    }
}
