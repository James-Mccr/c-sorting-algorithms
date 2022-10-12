// Collection of tests for generation, sorting, and searching arrays
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Generate.h"
#include "Sort.h"
#include "Search.h"

#define ARRAY_SIZE 11

int min = 0;
int max = 10;
int size = 100000;
int seed = 0;
int expected[] = { -1,0,1,2,3,4,5,6,7,8,9 };
int actual[] = { 4,7,0,9,2,6,1,5,3,8,-1 };

int* CreateTestArray()
{
    int* array = malloc(ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = actual[i];
    }
    return array;
}

int Equals(int* a, int* b, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!(a[i] == b[i]))
        {
            return 0;
        }
    }
    return 1;
}

int TestGenerateMin()
{
    int* actual = Generate(min, max, size, seed);
    for (int i = 0; i < size; i++)
    {
        if (actual[i] < min)
        {
            free(actual);
            return 0;
        }
    }
    free(actual);
    return 1;
}

int TestGenerateMax()
{
    int* actual = Generate(min, max, size, seed);
    for (int i = 0; i < size; i++)
    {
        if (actual[i] > max)
        {
            free(actual);
            return 0;
        }
    }
    free(actual);
    return 1;
}

int TestGenerateSize()
{
    int* actual = Generate(0, 0, size, seed);
    int* expected = calloc(size, sizeof(int)); 
    int flag = Equals(actual, expected, size);
    free(actual);
    free(expected);
    return flag;
}

int TestGenerateSeed()
{
    int lsize = 10;
    int* actual = Generate(min, max, lsize, seed);
    int expected[] = { 5,8,8,6,0,5,5,0,0,10 };
    int flag = Equals(actual, expected, lsize);
    free(actual);
    return flag;
}

int TestBinarySearchPasses()
{
    int* array = expected;
    int target = 5;
    int index = BinarySearch(array, ARRAY_SIZE, target);
    return array[index] == target;
}

int TestBinarySearchFails()
{
    int* array = expected;
    int target = 10;
    int index = BinarySearch(array, ARRAY_SIZE, target);
    return index == -1;
}

int TestSelectionSort()
{
    int* actual = CreateTestArray();
    SelectionSort(actual, ARRAY_SIZE);
    int flag = Equals(actual, expected, ARRAY_SIZE);
    free(actual);
    return flag;
}

int TestInsertionSort()
{
    int* actual = CreateTestArray();
    InsertionSort(actual, ARRAY_SIZE);
    int flag = Equals(actual, expected, ARRAY_SIZE);
    free(actual);
    return flag;
}

int TestMergeSort()
{
    int* actual = CreateTestArray();
    MergeSort(actual, ARRAY_SIZE);
    int flag = Equals(actual, expected, ARRAY_SIZE);
    free(actual);
    return flag;
}

int TestQuickSort()
{
    int* actual = CreateTestArray();
    QuickSort(actual, 0, ARRAY_SIZE-1);
    int flag = Equals(actual, expected, ARRAY_SIZE);
    free(actual);
    return flag;
}

int TestBubbleSort()
{
    int* actual = CreateTestArray();
    BubbleSort(actual, ARRAY_SIZE);
    int flag = Equals(actual, expected, ARRAY_SIZE);
    free(actual);
    return flag;
}

int TestHeapSort()
{
    int* actual = CreateTestArray();
    HeapSort(actual, ARRAY_SIZE);
    int flag = Equals(actual, expected, ARRAY_SIZE);
    free(actual);
    return flag;
}

int TestCountSort()
{
    int* actual = CreateTestArray();
    CountSort(actual, ARRAY_SIZE);
    int flag = Equals(actual, expected, ARRAY_SIZE);
    free(actual);
    return flag;
}

int TestRadixSort()
{
    int* actual = CreateTestArray();
    RadixSort(actual, ARRAY_SIZE);
    int flag = Equals(actual, expected, ARRAY_SIZE);
    free(actual);
    return flag;
}

void passed()
{
    printf("PASSED\n");
}

void failed()
{
    printf("FAILED\n");
    exit(1);
}

void AssertSuccess(int flag)
{
    if (flag)
    {
        passed();
    } 
    else
    {
        failed();
    }
}

int main()
{
    // generation
    printf("TestGenerateMin...");
    AssertSuccess(TestGenerateMin());

    printf("TestGenerateMax...");
    AssertSuccess(TestGenerateMax());

    printf("TestGenerateSize...");
    AssertSuccess(TestGenerateSize());
    
    printf("TestGenerateSeed...");
    AssertSuccess(TestGenerateSeed());

    // search
    printf("TestBinarySearchPasses...");
    AssertSuccess(TestBinarySearchPasses());

    printf("TestBinarySearchFails...");
    AssertSuccess(TestBinarySearchFails());

    // sort
    printf("TestSelectionSort...");
    AssertSuccess(TestSelectionSort());

    printf("TestInsertionSort...");
    AssertSuccess(TestInsertionSort());

    printf("TestMergeSort...");
    AssertSuccess(TestMergeSort());

    printf("TestQuickSort...");
    AssertSuccess(TestQuickSort());

    printf("TestBubbleSort...");
    AssertSuccess(TestBubbleSort());

    printf("TestHeapSort...");
    AssertSuccess(TestHeapSort());

    printf("TestCountSort...");
    AssertSuccess(TestCountSort());

    printf("TestRadixSort...");
    AssertSuccess(TestRadixSort());

    return 0;
}