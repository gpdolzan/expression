#include "binary_tree.h"

t_node* initialize(char* value, int value_size)
{
    int symbols[SYMBOLS_SIZE] = {'*', '/', '+', '-'};
    int symbol_flag = 0;
    int number = 0;

    if(value_size == 1)
    {
        for(int i = 0; i < SYMBOLS_SIZE; i++)
        {
            if(value[0] == symbols[i])
                symbol_flag = 1;
        }    
    }
    else
        number = atoi(value);

    t_node* node = (t_node*)malloc(sizeof(t_node));
    if(symbol_flag == 1)
    {
        node->value = value;
        node->number = NULL;
    }
    else
    {
        node->number = number;
        node->value = NULL;
    }
    node->right = NULL;
    node->left = NULL;
    return node;
}

t_node* assemble_tree(char* str, int* i)
{
    int number_position = 0;
    int number_size = 0;
    int str_position = 0;
    char* number_in_str;
    t_node* node = NULL;

    if (str[*i] == '(') 
    {
        (*i)++;
        number_position = (*i);

        while(str[number_position] != ')')
            number_position++;

        number_size = (number_position - (*i)) + 1;
        number_in_str = (char*)malloc((sizeof(char) * number_size) + 1);

        for(int j = (*i); j <= number_position; j++)
        {
            number_in_str[str_position] = str[j];
            str_position++;
        }
        node = initialize(number_in_str, number_size); 
        (*i) = number_position;
        free(number_in_str);

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