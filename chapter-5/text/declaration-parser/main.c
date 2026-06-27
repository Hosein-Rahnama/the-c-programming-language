/* This program converts declaration to word description. */

#include <stdio.h>
#include <string.h>

#include "dcl.h"

// Define external variables.
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main() {
    while (gettoken() != EOF) {
        // First token on a given line is the datatype.
        strcpy(datatype, token);
        out[0] = '\0';
        // Parse rest of the line.
        dcl();
        if (tokentype != '\n') {
            printf("syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }

    return 0;
}
