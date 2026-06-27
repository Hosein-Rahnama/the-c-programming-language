/* This program calculates the frequency of words that appear in a given input
   text. In this second version, we show how typedef can be used for declaratoin
   of complex types. Check out 'tree.h' and 'tree.c' for more details. */

#include <ctype.h>
#include <stdio.h>

#include "tree.h"
#include "util.h"

#define MAXWORD 100

int main() {
    Treeptr root;
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
