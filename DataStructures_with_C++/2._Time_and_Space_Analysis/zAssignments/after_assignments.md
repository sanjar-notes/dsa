<details> <summary><strong> 1. Find the Unique Element </strong></summary>

# 1. Find the Unique Element

    Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.

    You need to find and return that number which is unique in the array.

    Note : Given array will always contain odd number of elements.

**Input Format**

    Line 1 : Array size i.e. 2N+1

    Line 2 : Array elements (separated by space)

**Output Format**

    Unique element present in the array

**Constraints**

    1 <= N <= 10^6

**Sample Input**

    7
    2 3 1 6 3 6 2

**Sample Output**

    1

<details> <summary><strong>Code</strong></summary>

    Using the associative and commumtative property of XOR, we will calculate the XOR of the array, which is mathematically equal to 0 ^ (distinct element) = distinct element, found it.
    // arr - input array
    // size - size of array

    int FindUnique(int arr[], int size)
    {
        int ret = 0;
        for(int i=0; i<size;i++)
            ret ^= arr[i];
        return ret;
    }

</details>

---

</details>

<details> <summary><strong> 2. Duplicate in array </strong></summary>

# 2. Duplicate in array

    Given an array of integers of size n which contains numbers from 0 to n - 2. Each number is present at least once. That is, if n = 5, numbers from 0 to 3 is present in the given array at least once and one number is present twice. You need to find and return that duplicate number present in the array.

    Assume, duplicate number is always present in the array.

**Input Format**

    Line 1 : Size of input array

    Line 2 : Array elements (separated by space)

**Output Format**

    Duplicate element

**Constraints**

    1 <= n <= 10^6

**Sample Input**

    9
    0 7 2 5 4 7 1 3 6

**Sample Output**

    7

<details> <summary><strong>Code</strong></summary>

    // arr - input array
    // size - size of array

    int MissingNumber(int arr[], int size)
    {
        int idealSum = (size-2)*(size-1)/2; // sum from 0 to n-2, i.e 1 is missing
        int realSum = 0;
        for(int i=0; i<size; i++)
            realSum+=arr[i];
        return realSum-idealSum;
    }

</details>

---

</details>

<details> <summary><strong> 3. Print Array intersection </strong></summary>

# 3. Print Array intersection

    Given two random integer arrays, print their intersection. That is, print all the elements that are present in both the given arrays.

    Input arrays can contain duplicate elements.

    Note : Order of elements are not important

**Input Format**

    Line 1 : Integer N, Array 1 Size

    Line 2 : Array 1 elements (separated by space)

    Line 3 : Integer M, Array 2 Size

    Line 4 : Array 2 elements (separated by space)

**Output Format**

    Print intersection elements in different lines

**Constraints**

    1 <= M, N <= 10^6

**Sample Input 1**

    6
    2 6 8 5 4 3
    4
    2 3 4 7

**Sample Output 1**

    2
    4
    3

**Sample Input 2**

    4
    2 6 1 2
    5
    1 2 3 4 2

**Sample Output 2**

    2
    2
    1

<details> <summary><strong>Code</strong></summary>

    // input1 - first array
    // input2 - second array
    // size1 - size of first array
    // size2 - size of second array
    void intersection(int input1[], int input2[], int size1, int size2)
    {
        std::sort(input1, input1+size1);
        std::sort(input2, input2+size2);
        int i = 0, j = 0;

        while(i < size1 && j < size2)
        {
            if(input1[i]==input2[j])
            {
                cout << input1[i] <<  endl;
                i++, j++;
            }
            else if(input1[i]<input2[j]) // you won't be able to find input2[j] except for the next elements of input1[i]
                i++;
            else if(input1[i]>input2[j]) // you won't be able to find input1[i] except for the next elements of input2[j]
                j++;
        }
        // that was easy enough
        // we can use maps too, time complexity is O(n)
    }

</details>

---

</details>

<details> <summary><strong> 4. Pair sum in array </strong></summary>

# 4. Pair sum in array

    Given a random integer array A and a number x. Find and print the pair of elements in the array which sum to x.

    Array A can contain duplicate elements.

    While printing a pair, print the smaller element first.

    That is, if a valid pair is (6, 5) print "5 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.

**Input Format**

    Line 1 : Integer N (Array size)

    Line 2 : Array elements (separated by space)

    Line 3 : Integer x

**Output Format**

    Line 1 : Pair 1 elements (separated by space)

    Line 2 : Pair 2 elements (separated by space)

    Line 3 : and so on

**Constraints**

    1 <= N <= 1000

    1 <= x <= 100

**Sample Input**

    9
    1 3 6 2 5 4 3 2 4
    7

**Sample Output**

    1 6
    3 4
    3 4
    2 5
    2 5
    3 4
    3 4

