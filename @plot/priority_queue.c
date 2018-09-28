#include "priority_queue.h"

struct node
{
	void* item;
	int priority;
	node *next;
};

struct priority_queue
{
	node *head;
};

/* cria fila vazia */
priority_queue* create_priority_queue()
{
	priority_queue *new_pq = (priority_queue*)malloc(sizeof(priority_queue));
	new_pq->head = NULL;
	return new_pq;
}

/* verifica se a fila está vazia */
int is_queue_empty(priority_queue *pq)
{
	return (pq->head == NULL);
}

/* adiciona um nó na fila e retorna o número de comparações que foram necessárias para inserí-lo */
int enqueue(priority_queue *pq, void *i, int p)
{
	node *new_node = (node*) malloc(sizeof(node));
	int comparisons = 1;
	new_node->item = i;
	new_node->priority = p;
	if((is_queue_empty(pq)) || (p > pq->head->priority)) 
	{
		new_node->next = pq->head;
		pq->head = new_node;
	} 
	else 
	{
		node *current = pq->head;
		while ((current->next != NULL) && (current->next->priority > p)) 
		{
			comparisons++;
			current = current->next;
		}
		comparisons++;
		new_node->next = current->next;
		current->next = new_node;
	}
	return comparisons;
}

/* remove da fila o nó de maior prioridade */
node* dequeue(priority_queue *pq)
{
	if(is_queue_empty(pq)) 
	{
		printf("Priority Queue underflow");
		return NULL;
	} 
	else 
	{
		node *node = pq->head;
		pq->head = pq->head->next;
		node->next = NULL;
		return node;
	}
}

/* retorna o valor do nó de maior prioridade */
int maximum(priority_queue *pq)
{
	if(is_queue_empty(pq)) 
	{
		printf("Priority Queue underflow");
		return -1;
	} 
	else 
	{
		return *(int*)pq->head->item;
	}
}

/* imprime a fila */
void print_priority_queue(priority_queue *pq)
{
	node *temp = pq->head;
	while(temp != NULL)
	{
		printf("%d\n", *(int*)temp->item);
		temp = temp->next;
	}
}
