/* This program tries to simulate the fopen function of the standard library by
   using the low-level input and output interfaces provided by Linux. */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "usrio.h"
#include "util.h"

int main() {
    char c;
    char buf[10];
    char* endl = "\n";
    char* mode = "r";
    FILE* fp;

    if ((fp = fopen("input.txt", mode)) != NULL) {
        while ((c = getc(fp)) != EOF) {
            write(1, &c, 1);
        }
        write(1, endl, 1);
        write(1, endl, 1);

        print("File descriptor: ");
        itoa(fileno(fp), buf);
        write(1, buf, 1);
        write(1, endl, 1);

        print("End of file: ");
        itoa(feof(fp), buf);
        write(1, buf, 1);
        write(1, endl, 1);

        print("File error: ");
        itoa(ferror(fp), buf);
        write(1, buf, 1);
        write(1, endl, 1);
    } else {
        print("Error: could not open file.\n");
    }

    return 0;
}
