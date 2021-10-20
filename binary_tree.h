#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

typedef struct t_node
{
    char value;
    t_node *left, *right;
} t_node;

t_node* initialize(char value);
t_node* assemble_tree(char* str, int* i);

#endif