/* This program shows some applications of the ternary operator. */

#include <stdio.h>
#define SIZE 44

double max(double x, double y);

int main() {
    double x = 23.235;
    double y = -534.6632;
    printf("Maximum of %f and %f is %f.\n", x, y, max(x, y));

    int i;
    int a[SIZE];
    for (i = 0; i < SIZE; i++) {
        a[i] = i + 1;
    }
    for (i = 0; i < SIZE; i++) {
        printf("%6d%c", a[i], (i % 10 == 9 || i == SIZE - 1) ? '\n' : ' ');
    }

    int n = 1;
    printf("You have %d item%s.", n, (n == 1) ? "" : "s");

    return 0;
}

double max(double x, double y) {
    return (x > y) ? x : y;
}
