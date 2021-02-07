<details> <summary><strong> 1. Check AB </strong></summary>

# 1. Check AB

    Suppose you have a string made up of only 'a' and 'b'.

    Write a recursive function that checks if the string was generated using the following rules:
        a. The string begins with an 'a'
        b. Each 'a' is followed by nothing or an 'a' or "bb"
        c. Each "bb" is followed by nothing or an 'a'

    If all the rules are followed by the given string, return true otherwise return false.

**Sample Input**

    abb

**Sample Output**

    true

<details> <summary><strong>Code</strong></summary>

    bool helper(char* input);

    bool checkAB(char input[])
    {
        if(*input!='a')
            return false;
        return helper(input);
    }

    bool helper(char *input)
    {
        if(input[0]==0)
            return true;

        bool rule_2 = input[0]=='a' && (input[1]==0 || (input[1]=='a') || (input[1]=='b' && input[2]=='b'));
        if(rule_2)
            return helper(input+1);

        bool rule_3 = (input[0]=='b' && input[1]=='b') && (input[2]==0 || input[2]=='a');
         if(rule_3)
            return helper(input+2);

        return false;
    }

</details>

---

</details>

<details> <summary><strong> 2. Staircase </strong></summary>

# 2. Staircase

    A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs.
    You need to return number of possible ways W.

**Input Format**

    Line 1 : Integer N (No. of steps)

**Output Format**

    Line 1 : Integer W i.e. Number of possible ways

**Constraints**

    (1 <= N <= 30)

**Sample Input**

    4

**Sample Output**

    7

<details> <summary><strong>Code</strong></summary>

    int staircase(int n)
    {
        if(n<0)
            return 0; // no possible way to do this

        if(n==0)    // i.e we took a full step of length 1 or 2 or 3. Mark it as 'a' step.
            return 1;
        // taking no step is also a single operation. i.e don't move 0C0. This will not affect our ops in any way

        // we take a step of length 1 or 2 or 3, the remaining length's way's into 1 for each term
        // i.e
        // 1 f(n-1)
        // 2 f(n-2)
        // 3 f(n-3)
        // add them up = 1*f(n-1) + 1*f(n-2) + 1*f(n-3) = f(n-1) + f(n-2) + f(n-3)

        return staircase(n-1) + staircase(n-2) + staircase(n-3);
    }

    //  Resources
    //  https://www.youtube.com/watch?v=5o-kdjv7FD0
    //  https://www.dailycodingproblem.com/?ref=csdojo

</details>

---

</details>

<details> <summary><strong> 3. Binary Search (Recursive) </strong></summary>

# 3. Binary Search (Recursive)

    Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.

    Return -1 if x is not present in the given array.
    Note : If given array size is even, take first mid.

**Input Format**

    Line 1 : Array size

    Line 2 : Array elements (separated by space)

    Line 3 : x (element to be searched)

**Sample Input**

    6
    2 3 4 5 6 8
    5

**Sample Output**

    3

<details> <summary><strong>Code</strong></summary>

    int helper(int* A, int start, int end, int &x)
    {
        if(start==end)
        {
            if(A[start]==x)
                return start;
            return -1;
        } // base case

        if( x== A[(start+end)/2])     // calculation
            return (start+end)/2;
        else if(x < A[(start+end)/2])
            return helper(A, start, (start+end)/2 - 1, x); // recursive 1
        return helper(A, 1+(start+end)/2, end, x);    // recursive
    }

    int binarySearch(int input[], int size, int element) {
        // Write your code here
        if(size==0)
            return -1;
        return helper(input, 0, size-1, element);
    }

</details>

---

</details>

<details> <summary><strong> 4. Return subset of an array </strong></summary>

# 4. Return subset of an array

    Given an integer array (of length n), find and return all the subsets of input array.

    Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
    Note : The order of subsets are not important.

**Input Format**

    Line 1 : Size of array

    Line 2 : Array elements (separated by space)

**Sample Input**

    3
    15 20 12

