#include "sortingAlgorithms.h"

//Swaps a n1 integer with a n2 integer.
//Receives two int points as input.
void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
