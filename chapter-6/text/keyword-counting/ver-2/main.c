/* This program counts the occurences of each C keyword in a given input. This
   second version illustrate the usage of pointers to structrues. */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "keyword.h"

#define MAXWORD 100
#define NKEYS (sizeof(keytab) / sizeof(struct key))

// Sorted array of C keywords.
struct key keytab[] = {
    {"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0}, {"const", 0}, {"continue", 0}, {"default", 0}, {"for", 0},
    {"return", 0}, {"signed", 0}, {"unsigned", 0}, {"void", 0}, {"volatile", 0}, {"while", 0}
};

int main() {
    struct key* p;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((p = binsearch(word, keytab, NKEYS)) != NULL) {
                p->count++;
            }
        }
    }
    for (p = keytab; p < keytab + NKEYS; p++) {
        if (p->count > 0) {
            printf("%4d %s\n", p->count, p->word);
        }
    }

    return 0;
}
