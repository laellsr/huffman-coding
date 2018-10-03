#ifndef TREE_H
#define TREE_H

#include "../@functions/default.h"
//#include "hash_table.h"

typedef struct binary_tree binary_tree;
struct binary_tree;

binary_tree* create_empty_binary_tree();
binary_tree* create_binary_tree(void *value, int frequency, binary_tree *left, binary_tree *right);
void print_pre_order(binary_tree *bt);
int get_binary_tree_frequency(binary_tree *bt);
int is_leaf(binary_tree *bt);
unsigned char get_binary_tree_value(binary_tree *bt);
binary_tree* bt_right(binary_tree *bt);
binary_tree* bt_left(binary_tree *bt);
void print_pre_order_tree(binary_tree *bt);
int binary_tree_size(binary_tree *bt);

#endif
