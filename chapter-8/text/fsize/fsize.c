#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include "dirc.h"
#include "fsize.h"

// Print size of a file.
void fsize(char* name) {
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: cannot access %s\n", name);
        return;
    }
    if (S_ISDIR(stbuf.st_mode)) {
        dirwalk(name, fsize);
        return;
    }
    printf("%8ld %s\n", stbuf.st_size, name);
}

// Apply fcn to all files in dir.
void dirwalk(char* dir, void (*fcn)(char*)) {
    char name[MAXPATH];
    DirEnt* dp;
    Dir* dfd;

    if ((dfd = open_dir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: cannot open %s\n", dir);
        return;
    }
    while ((dp = read_dir(dfd)) != NULL) {
        // Skip self and parent directories.
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0) {
            continue;
        }
        // Plus 2 accounts for for / and the null terminator.
        if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name)) {
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
        } else {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    close_dir(dfd);
}
