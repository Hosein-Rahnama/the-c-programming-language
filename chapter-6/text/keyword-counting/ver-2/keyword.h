#ifndef KEYWORD
#define KEYWORD

struct key {
    char* word;
    int count;
};

int getword(char*, int);
struct key* binsearch(char*, struct key*, int);
int getch(void);
void ungetch(int);

#endif
