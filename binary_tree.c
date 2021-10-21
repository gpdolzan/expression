#include "binary_tree.h"

//Inicializa nodo com base no tamanho da string e na string recebida
t_node* initialize(char* value, int value_size)
{
    //Variaveis
    int symbols[SYMBOLS_SIZE] = {'*', '/', '+', '-'};
    int symbol_flag = 0;
    int number = 0;

    //Se o tamanho da string for 1, verifica se eh um simbolo
    if(value_size == 1)
    {
        //Percorre vetor de simbolos para verificacao
        for(int i = 0; i < SYMBOLS_SIZE; i++)
        {
            //Se o valor for um simbolo, ativa flag
            if(value[0] == symbols[i])
            {
                symbol_flag = 1;
                break;
            }
        }
    }

    //Se a flag nao esta ativada, converte string pra numero
    if(symbol_flag != 1)
        number = atoi(value);

    //Cria e preenche nodo com a informacao obtida
    t_node* node = (t_node*)malloc(sizeof(t_node));
    if(symbol_flag == 1)
        node->value = value[0];
    else
    {
        node->number = number;
        node->value = '\0';
    }

    //Inicializa os nodos filhos como nulo
    node->right = NULL;
    node->left = NULL;

    //Devolve nodo com as informacoes preenchidas
    return node;
}

//Monta arvore com base em uma string e um contador i
t_node* assemble_tree(char* str, int* i)
{
    //Variaveis
    int number_position = 0;
    int number_size = 0;
    int str_position = 0;
    char* str_aux;
    t_node* node = NULL;

    //Testa para ver se um novo nodo foi encontrado
    if (str[*i] == '(') 
    {
        //Soma 1 no contador e guarda essa posicao como number_position
        (*i)++;
        number_position = (*i);

        //Conta ate chegar no final do nodo ou no comeco de outro nodo
        while((str[number_position] != ')') && (str[number_position] != '('))
            number_position++;
        number_position--;

        //Aloca dinamicamente o tamanho da string auxiliar
        number_size = (number_position - (*i)) + 1;
        str_aux = (char*)malloc((sizeof(char) * number_size) + 1);

        //Coloca na string auxilir a informacao obtida atraves da string original
        for(int j = (*i); j <= number_position; j++)
        {
            str_aux[str_position] = str[j];
            str_position++;
        }
        //Inicializa o ultimo caracter como nulo, evitando acesso de memoria indevido
        str_aux[str_position] = '\0';

        //Inicializa um novo nodo, passando a string auxiliar e o tamanho dela
        node = initialize(str_aux, number_size); 

        //Ajusta posicao do contador
        (*i) = number_position;

        //Libera vetor de informacao
        free(str_aux);

        //Monta o lado esquerdo e direito da arvore
        (*i)++;
        node->left = assemble_tree(str, i);
        node->right = assemble_tree(str, i);            
        (*i)++;
    }

    //Retorna nodo com as informacoes preenchidas
    return node;
}

//Libera nodos para evitar vazamento de memoria
void free_nodes(t_node* node)
{
    if(node != NULL)
    {
        free_nodes(node->left);
        free_nodes(node->right);
        free(node);
    }
}