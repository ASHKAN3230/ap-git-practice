
#include "transform.h"
// تابعی برای چاپ عناصر یک آرایه
void printArray(const int *arr, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++) // حلقه برای دسترسی به عناصر هر آرایه
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int *transform(const int *arr, unsigned int size, int (*callbackFunc)(int))
{
    int *newArr = (int *)malloc(size * sizeof(int));
    if (newArr == NULL) // بررسی کننده این که تبدیل حافظه درست بوده یا نه برای جلوگیری از کرش برنامه
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (unsigned int i = 0; i < size; i++)
    {
        newArr[i] = callbackFunc(arr[i]);
    }

    return newArr;
}