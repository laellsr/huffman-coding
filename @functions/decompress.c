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
	FILE *new_file = fopen("decompressed.huff", "wb");
	int index, value = 1, trash_aux=-1;
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
		if (fscanf(file, "%c", &byte_aux)==EOF)
		{
			value--;
			trash_aux = trash_size - 1;
		}
		/* Percorre todo o byte enquanto o "trash_aux" for igual a -1
		 * Quando ler o último byte, o "trash_aux" vai ser igual ao lixo */
		while(index > trash_aux)
		{
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
}

/*
 *Recebe um ponteiro para uma árvore binária, o arquivo fonte e o arquivo de destino
 *Apartir da leitura do arquivo fonte, percorre a árvore e quando chega a uma folha, imprime no arquivo de destino o byte da folha 
 */
/*void make_program(binary_tree *tree, FILE *sFile, FILE *dFile)
{
	int i,j;//j faz o controle de posição dentro dos bytes OBS.: Lembrar que andamos nos bytes em índice decrescente
	int content_size;
	int tree_size = tree_size(sFile);
	binary_tree *saveTop = tree;
	unsigned char rByte;//Caractere a ser lido
	fseek(sFile,0,SEEK_END);//Coloca o ponteiro de leitura de arquivo na última posição do arquivo
	content_size = ftell(sFile) - 2 - tree_size;//Pega o tamanho do conteúdo referente ao programa, tirando o cabeçalho e a árvore printada
	fseek(sFile,2 + tree_size,SEEK_SET);//Volta o ponteiro de leitura de arquivo para a primeira posição após o cabeçalho e a árvore printada
	fseek(dFile,0,SEEK_SET);//Para evitar possíveis erros
	
	j=7;//Índice do byte está como decrescente, começando do 7 para o 0
	for(i=0;i<content_size;i++)
	{
		if(j==7)
		{
			rByte = getc(sFile);
		}

		if(is_bit_i_set(rByte,j))
		{
			tree = tree->left;
			if(is_leaf(tree))
			{
				fprintf(dFile,"%c",tree->item);
			}
			j--;
		}
		else
		{
			tree = tree->right;
			if(is_leaf(tree))
			{
				fprintf(dFile,"%c",tree->item);
			}
			j--;
		}

		if(j==-1)
		{
			j=7;
		}
	}	

	fseek(sFile,0,SEEK_SET);
	fseek(dFile,0,SEEK_SET);
	fclose(sFile);
	fclose(dFile);	
}*/


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
		tree_size |= byte;*/

		/* Refaz a árvore de Huffman */
		binary_tree *tree; 
		tree = rebuild_huffman_tree(file);
    	write_original_file(file, tree, trash_size);
    	fclose(file); 
	}
	else
	{
		printf("\nInvalid file.\n\n##########  END OF EXECUTION  ###########\n");
	}

	printf("\n##########        DONE!       ###########\n");
   
}
