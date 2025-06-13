
#include "stack_calculator.h"
#include "stack_calculator.c"

int main()
{
    char expression[100];
    fgets(expression, 100, stdin);

    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluateExpression(expression);
    printf("%d\n", result);

    return 0;
}