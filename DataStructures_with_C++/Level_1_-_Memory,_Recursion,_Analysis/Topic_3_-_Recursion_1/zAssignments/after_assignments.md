# Multiplication (Recursive)

    Given two integers m & n, calculate and return their multiplication using recursion.
    You can only use subtraction and addition for your calculation.
    No other operators are allowed.
    Input format : m and n (in different lines)

**Sample Input**

    3
    5

**Sample Output**

    15

<details> <summary><strong>Code</strong></summary>

    int multiplyNumbers(int m, int n)
    {
        if(m==0|| n==0)// either of them could becime 0 depending on the first
            return 0;
        return n + multiplyNumbers(m-1, n);
    }

</details>

---

# Count Zeros

    Given an integer n, count and return the number of zeros that are present in the given integer using recursion.

    Input Format : Integer n
    Output Format : No. of 0s

**Sample Input**

    10204

**Sample Output**

    2

<details> <summary><strong>Code</strong></summary>

    int countZeros(int n)
    {
        if(n==0)
            return 0;
        if(n%10==0)
            return 1 + countZeros(n/10);
        else
            return 0 + countZeros(n/10);
    }

</details>

---

# Geometric Sum

    Given k, find the geometric sum i.e. 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)
    using recursion. Return the answer.

**Sample Input**

    3

**Sample Output**

    1.875

<details> <summary><strong>Code</strong></summary>

    double geometricSum(int k)
    {
        if(k==0)
            return 1;
        return 1.0 + geometricSum(k-1)/2.0;
    }

</details>

---

# Check Palindrome (recursive)

    Check if a given String S is palindrome or not (using recursion). Return true or false.
    Input Format : String S
    Output Format : true or false

**Sample Input 1**

    racecar

**Sample Output 1**

    true

**Sample Input 2**

    ninja

**Sample Output 2**

    false

<details> <summary><strong>Code</strong></summary>

    bool helper(char* start, char* end)
    {
        if(end<=start) // if equal, then true. A letter is same as itself, lame
            return true; // when they pass
        if(*start==*end)
            return helper(start+1, end-1);
        else
            return false;
    }

    bool checkPalindrome(char input[])
    {
        char* end = input;
        while(*end!=0)
            end++; // end at the null
        return helper(input, end-1); // we need to seek from the back
    }

    //Way better a solution then the CN solution. Elegance guarenteed

</details>

---

# Sum of Digits (recursive)

    Write a recursive function that returns the sum of the digits of a given integer.

**Sample Input**

    12345

**Sample Output**

    15

<details> <summary><strong>Code</strong></summary>

    int sumOfDigits(int n)
    {
        if(n==0)  // or n<=9 is better, 1 step less
            return 0;
        return n%10 + sumOfDigits(n/10);
    }

</details>

---
