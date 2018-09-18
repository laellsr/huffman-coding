#include "decompress.h"
/*
 * Recebe um ponteiro para uma arvore binária e um ponteiro para o arquivo fonte
 * Monta recursivamente a árvore binária a partir da árvore em impressa em pré-ordem
 * Retorna um ponteiro para a árvore binária montada
 */
/*binary_tree* build_tree(binary_tree *tree,FILE *sFile)
{
	unsigned char byte;

	byte =  getc(sFile);

	if(byte == '*')
	{
		tree = create_binary_tree(byte,0,NULL,NULL);//Cria um nó com o byte lido do arquivo fonte
		tree->left = build_tree(tree->left,sFile);
		tree->right = build_tree(tree->right,sFile);
	}
	else//Se não é asterisco então é folha
	{
		if(byte == '\\')//Se for um caractere de escape
		{
			byte = getc(sFile);//Cria um nó com o próximo
			tree = create_binary_tree(byte,0,NULL,NULL);
		}
        else
        {
            tree = create_binary_tree(byte,0,NULL,NULL);//Se não for um caractere de escape, já coloca um nó no lugar diretamente
        }
	}
	return tree;
}*/

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
}/*

/*
 * Recebe um ponteiro para o arquivo fonte e um ponteiro para o arquivo de destino
 * Descomprime o programa comprimido no arquivo de destino
 */
/*void decompress(FILE *sFile, FILE *dFile)//source file (arquivo fonte), destination file (arquivo de destino)
{
    binary_tree *tree;
    fseek(sFile,2,SEEK_SET)//Anda 2 bytes no arquivo fonte a partir do início
    tree = build_tree(tree,sFile);
    make_program(tree,sFile,dFile);
}*/
