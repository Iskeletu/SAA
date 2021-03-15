#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


//This function receives a string a writes it at the end of a text file.
void fileWrite(char string[])
{
    FILE *BenchmarkResults;
    BenchmarkResults = fopen("Benchmark\\BenchmarkResults.dat", "a");

    if(BenchmarkResults == NULL)
    {
        printf("Error!\n");
        exit(2); //Means that the program has failed to create/open a .dat file to write results.
    }
    else
    {
        fprintf(BenchmarkResults, "----------%s----------\n", string);

        if(strcmp(string, "----------") == 0)
        {
            fprintf(BenchmarkResults, "\n\n");
        }
    }

    fclose(BenchmarkResults);
}



//Calls for "benchmark" function for every implementation of sorting algorithms.
int main()
{
    int result;


    //Bubble Sort Benchmark.
    fileWrite("BUBBLE SORT:");
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
    fileWrite("----------");


    //Selection Sort Benchmark.
    fileWrite("SELECTION SORT:");
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
    fileWrite("----------");


    //Insertion Sort Benchmark.
    fileWrite("INSERTION SORT:");
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
    fileWrite("----------");


    //Shell Sort Benchmark.
    fileWrite("SHELL SORT:");
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
    fileWrite("----------");


    //Heap Sort Benchmark.
    fileWrite("HEAP SORT:");
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
    fileWrite("----------");


    //Merge Sort Benchmark.
    fileWrite("MERGE SORT:");
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
    fileWrite("----------");


    //Quick Sort Benchmark.
    fileWrite("QUICK SORT:");
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
    fileWrite("----------");


    //Counting Sort Benchmark.
    fileWrite("COUNTING SORT:");
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
    fileWrite("----------");

    return 0;
}
