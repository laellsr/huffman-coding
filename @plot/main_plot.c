#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "pq_heap.h"

/*
	nos arquivos criados cada linha é composta pela ordem de inserção e a quantidade de comparações necessárias pra inserir na fila, 
  a prioridade é sorteada
*/

int main()
{
	priority_queue *pq = create_priority_queue();
	heap *pq_h = create_heap();
	FILE *f_pq = fopen("comparisons_pq.txt", "w"); // cria arquivo para as comparaçãos da fila de prioridade sem heap
	FILE *f_pqh = fopen("comparisons_pq_heap.txt", "w"); // cria arquivo para as comparaçãos da fila de prioridade com heap
	int n, i, priority;
	int comparisons, comparisons_h;
	int *item;

	printf("Enter the number of elements to be added:\n");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		*item = i;
		priority = rand();
		comparisons = enqueue(pq, item, priority);
		comparisons_h = enqueue_heap(pq_h, item, priority);
		fprintf(f_pq, " %d %d\n", i, comparisons);
		fprintf(f_pqh, "%d %d\n", i, comparisons_h);
	}

	fclose(f_pq);
	fclose(f_pqh);
	
	return 0;
}
