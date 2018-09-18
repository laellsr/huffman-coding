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
void huffman_tree(heap *heap)
{

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
				enqueue(hp, get_element_hash_frequency(eh_aux));
			}
		}

		huffman_tree(hp);

	}

	else
	{
		printf("\nInvalid file.\n\n##########  END OF EXECUTION  ###########\n");
	}

	printf("\n##########        DONE!       ###########\n");
	fclose(file);
}