<details> <summary><strong>Code</strong></summary>

    #include<algorithm>
    void pairSum(int input[], int size, int x)
    {
        *// start from the two ends*
        // Advantage: As compare the biggest to the smallest, if they sum equals
        // the numbers at hand, then print em. Else leave them

        // We need to scan further as we might get the sum in the insides.

        // when we scan if ar[i]+arr[j]<su, move from the front. The left part(at hand) is useless
        // if(ar[i]+ar[j]>sum), right part(check with while) is useless.
        // when we get (ar[i]==arr[j])
        // case1: if(ar[i]==arr[j])
                // print the number len1*(len1-1)/2
        // case 2:
        // count the stretch for both the ends and print the numbers len1*len2 times.

        // T.C = nlong + n  = O(nlogn), SC = O(1)

        sort(input, input+size);
        int i = 0, j = size - 1;
        int len1 = 0, len2 = 0;
        while(i<j) // i==j is useless
        {

            if(input[i]==input[j]) // if both are equal then everything between them is the same
            {
                if(input[i]+input[j]!=x)
                    break;
                else  // redundant
                {
                    len1 = j-i+1;
                    for(int k=0; k < (len1*(len1-1))/2; k++)
                        cout << input[i] << " " << input[i] << endl;
                    break;
                }
            } // saves a lot of time, you can check the case using custom input

            else // input[i] is not equal to input[j]
            {
                if(input[i]+input[j]<x)
                {
                    while(i<j && input[i]+input[j]<x)
                        i++; // will stop is sum>=x the next case will take care of it.
                }
                else if(input[i]+input[j]>x)
                {
                    while(i<j && input[i]+input[j]>x)
                        j--; // will stop is sum>=x the next case will take care of it.
                }
                else
                {
                    len1 = 1, len2 = 1;
                    while(input[i]==input[++i]) // not equal so for sure will find a wall or interface
                        len1+=1; // don't worry about i and j as input[i] and input[j] cannot be the same for all values
                    while(input[j]==input[--j]) // not equal so for sure will find a wall or interface
                        len2+=1;
                    for(int k=0; k < len1*len2; k++)
                        cout << input[i-1] << " " << input[j+1] << endl;
                }
            }
        }
    }

</details>

---

</details>

<details> <summary><strong> 5. Triplet sum </strong></summary>

# 5. Triplet sum

    Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.

    While printing a triplet, print the smallest element first.

    That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which have to be printed on 1st line. You can print triplets in any order, just be careful about the order of elements in a triplet.

**Input Format**

    Line 1 : Integer N (Array Size)

    Line 2 : Array elements (separated by space)

    Line 3 : Integer x

**Output Format**

    Line 1 : Triplet 1 elements (separated by space)

    Line 2 : Triplet 3 elements (separated by space)

    Line 3 : and so on

**Constraints**

    1 <= N <= 1000

    1 <= x <= 100

**Sample Input**

    7
    1 2 3 4 5 6 7
    12

**Sample Output**

    1 4 7
    1 5 6
    2 3 7
    2 4 6
    3 4 5

<details> <summary><strong>Code</strong></summary>

    // arr - input array
    // size - size of array
    // x - sum of triplets

    void FindTriplet(int arr[], int size, int x)
    {
        /* Don't write main().
         * Don't read input, it is passed as function argument.
         * Print output and don't return it.
         * Taking input is handled automatically.
         */

    }

</details>

---

</details>

<details> <summary><strong> 6. Rotate array </strong></summary>

# 6. Rotate array

    Given a random integer array of size n, write a function that rotates the given array by d elements (towards left).

    Change in the input array itself. You don't need to return or print elements.

**Input Format**

    Line 1 : Integer n (Array Size)

    Line 2 : Array elements (separated by space)

    Line 3 : Integer d

**Output Format**

    Updated array elements (separated by space)

**Constraints**

    1 <= N <= 1000

    1 <= d <= N

**Sample Input**

    7
    1 2 3 4 5 6 7
    2

**Sample Output**

    3 4 5 6 7 1 2

<details> <summary><strong>Code</strong></summary>

    // arr - input array
    // n - size of array
    // d - array to be rotated by d elements

    #include<algorithm>
    void rotate(int *arr, int d, int n)
    {
        if(d==0)
            return;
    	d%=n;
        d = n-d;
        int buckets = __gcd(n, d);
        int bucket_size = n/buckets;
        int position = 0;
        int store = arr[0], swap;
        for(int i=0; i<buckets; i++)
        {
            for(int j=0; j<bucket_size; j++)
            {
                position = (position+d)%n;
                swap = arr[position];
                arr[position] = store;
                store = swap;
            }
            store=arr[++position]; // new bucket
        }
    }

</details>

---

</details>

<details> <summary><strong> 7. Check array rotation </strong></summary>
s
# 7. Check array rotation

    Given an integer array, which is sorted (in increasing order) and has been rotated by some number k in clockwise direction. Find and return the k.

**Input Format**

    Line 1 : Integer n (Array Size)

    Line 2 : Array elements (separated by space)

**Output Format**

    Integer k

**Constraints**

    1 <= n <= 1000

**Constraints**

    1 <= n <= 20

**Sample Input 1**

    6
    5 6 1 2 3 4

**Sample Output 1**

    2

**Sample Input 2**

    5
    3 6 8 9 10

**Sample Output 2**

    0

<details> <summary><strong>Code</strong></summary>

    // arr - input array
    // n - size of array

    int FindSortedArrayRotation(int arr[], int n)
    {
        /* Don't write main().
         * Don't read input, it is passed as function argument.
         * Return output and don't print it.
         * Taking input and printing output is handled automatically.
         */

    }

</details>

---

</details>
