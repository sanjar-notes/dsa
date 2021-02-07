/*
                                        <----Triplet Sum---->
Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.
That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which have to be printed on 1st line. You can print triplets in any order, just be careful about the order of elements in a triplet.
Input format :
Line 1 : Integer N (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer x
Output format :
Line 1 : Triplet 1 elements (separated by space)
Line 2 : Triplet 3 elements (separated by space)
Line 3 : and so on
Constraints :
1 <= N <= 1000
1 <= x <= 100
Sample Input:
7
1 2 3 4 5 6 7
12
Sample Output ;
1 4 7
1 5 6
2 3 7
2 4 6
3 4 5
*/

// arr - input array
// size - size of array
// x - sum of triplets
#include <iostream>
using namespace std;
void FindTriplet(int *, int, int);
void FindTripletC(int *, int, int);
void printc(int, int, int);

int main()
{

    int size, x;
    cout << "Sum: ";
    cin >> x;
    cout << "Size: ";
    cin >> size;
    cout << "Enter values: ";
    int input[100] = {0};
    for (int i = 0; i < size; i++)
        cin >> input[i];

    FindTripletC(input, size, x);
    // printc(23, 12, 132);

    return 0;
}

void FindTriplet(int arr[], int size, int x)
{k
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */

    // We do kind of a chain here
    /*
        1. Select an element only if it is <=x-2(constraint is min 1), else continue
        2. Then complement init sum2 = x - ar[i] ahead of it.
        3. Look for pairs which add up to sum 2
            3. 1 choose a value ar[j] if ar[j] <= sum2 - 1
            3. 2 Search for the value ar[k] = sum2 - ar[j]
            3. 3 If found multiply both ar[j] and ar[k]. No need to mark anything here
        We'll take of duplicates later. Duplicates are allowed
    */

    for (int i = 0; i < size; i++)
    {
        // if (arr[i] > x - 2)
        //     continue;
        int sum2 = x - arr[i];

        // look for pairs with their sum being sum2
        for (int j = i + 1; j < size; j++)
        {
            // if (arr[j] > sum2 - 1)
            //     continue;
            int comp = sum2 - arr[j];

            // search for comp
            for (int k = j + 1; k < size; k++)
            {
                if (arr[k] == comp)
                {
                    // print them in order
                    int a = arr[i];
                    int b = arr[j];
                    int c = arr[k];

                    int p = 0, q = 0, r = 0;
                    if (a < b && a < c)
                        p = a;
                    else if (b < a && b < c)
                        p = b;
                    else //  c is the smallest
                        p = c;
                    if (p == a)
                    {
                        // a is the smallest
                        if (b < c)
                        {
                            q = b;
                            r = c;
                        }
                        else
                        {
                            q = c;
                            r = b;
                        }
                    }
                    else if (p == b)
                    {
                        if (a < c)
                        {
                            q = a;
                            r = c;
                        }
                        else
                        {
                            q = c;
                            r = a;
                        }
                    }
                    else // p==c
                    {
                        if (a < b)
                        {
                            q = a;
                            r = b;
                        }
                        else
                        {
                            q = b;
                            r = a;
                        }
                    }
                    // print p, q and r
                    cout << p << " " << q << " " << r << endl;
                }
            }
        }
    }
}

void FindTripletC(int *ar, int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        // if (ar[i] > sum - 2)
        //     continue;
        int sum2 = sum - ar[i];
        for (int j = i + 1; j < n; j++)
        {
            cout << ", sum2: " << sum2;

            // if (ar[j] > sum - 1)
            //     continue;
            int comp = sum2 - ar[j];
            for (int k = j + 1; k < n; k++)
            {
                cout << ", comp: " << comp;
                if (ar[k] == comp)
                {
                    printc(ar[i], ar[j], ar[k]);
                    cout << "FOund";
                }
            }
        }
    }
}

void printc(int a, int b, int c)
{
    int p, q, r;
    if (a < b && a < c)
        p = a; // q is the smallest
    else if (b < c && b < a)
        p = b; //
    else
        p = c;
    if (p == a)
    {
        if (b < c)
        {
            q = b;
            r = c;
        }
        else
        {
            q = c;
            r = b;
        }
    }
    else if (p == b)
    {
        if (a < c)
        {
            q = a;
            r = c;
        }
        else
        {
            q = c;
            r = a;
        }
    }
    else // i.e p==c is True
    {
        if (a < b)
        {
            q = a;
            r = b;
        }
        else
        {
            q = b;
            r = a;
        }
    }
    cout << p << " " << q << " " << r << endl;
}
