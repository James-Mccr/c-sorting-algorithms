// Collection of tests for generation, sorting, and searching arrays
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Generate.h"
#include "Sort.h"
#include "Search.h"

int min = 0;
int max = 10;
int size = 100000;
int seed = 0;

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

int TestMergeSort()
{
    int actual[] = { 0,9,1,8,5,6,7,3,2,4 };
    int expected[] = { 0,1,2,3,4,5,6,7,8,9 };
    int size = sizeof(actual) / sizeof(int);
    MergeSort(actual, size);
    int flag = Equals(actual, expected, size);
    return flag;
}

int TestSelectionSort()
{
    int actual[] = { 0,9,1,8,5,6,7,3,2,4 };
    int expected[] = { 0,1,2,3,4,5,6,7,8,9 };
    int size = sizeof(actual) / sizeof(int);
    SelectionSort(actual, size);
    int flag = Equals(actual, expected, size);
    return flag;
}

int TestInsertionSort()
{
    int actual[] = { 0,9,1,8,5,6,7,3,2,4 };
    int expected[] = { 0,1,2,3,4,5,6,7,8,9 };
    int size = sizeof(actual) / sizeof(int);
    InsertionSort(actual, size);
    int flag = Equals(actual, expected, size);
    return flag;
}

int TestBinarySearchPasses()
{
    int array[] = { 0,1,2,3,4,5,6,7,8,9 };
    int size = sizeof(array) / sizeof(int);
    int target = 5;
    int index = BinarySearch(array, size, target);
    return index == target;
}

int TestBinarySearchFails()
{
    int array[] = { 0,1,2,3,4,5,6,7,8,9 };
    int size = sizeof(array) / sizeof(int);
    int target = 10;
    int index = BinarySearch(array, size, target);
    return index == -1;
}

int TestQuickSort()
{
    int actual[] = { 0,9,1,8,5,6,7,3,2,4 };
    int expected[] = { 0,1,2,3,4,5,6,7,8,9 };
    int size = sizeof(actual) / sizeof(int);
    QuickSort(actual, 0, size-1);
    int flag = Equals(actual, expected, size);
    return flag;
}

int TestBubbleSort()
{
    int actual[] = { 0,9,1,8,5,6,7,3,2,4 };
    int expected[] = { 0,1,2,3,4,5,6,7,8,9 };
    int size = sizeof(actual) / sizeof(int);
    BubbleSort(actual, size);
    int flag = Equals(actual, expected, size);
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

int main()
{
    // generation
    printf("TestGenerateMin...");
    if (TestGenerateMin())
    {
        passed();
    } 
    else
    {
        failed();
    }

    printf("TestGenerateMax...");
    if (TestGenerateMax())
    {
        passed();
    } 
    else 
    {
        failed();
    }

    printf("TestGenerateSize...");
    if (TestGenerateSize())
    {
        passed();
    }
    else
    {
        failed();
    }
    
    printf("TestGenerateSeed...");
    if (TestGenerateSeed())
    {
        passed();
    }
    else 
    {
        failed();
    }

    // sort
    printf("TestSelectionSort...");
    if (TestSelectionSort())
    {
        passed();
    }
    else 
    {
        failed();
    }

    printf("TestInsertionSort...");
    if (TestInsertionSort())
    {
        passed();
    }
    else
    {
        failed();
    }

    // search
    printf("TestBinarySearchPasses...");
    if (TestBinarySearchPasses())
    {
        passed();
    }
    else
    {
        failed();
    }

    printf("TestBinarySearchFails...");
    if (TestBinarySearchFails())
    {
        passed();
    }
    else
    {
        failed();
    }

    printf("TestMergeSort...");
    if(TestMergeSort())
    {
        passed();
    }
    else
    {
        failed();
    }

    printf("TestQuickSort...");
    if(TestQuickSort())
    {
        passed();
    }
    else
    {
        failed();
    }

    printf("TestBubbleSort...");
    if (TestBubbleSort())
    {
        passed();
    }
    else
    {
        failed();
    }

    return 0;
}