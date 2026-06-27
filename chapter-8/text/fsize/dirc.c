#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>

#include "dirc.h"

// Open a directory for read_dir calls.
Dir* open_dir(char* dirname) {
    int fd;
    struct stat stbuf;
    Dir* dp;

    if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 || !S_ISDIR(stbuf.st_mode) ||
        (dp = (Dir*)(malloc(sizeof(Dir)))) == NULL) {
        return NULL;
    }
    dp->fd = fd;

    return dp;
}

// Close directory opened by opendir.
void close_dir(Dir* dp) {
    if (dp) {
        close(dp->fd);
        free(dp);
    }
}

// Read directory enteries in sequence.
DirEnt* read_dir(Dir* dp) {
    // Local directory structure.
    LinuxDirEnt* ld;
    // Portable directory structure.
    static DirEnt d;

    while (ld = read_dirent(dp->fd)) {
        // Slot is not in use.
        if (ld->d_ino == 0) {
            continue;
        }
        d.ino = ld->d_ino;
        strncpy(d.name, ld->d_name, NAMEMAX);
        // Ensure termination.
        d.name[NAMEMAX] = '\0';
        return &d;
    }
    return NULL;
}

LinuxDirEnt* read_dirent(int fd) {
    static int nread = 0;
    static int bpos = 0;
    static char buf[BUFSIZE];
    static LinuxDirEnt* d;

    if (nread == 0) {
        nread = syscall(SYS_getdents, fd, buf, BUFSIZE);
        if (nread == 0) {
            return NULL;
        }
        bpos = 0;
    } else {
        bpos += d->d_reclen;
    }
    d = (LinuxDirEnt*)(buf + bpos);
    nread -= d->d_reclen;

    return d;
}
