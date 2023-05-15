#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int Data;
typedef struct
{
    Data *vec; //vectorul in care stochez elementele colectiei
    int size, capacity; // size – cate elemente exista la un moment dat
//capacity – nr. max de elemente ce pot sa fie stocate
//int type; //min sau max – poate sa lipseasca
} Heap;

///1
Heap * create (int capacitate /*, int heap_type*/);

///2
void resize(Heap *h);

///3
void delete (Heap**h);

///4
void printHeap(Heap *h);

///5
int parent(Heap *h, int i);

int leftChild(Heap *h,int i);

int rightChild(Heap *h,int i);

///6
Data min(Heap *h);

///7
void heapify_down(Heap *h, int i);

///8
void heapify_up(Heap *h, int i);

///9
void insert (Heap *h, Data x);

///10
void deleteRoot(Heap *h, int n);

///11
void heapsort(Heap *h, Data *buf, int n);

void populateHeap ( Heap * h, Data *buf, int n);

#endif
