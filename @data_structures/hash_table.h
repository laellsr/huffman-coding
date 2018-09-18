#ifndef HASH_H
#define HASH_H

#include "../@functions/default.h"

#define MAX_SIZE_HASH 257
#define MAX_SIZE_STRING 13

typedef struct element_hash element_hash;
typedef struct hash_table hash_table;

hash_table* create_hash_table();
void put_hash(hash_table *ht, void *value);
void free_hash_table(hash_table *ht);
element_hash* get_hash_data(hash_table *ht, int i);
int get_element_hash_frequency(element_hash *eh);

#endif
