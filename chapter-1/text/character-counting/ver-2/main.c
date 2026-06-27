/* Count characters in input. */

#include <stdio.h>

int main() {
    double nc;

    for (nc = 0; getchar() != EOF; nc++);

    printf("%.0f", nc);

    return 0;
}
