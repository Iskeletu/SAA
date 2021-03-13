#include <stdio.h>
#include <stdlib.h>

//Includes the C implementation of the following sorting algorithms:
// - Bubble Sort
// -
// -
// -
// -
#include "sortingalgorithms.h"


//
int main()
{
    int vector[] = {2, 3, 9, 0, 5, 1, 8, 7, 4, 6};

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", vector[i]);
    }

    bubbleSort(vector, 10);
    printf("\n");

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", vector[i]);
    }

    return 0;
}
