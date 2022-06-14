/*

            THIS IS THE KEY TO KADANE'S ALGORITHM
            Difference: We don't have to shift anything in kadane's algorithm, time saved as compared to this.
                                                    <----Sum of two arrays---->
Send Feedback
Two random integer arrays are given A1 and A2, in which numbers from 0 to 9 are present at every
index (i.e. single digit integer is present at every index of both given arrays).
You need to find sum of both the input arrays (like we add two integers) and put the result in
another array i.e. output array (output arrays should also contain only single digits at every index).
The size A1 & A2 can be different.
Note : Output array size should be 1 more than the size of bigger array and place 0 at the 0th index if there is no carry.
 No need to print the elements of output array.
Input format :
Line 1 : Integer n1 (A1 Size)
Line 2 : A1 elements (separated by space)
Line 3 : Integer n2 (A2 Size)
Line 4 : A2 elements (separated by space)
Output Format :
Output array elements (separated by space)
Constraints :
1 <= n1, n2 <= 10^6
Sample Input 1:
3
6 2 4
3
7 5 6
Sample Output 1:
1 3 8 0
Sample Input 2:
3
8 5 2
2
1 3
Sample Output 2:
0 8 6 5
*/
// arr - input array
// n - size of array


void sumOfTwoArrays(int input1[], int size1, int input2[], int size2, int output[]){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output. Just fill the output in given output array.
     * Taking input and printing output is handled automatically.
     */
    int *ar1 = input1, *ar2=input2, n1=size1, n2=size2;
    // output is of size n1+n2 by 2.
    // clear the output
    // for(int i=0; i<)
    // Implementing Ripple Carry adder


    int e1=0, e2=0;
    int max = n1 > n2 ? n1 : n2;
     int carry = 0, sum = 0;
while(max>=0)
{
        e1 = 0; e2=0;
        if(n1>0)
            e1 = ar1[n1-1];
        if(n2>0)
            e2 = ar2[n2-1];

        sum = e1 + e2 + carry; // for this step
        carry = sum/10; // for the next step
        output[max] = sum%10;     // coz it is +1 in size, for the next step

        n1--, n2--, max--;
    }
}
