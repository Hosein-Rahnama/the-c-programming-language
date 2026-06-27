/* This program implements a hash table which is a very common data structure used
   in the symbol table management routines of a macro processor or a compiler. */

#include <stdio.h>
#include <string.h>

#include "hash.h"

#define SIZE 100

int sum_char(char* s);

int main() {
    struct nlist* p;
    char* key[] = {
        "HASH", "IN", "OUT", "TABLE", "MAX", "MIN", "SIZE", "LENGTH", "BUFF", "PI", "BACK", "FRONT", "CALC", "RED",
        "GREEN", "BLUE", "DAY", "NIGHT", "WEEK", "YEAR"
    };
    char value[SIZE];
    int n = sizeof(key) / sizeof(char*);

    init_table();
    for (int i = 0; i < n; i++) {
        sprintf(value, "%d", sum_char(key[i]));
        install(key[i], value);
    }
    print_table();

    printf("\n");
    p = lookup("HASH");
    printf("Key: %7s, Value: %3s\n", p->name, p->defn);
    p = lookup("TABLE");
    printf("Key: %7s, Value: %3s\n", p->name, p->defn);

    return 0;
}

int sum_char(char* s) {
    int sum = 0;

    for (NULL; *s != '\0'; s++) {
        sum += *s;
    }

    return sum;
}
