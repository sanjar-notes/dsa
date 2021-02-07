<details> <summary><strong> 1. Code : Maximum Frequency Number </strong></summary>

# 1. Code : Maximum Frequency Number

    You are given with an array of integers that contain numbers in random order. Write a program to find and return the number which occurs maximum times in the given input.

    If more than one element occurs same number of times in the input, return the element which is present in the input first.

**Input format**

    Line 1 : An Integer N i.e. size of array
    Line 2 : N integers which are elements of the array, separated by spaces

**Output Format**

    Most frequent element

**Constraints**:

    1 <= N <= 10^5

**Sample Input 1**

    13
    2 12 2 11 12 2 1 2 2 11 12 2 6

**Sample Output 1**

    2

**Sample Input 2**

    3
    1 4 5

**Sample Output 2**

    1

<details> <summary><strong>Code</strong></summary>

    #include<unordered_map>
    int highestFrequency(int *input, int n)
    {
        unordered_map<int, int> mp;
        int max_int = 0;
        int freq = -1;
        for(int i=0; i<n; i++)
        {
            mp[input[i]]++; // increase the frequency
            // update only if frequency has increases
            // for elements with the same frequency and max value is for the max found first
            if(mp[input[i]]>freq)
            {
                freq = mp[input[i]];
                max_int = input[i];
            }
        }
        return max_int;
    }

</details>

---

</details>

<details> <summary><strong> 2. Code : Print Intersection </strong></summary>

# 2. Code : Print Intersection

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

**Constraints**:

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

    #include<unordered_map>
    using namespace std;

    #include<unordered_map>
    void intersection(int input1[], int input2[], int size1, int size2)
    {
        if(size1 > size2)
        {
            int temp = size1;
            size1 = size2;
            size2 = temp;
            int* tmp = input1;
            input1 = input2;
            input2 = tmp;
        }

        unordered_map<int, int> mp; // value and occurrences
        for(int i=0; i<size1; i++)
            mp[input1[i]]++;

        // got all the values with occurrences
        for(int i=0; i<size2; i++)
        {
            if(mp.count(input2[i])==1 && mp[input2[i]]>0)   // if any occurrences left
            {
                    cout << input2[i] << "\n";
                    mp[input2[i]]--; // printed
            }
        }
    }
    // TC = O(n)
    // SC = O(n)

</details>

---

</details>

<details> <summary><strong> 3. Code : Pair Sum to 0 </strong></summary>

# 3. Code : Pair Sum to 0

    Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.

    Array A can contain duplicate elements.

    While printing a pair, print the smaller element first.

    That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.

**Input Format**

    Line 1 : Integer N (Array size)
    Line 2 : Array elements (separated by space)

**Output Format**

    Line 1 : Pair 1 elements (separated by space)
    Line 2 : Pair 2 elements (separated by space)
    Line 3 : and so on

**Constraints**

    1 <= N <= 10^6

**Sample Input**

    5
    2 1 -2 2 3

**Sample Output**

    -2 2
    -2 2

<details> <summary><strong>Code</strong></summary>

    #include<unordered_map>
    using namespace std;

    void PairSum(int *input, int n)
    {
        // pass through the array and note the number of complements
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
            mp[input[i]]++; // starts at 0

        // numbers with their occurrences noted
        for(auto i=mp.begin(); i!=mp.end(); i++)
        {
            if(i->second!=0 && mp.count(-(i->first))==1) // if complement exists
            {
                int p = i->first > 0 ? i->first : -i->first;
                int k = mp[p] * mp[-p];

                for(int j=0; j<k; j++)
                    cout << -p << " " << p << "\n";
                mp[p]=mp[-p]=0;
            }
        }
    }

</details>

---

</details>
