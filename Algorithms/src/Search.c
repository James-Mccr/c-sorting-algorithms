/* 
Binary Search algorithm 
For an array of n values a0, a1, ... , a(n-1)
Where values are sorted such that a0 <= a1 <= ... <= a(n-1)
Find index of target T

Set L to 0 and R to n-1.
If L > R, the search terminates as unsuccessful.
Set m (the position of the middle element) to the floor of L + R / 2, which is the greatest integer less than or equal to L + R / 2
If am < T, set L to m + 1 and go to step 2.
If am > T, set R to m - 1 and go to step 2.
Now am = T, the search is done; return m.
*/
int BinarySearch(int* array, int size, int target)
{
    int l = 0;
    int r = size-1;

    while (l <= r)
    {
        int m = (float)(l + r) / 2;

        if (array[m] < target)
        {
            l = m + 1;
        }
        else if (array[m] > target)
        {
            r = m - 1;
        }
        else 
        {
            return m;
        }
    }

    return -1;
}