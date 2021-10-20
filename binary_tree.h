#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

#define SYMBOLS_SIZE 4

typedef struct t_node
{
    char value;
    int number;
    struct t_node *left;
    struct t_node *right;
} t_node;

t_node* initialize(char* value, int value_size);
t_node* assemble_tree(char* str, int* i);
void free_nodes(t_node* node);

#endif