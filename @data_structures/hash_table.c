#include "hash_table.h"

/* Estrutura da Hash dinâmica */
struct element_hash
{
	int element_frequency;
	char string[MAX_STRING_SIZE];
};

struct hash_table
{
	element_hash *table[MAX_HASH_SIZE];
};

/* Cria a Hash */
hash_table* create_hash_table()
{
	hash_table *new_hash_table = (hash_table*) malloc (sizeof(hash_table));

	int i;
	for (i = 0; i < MAX_HASH_SIZE; ++i)
	{
		new_hash_table->table[i] = NULL;
	}
	return new_hash_table;
}

/* Adiciona na Hash */
void put_hash(hash_table *ht, void *value)
{
	int h = *(unsigned char*)value;

	element_hash *temp = ht->table[h];

	if (temp==NULL)
	{
		element_hash *new_element = (element_hash*) malloc (sizeof(element_hash));
		new_element->element_frequency = 1;
		ht->table[h] = new_element;
	}
	else
	{
		temp->element_frequency++;
	}
}

/* Destrói a Hash */
void free_hash_table(hash_table *ht)
{
	element_hash *temp;
	int i;
	for (i = 0; i < MAX_HASH_SIZE; ++i)
	{
		temp = ht->table[i];
		free(temp);
		ht->table[i] = NULL;
	}

	free(ht);
}

/* Retorna a frequência */
element_hash* get_hash_data(hash_table *ht, int i)
{
	return ht->table[i];
}

/* Retorna a frequência do elemento */
int get_element_hash_frequency(element_hash *eh)
{
  return eh->element_frequency;
}

/* Adiciona o mapa na Hash */
void add_hash_map(element_hash *eh, char *temp)
{
	//printf("%s\n", temp);
	strcpy(eh->string, temp);
}

/* Retorna a string dentro da Hash */
char* get_hash_string(hash_table *ht, int i)
{
	printf("entrei\n");
	element_hash *eh = get_hash_data(ht, i);
	char out[MAX_STRING_SIZE];
	strcpy(out, ht->string);
	return &out;
}
