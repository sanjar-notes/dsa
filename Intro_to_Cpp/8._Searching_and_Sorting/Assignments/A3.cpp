/*
                                                <----Second Largest in array---->

Given a random integer array of size n, find and return the second largest element present in the array.
If n <= 1 or all elements are same in the array, return -2147483648 i.e. -2^31.
Input format :
Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)
Output Format :
Second largest element
Constraints :
1 <= N <= 10^6
Sample Input 1:
7
2 13 4 1 3 6 28
Sample Output 1:
13
Sample Input 2:
5
9 3 6 2 9
Sample Output 2:
6
Sample Input 3:
2
6 6
Sample Output 3:
-2147483648
*/

/ arr - input array
// n - size of array
#include<climits>
int FindSecondLargest(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n<=1)
            return INT_MIN;
    int max2=INT_MIN, max=arr[0]; // a is the final answer
    // b is larger anyday
    for(int i=0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max2 = max;
            max =arr[i];
        }
        else if(arr[i]<max && arr[i] >max2 ) // i.e lessening the gap between max and max2
                max2 = arr[i];
    }
    return max2;
}
