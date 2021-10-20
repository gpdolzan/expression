#include "binary_tree.h"
#include <stdio.h>

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
    {
        printf("printing array to check info\n");
        for(int i = 0; i < value_size; i++)
            printf("%c ", value[i]);
        printf("\n");
        number = atoi(value);
        printf("number after atoi: %d\n", number);
    }

    t_node* node = (t_node*)malloc(sizeof(t_node));
    if(symbol_flag == 1)
        node->value = value[0];
    else
    {
        node->number = (int*)malloc(sizeof(int));
        printf("number before placing %d\n", number);
        node->number = &(number);
        node->value = '\0';
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
    char* str_aux;
    t_node* node = NULL;

    if (str[*i] == '(') 
    {
        (*i)++;
        number_position = (*i);

        while((str[number_position] != ')') || (str[number_position] != '('))
            number_position++;
        number_position--;

        number_size = (number_position - (*i)) + 1;
        str_aux = (char*)malloc((sizeof(char) * number_size) + 1);

        for(int j = (*i); j <= number_position; j++)
        {
            str_aux[str_position] = str[j];
            str_position++;
        }
        str[number_position + 1] = '\0';

        printf("STRING: %s", str_aux);

        node = initialize(str_aux, number_size); 
        (*i) = number_position;
        free(str_aux);

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