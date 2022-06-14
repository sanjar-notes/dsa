/*
                                            <----Rotate array---->
Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
Change in the input array itself. You don't need to return or print elements.
Input format :
Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer d
Output Format :
Updated array elements (separated by space)
Constraints :
1 <= N <= 1000
1 <= d <= N
Sample Input :
7
1 2 3 4 5 6 7
2
Sample Output :
3 4 5 6 7 1 2

*/


// arr - input array
// size - size of array
// d - array to be rotated by d elements
void Rotate(int arr[], int d, int size)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    int n = size, vari = 0;
    for (int j = 0; j < d; j++)
    {
        vari = arr[0];
        for(int i=1; i<n; i++)
            arr[i-1]=arr[i];
        arr[n-1]=vari;
    }
}

// Time n*d, space = o(1)
// using aux array, space = o(n), time = o(n)
