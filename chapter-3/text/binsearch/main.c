/* This program implements the binary search algorithm. The algorithm
   tries to find a specified element in a sorted array of integers.
   Here we assume that the array is sorted in increasing order. */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int v[] = {-9, -4, 0, 1, 4, 7, 8, 11, 25, 44};
    int x = 7;
    int n = sizeof(v) / sizeof(int);
    int index;

    index = binsearch(x, v, n);
    if (index >= 0) {
        printf("The index of %d in the given array is %d.", x, index);
    } else {
        printf("There was no occurence of %d in the given array.", x);
    }

    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            // Found a match.
            return mid;
        }
    }
    // Found no match.
    return -1;
}
