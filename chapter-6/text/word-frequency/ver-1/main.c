/* This program calculates the frequency of words that appear in a given input text. */

#include <ctype.h>
#include <stdio.h>

#include "tree.h"
#include "util.h"

#define MAXWORD 100

int main() {
    struct tnode* root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);

    return 0;
}
