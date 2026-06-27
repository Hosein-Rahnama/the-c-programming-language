/* This program reads any number of bytes from an arbitrary place in a file. */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 100

int get(int fd, long pos, char* buf, int n);

int main() {
    char buf[BUFSIZE];
    int n = 50;
    int fd = open("input.txt", O_RDONLY, 0);

    if (fd >= 0 && get(fd, 9, buf, n) >= 0) {
        buf[n] = '\0';
        printf("%s\n", buf);
    } else {
        printf("Error: unsuccessful read.\n");
    }

    return 0;
}

// Read n bytes from position pos.
int get(int fd, long pos, char* buf, int n) {
    if (lseek(fd, pos, 0) >= 0) {
        return read(fd, buf, n);
    } else {
        return -1;
    }
}
