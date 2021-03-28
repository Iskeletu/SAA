#include "sortingAlgorithms.h"

//This function searches for the largest element of an input vector.
int largest(int vector[], int vector_size)
{
    int result = vector[0];

    for(int i = 1; i < vector_size; i++)
    {
        if (vector[i] > result)
        {
            result = vector[i];
        }
    }

    return result;
}


//This function copies the contents of a integer vector to another integer vector
void copyVector(int copy_from[], int copy_to[], int vector_size)
{
    for (int i = 0; i < vector_size; i++)
    {
        copy_to[i] = copy_from[i];
    }
}


//C implementation of counting sort.
//Receives a integer vector and it's size as input.
void countingSort(int vector[], int vector_size)
{
    int i;
    int output[vector_size];
    int max = largest(vector, vector_size);
    int* counter = (int*)calloc((max+1), sizeof(int));

    for (i = 0; i < vector_size; i++)
    {
        counter[vector[i]]++;
    }

    for (i = 1; i <= max; i++)
    {
        counter[i] += counter[i-1];
    }

    for (i = vector_size - 1; i >= 0; i--)
    {
        output[counter[vector[i]]-1] = vector[i];
        counter[vector[i]]--;
    }

    free(counter);
    copyVector(output, vector, vector_size);
}
