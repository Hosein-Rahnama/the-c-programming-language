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
    int i, j, found = 0;

    /* We want to exit the nested for loops as soon as we find a match. Here, we
       avoid using goto with the cost of some extra checks. */
    found = 0;
    for (i = 0; i < n && !found; i++) {
        for (j = 0; j < m && !found; j++) {
            if (a[i] == b[j]) {
                found = 1;
            }
        }
    }
    if (found) {
        c[0] = a[i - 1];
        c[1] = i - 1;
        c[2] = j - 1;
        printf("The first matched element is %d and appears in a[%d] and b[%d].\n", c[0], c[1], c[2]);
    } else {
        printf("There is no common element.");
    }

    return;
}
