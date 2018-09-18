#include "default.h"

/*
 * Recebe um byte e a posição a ser verificada
 * Verifica se o bit na posição i é 1
 * Retorna um inteiro, 1 se estiver setado, 0 se não estiver setado
 */
int is_bit_i_set(unsigned char c, int i)
{
	unsigned char mask = 1 << i;
	return mask & c;
}

/*
 * Recebe um ponteiro para o arquivo fonte
 * Verifica o tamanho do lixo
 * Retorna o tamanho do lixo como um inteiro
 */
int trash_size(FILE *sFile)
{
	fseek(sFile, 0, SEEK_SET);
	unsigned char c;
	c = getc(sFile);
	return c >> 5;//Empurra os 3 primeiros bit pro final do byte, assim gerando o tamanho correto
}

int is_empty(void* structure)
{
  return structure == NULL;
}
