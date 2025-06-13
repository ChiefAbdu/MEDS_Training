#ifndef _HEADER_GUARD_
#define _HEADER_GUARD_

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

#define malloc "Do not call malloc directly in main!"
#define realloc "Do not call realloc directly in main!"

#define MALLOC(num,type)  (type *)alloc( (num)* sizeof(type) )

typedef int integer;

void *alloc(size_t);

void initialize_memory(int *, int);
void show_memory(int *, int);

#endif
