#include "sortingAlgorithms.h"


//This function is a utility to find the lower between two integers.
int lower(int n1, int n2)
{
    return n1 < n2 ? n1 : n2;
}


//This function sort and merges two haves of an input array.
void merge(int vector[], int left_pos, int mid_pos, int right_pos)
{
    int i, j, k;

    int n1 = (mid_pos-left_pos+1);
    int n2 = (right_pos-mid_pos);

    int Left[n1], Right[n2];

    for(i = 0; i < n1; i++)
    {
        Left[i] = vector[left_pos+i];
    }

    for(j = 0; j < n2; j++)
    {
        Right[j] = vector[mid_pos+1+j];
    }

    i = 0; j = 0; k = left_pos;
    while(i < n1 && j < n2)
    {
        if(Left[i] <= Right[j])
        {
            vector[k] = Left[i];
            i++;
        }
        else
        {
            vector[k] = Right[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        vector[k] = Left[i];
        i++; k++;
    }

    while(j < n2)
    {
        vector[k] = Right[j];
        j++; k++;
    }
}


//C implementation of merge sort.
//Receives a integer vector and it's size as input.
void mergeSort(int vector[], int vector_size)
{
    int current_size, left_start;

    for (current_size = 1; current_size <= (vector_size-1); current_size = (2*current_size))
    {
        for (left_start = 0; left_start < (vector_size-1); left_start += (2*current_size))
        {
            int mid = lower((left_start+current_size-1), (vector_size-1));
            int right_end = lower((left_start+2*current_size-1), (vector_size-1));

            merge(vector, left_start, mid, right_end);
        }
    }
}
