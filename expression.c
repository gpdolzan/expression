#include "binary_tree.h"
#include "expression.h"

void start_program(char* str)
{
    t_node* node = NULL;
    int i = 0;

    node = assemble_tree(str, &i);

    int result = calculate(node);
    printf("%d\n", result);
    free_nodes(node);
}

int calculate(t_node* node)
{
    if(node->value == '*')
    {
        int left_node_value = calculate(node->left);
        int right_node_value = calculate(node->right);

        printf("%d * %d\n", left_node_value, right_node_value);
        return left_node_value * right_node_value;
    }
    else if(node->value == '/')
    {
        int left_node_value = calculate(node->left);
        int right_node_value = calculate(node->right);

        printf("%d / %d\n", left_node_value, right_node_value);
        return left_node_value / right_node_value;
    }
    else if(node->value == '-')
    {
        int left_node_value = calculate(node->left);
        int right_node_value = calculate(node->right);

        printf("%d - %d\n", left_node_value, right_node_value);
        return left_node_value - right_node_value;
    }
    else if(node->value == '+')
    {
        int left_node_value = calculate(node->left);
        int right_node_value = calculate(node->right);

        printf("%d + %d\n", left_node_value, right_node_value);
        return left_node_value + right_node_value;
    }
    else
        return node->number;
}