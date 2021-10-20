#include "binary_tree.h"
#include "expression.h"

#define MAX_STR_LEN 2048

int main()
{
    char str[MAX_STR_LEN];
    scanf("%s[^\n]", str);

    start_program(str);
    return 1;
}