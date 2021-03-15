#include "sortingAlgorithms.h"


//C implementation of insertion sort.
//Receives a integer vector and it's size as input.
void insertionSort(int vector[], int vector_size)
{
    int i, j, key;

    for (i = 1; i < vector_size; i++)
    {
        key = vector[i];
        j = i - 1;

        while (j >= 0 && vector[j] > key)
        {
            vector[j+1] = vector[j];
            j = j - 1;
        }

        vector[j+1] = key;
    }
}
