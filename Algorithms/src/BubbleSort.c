#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Generate.h"
#include "Sort.h"
#include "Console.h"

int main()
{
    printf("Bubble sort\n\n");

    int min = ReadInt("Enter lower bound...");
    int max = ReadInt("Enter upper bound...");
    int size = ReadUInt("Enter capacity...");

    time_t t;
    int* array = Generate(min, max, size, time(&t));

    BubbleSort(array, size);

    PrintArray(array, size);

    free(array);

    return 0;
}