# MCQs

**1. Recurrence Relation for Tower of Hanoi Problem**

    The recurrence relation capturing the optimal execution time of the Towers of Hanoi problem with n discs is :

**Options**

    a. T(n) = 2T(n − 2) + 2
    b. T(n) = 2T(n − 1) + n
    c. T(n) = 2T(n/2) + 1
    d. T(n) = 2T(n − 1) + 1

<details> <summary><strong>Correct Answer</strong></summary>

    d. T(n) = 2T(n − 1) + 1
    Move the n-1 disc-heap to auxilary, move the heaviest disc to the destination. Then move the n-1 disc-heap to the destination.
    T(n-1) + 1 + T(n-1) = 2T(n-1) + 1

</details>

---

**Complexity of different operations in a sorted array.**

    Which of the following operations is not O(1) for an array of sorted data. You may assume that array elements are distinct.

**Options**

    a. Find the ith largest element
    b. Delete an element
    c. Find the ith smallest element
    d. All of the above

<details> <summary><strong>Correct Answer</strong></summary>

    b. Delete an element
    Catch all ops here are O(1) except delete because all elements are "distinct".

</details>

---

**Complexity of a Recurrence Relation**

    Which one of the following correctly determines the solution of the recurrence relation with T(1) = 1?

    T(n) = 2T(n/2) + Logn

**Options**

    a. O(N)
    b. O(NlogN)
    c. O(N^2)
    d. O(log N)

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(N)
    Make a recursion tree, add all values up

</details>

---

# Coding Problems

<details> <summary><strong> 1. Does s contain t ? </strong></summary>

# 1. Does s contain t ?

    Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).

    Return true or false.

    Do it recursively.

    E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.

**Input Format**

    Line 1 : String s
    Line 2 : String t

**Output Format**

    true or false

**Sample Input 1**

    abchjsgsuohhdhyrikkknddg
    coding

**Sample Output 1**

    1

**Sample Input 2**

    abcde
    aeb

**Sample Output 2**

    false

<details> <summary><strong>Code</strong></summary>

    bool checksequenece(char t[] , char*s)
    {
        if(*s==0)
            return true; // i.e all found or nothing to (or left to) search

        while(*t!=0 && *t!=*s)
            t++;
        if(*t==0)
            return false; // search space ends but not found
        return checksequenece(t+1, s+1);
    }

    // Time Complexity: O(n)
    // Space Complexity: O(n)

</details>

---

</details>

<details> <summary><strong> 2. Maximum Profit on App </strong></summary>

# 2. Maximum Profit on App

    You have made a smartphone app and want to set its price such that the profit earned is maximised. There are certain buyers who will buy your app only if their budget is greater than or equal to your price.

    You will be provided with a list of size N having budgets of buyers and you need to return the maximum profit that you can earn.

    Lets say you decide that price of your app is Rs. x and there are N number of buyers. So maximum profit you can earn is :

        m * x

    where m is total number of buyers whose budget is greater than or equal to x.

**Input Format**

    Line 1 : N (No. of buyers)
    Line 2 : Budget of buyers (separated by space)

**Output Format**

    Maximum profit

**Constraints**

    1 <= N <= 10^6

**Sample Input 1**

    4
    30 20 53 14

**Sample Output 1**

    60

**Sample Output 1 Explanation**

    Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.

**Sample Input 2**

    5
    34 78 90 15 67

**Sample Output 2**

    201

**Sample Output 2 Explanation**

    Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).

<details> <summary><strong>Code</strong></summary>

    #include<algorithm>
    int maximumProfit(int budget[], int n)
    {
        std::sort(budget, budget+n);

        int prev_profit = 0;
        int price = 0;
        int buyers = 0;

        int i = 0;

        while(i<n)
        {
            if(prev_profit < budget[i]*(n-i))
            {
                prev_profit = budget[i]*(n-i);
                price = budget[i];
                buyers = n-i;
            }

            while(i<=n-2 && budget[i]==budget[i+1]) // i<n-1 only for out of bounds check
                i++;

            i++; // on the different one
        }

        return price*buyers;
    }

    // T.C = O(nlogn)
    // S.C = O(n)

</details>

---

</details>

<details> <summary><strong> 3. Split Array </strong></summary>

# 3. Split Array

    Given an integer array A of size N, check if the input array can be splitted in two parts such that -

        - Sum of both parts is equal
        - All elements in the input, which are divisible by 5 should be in same group.
        - All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
        - Elements which are neither divisible by 5 nor by 3, can be put in any group.

    Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.

    Return true, if array can be split according to the above rules, else return false.

    Note : You will get marks only if all the test cases are passed.

**Input Format**

    Line 1 : Integer N (size of array)

    Line 2 : Array A elements (separated by space)

**Output Format**

    true or false

**Constraints**

    1 <= N <= 50

**Sample Input 1**

    2
    1 2

**Sample Output 1**

    false

**Sample Input 2**

    3
    1 4 3

**Sample Output 2**

    true

<details> <summary><strong>Code</strong></summary>

    bool splitArray(int *input, int size)
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
