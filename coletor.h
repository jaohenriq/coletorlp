
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

void pushPoint(Heap *heap, Point *point);

Objeto *pop(Heap *heap);

void mark(Point *point);

void mark_heap(Heap *heap);

void sweep(Heap *heap);

void coletor(Heap *heap);

Objeto *criaObj(Heap *heap);

void push(Heap *heap, int val);

void freeheap(Heap *heap);
