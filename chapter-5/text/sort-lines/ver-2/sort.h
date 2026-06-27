#ifndef SORT
#define SORT

#define MAXLINES 5000
#define MAXLEN 1000

char* alloc(int n);
void afree(char* p);
int getline(char line[], int lim);
int readlines(char* lineptr[], int maxlines);
void writelines(char* lineptr[], int nlines);
void my_qsort(void* lineptr[], int left, int right, int (*comp)(void*, void*));
void swap(void* v[], int i, int j);
int numcmp(char* s1, char* s2);
int my_strcmp(char* s1, char* s2);

#endif
