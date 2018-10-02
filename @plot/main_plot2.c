#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "pq_heap.h"

/*
	gcc main_plot2.c pq_heap.c priority_queue.c

	nos arquivos criados cada linha é composta pela ordem de inserção
	e a quantidade de comparações necessárias pra inserir na fila, a prioridade é sorteada
*/

int main()
{
	priority_queue *pq = create_priority_queue();
	heap *pq_h = create_heap();
	/* CSV é um tipo para base de dados separados por virgulas */
	FILE *f_pq = fopen("comparisons_pq.csv", "w"); 
	int n, i, priority;
	int comparisons, comparisons_h;
	int *item;

	fprintf(f_pq, "%s\n", "CASES, PQ, PQ_H");

	printf("Enter the number of elements to be added:\t");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		item = (int*)malloc(sizeof(int));
		*item = i;
		priority = rand();
		comparisons = enqueue(pq, item, priority);
		comparisons_h = enqueue_heap(pq_h, item, priority);
		fprintf(f_pq, "%d, %d, %d\n", i, comparisons, comparisons_h);
	}

	fclose(f_pq);
	printf("\nDone!\n");
	
	return 0;
}
