# Tips

The mechanics of how to compile and load a C program that resides on multiple source files depends on the compiler and the operating system.

For example, using the `gcc` compiler on GNU/Linux or Windows, the command

```bash
gcc main.c getline.c strindex.c -o main
```
    
compiles the three files, placing the resulting object code in files `main.o`, `getline.o`, and `strindex.o`, then loads them all into an executable file `main.out` on GNU/Linux and `main.exe` on Windows. If you want to compile all of the `.c` files in the current directory together just use

```bash
gcc *.c -o main
```
    
 If you want to get the object code of some of the source files then use

```bash
gcc -c getline.c strindex.c
```

If there is an error, say in `main.c`, that file can be recompiled by itself and the result can be loaded with the previous object files via the command

```bash
gcc main.c getline.o strindex.o -o main
```

The `gcc` command uses the `.c` versus `.o` naming convention to distinguish source files from object files. This is of cruicial importance if you have a lot of source files and you have modified only a few of them. Consequently, there is no need to recompile all of the files. Nowadays, no one even calls the compiler directly. Developers usually use `CMake` tools which automates the process of creating `makefile` and building a program.