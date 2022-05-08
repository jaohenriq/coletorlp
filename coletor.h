
#include <stdio.h>
#include <stdlib.h>
#define SIZE_HEAP 100

typedef struct structPoint {
    int select;
    struct structPoint *next;
    int value;
    
}   Point;

typedef struct {
    Point *heap[SIZE_HEAP];
    int size_heap;
}   Heap;

Heap *creatHeap();
