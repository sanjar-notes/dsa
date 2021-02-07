/*
                                            <----Find duplicate---->
Given an array of integers of size n which contains numbers from 0 to n - 2. Each number is present at least once. That is, if n = 5, numbers from 0 to 3 is present in the given array at least once and one number is present twice. You need to find and return that duplicate number present in the array.
Assume, duplicate number is always present in the array.
Input format :
Line 1 : Size of input array
Line 2 : Array elements (separated by space)
Output Format :
Duplicate element
Constraints :
1 <= n <= 10^3
Sample Input:
9
0 7 2 5 4 7 1 3 6
Sample Output:
7
*/

/*
    Don't write main().
    * Don't read input, it is passed as function argument.
    * Print the output and don't return it.
    * Taking input is handled automatically.
*/

// arr - input array
// size - size of array

int MissingNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    // range is 0 to n-2, hence n-1 numbers in all. 1 is duplicates. Total size n
    for (int i = 0, j; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
        // case when i = n-1, j will be n,and n<n is False, hence last element if unique taken care of
			if (arr[i] == arr[j])
				return arr[i];
        // else case is for that arr[i] which not equal to any in front(yes you don't need to go back)
		}
	}

}
