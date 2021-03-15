#include <stdlib.h>
#include <time.h>


#include "vectorFunctions.h"


//Generates integers and stores them in a integer vector.
//This function returns 1 if the generation was successful or 0 if it failed to do so.

//Has three generation types:
//Ascending (1): will fill every vector slot with it's index value plus one.
//Descending (2): will fill every vector slot with vector size value minus one minus it's index value.
//Random (3): will fill every vector slot with random number ranging from 1 to vector size value.
int vectorGenerator(int vector[], int vector_size, int generation_type)
{
    switch(generation_type)
    {
        case 1:
            for(int i = 0; i < vector_size; i++)
            {
                vector[i] = (i+1);
            }
            break;

        case 2:
            for(int i = 0; i < vector_size; i++)
            {
                vector[i] = (vector_size-i);
            }
            break;

        case 3:
            srand(time(0));

            for(int i = 0; i < vector_size; i++)
            {
                vector[i] = ((rand()%vector_size)+1);
            }
            break;

        default:
            return 0;
    }

    return 1;
}
