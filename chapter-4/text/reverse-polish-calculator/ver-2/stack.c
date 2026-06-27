#include <stdio.h>

/* Including this header file is optional here but we did this to
   ensure that the functions declarations match their definitions. */
#include "calc.h"

#define MAXVAL 100

/* Declaing these external varialbes as static limits their scope to the
   rest of this source file. */
static int sp = 0;
static double val[MAXVAL];

// Push f onto value stack.
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

// Pop and return top value from stack.
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
