#include <stdlib.h>

int Swap(int* a, int* b)
{
    if (*a == *b)
    {
        return 0;
    }

    int t = *a;
    *a = *b;
    *b = t;
    return 0;
}

// Sorts in ascending order
int SelectionSort(int* array, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                Swap(&array[i], &array[j]);
            }
        }
    }
    return 0;
}

// Sorts in ascending order
int InsertionSort(int* array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int t = array[i];
        for (int j = i-1; j >= 0; j--)
        {
            if (t >= array[j])      
            {
                array[j+1] = t;
                break;
            }
            array[j+1] = array[j];
            if (j == 0)
            {
                array[0] = t;
                break;
            }
        }
    }
    return 0;
}

int Merge(int* array, int* array2, int left, int mid, int right)
{
    int iLeft = left;
    int iRight = mid+1;
    int iMerge;

    // update array to match sorted subsets
    int diff = right - left;
    for (int i = left; i <= right; i++)
    {
        array2[i] = array[i];
    }

    for (iMerge = left; iMerge < right; iMerge++)
    {
        if (iLeft <= mid && iRight <= right)   // check bounds
        {
            if (array2[iLeft] <= array2[iRight])    // output will be in ascending order
            {
                array[iMerge] = array2[iLeft];  
                iLeft++;
            }
            else 
            {
                array[iMerge] = array2[iRight];
                iRight++;
            }
        }
        else 
        {
            break;
        }
    }

    // copy remaining left elements
    while (iLeft <= mid)
    {
        array[iMerge] = array2[iLeft];
        iLeft++;
        iMerge++;
    }

    // copy remaining right elements
    while (iRight <= right)
    {
        array[iMerge] = array2[iRight];
        iRight++;
        iMerge++;
    }

    return 0;
}

int MergeSplit(int* array, int* array2, int left, int right)
{
    if (left >= right)
    {
        return 0;
    }

    int mid = left + (right - left) / 2;   // may overflow for large left/right values

    MergeSplit(array, array2, left, mid);

    MergeSplit(array, array2, mid+1, right);

    Merge(array, array2, left, mid, right);

    return 0;
}

// Sorts in ascending order
int MergeSort(int* array, int size)
{
    int* array2 = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        array2[i] = array[i];
    }

    MergeSplit(array, array2, 0, size-1);

    free(array2);

    return 0;
}

int LomutoPartition(int* array, int left, int right)
{
    int pivot = array[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        if (array[j] < pivot)
        {
            Swap(&array[i++], &array[j]);
        }
    }

    Swap(&array[i], &array[right]);
    return i;

}

// Sorts in ascending order
int QuickSort(int* array, int left, int right)
{
    if (left >= right)
    {
        return 0;
    }

    int pivotIndex = LomutoPartition(array, left, right);

    QuickSort(array, left, pivotIndex-1);
    QuickSort(array, pivotIndex+1, right);

    return 0;
}

// Sorts in ascending order
int BubbleSort(int* array, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                Swap(&array[j], &array[j+1]);
            }
        }
    }
}