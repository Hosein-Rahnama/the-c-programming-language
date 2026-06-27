#include <string.h>

#include "keyword.h"

struct key* binsearch(char* word, struct key tab[], int n) {
    int cond;
    struct key* low = &tab[0];
    struct key* high = &tab[n];
    struct key* mid;

    while (low < high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0) {
            high = mid;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return NULL;
}
