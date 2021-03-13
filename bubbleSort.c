#include "sortingAlgorithms.h"

//C implementation of bubble sort, uses a secondary function "swap".
void bubbleSort(int vector[], int vector_size)
{
    int i, j;

    for (i = vector_size - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                swap(&vector[j], &vector[j+1]);
            }
        }
    }
}
