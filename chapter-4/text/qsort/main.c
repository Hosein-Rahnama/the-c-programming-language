/* This program is a sorting algorithm known as quick sort. */

#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void printarr(int v[], int n);

int main() {
    int v[] = {10, -1, 2, 7, 4, 9, -5, 23, 13};
    int n = sizeof(v) / sizeof(int);

    printarr(v, n);
    qsort(v, 0, n - 1);
    printarr(v, n);

    return 0;
}

void qsort(int v[], int left, int right) {
    int i, last;

    // Do nothing if array contains fewer than two elements.
    if (left >= right) {
        return;
    }
    // Move the partition element to v[0].
    swap(v, left, (left + right) / 2);
    // Partition.
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    // Restore partition element.
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void printarr(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1) ? ", " : "\n");
    }
}
