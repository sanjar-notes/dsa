/*

                                        <----Sort 0 1---->
You are given an integer array A that contains only integers 0 and 1. Write a function to sort this array. Find a solution which scans the array only once. Don't use extra array.
You need to change in the given array itself. So no need to return or print anything.
Input format :
Line 1 : Integer N (Array Size)
Line 2 : Array elements (separated by space)
Output format :
Sorted array elements
Constraints :
1 <= N <= 10^6
Sample Input :
7
0 1 1 0 1 0 1
Sample Output :
0 0 0 1 1 1 1


*/
// arr - input array
// n - size of array

void SortZeroesAndOne(int arr[], int n)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Update in the given array itself. Don't return or print anything.
     * Taking input and printing output is handled automatically.
     */
    // T.C O(1) and S.C O(1)

    // start from both ends ignore if you find 0 on left and/or 1 on the right(coz that is already sorted)
    // then progress towards the center(either for 'and' or for 'or')
    // but if we find 0 on the right and a 1 on the left, swap them.

    for (int i = 0, j = n - 1; i < j;) //movement based on what is found
    {
        if (arr[i] == 1 and arr[j] == 0)
        {
            arr[i] = 0;
            arr[j] = 1;
        }
        else
        {
            if (arr[i] == 0)
                i++;
            if (arr[j] == 1)
                j--;
    }
        }
}
