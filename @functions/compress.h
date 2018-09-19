#ifndef COMPRESS_H
#define COMRPESS_H

#include "../@functions/default.h"
#include "../@data_structures/binary_tree.h"
#include "../@data_structures/hash_table.h"
#include "../@data_structures/heap.h"


void byte_frequency(FILE* file, hash_table* ht);
binary_tree* huffman_tree(heap *heap);
void compress();
void make_new_map(binary_tree* bt, hash_table *ht, char *temp, int i);
void write_huffman_tree(FILE *new_file, binary_tree *bt);
void write_new_file(FILE *file, binary_tree *bt, hash_table *ht);


#endif
