#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"
#include "Search.h"
#include "Generate.h"
#include "Console.h"

int main()
{
    printf("Binary Search\n\n");

    int min = ReadInt("Enter lower bound...");
    int max = ReadInt("Enter upper bound...");
    int size = ReadUInt("Enter capacity...");
    int target = ReadInt("Enter target...");

    time_t t;
    int* array = Generate(min, max, size, time(&t));

    SelectionSort(array, size);

    PrintArray(array, size);
    
    int index = BinarySearch(array, size, target);

    printf("Index=%d\n", index);
    
    free(array);

    return 0;
}

