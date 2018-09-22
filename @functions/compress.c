#include "compress.h"

/* Lê o arquivo e faz a frequência utilizando a Hash */
void byte_frequency(FILE* file, hash_table* ht)
{
	unsigned char c; 
  	rewind(file);
	
	while(fscanf(file, "%c", &c)!=EOF)
	{
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
		sum = get_binary_tree_frequency(temp) + get_binary_tree_frequency(temp2);
		new_bt = create_binary_tree(&character, sum, temp, temp2);
		enqueue(heap, new_bt);
	}
	return dequeue(heap);
}

/* Faz o mapeamento do novo caminho */
void make_new_map(binary_tree* bt, hash_table *ht, char *temp, int i)
{
	if (!is_empty(bt))
	{
		if (is_leaf(bt))
		{
			temp[i] = '\0';
			int value = get_binary_tree_value(bt);
			add_hash_map(get_hash_data(ht, value), temp);
			return;
		}
		temp[i] = '0';
		make_new_map(bt_left(bt), ht, temp, i+1);
			
		temp[i] = '1';
		make_new_map(bt_right(bt), ht, temp, i+1);	
	}
}

/* Escreve a árvore em pré-ordem no novo arquivo */
void write_huffman_tree(FILE *new_file, binary_tree *bt)
{	
	if(!is_empty(bt))
	{
		unsigned char value = get_binary_tree_value(bt);
		
		if(is_leaf(bt) && (value == '*' || value == '\\'))
		{
			fprintf(new_file, "\\%c", value);
		}
		else
		{
			fprintf(new_file, "%c", value);
		}	
	
		write_huffman_tree(new_file, bt_left(bt));
		write_huffman_tree(new_file, bt_right(bt));
	}
}

/* Cria e escreve o arquivo comprimido */
void write_new_file(FILE *file, binary_tree *bt, hash_table *ht)
{
	FILE *new_file = fopen("compressed.huff", "wb");
	/* "byte" é a variável usada para adicionar os bits no arquivo */
	unsigned char byte = 0, character;
	/* Dois bytes nulos para o cabeçalho */
	fprintf(new_file, "%c%c", byte, byte);
	/* Escrever a árvorede de huffman em pré-ordem */
	write_huffman_tree(new_file, bt);
	/* Escrever o arquivo comprimido */
	rewind(file);
	/* index byte é índice do arquivo lido
	 * index_new_byte é o índice de bits do novo arquivo
	 * index_way armazena o bit a ser colocado */
	int index_byte, index_new_byte = 7;
	char index_way;
	while (fscanf(file, "%c", &character)!=EOF)
	{
		index_byte = 0;

		while(index_byte<get_string_size(ht, character))
		{
			index_way = get_hash_char_way(ht, character, index_byte);
			if (index_way == '1')
			{
				byte = set_bit(byte, index_new_byte);
			}
		
			index_byte++;
			index_new_byte--;

			if(index_new_byte<0)
			{
				fprintf(new_file, "%c", byte);
				index_new_byte = 7;
				byte = 0;
			}
		}
	}
	fclose(file);
	/* Edição do cabeçalho após escrever o arquivo comprimido */
	rewind(new_file);
	/* Tamanho do lixo (3 bits) */
	int trash = (index_new_byte+1) % 8;
	if (trash<0) trash *= -1;
	/* Tamanho da árvore */
	int tree_size = 0;
	tree_size = binary_tree_size(bt);
	/* Primeiro byte recebe o lixo (3 bits) mais os 5 bits do tamanho da árvore */	
	byte = trash;
	byte = byte << 5;
	byte |= tree_size >> 8;
	/* O segundo byte recebe os 8 bits restantes do tamanho da árvore */
	unsigned char second_byte = 0;
	second_byte = tree_size;
	/* Cabeçalho alterado */
	fprintf(new_file, "%c%c", byte, second_byte);
	fclose(new_file);	
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
		/* Frequência do bytes */
		byte_frequency(file, ht);
		/* Adicionando à Heap */
		element_hash *eh_aux;
		for(i = 0; i < 257; i++)
		{
			eh_aux = get_hash_data(ht, i);
			if (!is_empty(eh_aux))
			{
				enqueue(hp, create_binary_tree(&i, get_element_hash_frequency(eh_aux), NULL, NULL));
			}
		}
		/* Criando a árvore de Huffman */
		binary_tree *tree = huffman_tree(hp);
		/* Criando o novo caminho */
		char temp[13];
		make_new_map(tree, ht, temp, 0);
		/* Escrevendo o novo arquivo */
		write_new_file(file, tree, ht);
		/* Fim da Compressão */
	}

	else
	{
		printf("\nInvalid file.\n\n##########  END OF EXECUTION  ###########\n");
	}

	printf("\n##########        DONE!       ###########\n");
	fclose(file);
}
