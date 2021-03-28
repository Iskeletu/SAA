#include "sortingAlgorithms.h"


//This function find and swap a smaller element in a partition.
int partition(int vector[], int low, int high)
{
    int x = vector[high];
    int counter = (low-1);

    for(int i = low; i <= (high-1); i++)
    {
        if(vector[i] <= x)
        {
            counter++;
            swap(&vector[counter], &vector[i]);
        }
    }

    swap(&vector[counter+1], &vector[high]);

    return (counter+1);
}


//Main Quick Sort function, uses a secondary function "swap".
//Receives a integer vector and it's size as input.
void quickSort(int vector[], int ending_index)
{
    ending_index--;
    int starting_index = 0, stack[ending_index-starting_index+1], top = -1;

    stack[++top] = starting_index;
    stack[++top] = ending_index;

    while (top >= 0)
    {
        ending_index = stack[top--];
        starting_index = stack[top--];

        int p = partition(vector, starting_index, ending_index);

        if((p-1) > starting_index)
        {
            stack[++top] = starting_index;
            stack[++top] = p - 1;
        }

        if((p+1) < ending_index)
        {
            stack[++top] = p + 1;
            stack[++top] = ending_index;
        }
    }
}
