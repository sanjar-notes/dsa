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
