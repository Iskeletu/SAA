#include "sortingAlgorithms.h"


//C implementation of shell sort.
//Receives a integer vector and it's size as input.
void shellSort(int vector[], int vector_size)
{
    int j, i, temp;

    for (int gap = (vector_size/2); gap > 0; gap /= 2)
    {
        for (i = gap; i < vector_size; i += 1)
        {
            temp = vector[i];

            for (j = i; j >= gap && vector[j-gap] > temp; j -= gap)
            {
                vector[j] = vector[j-gap];
            }

            vector[j] = temp;
        }
    }
}
