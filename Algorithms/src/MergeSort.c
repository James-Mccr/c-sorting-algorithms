#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Generate.h"
#include "Sort.h"

int main()
{
    printf("Merge sort\n\n");

    printf("Enter lower bound...");
    int min;
    scanf("%d", &min);

    printf("Enter upper bound...");
    int max;
    scanf("%d", &max);

    printf("Enter capacity...");
    int size;
    scanf("%u", &size);

    time_t t;
    int* array = Generate(min, max, size, time(&t));

    MergeSort(array, size);

    for (int i = 0; i < size-1; i++) 
    {
        printf("%d,", array[i]);
    }
    printf("%d\n", array[size-1]);

    free(array);

    return 0;
}