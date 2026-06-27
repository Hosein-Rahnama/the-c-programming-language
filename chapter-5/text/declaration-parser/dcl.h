#ifndef DCL
#define DCL

#define MAXTOKEN 100

enum {
    NAME,
    PARENS,
    BRACKETS
};

// Declare external variables.
extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];

// Declare functions.
void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int c);

#endif
