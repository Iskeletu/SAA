#include "sortingAlgorithms.h"

//C implementation of selection sort, uses a secondary function "swap".
//Receives a integer vector and it's size as input.
void selectionSort(int vector[], int vector_size)
{
    int i, j, index;

    for (i = 0; i < (vector_size-1); i++)
    {
        index = i;

        for (j = (i+1); j < vector_size; j++)
        {
            if (vector[j] < vector[index])
            {
                index = j;
            }
        }

        swap(&vector[index], &vector[i]);
    }
}
