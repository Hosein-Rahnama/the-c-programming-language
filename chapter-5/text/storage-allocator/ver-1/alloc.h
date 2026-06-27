/* #pragma once ensures that the header file is included only once. It does the
   same thing that we did with #ifndef, #define and #endif in the
   reverse-polish-calculator program. However, it has the advantage of not being
   worried about the uniqueness of the keyword included after #define. */

#pragma once

char* memalloc(int);
void memfree(char*);
int freespace(void);
