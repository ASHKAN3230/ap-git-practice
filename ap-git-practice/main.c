

#include "transform.h"
#include "transform.c"

int cbPrime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int cbSquare(int x)
{
    return x * x;
}

int main()
{
    int Arr[5] = {1, 2, 3, 4, 5};

    int *primeArr = transform(Arr, 5, cbPrime);
    if (primeArr != NULL)
    {
        printArray(primeArr, 5);
        free(primeArr);
    }

    int *squareArr = transform(Arr, 5, cbSquare);
    if (squareArr != NULL)
    {
        printArray(squareArr, 5);
        free(squareArr);
    }

    return 0;
}