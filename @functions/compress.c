#include "compress.h"

/* Lê o arquivo e faz a frequência utilizando a Hash */
void byte_frequency(FILE* file, hash_table* ht)
{
	unsigned char c; int i, size = 0;

	fseek(file, 0, SEEK_END);
	size = ftell(file);
  rewind(file);

	for(i = 0; i < size; i++)
	{
		c = fgetc(file);
		put_hash(ht, &c);
	}
}

/* Cria a árvore de Huffman */
binary_tree* huffman_tree(heap *heap)
{
	unsigned char character = '*';
	binary_tree *temp, *temp2, *new_bt;
	int sum;
	while (get_heap_size(heap)>1)
	{
		temp = dequeue(heap);
		temp2 = dequeue(heap);
		sum = get_binary_tree_frequency(temp) + get_binary_tree_frequency(temp2); //printf("%d - sum -", sum);
		new_bt = create_binary_tree(&character, sum, temp, temp2);
		enqueue(heap, new_bt);
	}
	return dequeue(heap);
}

/* Faz o mapeamento do novo caminho */
void make_new_map(binary_tree* bt, hash_table *ht, char *temp, int i)
{
	/*if (is_empty(bt))
	{
		return;
	}
	else*/ if (is_leaf(bt))
	{
		temp[i] = '\0';
		add_hash_map(get_hash_data(ht, i), temp);
		return;
	}
	if (!is_empty(bt_left(bt)))
	{
		temp[i] = '0';
		make_new_map(bt_left(bt), ht, temp, i+1);
	}
	if (!is_empty(bt_right(bt)))
	{
		temp[i] = '1';
		make_new_map(bt_right(bt), ht, temp, i+1);
	}

}

/* Função para compressão do arquivo */
void compress()
{
	FILE* file;
	unsigned char file_name[200]; int i;

	printf("\nEnter a directory or a file name:	");
	scanf("%s", file_name);
	file = fopen(file_name , "rb");

	if (file != NULL)
	{
		heap* hp = create_heap();
		hash_table* ht = create_hash_table();

		byte_frequency(file, ht);

		element_hash *eh_aux;
		for(i = 1; i < 257; i++)
		{
			eh_aux = get_hash_data(ht, i);
			if (!is_empty(eh_aux))
			{
				enqueue(hp, create_binary_tree(&i, get_element_hash_frequency(eh_aux), NULL, NULL));
			}
		}

		binary_tree *tree = huffman_tree(hp);

		char temp[20];
		make_new_map(tree, ht, temp, 0);

	}

	else
	{
		printf("\nInvalid file.\n\n##########  END OF EXECUTION  ###########\n");
	}

	printf("\n##########        DONE!       ###########\n");
	fclose(file);
}
