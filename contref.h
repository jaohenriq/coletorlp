#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct gc* GC;

GC init();
void* malloc2(GC mem, size_t tam);
void* attrib(GC mem, void *orig, void *dest);
void dump(GC mem);
GC dealloc(GC mem);
