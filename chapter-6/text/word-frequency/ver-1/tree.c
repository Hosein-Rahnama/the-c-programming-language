#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "util.h"

// Add a node with the word w at or below p.
struct tnode* addtree(struct tnode* p, char* w) {
    int cond;

    // A new word has arrived.
    if (p == NULL) {
        // Make a new node.
        p = talloc();
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        // Repeated word.
        p->count++;
    } else if (cond < 0) {
        // Less than, into the left subtree.
        p->left = addtree(p->left, w);
    } else {
        // Greater than, into the right subtree.
        p->right = addtree(p->right, w);
    }

    return p;
}

// In-order print of a tree with root p.
void treeprint(struct tnode* p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

// Make a tnode.
struct tnode* talloc(void) {
    return (struct tnode*)(malloc(sizeof(struct tnode)));
}
