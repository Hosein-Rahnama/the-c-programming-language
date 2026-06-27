/* This program concatenates files and shows the result on the standard output. */

#include <stdio.h>

void filecopy(FILE*, FILE*);

int main(int argc, char* argv[]) {
    FILE* fp;

    // No args, copy strandard input.
    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                filecopy(fp, stdout);
                printf("\n");
                fclose(fp);
            }
        }
    }

    return 0;
}

// Copy file ifp to file ofp.
void filecopy(FILE* ifp, FILE* ofp) {
    int c;

    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}
