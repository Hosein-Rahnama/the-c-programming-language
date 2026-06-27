#include <ctype.h>
#include <string.h>

#include "dcl.h"

// Return next tokentype and save the recieved token.
int gettoken(void) {
    int c;
    char* p = token;

    while ((c = getch()) == ' ' || c == '\t');
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            strcpy(token, "(");
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; NULL);
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); NULL) {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else {
        *p++ = c;
        *p = '\0';
        return tokentype = c;
    }
}
