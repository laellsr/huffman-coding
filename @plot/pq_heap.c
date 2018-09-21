#include "pq_heap.h"

struct heap_node
{
	void* item;
	int priority;
};

struct heap
{
	int size;
	heap_node *data[MAX_HEAP_SIZE];
};

/* cria heap vazia */
heap* create_heap()
{
	heap *new_heap = (heap*)malloc(sizeof(heap));
	int i;
	for(i = 0; i < MAX_HEAP_SIZE; i++)
	{
		new_heap->data[i] = NULL;
	}
	new_heap->size = 0;
	return new_heap;
}

/* verifica se a heap está vazia */
int is_heap_empty(heap *h)
{
	return (h->size == 0);
}

/* troca o conteúdo de dois nós da heap */
void swap(heap *h, int a, int b)
{
	int temp_p = h->data[a]->priority;
	h->data[a]->priority = h->data[b]->priority;
	h->data[b]->priority = temp_p;
	int *temp_i = h->data[a]->item;
	h->data[a]->item = h->data[b]->item;
	h->data[b]->item = temp_i;
}

/* retorna o índice do pai do nó i */
int get_parent_index(heap *h, int i)
{
	return (i >> 1);
}

/* retorna o índice do filho da esquerda do nó i */
int get_left_index(heap *h, int i)
{
	return (i << 1);
}

/* retorna o índice do filho da direita do nó i */
int get_right_index(heap *h, int i)
{
	return((i << 1) + 1);
}

/* dado uma árvore que é uma max-heap, exceto pelo nó i, arruma o nó i e suas sub-árvores de modo que a propriedade da heap seja satisfeita */
void max_heapify(heap *h, int i)
{
	int largest;
	int left_index = get_left_index(h, i);
	int right_index = get_right_index(h, i);

	if(left_index <= h->size && h->data[left_index]->priority > h->data[i]->priority)
	{
		largest = left_index;
	}
	else
	{
		largest = i;
	}

	if(right_index <= h->size && h->data[right_index]->priority > h->data[largest]->priority)
	{
		largest = right_index;
	}

	if(h->data[i]->priority != h->data[largest]->priority)
	{
		swap(h, i, largest);
		max_heapify(h, largest);
	}
}

/* retorna o item do nó i */
int item_of(heap *h, int i)
{
	return *(int*)h->data[i]->item;
}

/* ordena o array da heap em ordem crescente */
void heapsort(heap *h)
{
	int i;

	for(i = h->size; i >= 2; i--)
	{
		swap(h, 1, i);
		h->size--;
		max_heapify(h, 1);
	
	}
}

/* adiciona um nó na heap e retorna o número de comparações que foram necessárias */
int enqueue_heap(heap *h, void* item, int priority)
{
	int comparisons = 0;
	if(h->size >= MAX_HEAP_SIZE)
	{
		comparisons++;
		printf("Heap overflow\n");
	}
	else
	{
		if(h->data[++h->size] == NULL)
		{
			h->data[h->size] = (heap_node*)malloc(sizeof(heap_node));
		}

		int *aux = (int*)malloc(sizeof(int));
		*aux = *(int*)item;
		h->data[h->size]->item = aux;
		h->data[h->size]->priority = priority;

		int key_index = h->size;
		int parent_index = get_parent_index(h, h->size);

		while(parent_index >= 1 && h->data[key_index]->priority > h->data[parent_index]->priority)
		{
			comparisons++;
			swap(h, key_index, parent_index);
			key_index = parent_index;
			parent_index = get_parent_index(h, key_index);
		}
		comparisons++;
	}
	return comparisons;
}

/* remove uda heap o nó de maior prioridade */
int dequeue_heap(heap *h)
{
	if(is_heap_empty(h))
	{
		printf("Heap underflow\n");
		return -1;
	}
	else
	{
		int item = *(int*)h->data[1]->item;

		h->data[1]->item = h->data[h->size]->item;
		h->data[1]->priority = h->data[h->size]->priority;
		h->size--;
		max_heapify(h, 1);

		return item;
	}
}

/* imprime a heap, cada nó representado por um par ordenado (priority, item) */
void print_heap(heap *h)
{
	int i;

	for(i = 1; i < h->size; i++)
	{
		printf(" (%d, %d) |", h->data[i]->priority, *(int*)h->data[i]->item);
	}
	if(i == h->size)
	{
		printf(" (%d, %d)\n", h->data[i]->priority, *(int*)h->data[i]->item);
	}
}
