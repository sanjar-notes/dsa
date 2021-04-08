
/*
                                                    <----Sort 0 1 2---->
Send Feedback
You are given an integer array containing only 0s, 1s and 2s. Write a solution to sort this array using one scan only.
You need to change in the given array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)
Output Format :
Updated array elements (separated by space)
Constraints :
1 <= n <= 10^6
Sample Input:
7
0 1 2 0 2 0 1
Sample Output:
0 0 0 1 1 2 2
*/

void sort012(int arr[], int n)  {

    int i=0;
    // for (i=0; i<n; i++)
    //     arr[i] = 1;
    // int front = 0, back = n;
    int count[3]={0};

    for(i=0; i<n; i++)
    {
        if(arr[i]==0)
            count[0]++;
        else if(arr[i]==1)
            count[1]++;
        else
            count[2]++;
    }

    //o(2n), but not in one scan
    // reconstruct
    i = 0;

    while(count[0]--)
        arr[i++] = 0;
    while(count[1]--)
        arr[i++] = 1;
    while(count[2]--)
        arr[i++] = 2;

}
