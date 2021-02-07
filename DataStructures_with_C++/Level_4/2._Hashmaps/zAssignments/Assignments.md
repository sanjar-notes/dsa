# Assignments

<details> <summary><strong> 1. Extract Unique characters </strong></summary>

# 1. Extract Unique characters

    Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.

**Input format**

    String S

**Output format**

    Output String

**Constraints**:

    1 <= Length of S <= 50000

**Sample Input 1**

    ababacd

**Sample Output 1**

    abcd

**Sample Input 2**

    abcde

**Sample Output 2**

    abcde

<details> <summary><strong>Code</strong></summary>

    #include<unordered_set>
    #include<cstring>

    char* uniqueChar(char *str)
    {
        int length = strlen(str);
        // while(str[length]!=0)
        //     length++;
        // got length
        char * ret = new char[length]; // max size possible
        int j = -1;
        unordered_set<char> mp;
        for(int i=0; i<length; i++)
        {
            if(mp.count(str[i])==0) // not present
                ret[++j] = str[i], mp.insert(str[i]);
        }
        ret[++j] = 0;
        return ret;
    }

</details>

---

</details>

<details> <summary><strong> 2. Longest consecutive Sequence </strong></summary>

# 2. Longest consecutive Sequence

    You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.

    You need to return the output array which contains consecutive elements. Order of elements in the output is not important.

    Best solution takes O(n) time.

    If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.

**Input Format**

    Line 1 : Integer n, Size of array
    Line 2 : Array elements (separated by space)

**Constraints**:

    1 <= Length of S <= 50000

**Sample Input 1**

    13
    2 12 9 16 10 5 3 20 25 11 1 8 6

**Sample Output 1**

    8
    9
    10
    11
    12

**Sample Input 2**

    7
    3 7 2 1 9 8 1

**Sample Output 2**

    7
    8
    9
    Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.

**Sample Input 2**

    7
    15 24 23 12 19 11 16

**Sample Output 2**

    15
    16

<details> <summary><strong>Code</strong></summary>

    #include <vector>
    using namespace std;
    #include<unordered_map>
    vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
    {
        // Method 1: sort, this is o(nlogn)
        // Method 2: o(n) solution definitely need map, hash everything in the map
        unordered_map<int, bool> mp;
        for(int i=0; i<n; i++)
            mp[arr[i]] = true; // not part of a consecutive sequence

        // map ready
        int start = 0, maxLength = 0; // identifies the return value
        mp[arr[0]] = false;    // part of a sequence

        int tstart = 0, tlen = 0, curr = 0;

        int insequence = 0;    // just so that the for loop stops if we have visited all

        for(int i=0; i<n && insequence<n; i++) // this for loop ensures that the elements occurring in the array have an upper hand, as requited by the problem.
        {
            if(mp[arr[i]]==false)
                continue; // already part of a sequence

            tlen = 1;
            curr = arr[i];
            mp[arr[i]]=false; // being part of a sequence
            insequence++;

            // look forward
            while(mp.count(curr+1)==1 && mp[curr+1]==true)// exists and has not been visited
            {
                mp[++curr]=false;
                tlen++;
                insequence++;
            }

            // look back
            curr = arr[i];
            while(mp.count(curr-1)==1 && mp[curr-1]==true)
            {
                mp[--curr] = false;
                tlen++;
                tstart--; // start changes here
                insequence++;
            }

            if(tlen > maxLength) // if we formed a equilength sequence now, it will not be considered
            {
                start = tstart;
                maxLength = tlen;
                break;
            }

            if(tlen==maxLength)
                start = tstart < start ? tstart : start; // no update required for length
        }

        // make the vector
        vector<int> ret;
        for(int i=0; i<maxLength; i++)
            ret.push_back(i+start);

        return ret;
    }

</details>

---

</details>

<details> <summary><strong> 3. Pairs with difference K </strong></summary>

# 3. Pairs with difference K

    You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
    Best solution takes O(n) time. And take difference as absolute.

**Input Format**

    Line 1 : Integer n, Size of array
    Line 2 : Array elements (separated by space)
    Line 3 : K

**Output Format**

    Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
    (Order of different pairs is not important)

**Constraints**:

    1 <= n <= 5000

**Sample Input 1**

    4
    5 1 2 4
    3

**Sample Output 1**

    2 5
    1 4

**Sample Input 1**

    4
    4 4 4 4
    0

**Sample Output 1**

    4 4
    4 4
    4 4
    4 4
    4 4
    4 4

<details> <summary><strong>Code</strong></summary>

    using namespace std;
    #include<unordered_map>
    void printPairs(int *arr, int n, int k)
    {
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++)
            mp[arr[i]]++;
        // created a note pad with all occurrences

        if(k==0)    // just print each term frequency ! times
        {
            for(auto i=mp.begin(); i!=mp.end(); i++)
            {
                int fct = 1;
                for(int j=1; j<i->second; j++)
                    fct*=j;

                for(int j=0; j<fct; j++)
                    cout << i->first << " " << i->first << "\n";
            }
            return;
        }

        int n1 = 0;
        for(auto i=mp.begin(); i!=mp.end(); i++)
        {
            n1 = 0;
            if(mp.count((i->first) - k)!=0)
                n1 = mp[(i->first) - k];
            n1*=(i->second);
            for(int j=0; j<n1; j++)
                cout << (i->first) - k << " " << (i->first) << "\n";

            n1 = 0;
            if(mp.count((i->first) + k)!=0)
                n1 = mp[(i->first) + k];
            n1*=(i->second);
            for(int j=0; j<n1; j++)
                cout << (i->first) << " " << (i->first) + k << "\n";

            i->second = 0;
        }
    }

</details>

---

</details>

<details> <summary><strong> 4. Longest subset zero sum </strong></summary>

# 4. Longest subset zero sum

    Given an array consisting of positive and negative integers, find the length of the longest continuous subset whose sum is zero.

    NOTE: You have to return the length of longest subset.

**Input Format**

    Line 1 : Contains an integer N i.e. size of array
    Line 2 : Contains N elements of the array, separated by spaces

**Output Format**

     Line 1 : Length of longest continuous subset

**Sample Input**

    10
    95 -97 -387 -435 -5 -70 897 127 23 284

**Sample Output**

    5

<details> <summary><strong>Code</strong></summary>

    #include<unordered_map>
    using namespace std;

    int lengthOfLongestSubsetWithZeroSum(int* arr, int size)
    {
        // naive solution
        for(int l=size; l>0; l--)
        {
            // starting point is zero
            int sum = 0;
            for(int i = 0; i < size - l + 1; i++)
            {
                sum = 0;
                for(int in=i; in < i+l; in++)
                    sum+=arr[in];
                if(sum==0)
                    return l;
            }
        }
        return -1;
    }

</details>

---

</details>
