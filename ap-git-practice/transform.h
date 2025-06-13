
#include <stdio.h>
#include <stdlib.h>

#ifndef TRANSFORM_H
#define TRANSFORM_H

int *transform(const int *arr, unsigned int size, int (*callbackFunc)(int));
void printArray(const int *arr, unsigned int size);

#endif