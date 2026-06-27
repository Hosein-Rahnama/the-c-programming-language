#ifndef KEYWORD
#define KEYWORD

struct key {
    char* word;
    int count;
};

int getword(char*, int);
int binsearch(char*, struct key*, int);
int getch(void);
void ungetch(int);

#endif
