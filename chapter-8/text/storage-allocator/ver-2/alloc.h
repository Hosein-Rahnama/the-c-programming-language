#ifndef ALLOC
#define ALLOC

#define NALLOC 1024

typedef long int Align;

union header {
    struct {
        union header* ptr;
        unsigned int size;
    } s;
    Align x;
};

typedef union header Header;

void* memalloc(unsigned int);
void memfree(void*);
int freespace(void);
static Header* morecore(unsigned int);

#endif
