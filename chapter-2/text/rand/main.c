/* This program generates a pseudo-random integer in [0..32767]. */

#include <stdio.h>
#include <time.h>

unsigned long int next = 1;

void srand(unsigned int seed);
int rand(void);

int main() {
    srand(time(NULL));
    for (int i = 1; i <= 5; i++) {
        printf("pseudo-random integer %d is: %d.\n", i, rand());
    }

    return 0;
}

void srand(unsigned int seed) {
    next = seed;
}

int rand() {
    int rand_num;

    next = next * 1103515245 + 12345;
    rand_num = (unsigned int)(next / 65536) % 32768;

    return rand_num;
}
