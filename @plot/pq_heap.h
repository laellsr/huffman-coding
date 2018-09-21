#ifndef PQ_HEAP
#define PQ_HEAP

#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 100000

typedef struct heap_node heap_node;
typedef struct heap heap;

heap* create_heap();
int is_heap_empty(heap *h);
void swap(heap *h, int a, int b);
int get_parent_index(heap *h, int i);
int get_left_index(heap *h, int i);
int get_right_index(heap *h, int i);
void max_heapify(heap *h, int i);
int item_of(heap *h, int i);
void heapsort(heap *h);
int enqueue_heap(heap *h, void* item, int priority);
int dequeue_heap(heap *h);
void print_heap(heap *h);

#endif
