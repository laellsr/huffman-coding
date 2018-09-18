#ifndef TREE_H
#define TREE_H

#include "../@functions/default.h"

typedef struct binary_tree binary_tree;
struct binary_tree;

binary_tree* create_empty_binary_tree();
binary_tree* create_binary_tree(void *value, int frequency, binary_tree *left, binary_tree *right);
void destruct_binary_tree(binary_tree *bt);
void print_pre_order(binary_tree *bt);


#endif
