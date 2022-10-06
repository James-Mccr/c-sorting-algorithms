#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Generate.h"
#include "Sort.h"
#include "Console.h"

int main()
{
    printf("Quick sort\n\n");

    int min = ReadInt("Enter lower bound...");
    int max = ReadInt("Enter upper bound...");
    int size = ReadUInt("Enter capacity...");

    time_t t;
    int* array = Generate(min, max, size, time(&t));

    QuickSort(array, 0, size-1);

    PrintArray(array, size);

    free(array);

    return 0;
}