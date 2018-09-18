#include "heap.h"

/* Estrutura da Heap */
struct heap
{
	int size;
	binary_tree* data[MAX_HEAP_SIZE];
};

/* Cria a Heap */
heap* create_heap()
{
	int i;
	heap* new_hp = (heap*)malloc(sizeof(heap));
	new_hp->size = 0;
	for (i = 0; i < MAX_HEAP_SIZE; ++i)
	{
		new_hp->data[i] = NULL;
	}
	return new_hp;
}

/* Adiciona a Heap de acordo com a Hash */
void enqueue(heap* hp, int frequency)
{
	/*if (hp->size < MAX_HEAP_SIZE)
	{
		int parent_index, current; binary_tree* aux;

		hp->data[++hp->size] = create_binary_tree(value, frequency, NULL, NULL);

		current = hp->size;
		parent_index = get_parent_index(current);

		while(parent_index >= 1 && hp->data[current]->frequency < hp->data[parent_index]->frequency)
		{
			/* Troca de nós */	/*
			aux = hp->data[current];
			hp->data[current] = hp->data[parent_index];
			hp->data[parent_index] = aux;

			current = parent_index;
			parent_index = get_parent_index(current); */
//		}
//	}

}

/* Retorna o pai do índice */
int get_parent_index(int i) {return i/2;}

/* Retorna o filho esquerdo do índice */
int get_left_index(int i) {return 2*i;}

/* Retorna o filho direito do índice */
int get_right_index(int i) {return 2*i + 1;}

/* Ordena a Heap em ordem decrescente */
void min_heapify(heap *heap, int index)
{
	int largest;
	int left = get_left_index(index);
	int right = get_right_index(index);
	/*
	if (left <= heap->size && heap->data[left]->frequency < heap->data[index]->frequency)
	{
		largest = left;
	}
	else
	{
		largest = index;
	}
	if (right <= heap->size && heap->data[right]->frequency < heap->data[largest]->frequency)
	{
		largest = right;
	}
	if (heap->data[index]->frequency != heap->data[largest]->frequency)
	{
		binary_tree* aux;
		/* Troca de nós */
	/*	aux = heap->data[index];
		heap->data[index] = heap->data[largest];
		heap->data[largest] = aux;

		min_heapify(heap, largest);
	} */
}

/* Retorna o nó da árvore de menor valor*/
binary_tree* dequeue(heap *heap)
{
	/*
	if (heap->size)
	{
		heap->size--;
		binary_tree* aux;
		aux = heap->data[1];
		heap->data[1] = heap->data[heap->size];
		min_heapify(heap, 1);
		return aux;
	}
	else
	{
		return NULL;
	} */
}
