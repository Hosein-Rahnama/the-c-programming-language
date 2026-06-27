/* This program implements some functions for inputing and outputing lines. */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

char* my_fgets(char*, int, FILE*);
int my_fputs(char*, FILE*);
int getline(char*, int);

int main() {
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0) {
        my_fputs(line, stdout);
    }

    return 0;
}

// Get a line of at most n characters from iop and copy it into s.
char* my_fgets(char* s, int n, FILE* iop) {
    register int c;
    register char* cs;

    cs = s;
    while (--n > 0 && (c = getc(iop)) != EOF) {
        if ((*cs++ = c) == '\n') {
            break;
        }
    }
    *cs = '\0';

    return (c == EOF && cs == s) ? NULL : s;
}

// Put string s on file iop.
int my_fputs(char* s, FILE* iop) {
    int c;

    while (c = *s++) {
        putc(c, iop);
    }

    return ferror(iop) ? EOF : 0;
}

// Read a line from standard input and return its length.
int getline(char* line, int max) {
    if (my_fgets(line, max, stdin) == NULL) {
        return 0;
    } else {
        return strlen(line);
    }
}
