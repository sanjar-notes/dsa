/*

                                                <----Push Zeros to end---->
Send Feedback
Given a random integer array, push all the zeros that are present to end of the array. The respective order of other elements should remain same.
Change in the input array itself. You don't need to return or print elements. Don't use extra array.
Note : You need to do this in one scan of array only.
Input format :
Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)
Output Format :
Array elements (separated by space)
Constraints :
1 <= N <= 10^6
Sample Input 1:
7
2 0 4 1 3 0 28
Sample Output 1:
2 4 1 3 28 0 0
Sample Input 2:
5
0 3 0 2 0
Sample Output 2:
3 2 0 0 0
*/
// arr - input array
// n - size of array

void slide_window(int* arr, int &front, int &back, int n)
{
    if(back>=n-1)
        return;
    int vari = arr[back+1];
    for(int i=back;  i>=front; i--)
        arr[i+1] = arr[i];
    arr[front] =vari;
    front++;
    back++;
}
void PushZeroesEnd(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to return or print the output.
     * Taking input and printing output is handled automatically.
     */
    // how to do this
    int front=0, back = 0;
    while(front<n && arr[front++]!=0);
    // dynamic window, very very important
    if(front==n-1)
        return;
    front --;
    back = front;

   while(back!=n-1)
    {
        if(arr[back+1]==0)
            back++;
        else
            slide_window(arr, front, back,n);
    }
}


