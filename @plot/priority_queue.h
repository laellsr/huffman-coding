#ifndef P_QUEUE
#define P_QUEUE

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct priority_queue priority_queue;

priority_queue* create_priority_queue();
int is_empty(priority_queue *pq);
void enqueue(priority_queue *pq, void *i, int p);
node* dequeue(priority_queue *pq);
int maximum(priority_queue *pq);
void print_priority_queue(priority_queue *pq);

#endif
