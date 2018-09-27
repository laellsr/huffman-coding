#include "decompress.h"

/* Refaz a árvore de Huffman */
binary_tree* rebuild_huffman_tree(FILE *file)
{
	binary_tree *tree;
	unsigned char byte;
	byte = getc(file);

	/* Caso seja a base da árvore */
	if(byte == '*') 
	{
		binary_tree *tree_left, *tree_right;
		tree_left = rebuild_huffman_tree(file);
		tree_right = rebuild_huffman_tree(file);
		tree = create_binary_tree(&byte, 0, tree_left, tree_right);
	}
	/* Caso seja a folha da árvore */
	else	
	{
		/* Caso tenha um byte de escape */
		if(byte == '\\')
		{
			/* Lê o próximo byte */
			byte = getc(file);
			tree = create_binary_tree(&byte, 0, NULL, NULL);
		}
        else
        {
            tree = create_binary_tree(&byte, 0, NULL, NULL);
        }
	}
	return tree;
	
}

/* Escreve o arquivo original antes da compressão */
void write_original_file(FILE *file, binary_tree *huffman_tree, int trash_size)
{
	FILE *new_file = fopen("decompressed", "wb");
	int index, value = 1, trash_aux = -1;
	unsigned char byte, byte_aux;
	binary_tree *original_tree = huffman_tree;
	byte_aux = getc(file);
	/* Escreve os bytes de acordo com o caminho da árvore */
	while(value)
	{
		/* "byte" recebe o novo byte caso não seja o final do arquivo */
		byte = byte_aux;
		/* Índice do byte */
		index = 7;
		/* Se for o final do arquivo, será necessário parar o loop e conferir o lixo */
		//byte_aux = getc(file);
		if (fscanf(file, "%c", &byte_aux)==EOF)
		{
			value--;
			/* Quando não existir lixo (= zero), o último byte é lido por completo, então "trash_aux" = -1 */
			trash_aux = trash_size - 1;
		}
		/* Percorre todo o byte enquanto o "trash_aux" for igual a -1
		 * Quando ler o último byte, o "trash_aux" vai ser igual ao lixo se este existir */
		while(index > trash_aux)
		{
			/* Faz a busca por folhas na árvore */
			if (is_bit_i_set(byte, index))
			{
				huffman_tree = bt_right(huffman_tree);
			}
			else huffman_tree = bt_left(huffman_tree);
			
			if (is_leaf(huffman_tree))
			{
				fprintf(new_file, "%c", get_binary_tree_value(huffman_tree));
				huffman_tree = original_tree; 
			}

			index--;
		}
	}

	fclose(file);
	fclose(new_file);
}


/* Descomprime o arquivo */
void decompress()
{
	FILE* file;
	unsigned char file_name[200];
	printf("\nEnter a directory or a file name:	");
	scanf("%s", file_name);
	file = fopen(file_name, "rb");

	if (!is_empty(file))
	{
		unsigned char byte = getc(file);
		/* Tamanho do lixo de acordo com o cabeçalho */
		int trash_size = byte >> 5;
		 
		 /* Tamanho da árvore de acordo com o cabeçalho
			byte = byte << 3;
			byte = byte >> 3;
			int tree_size = byte;
			tree_size = tree_size << 8;
			byte = getc(file);
			tree_size |= byte;
		*/
		
		/* Avança 1 byte pois não é necessário usar o tamanho da árvore */
		fseek(file, 1, SEEK_CUR);
		/* Refaz a árvore de Huffman */
		binary_tree *tree; 
		tree = rebuild_huffman_tree(file);
		/* Escreve o arquivo a partir da árvore */
    	write_original_file(file, tree, trash_size); 
	}
	else
	{
		printf("\nInvalid file.\n\n##########  END OF EXECUTION  ###########\n");
	}

	printf("\n##########        DONE!       ###########\n");
   
}