**Sample Output**

    [] (this just represents an empty array, don't worry about the square brackets)
    12
    20
    20 12
    15
    15 12
    15 20
    15 20 12

<details> <summary><strong>Code</strong></summary>

    int subset(int input[], int n, int output[][20])
    {
        if (n == 0)
        {
            output[0][0] = 0; // length updated
            return 1;
        }

        int num = subset(input + 1, n - 1, output);

        // doing it in one go
        for (int i = 0; i < num; i++)
        {
            output[i + num][0] = output[i][0] + 1; // length updated
            output[i + num][1] = input[0];         // value prepended
            for (int j = 0; j < output[i][0]; j++)
            {
                output[i + num][j + 2] = output[i][j + 1];
            }
        }
        return 2 * num;
    }

</details>

---

</details>

<details> <summary><strong> 5. Print Subsets of Array </strong></summary>

# 5. Print Subsets of Array

    Given an integer array (of length n), find and print all the subsets of input array.

    Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

    Note : The order of subsets are not important. Just print the subsets in different lines.

**Input Format**

    Line 1 : Integer n, Size of array
    Line 2 : Array elements (separated by space)

**Constraints**

    1 <= n <= 15

**Sample Input**

    3
    15 20 12

**Sample Output**

    [] (this just represents an empty array, don't worry about the square brackets)
    12
    20
    20 12
    15
    15 12
    15 20
    15 20 12

<details> <summary><strong>Code</strong></summary>

    void helper(int *input, int n, int *output, int onum);

    void printSubsetsOfArray(int input[], int size)
    {
        int *b = new int[20];
        if (size != 0)
            helper(input, size, 0, 0);
    }

    void helper(int *input, int n, int *output, int onum)
    {
        if (n == 0)
        {
            for (int i = 0; i < onum; i++)
                cout << output[i] << " ";
            cout << endl;
            delete[] output;
            return;
        }

        int *contrib = new int[onum + 1];
        // int *op2 = new int[onum];

        for (int i = 0; i < onum; i++)
            contrib[i] = output[i];

        contrib[onum] = input[0];

        helper(input + 1, n - 1, output, onum);
        helper(input + 1, n - 1, contrib, onum + 1);

        delete[] contrib;
    }

</details>

---

</details>

<details> <summary><strong> 6. Return subsets sum to K </strong></summary>

# 6. Return subsets sum to K

    Given an array A of size n and an integer K, return all subsets of A which sum to K.

    Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

    Note : The order of subsets are not important.

**Input Format**

    Line 1 : Integer n, Size of input array
    Line 2 : Array elements separated by space
    Line 3 : K

**Constraints**

    1 <= n <= 20

**Sample Input**

    9
    5 12 3 17 1 18 15 3 17
    6

**Sample Output**

3 3
5 1

<details> <summary><strong>Code</strong></summary>

    /***
    You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

    In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
    For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
    	{{2, 1, 4},	// Length of this subset is 2
    	{2, 3, 2}}	// Length of this subset is 2

    Don’t print the subsets, just save them in output.
    ***/

    int subsetSumToK(int input[], int n, int output[][50], int k) {
        // Write your code here

    }

</details>

---

</details>

<details> <summary><strong> 7. Print subsets sum to K </strong></summary>

# 7. Print subsets sum to K

    Given an array A and an integer K, print all subsets of A which sum to K.
    Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

    Note : The order of subsets are not important. Just print them in different lines.

**Input Format**

    Line 1 : Size of input array
    Line 2 : Array elements separated by space
    Line 3 : K

**Constraints**

    1 <= n <= 20

**Sample Input**

    9
    5 12 3 17 1 18 15 3 17
    6

**Sample Output**

    3 3
    5 1

<details> <summary><strong>Code</strong></summary>

    void printSubsetSumToK(int input[], int size, int k)
    {
        // Write your code here
    }

</details>

---

</details>

<details> <summary><strong> 8. Return all codes - String </strong></summary>

# 8. Return all codes - String

    Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
    Note : The order of codes are not important. And input string does not contain 0s.

**Input Format**

    A numeric string

**Constraints**

    1 <= Length of String S <= 10

**Sample Input**

    1123

**Sample Output**

    aabc
    kbc
    alc
    aaw
    kw

<details> <summary><strong>Code</strong></summary>

    #include <string.h>
    using namespace std;

    int getCodes(string input, string output[10000]) {
        /*
        You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
        Also, return the number of codes return to the output string. You do not need to print anything.
        */
    }

</details>

---

</details>

<details> <summary><strong> 9. Print all codes - String </strong></summary>

# 9. Print all codes - String

    Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.

    Note : The order of codes are not important. Just print them in different lines.

**Input Format**

    A numeric string S

**Output Format**

    All possible codes in different lines

**Constraints**

    1 <= Length of String S <= 10

**Sample Input**

    1123

**Sample Output**

    aabc
    kbc
    alc
    aaw
    kw

<details> <summary><strong>Code</strong></summary>

    #include <string.h>
    using namespace std;

    void printAllPossibleCodes(string input)
    {
        /*
        Given the input as a string, print all its possible combinations. You do not need to return anything.
        */
    }

</details>

---

</details>

<details> <summary><strong> 10. Return Permutations - String </strong></summary>

# 10. Return Permutations - String

    Given a string S, find and return all the possible permutations of the input string.
    Note 1 : The order of permutations is not important.
    Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

**Input Format**

    String S

**Sample Input**

    abc

**Sample Output**

    abc
    acb
    bac
    bca
    cab
    cba

<details> <summary><strong>Code</strong></summary>

    #include <string>
    using namespace std;

    int returnPermutations(string input, string output[])
    {
       	/* Don't write main() function.
    	 * Don't read input, it is passed as function argument.
    	 * Print output as specified in the question
    	*/
    }

</details>

---

</details>

<details> <summary><strong> 11. Print Permutations - String </strong></summary>

# 11. Print Permutations - String

    Given a string, find and print all the possible permutations of the input string.

    Note : The order of permutations are not important. Just print them in different lines.

**Sample Input**

    abc

**Sample Output**

    abc
    acb
    bac
    bca
    cab
    cba

<details> <summary><strong>Code</strong></summary>

    #include <iostream>
    #include <string>
    using namespace std;

    void helper(string output, string input);

    void printPermutations(string input)
    {
        if(input.size()==0)
            return;
        helper("", input);
    }

    void helper(string output, string input)
    {
        if(input.size()==0)
        {
            cout << output << endl;
            return;
        }

        int num = input.size();
        // just the shift function
        for(int i = 0; i < num; i++)
            helper(output + input[i], input.substr(0, i) + input.substr(i+1));

    }

    // in the second half of the call, we just do our move to front "move"

</details>

---

</details>
