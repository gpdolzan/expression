#include "binary_tree.h"
#include "expression.h"

#define MAX_STR_LEN 2048

int main()
{
    char str[MAX_STR_LEN];

    //Pega string do stdin, sendo essa string a expressao aritmetica
    fprintf(stderr, "Por favor, insira a expressao que deseja calcular: ");
    scanf("%s[^\n]", str);
    fprintf(stderr, "Mostrando contas realizadas:\n");

    //Constroi uma arvore para analisar a expressao aritmetica
    start_program(str);

    //Encerra execucao do programa
    return 1;
}