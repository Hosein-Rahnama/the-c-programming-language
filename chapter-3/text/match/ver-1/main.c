/* This program finds the first match in two integer arrays and returns
   the matched element and the corresponding indices. */

#include <stdio.h>

void match(int a[], unsigned int n, int b[], unsigned int m, int c[]);

int main() {
    int a[] = {-3, -5, -1, 0, 2, 1, 7};
    int b[] = {-7, 0, -4, 1, 6, 5, 3};
    unsigned int n = sizeof(a) / sizeof(int);
    unsigned int m = sizeof(b) / sizeof(int);
    int c[3] = {0, 0, 0};

    match(a, n, b, m, c);

    return 0;
}

void match(int a[], unsigned int n, int b[], unsigned int m, int c[]) {
    int i, j;

    /* We want to exit the nested for loops as soon as we find a match.
       The break statement won't work for this purpose. */
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                goto found;
            }
        }
    }
    // Found no common element.
    printf("There is no common element.");

// Record the indices of the matched elements.
found:
    c[0] = a[i];
    c[1] = i;
    c[2] = j;
    printf("The first matched element is %d and appears in a[%d] and b[%d].\n", c[0], c[1], c[2]);

    return;
}
