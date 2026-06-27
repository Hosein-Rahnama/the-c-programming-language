/* This program concatenates files and shows the result on the standard output.
   In this second version, we do a better job of error handling. */

#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE*, FILE*);

int main(int argc, char* argv[]) {
    FILE* fp;
    // Program name for errors.
    char* prog = argv[0];

    // No args, copy standard input.
    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                printf("\n");
                fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }

    exit(0);
}

// Copy file ifp to file ofp.
void filecopy(FILE* ifp, FILE* ofp) {
    int c;

    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}
