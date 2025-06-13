#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int top;
    int array[MAX_SIZE];
} Stack;

Stack *createStack();
void push(Stack *stack, int data);
int pop(Stack *stack);
int isOperator(char op);
int applyOperator(int a, int b, char op);
int evaluateExpression(char *expression);
#endif
