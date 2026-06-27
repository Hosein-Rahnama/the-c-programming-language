#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "usrio.h"

// RW permission for owner, group, and others.
#define PERMS 0666

// Initialize stdin, stdout, sterr in _iob.
FILE _iob[OPEN_MAX] = {
    {0, (char*)(0), (char*)(0), _READ, 0}, {0, (char*)(0), (char*)(0), _WRITE, 1},
    {0, (char*)(0), (char*)(0), _WRITE | _UNBUF, 2}
};

// Open file and return a file pointer.
FILE* fopen(char* name, char* mode) {
    int fd;
    FILE* fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
        return NULL;
    }
    // Find a free slot.
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
        if ((fp->flag & (_READ | _WRITE)) == 0) {
            break;
        }
    }
    // No free slots.
    if (fp >= _iob + OPEN_MAX) {
        return NULL;
    }

    if (*mode == 'w') {
        fd = creat(name, PERMS);
    } else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1) {
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2);
    } else {
        fd = open(name, O_RDONLY, 0);
    }

    // Could not access name.
    if (fd == -1) {
        return NULL;
    }
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;

    return fp;
}

// Allocate and fill input buffer.
int _fillbuf(FILE* fp) {
    int bufsize;

    if ((fp->flag & (_READ | _EOF | _ERR)) != _READ) {
        return EOF;
    }
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    // No buffer yet.
    if (fp->base == NULL) {
        // Allocate buffer and handle possible allocation failure.
        if ((fp->base = (char*)(malloc(bufsize))) == NULL) {
            return EOF;
        }
    }
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1) {
            fp->flag |= _EOF;
        } else {
            fp->flag |= _ERR;
        }
        fp->cnt = 0;

        return EOF;
    }

    return (unsigned char)(*fp->ptr++);
}
