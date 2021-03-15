#include <stdio.h>
#include <stdlib.h>

//Benchmark function monitors CPU runtime and memory usage of sorting algorithms.
//This function will check if the vector is properly sorted and save results as a .dat file.
//Receives a integer that indicates which sorting algorithm it should run (1 to 8).
//Returns 1 if benchmark was successful.
#include "benchmark.h"


//Converts sorting algorithms name into integer UUID's.
#define BUBBLE 1
#define SELECTION 2
#define INSERTION 3
#define SHELL 4
#define HEAP 5
#define MERGE 6
#define QUICK 7
#define COUNTING 8


//Calls for "benchmark" function for every implementation of sorting algorithms.
int main()
{
    int result;


    //Bubble Sort Benchmark.
    result = benchmark(BUBBLE);
    if(result == 1)
    {
        printf("\tBUBBLESORT BENCHMARK SUCCESSFULL!\n\n\n\n\n");
    }
    else
    {
        printf("\tBUBBLESORT BENCHMARK HAS FAILED!\n\n\n\n\n");
        exit(404); //Means that the benchmark has failed (should not happen without another error triggering first).
    }


    //Selection Sort Benchmark.
    result = benchmark(SELECTION);
    if(result == 1)
    {
        printf("\tSELECTIONSORT BENCHMARK SUCCESSFULL!\n\n\n\n\n");
    }
    else
    {
        printf("\tSELECTIONSORT BENCHMARK HAS FAILED!\n\n\n\n\n");
        exit(404); //Same as above.
    }

    
    //Insertion Sort Benchmark.
    result = benchmark(INSERTION);
    if(result == 1)
    {
        printf("\tINSERTIONSORT BENCHMARK SUCCESSFULL!\n\n\n\n\n");
    }
    else
    {
        printf("\tINSERTIONSORT BENCHMARK HAS FAILED!\n\n\n\n\n");
        exit(404); //Same as above.
    }


    //Shell Sort Benchmark.
    result = benchmark(SHELL);
    if(result == 1)
    {
        printf("\tSHELLSORT BENCHMARK SUCCESSFULL!\n\n\n\n\n");
    }
    else
    {
        printf("\tSHELLSORT BENCHMARK HAS FAILED!\n\n\n\n\n");
        exit(404); //Same as above.
    }


    //Heap Sort Benchmark.
    result = benchmark(HEAP);
    if(result == 1)
    {
        printf("\tHEAPSORT BENCHMARK SUCCESSFULL!\n\n\n\n\n");
    }
    else
    {
        printf("\tHEAPSORT BENCHMARK HAS FAILED!\n\n\n\n\n");
        exit(404); //Same as above.
    }


    //Meage Sort Benchmark.
    result = benchmark(MERGE);
    if(result == 1)
    {
        printf("\tMERGESORT BENCHMARK SUCCESSFULL!\n\n\n\n\n");
    }
    else
    {
        printf("\tMERGESORT BENCHMARK HAS FAILED!\n\n\n\n\n");
        exit(404); //Same as above.
    }


    //Quick Sort Benchmark.
    result = benchmark(QUICK);
    if(result == 1)
    {
        printf("\tQUICKSORT BENCHMARK SUCCESSFULL!\n\n\n\n\n");
    }
    else
    {
        printf("\tQUICKSORT BENCHMARK HAS FAILED!\n\n\n\n\n");
        exit(404); //Same as above.
    }


    //Counting Sort Benchmark.
    result = benchmark(COUNTING);
    if(result == 1)
    {
        printf("\tCOUNTINGSORT BENCHMARK SUCCESSFULL!\n\n\n\n\n");
    }
    else
    {
        printf("\tCOUNTINGSORT BENCHMARK HAS FAILED!\n\n\n\n\n");
        exit(404); //Same as above.
    }

    return 0;
}
