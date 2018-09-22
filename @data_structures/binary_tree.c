#include "binary_tree.h"


/* estrutura da árvore binária */
struct binary_tree
{
    void *value;
    int frequency;
    struct binary_tree *left;
    struct binary_tree *right;

};
/* retorna NULL para o ponteiro */
binary_tree* create_empty_binary_tree()
{
    return NULL;
}
/* criar a árvore */
binary_tree* create_binary_tree(void *value, int frequency, binary_tree *left, binary_tree *right)
{
    /* alocar um ponteiro para salvar o valor do endereço */
    unsigned char *temp = (unsigned char*) malloc(sizeof(unsigned char));
    *temp = *(unsigned char*)value;
    /* método de conversão "*((char *) character))" */
    binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
    new_binary_tree->value = temp;
    new_binary_tree->frequency = frequency;
    new_binary_tree->left = left;
    new_binary_tree->right = right;
    return new_binary_tree;
}

/* limpar a árvore */
void destruct_binary_tree(binary_tree *bt)
{
    if (bt==NULL)
    {
        return;
    }

    destruct_binary_tree(bt->left);
    destruct_binary_tree(bt->right);

    free(bt);
}

/* frequência do nó da árvore */
int get_binary_tree_frequency(binary_tree *bt)
{
  return bt->frequency;
}

/* Verifica se é uma folha */
int is_leaf(binary_tree *bt)
{
  if (is_empty(bt->left) && is_empty(bt->right))
  {
    return 1;
  }
  else return 0;
}

/* Retorna o valor do nó */
unsigned char get_binary_tree_value(binary_tree *bt)
{
  return *(unsigned char*) bt->value;
}

/* Retorna nó direito */
binary_tree* bt_right(binary_tree *bt)
{
  return bt->right;
}

/* Retorna nó esquerdo */
binary_tree* bt_left(binary_tree *bt)
{
  return bt->left;
}

/* Imprime a árvore em pré-ordem */
void print_pre_order_tree(binary_tree *bt)
{
  if (bt!=NULL)
  {
    printf("%c | ", *(unsigned char*)bt->value);
    print_pre_order_tree(bt->left);
    print_pre_order_tree(bt->right);
  }
}

/* Retorna o tamanho da árvore */
int binary_tree_size(binary_tree *bt)
{
  if (is_empty(bt))
  {
    return 0;
  }
  return 1 + binary_tree_size(bt->left) + binary_tree_size(bt->right);
}