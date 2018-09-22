#ifndef HEAP_H
#define HEAP_H

#include "../@functions/default.h"
#include "binary_tree.h"

#define MAX_HEAP_SIZE 257

typedef struct heap heap;

heap* create_heap();
void enqueue(heap* hp, binary_tree* new_bt);
binary_tree* dequeue(heap *heap);
int get_parent_index(int i);
int get_left_index(int i);
int get_right_index(int i);
void min_heapify(heap *heap, int index);
int get_heap_size(heap* heap);
void print_heap(heap* heap);
void build_minheap(heap *heap);

#endif
