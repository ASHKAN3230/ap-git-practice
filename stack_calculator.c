#include "stack_calculator.h"
// تابعی برای مقدار دهی چون برای مقدار دهی به پشته نیاز داریم
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}
// اضافه کردن مقدار به پشته
void push(Stack *stack, int data)
{
    if (stack->top < MAX_SIZE - 1)
    {
        stack->array[++(stack->top)] = data;
    }
}
// حذف عنصر از داخل پشته

int pop(Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->array[(stack->top)--];
    }
    return -1;
}
// بررسی اینکه یک عملگر ریاضی است یا خیر
int isOperator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/';
}
// اعمال یک عملگر ریاضی بین دو عدد برای محاسبه
int applyOperator(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}
// تابعی برای برسی عبارت پسوندی
int evaluateExpression(char *expression)
{
    Stack *stack = createStack();
    char *token = strtok(expression, " ");

    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            push(stack, atoi(token));
        }
        else if (isOperator(token[0]))
        {
            int b = pop(stack);
            int a = pop(stack);
            int result = applyOperator(a, b, token[0]);
            push(stack, result);
        }
        token = strtok(NULL, " "); // تبدیل به توکن برای پردازش بهتر
    }

    int finalResult = pop(stack);
    free(stack);
    return finalResult;
}