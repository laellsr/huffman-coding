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
