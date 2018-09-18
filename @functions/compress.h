#ifndef COMPRESS_H
#define COMRPESS_H

#include "../@functions/default.h"
#include "../@data_structures/binary_tree.h"
#include "../@data_structures/hash_table.h"
#include "../@data_structures/heap.h"


void byte_frequency(FILE* file, hash_table* ht);
void huffman_tree(heap *heap);
void compress();


#endif
