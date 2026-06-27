#ifndef DIRC
#define DIRC

#include <fcntl.h>

#define BUFSIZE 48
#define NAMEMAX 256

typedef struct linux_dirent {
    long d_ino;
    off_t d_off;
    unsigned short d_reclen;
    char d_name[];
} LinuxDirEnt;

typedef struct {
    long ino;
    char name[NAMEMAX + 1];
} DirEnt;

typedef struct {
    int fd;
    DirEnt d;
} Dir;

Dir* open_dir(char*);
DirEnt* read_dir(Dir*);
LinuxDirEnt* read_dirent(int);
void close_dir(Dir*);

#endif
