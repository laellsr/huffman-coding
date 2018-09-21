#ifndef HASH_H
#define HASH_H

#include "../@functions/default.h"

#define MAX_HASH_SIZE 257
#define MAX_STRING_SIZE 13

typedef struct element_hash element_hash;
typedef struct hash_table hash_table;

hash_table* create_hash_table();
void put_hash(hash_table *ht, void *value);
void free_hash_table(hash_table *ht);
element_hash* get_hash_data(hash_table *ht, int i);
int get_element_hash_frequency(element_hash *eh);
void add_hash_map(element_hash *eh, char *temp);
char* get_hash_string(hash_table *ht, int i);

#endif
