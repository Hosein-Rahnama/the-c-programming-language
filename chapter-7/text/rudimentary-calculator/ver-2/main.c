/* This is a rudimentary calculator which reads one number per line and adds
   them up, printing the running sum after each input. */

#include <stdio.h>

int main() {
    double sum, v;
    int rounded_sum;

    sum = rounded_sum = 0;
    while (scanf("%lf", &v) == 1) {
        printf("\tsum: %g\n", sum += v);
        printf("\trounded sum: %d\n", rounded_sum += v);
    }

    return 0;
}
