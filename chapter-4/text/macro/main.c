/* This program shows some applications of macros. */

#include <stdio.h>

#define max(A, B) ((A) > (B) ? (A) : (B))
#define dprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front##back

int main() {
    double x = -3, y = 5, xy, z;
    xy = x * y;
    z = max(x + y, x - y);

    printf("x * y = %f\n", paste(x, y));
    dprint(z / y);

    return 0;
}
