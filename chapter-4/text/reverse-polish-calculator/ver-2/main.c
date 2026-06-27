/* This is a calculator that takes inputs in reverse polish notation. Here,
   we have splitted the program into several source files. We also take
   advantage of header file for centeralizing definitions and declarations. This
   also gives us the garauntee that the functions declations and definitions match. */

#include <stdio.h>
#include <stdlib.h>

/* Including this header file is mandatory here as this source file uses
   functions that are declared in it. */
#include "calc.h"

#define MAXOP 100

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("\t%.8g\n", pop());
                }
                break;
            case '\n':
                printf("\tans = %f\n", pop());
                printf("Enter a new expression or finish the program.\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}
