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

// Orders the given node and direct children (if any) into a max-heap structure
int MaxHeapify(int* array, int size, int parentIndex)
{
    int nodeIndex = parentIndex;
    int leftChildIndex = (2*parentIndex)+1;   // assume it exists, we'll check later
    int rightChildIndex = (2*parentIndex)+2;  

    if (leftChildIndex < size && array[leftChildIndex] > array[nodeIndex])
    {
        nodeIndex = leftChildIndex;
    }

    if (rightChildIndex < size && array[rightChildIndex] > array[nodeIndex])
    {
        nodeIndex = rightChildIndex;
    }

    if (nodeIndex != parentIndex)
    {
        Swap(&array[parentIndex], &array[nodeIndex]);

        MaxHeapify(array, size, nodeIndex); // recurse in case swap affects subtree (any of the descendants)
    }
}

int HeapSort(int* array, int size)
{
    // build max-heap
    // (size/2)-1 is the last non-leaf index
    for (int internalNodeIndex = (size/2)-1; internalNodeIndex >= 0; internalNodeIndex--)   
    {
        MaxHeapify(array, size, internalNodeIndex);
    }

    for (int i = size-1; i >= 0; i--)
    {   
        // move root node to end of array because it is in ascending order and we can ignore it for future iterations
        Swap(&array[0], &array[i]);

        // build max-heap
        MaxHeapify(array, i, 0);
    }

    return 0;
}

int CountSort(int* array, int size)
{
    // Get min and max since count array depends on the range of values
    int min = array[0];
    int max = min;
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        } 
        else if (array[i] > max)
        {
            max = array[i];
        }
    }

    int range = max - min + 1;

    int* counts = calloc(range, sizeof(int));
    int* output = malloc(size * sizeof(int));

    //  count each distinct value from input
    for (int i = 0; i < size; i++)
    {
        counts[array[i] - min]++;
    }

    // sum counts to get position of the values within output (this is not the index)
    for (int i = 1; i < range; i++)
    {
        counts[i] += counts[i-1];
    }

    // sort values into output
    for (int i = size-1; i >= 0; i--)
    {    
        output[counts[array[i]-min]-1] = array[i]; // offset position 1 to the right to get index
        counts[array[i]-min]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    free(counts);
    free(output);

    return 0;
}