/* This program converts a number stored as a character array to an integer. The 
   function name 'atoi' is an abbreviation for ASCII to integer. A more general 
   version of this program is given in Chapter 3. */

#include <stdio.h>

int my_atoi(char s[]);

int main() {
    char s[] = "129875245";

    printf("%d", my_atoi(s));

    return 0;
}

int my_atoi(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = 10 * n + (s[i] - '0');
    }

    return n;
}
