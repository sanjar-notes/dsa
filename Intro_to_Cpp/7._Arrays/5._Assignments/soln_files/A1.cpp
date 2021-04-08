/*
                                        <----Find Unique---->
Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.
You need to find and return that number which is unique in the array.
Note : Given array will always contain odd number of elements.
Input format :
Line 1 : Array size i.e. 2N+1
Line 2 : Array elements (separated by space)
Output Format :
Unique element present in the array
Constraints :
1 <= N <= 10^3
Sample Input :
7
2 3 1 6 3 6 2
Sample Output :
1
*/

int FindUnique(int *arr, int size)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    //     We'll traverse the array and look for the duplicates if none is found return the element
    //     If found next element

    //    But what about the fact that we have already matched an element, and there are no matches ahead
    //    So it will behave as if it's unique, to avoid this we mark it by making it -ve
    int j;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            continue;
        for (j = i + 1; j < size; j++)
        {
            // case when i = n-1, j will be n,and n<n is False, hence last element if unique taken care of
            if (arr[i] == arr[j])
            {
                arr[j] *= -1; // traversed
                break;
            }
            // else case is for that arr[i] which not equal to any in front(yes you don't need to go back)
        }
        // all traversed nothing found
        if (j == size)
            return arr[i];
    }
}
