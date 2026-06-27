#ifndef TREE
#define TREE

struct tnode {
    char* word;
    int count;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* addtree(struct tnode*, char*);
void treeprint(struct tnode*);
struct tnode* talloc(void);

#endif
