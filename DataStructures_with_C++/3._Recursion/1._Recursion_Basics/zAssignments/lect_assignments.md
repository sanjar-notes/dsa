# Power

    Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
    Do this recursively.

    Input format : Two integers x and n (separated by space)
    Output Format : x^n (i.e. x raise to the power n)
    Constraints :
    1 <= x <= 30
    0 <= n <= 30

**Sample Input 1**

    3 4

**Sample Output 1**

    81

**Sample Input 2**

    2 5

**Sample Output 2**

    32

<details> <summary><strong>Code</strong></summary>

    int power(int x, int n)
    {
        if(n==0)
            return 1;
        return x * power(x, n - 1);
    }

    // can be optimized using odd even value of the exponent

</details>

---

# Print Numbers

    Given the code to print number from 1 to n in increasing order recursively. But it contains few bugs, that you need to rectify such that all the test cases should pass.
    Input Format : Integer n
    Output Format : Numbers from 1 to n (separated by space)
    Constraints :
    1 <= n <= 10000

**Sample Input**

    6

**Sample Output**

    1 2 3 4 5 6

<details> <summary><strong>Code</strong></summary>

    void print(int n)
    {
        if(n == 1)
        {
            cout << n << " ";
            return;
        }

        print(n - 1);        // induction hypothesis and the next step in one go.
        cout << n << " ";
    }

</details>

---

# Number of Digits

    Given the code to find out and return the number of digits present in a number recursively. But it contains few bugs, that you need to rectify such that all the test cases should pass.
    Input Format : Integer n
    Output Format : Count of digits
    Constraints :
    1 <= n <= 10^6

**Sample Input**

    156

**Sample Output**

    3

<details> <summary><strong>Code</strong></summary>

    int count(int n){
        if(n < 10)
        {
            return 1;
        }

        int smallAns = count(n / 10);
        return smallAns + 1;
    }

</details>

---

# Sum of Array

    Given an array of length N, you need to find and return the sum of all elements of the array.
    Do this recursively.
    Input Format :
    Line 1 : An Integer N i.e. size of array
    Line 2 : N integers which are elements of the array, separated by spaces
    Output Format :
    Sum
    Constraints :
    1 <= N <= 10^3

**Sample Input**

    3
    9 8 9

**Sample Output 1**

    26

<details> <summary><strong>Code</strong></summary>

    int sum(int input[], int n)
    {
        if(n==0)
            return 0;
        return input[0] + sum(input + 1, n - 1);
    }

</details>

---

# Check Number

    Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
    Do this recursively.
    Input Format :
    Line 1 : An Integer N i.e. size of array
    Line 2 : N integers which are elements of the array, separated by spaces
    Line 3 : Integer x
    Output Format :
    true or false
    Constraints :
    1 <= N <= 10^3

**Sample Input**

    3
    9 8 10
    8

**Sample Output**

    true

<details> <summary><strong>Code</strong></summary>

    bool checkNumber(int input[], int size, int x)
    {
        if(size==0)
            return false; // base case
        // hypothesis -> assumed to be true

        // return true if the current one is the key or that remaining has it
        if(input[0]==x || checkNumber(input+1, size-1, x)==true)
            return true;
        return false;
    }

</details>

---

# First Index of Number

    Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
    First index means, the index of first occurrence of x in the input array.
    Do this recursively. Indexing in the array starts from 0.

    Input Format :
    Line 1 : An Integer N i.e. size of array
    Line 2 : N integers which are elements of the array, separated by spaces
    Line 3 : Integer x
    Output Format :
    first index or -1
    Constraints :
    1 <= N <= 10^3

**Sample Input**

    4
    9 8 10 8
    8

**Sample Output**

    1

<details> <summary><strong>Code</strong></summary>

    int firstIndex(int input[], int size, int x)
    {
        if(size==0)
            return -1; // if at all we reach an end

        if(input[0]==x)
            return 0;

        // if this is don't find it

        int k = firstIndex(input+1, size-1, x);
        // hav to take this variable as I have to compare the value I get, and 'pass' it.

        if(k==-1)
            return -1;
        return k+1;     // for add operation, we used k as the dummy variable
    }

</details>

---

# All Indices of Number

    Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
    Do this recursively. Indexing in the array starts from 0.
    Input Format :
    Line 1 : An Integer N i.e. size of array
    Line 2 : N integers which are elements of the array, separated by spaces
    Line 3 : Integer x
    Output Format :
    indexes where x is present in the array (separated by space)
    Constraints :
    1 <= N <= 10^3

**Sample Input**

    5
    9 8 10 8 8
    8

**Sample Output**

    1 3 4

<details> <summary><strong>Code</strong></summary>


    int allIndexes(int input[], int size, int x, int output[])
    {
        static int index = -1;
        if(size==0)
            return 0;
        if(input[++index]==x)
        {
            *output = index;
            return 1 + allIndexes(input, size-1, x, output+1);
        }
        return 0 + allIndexes(input, size-1, x, output);
    }
     // done easy. Just needed a static variable or use a helper function with a remenant of the static variable

</details>

---
