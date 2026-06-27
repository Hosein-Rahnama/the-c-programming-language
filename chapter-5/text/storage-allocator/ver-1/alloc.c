#include <stdio.h>

#include "alloc.h"

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

char* memalloc(int n) {
    if ((allocbuf + ALLOCSIZE) - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return NULL;
    }
}

void memfree(char* p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

int freespace() {
    return allocbuf + ALLOCSIZE - allocp;
}
