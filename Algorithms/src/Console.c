// Functions related to console input/output

#include <stdio.h>

int ReadInt(char* message)
{
    printf("%s\n", message);
    int min;
    scanf("%d", &min);
    return min;
}

unsigned int ReadUInt(char* message)
{
    printf("%s\n", message);
    int min;
    scanf("%u", &min);
    return min;
}

int PrintArray(int* array, int size)
{
    for (int i = 0; i < size-1; i++) 
    {
        printf("%d,", array[i]);
    }
    printf("%d\n", array[size-1]);
}