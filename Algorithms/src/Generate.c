#include <stdlib.h>

// malloc and fill a random array of integers
int* Generate(int min, int max, int size, unsigned int seed)
{
    srand(seed);
    int* array = malloc(sizeof(int) * size);   
    int range = max - min + 1;

    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % range) + min;
    }

    return array;
}