#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"
#include "Search.h"
#include "Generate.h"

int main()
{
    printf("Binary Search\n\n");

    printf("Enter lower bound...");
    int min;
    scanf("%d", &min);

    printf("Enter upper bound...");
    int max;
    scanf("%d", &max);

    printf("Enter capacity...");
    int size;
    scanf("%u", &size);

    printf("Enter target...");
    int target;
    scanf("%d", &target);

    time_t t;
    int* array = Generate(min, max, size, time(&t));

    SelectionSort(array, size);

    for (int i = 0; i < size-1; i++) 
    {
        printf("%d,", array[i]);
    }
    printf("%d\n", array[size-1]);
    
    int index = BinarySearch(array, size, target);

    printf("Index=%d\n", index);
    
    free(array);

    return 0;
}

