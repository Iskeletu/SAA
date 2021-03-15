#include "vectorVerification.h"

//Checks if a integer vector is sorted in ascending order.
//Requires a integer vector and it's size as input.
//This function returns 1 if the vector is properly sorted or 0 if it is not.
int vectorVerifier(int vector[], int vector_size)
{
    for(int i = 1; i < vector_size; i++)
    {
        if(vector[i] < vector[i-1])
        {
            return 0;
        }
    }

    return 1;
}
