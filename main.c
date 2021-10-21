#include "binary_tree.h"
#include "expression.h"

#define MAX_STR_LEN 2048

int main()
{
    //Pega string do stdin, sendo essa string a expressao aritmetica
    char str[MAX_STR_LEN];
    scanf("%s[^\n]", str);

    //Constroi uma arvore para analisar a expressao aritmetica
    start_program(str);

    //Encerra execucao do programa
    return 1;
}