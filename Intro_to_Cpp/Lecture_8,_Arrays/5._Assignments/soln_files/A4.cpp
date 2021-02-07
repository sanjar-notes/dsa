/*
                                            <----Pair sum---->
Given a random integer array A and a number x. Find and print the pair of elements in the array which sum to x.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, 5) print "5 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
Input format:
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Line 3 : Integer x
Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on
Constraints:
1 <= N <= 1000
1 <= x <= 100
Sample Input:
9
1 3 6 2 5 4 3 2 4
7
Sample Output :
1 6
3 4
3 4
2 5
2 5
3 4
3 4
*/

/*
    Don't write main().
    * Don't read input, it is passed as function argument.
    * Print the output and don't return it.
    * Taking input is handled automatically.
*/

void pairSum(int ar[], int size, int sum)
{

    // 1. We select a number which is less than sum(constrainy is min=1, so no equality)
    // 2. We do a linear search for it's complement(i.e sum-ar[i])
    // 3. When we get a match, we print comp and ar[i] it in increasing order, i.e the pair.
    // Note: We need not care about multiplicity here, so no marking required and
    //      only search ahead(observation from last example).

    for (int i = 0; i < size; i++)
    {
        if (ar[i] >= sum)
            continue; // as no negatives are allowed and min =1 , hence no pairs would be found
        int comp = sum - ar[i];
        // do linear search ahead for comp
        for (int j = i + 1; j < size; j++)
        {
            if (ar[j] == comp)
            {
                if (comp < ar[i])
                    cout << comp << " " << ar[i] << endl;
                else
                    cout << ar[i] << " " << comp << endl; // equality is also OK
            }
        }
    }
}
