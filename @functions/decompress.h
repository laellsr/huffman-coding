#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include "../@functions/default.h"
#include "../@data_structures/binary_tree.h"


binary_tree* build_tree(FILE *file);
void write_original_file(FILE *file, binary_tree *tree, int trash_size);
void decompress();


#endif
