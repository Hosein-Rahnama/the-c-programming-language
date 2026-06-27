/* This program sorts an array of integers in increasing order. */

#include <stdio.h>

void shellsort(int v[], int n);
void printarr(int v[], int n);

int main() {
    int v[] = {10, -1, 2, 7, 4, 9, -5, 23, 13};
    int n = sizeof(v) / sizeof(int);

    printarr(v, n);
    shellsort(v, n);
    printarr(v, n);

    return 0;
}

void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

void printarr(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1) ? ", " : "\n");
    }
}
