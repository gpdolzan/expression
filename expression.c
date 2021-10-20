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
    int right_node_value = 0;
    int left_node_value = 0;

    if(node->value == '*')
    {
        left_node_value = calculate(node->left);
        right_node_value = calculate(node->right);

        printf("%d * %d\n", left_node_value, right_node_value);
        return left_node_value * right_node_value;
    }
    else if(node->value == '/')
    {
        left_node_value = calculate(node->left);
        right_node_value = calculate(node->right);

        printf("%d / %d\n", left_node_value, right_node_value);
        return left_node_value / right_node_value;
    }
    else if(node->value == '-')
    {
        left_node_value = calculate(node->left);
        right_node_value = calculate(node->right);

        printf("%d - %d\n", left_node_value, right_node_value);
        return left_node_value - right_node_value;
    }
    else if(node->value == '+')
    {
        left_node_value = calculate(node->left);
        right_node_value = calculate(node->right);

        printf("%d + %d\n", left_node_value, right_node_value);
        return left_node_value + right_node_value;
    }
    else if(node->value == '\0')
    {
        printf("TESTING: %d", (*(node->number)));
        if(node->number != NULL)
            return (*(node->number));
    }
}