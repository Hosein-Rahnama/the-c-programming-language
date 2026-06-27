#ifndef TREE
#define TREE

typedef struct tnode* Treeptr;

typedef struct tnode {
    char* word;
    int count;
    Treeptr left;
    Treeptr right;
} Treenode;

Treeptr addtree(Treeptr, char*);
void treeprint(Treeptr);
Treeptr talloc(void);

#endif
