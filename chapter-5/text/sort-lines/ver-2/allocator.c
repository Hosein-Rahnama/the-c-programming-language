#include <stdio.h>

#include "sort.h"

#define ALLOCSIZE (MAXLINES * MAXLEN)

static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

char* alloc(int n) {
    if ((allocbuf + ALLOCSIZE) - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return NULL;
    }
}

void afree(char* p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}
