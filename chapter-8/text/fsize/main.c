/* This program prints sizes of all files within a directory, recursively. */

#include "fsize.h"

int main(int argc, char** argv) {
    // Default is the current directory.
    if (argc == 1) {
        fsize(".");
    } else {
        while (--argc > 0) {
            fsize(*++argv);
        }
    }

    return 0;
}
