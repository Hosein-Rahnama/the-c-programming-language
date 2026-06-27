#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

static struct nlist* hashtab[HASHSIZE];

// Form hash value for string s.
unsigned int hash(char* s) {
    unsigned int hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

// Look for s in hash table.
struct nlist* lookup(char* s) {
    struct nlist* np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            // Found.
            return np;
        }
    }
    // Not found.
    return NULL;
}

// Put (name, defn) in hash table.
struct nlist* install(char* name, char* defn) {
    struct nlist* np;
    unsigned int hashval;

    // Not found.
    if ((np = lookup(name)) == NULL) {
        // Get the required storage.
        np = (struct nlist*)(malloc(sizeof(*np)));
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        // Add the new entry to the hash table.
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    // Already there.
    else {
        // Free previous definition.
        free((void*)(np->defn));
    }
    if ((np->defn = strdup(defn)) == NULL) {
        return NULL;
    }

    return np;
}

// Print the hash table.
void print_table(void) {
    int n;
    struct nlist* p;

    for (n = 0; n < HASHSIZE; n++) {
        if (hashtab[n] != NULL) {
            printf("No: %2d\t", n);
            for (p = hashtab[n]; p != NULL; p = p->next) {
                printf("(%s, %s) -> ", p->name, p->defn);
            }
            printf("NULL\n");
        }
    }
}

// Initialize the hash table with NULL pointers.
void init_table(void) {
    int n;

    for (n = 0; n < HASHSIZE; n++) {
        hashtab[n] = (struct nlist*)(NULL);
    }
}
