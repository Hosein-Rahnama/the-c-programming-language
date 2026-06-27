/* Functions' declaration and defines which are shared among other
   source files are gathered here. Notice how we have gaurded the
   header file to make sure that it is included only once. */

#ifndef CALC
#define CALC

#define NUMBER '0'

void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);

#endif
