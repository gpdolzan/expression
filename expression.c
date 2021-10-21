#include "binary_tree.h"
#include "expression.h"

//Com base na string passada como parametro, realiza a analise da expressao aritmetica
void start_program(char* str)
{
    //Variaveis
    t_node* node = NULL;
    int i = 0;

    //Monta arvore com base na string passada
    node = assemble_tree(str, &i);

    //Calcula e imprime os resultados da arvore
    int result = calculate(node);
    printf("%d\n", result);

    //Libera memoria
    free_nodes(node);
}

//Usando o nodo como parametro, eh calculado os valores da expressao aritmetica
int calculate(t_node* node)
{
    //Se for multiplicacao
    if(node->value == '*')
    {
        //Calcula recursivamente, percorrendo a arvore ate achar um valor (int)
        int left_node_value = calculate(node->left);
        int right_node_value = calculate(node->right);

        //Imprime expressao e retorna o calculo
        printf("%d * %d\n", left_node_value, right_node_value);
        return left_node_value * right_node_value;
    }
    else if(node->value == '/') //Se for divisao
    {
        //Calcula recursivamente, percorrendo a arvore ate achar um valor (int)
        int left_node_value = calculate(node->left);
        int right_node_value = calculate(node->right);

        //Imprime expressao e retorna o calculo
        printf("%d / %d\n", left_node_value, right_node_value);
        return left_node_value / right_node_value;
    }
    else if(node->value == '-') //Se for subtracao
    {
        //Calcula recursivamente, percorrendo a arvore ate achar um valor (int)
        int left_node_value = calculate(node->left);
        int right_node_value = calculate(node->right);

        //Imprime expressao e retorna o calculo
        printf("%d - %d\n", left_node_value, right_node_value);
        return left_node_value - right_node_value;
    }
    else if(node->value == '+') //Se for adicao
    {
        //Calcula recursivamente, percorrendo a arvore ate achar um valor (int)
        int left_node_value = calculate(node->left);
        int right_node_value = calculate(node->right);

        //Imprime expressao e retorna o calculo
        printf("%d + %d\n", left_node_value, right_node_value);
        return left_node_value + right_node_value;
    }
    else //Se encontrou o valor (int) retorne o valor
        return node->number;
}