#include "binary_tree.h"

t_node* initialize(char value)
{
    t_node* node = (t_node*)malloc(sizeof(t_node));
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    return node;
}

t_node* assemble_tree(char* str, int* i)
{
    t_node* node = NULL;

    if (str[*i] == '(') {
        (*i)++;
        node = initialize(str[*i]);    
        (*i)++;
        node->left = assemble_tree(str, i);
        node->right = assemble_tree(str, i);            
        (*i)++;
    }
    return node;
}

void free_nodes(t_node* node)
{
    if(node != NULL)
    {
        free_nodes(node->left);
        free_nodes(node->right);
        free(node);
    }
}