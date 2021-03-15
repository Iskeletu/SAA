#include "sortingAlgorithms.h"


//This function changes root element.
void heapify(int vector[], int vector_size, int root)
{
    int largest = root;
    int left = (2*root+1);
    int right = (2*root+2);

    if (left < vector_size && vector[left] > vector[largest])
    {
        largest = left;
    }

    if (right < vector_size && vector[right] > vector[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        swap(&vector[root], &vector[largest]);
        heapify(vector, vector_size, largest);
    }
}

//Main Heap Sort function, uses a secondary function "swap".
//Receives a integer vector and it's size as input.
void heapSort(int vector[], int vector_size)
{
    for (int i = (vector_size/2-1); i >= 0; i--)
    {
        heapify(vector, vector_size, i);
    }

    for (int i = (vector_size-1); i >= 0; i--)
    {
        swap(&vector[0], &vector[i]);
        heapify(vector, i, 0);
    }
}
