#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>


//Includes the C implementation of the following sorting algorithms:
/*
- Bubble Sort
- Selection Sort
- Insertion Sort
- Shell Sort
- Heap Sort
- Merge Sort
- Quick Sort
- Counting Sort
*/
#include "sortingAlgorithms.h"


//Includes a vector generation function and a vector verification function.
//"vectorGenerator" Returns 1 if generation was successful or 0 if it failed to do so.
//"vectorVerifier" Returns 1 if the input vector is sorted or 0 if it is not.
#include "vectorFunctions.h"


//Converts data from memory counters into memory usage in megabytes.
double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
    return ((double)info.PeakWorkingSetSize/(1024*1024));
}


//Receives data from "benchmark" function and prints it to console.
void printResults(double cpu_time_used, double memory_used, int algorithm, int vector_size, int generation_type)
{
    printf("------------------------------\n");
    printf("Algorithm: ");

    switch(algorithm)
    {
            case 1:
                printf("Bubble Sort.\n");
                break;

            case 2:
                printf("Selection Sort.\n");
                break;

            case 3:
                printf("Insertion Sort.\n");
                break;

            case 4:
                printf("Shell Sort.\n");
                break;

            case 5:
                printf("Heap Sort.\n");
                break;

            case 6:
                printf("Merge Sort.\n");
                break;

            case 7:
                printf("Quick Sort.\n");
                break;

            case 8:
                printf("Counting Sort.\n");
                break;

            default:
                printf("Error!\n");
                exit(3); //Means that the algorithm value is invalid.
        }

    printf("Vector Size: %d.\n", vector_size);
    printf("Vector Generation Type: ");

    switch(generation_type)
    {
            case 1:
                printf("Ascending.\n");
                break;

            case 2:
                printf("Descending.\n");
                break;

            case 3:
                printf("Random.\n");
                break;

            default:
                printf("Error!\n");
                exit(4); //Means that the vector generation type is invalid.
        }

    printf("Runtime: %f Seconds.\n", cpu_time_used);
    printf("Memory Usage: %f MB.\n", memory_used);
}


//Receives data from "benchmark" function and converts into a .dat file (BenchmarkResults.dat).
void saveResults(double cpu_time_used, double memory_used, int algorithm, int vector_size, int generation_type)
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
        fprintf(BenchmarkResults, "Algorithm: ");

        switch(algorithm)
        {
            case 1:
                fprintf(BenchmarkResults, "Bubble Sort.\n");
                break;

            case 2:
                fprintf(BenchmarkResults, "Selection Sort.\n");
                break;

            case 3:
                fprintf(BenchmarkResults, "Insertion Sort.\n");
                break;

            case 4:
                fprintf(BenchmarkResults, "Shell Sort.\n");
                break;

            case 5:
                fprintf(BenchmarkResults, "Heap Sort.\n");
                break;

            case 6:
                fprintf(BenchmarkResults, "Merge Sort.\n");
                break;

            case 7:
                fprintf(BenchmarkResults, "Quick Sort.\n");
                break;

            case 8:
                fprintf(BenchmarkResults, "Counting Sort.\n");
                break;

            default:
                printf("Error!\n");
                exit(3); //Means that the algorithm value is invalid.
        }

        fprintf(BenchmarkResults, "Vector Size: %d.\n", vector_size);
        fprintf(BenchmarkResults, "Vector Generation Type: ");

        switch(generation_type)
        {
            case 1:
                fprintf(BenchmarkResults, "Ascending.\n");
                break;

            case 2:
                fprintf(BenchmarkResults, "Descending.\n");
                break;

            case 3:
                fprintf(BenchmarkResults, "Random.\n");
                break;

            default:
                printf("Error!\n");
                exit(4); //Means that the vector generation type is invalid.
        }

        fprintf(BenchmarkResults, "Runtime: %f Seconds.\n", cpu_time_used);
        fprintf(BenchmarkResults, "Memory Usage: %f MB.\n\n\n\n", memory_used);
    }

    printf("Results saved.\n");
    printf("------------------------------\n\n\n\n");

    fclose(BenchmarkResults);
}


//Benchmark function monitors CPU runtime and memory usage of sorting algorithms.
//Receives a integer that indicates which sorting algorithm it should run.
//Returns 1 if benchmark was successful.
int benchmark(int algorithm)
{
    //Algorithm types:
    /*
    1 - Bubble Sort
    2 - Selection Sort
    3 - Insertion Sort
    4 - Shell Sort
    5 - Heap Sort
    6 - Merge Sort
    7 - Quick Sort
    8 - Counting Sort
    */

    clock_t start_time, end_time;
    double cpu_time_used, memory_used;
    /*size_t peakSize;*/
    int error;

    int vector_size = 1000, generation_type = 1; //Standard benchmark, vector with 1000 integers and ascending number generation.
    //Generation types:
    /*
    1 - Ascending.
    2 - Descending.
    3 - Random.
    */

    //Runs benchmark until vector size reaches 100000 integers.
    do
    {

        //Runs benchmark for every type of vector generation (ascending, descending, random).
        do
        {

            //Vector Generation (not included in benchmark time/memory usage).
            int* vector = (int*)malloc(vector_size * sizeof(int));
            error = vectorGenerator(vector, vector_size, generation_type);
            if(error == 0)
            {
                printf("Error!\n");
                exit(1); //Means that the function "vectorGeneration" has failed to to fill the vector with integers.
            }


            //Benchmark start.
            start_time = clock();

            switch(algorithm)
            {
                case 1:
                    bubbleSort(vector, vector_size);
                    break;

                case 2:
                    selectionSort(vector, vector_size);
                    break;

                case 3:
                    insertionSort(vector, vector_size);
                    break;

                case 4:
                    shellSort(vector, vector_size);
                    break;

                case 5:
                    heapSort(vector, vector_size);
                    break;

                case 6:
                    mergeSort(vector, vector_size);
                    break;

                case 7:
                    quickSort(vector, vector_size);
                    break;

                case 8:
                    [countingSort(vector, vector_size);
                    break;

                default:
                    exit(300); //Means that the algorithm is invalid.
            }


            //Benchmark end.
            end_time = clock();
            cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
            memory_used = get_memory_used_MB();


            //Checks if vector if sorted:
            error = vectorVerifier(vector, vector_size);
            if(error == 0)
            {
                printf("Invalid Benchmark!\n");

                exit(100); //Means that the benchmark is invalid because the vector is not sorted properly!
            }
            free(vector);


            //Shows status on console:
            printResults(cpu_time_used, memory_used, algorithm, vector_size, generation_type);


            //Saves results in text file:
            saveResults(cpu_time_used, memory_used, algorithm, vector_size, generation_type);

            generation_type++;
        } while(generation_type <= 3);

        vector_size += 1000;
        generation_type = 1;
    } while(vector_size <= 100000);

    return 1;
}
