#ifndef UNDCL
#define UNDCL

#define MAXTOKEN 100

enum {
    NAME,
    PARENS,
    BRACKETS
};

// Declare external variables.
extern int tokentype;
extern char token[];
extern char out[];

// Declare functions.
int gettoken(void);
int getch(void);
void ungetch(int c);

#endif
