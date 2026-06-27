#ifndef HASH
#define HASH

#define HASHSIZE 101

struct nlist {
    struct nlist* next;
    char* name;
    char* defn;
};

unsigned int hash(char*);
struct nlist* lookup(char*);
struct nlist* install(char*, char*);
void print_table(void);
void init_table(void);

#endif
