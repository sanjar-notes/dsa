<details> <summary><strong> 1. Code : Min Steps to 1 (Brute Force) </strong></summary>

# 1. Code : Min Steps to 1 (Brute Force)

    Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.

        1.) Subtract 1 from it. (n= n - ­1) ,
        2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
        3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).

    Just write brute-force recursive solution for this.

**Input format**

    Line 1 : A single integer i.e. n

**Output format**

    Line 1 : Single integer i.e number of steps

**Constraints**:

    1 <= n <= 500

**Sample Input 1**

    4

**Sample Output 1**

    2

**Sample Output 1 Explanation**:

    For n = 4
    Step 1 : n = 4/2 = 2
    Step 2 : n = 2/2 = 1

**Sample Input 2**

    7

**Sample Output 2**

    3

**Sample Output 2 Explanation**:

    For n = 7
    Step 1 : n = 7 ­ - 1 = 6
    Step 2 : n = 6 / 3 = 2
    Step 3 : n = 2 / 2 = 1

<details> <summary><strong>Code</strong></summary>

    int countStepsTo1(int n)
    {
        if(n==1)
            return 0;

        int n1 = n, n2 = n, n3 = n;

        n1 = countStepsTo1(n-1) + 1;

        if(n%2==0)
            n2 = countStepsTo1(n/2) + 1;

        if(n%3==0)
            n3 = countStepsTo1(n/3) + 1;

        return min(n1, min(n2, n3));
    }

</details>

---

</details>

<details> <summary><strong> 1.2 Code : Min Steps to 1 (Memoized) </strong></summary>

# 1.2 Code : Min Steps to 1 (Memoized)

    Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.

        1.) Subtract 1 from it. (n= n - ­1) ,
        2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
        3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).

    Write a memoized recursive solution for this.

**Input format**

    Line 1 : A single integer i.e. n

**Output format**

    Line 1 : Single integer i.e number of steps

**Constraints**:

    1 <= n <= 500

**Sample Input 1**

    4

**Sample Output 1**

    2

**Sample Output 1 Explanation**:

    For n = 4
    Step 1 : n = 4/2 = 2
    Step 2 : n = 2/2 = 1

**Sample Input 2**

    7

**Sample Output 2**

    3

**Sample Output 2 Explanation**:

    For n = 7
    Step 1 : n = 7 ­ - 1 = 6
    Step 2 : n = 6 / 3 = 2
    Step 3 : n = 2 / 2 = 1

<details> <summary><strong>Code</strong></summary>

    // helper function
    int helper(int n, int* arr)
    {
        // base case: if present, return the answer
        if(arr[n]!=-1)
            return arr[n];

        // else - we need to calculate it

        int n1 = n-1, n2 = n-1, n3 = n-1; // max value is n-1

        n1 = helper(n-1, arr);    // steps required for n-1

        if(n%2==0)
                n2 = helper(n/2, arr);    // steps required for n/2

        if(n%3==0)
                n3 = helper(n/3, arr);    // steps required for n/3

        // store, we could have saved a function call if we checked if n/2 and /3 exist, that does not add to the complexity of the solution, as it is O(1)

        // also direct calling works because we save our work before returning

        arr[n] = min(n1, min(n2,n3)) + 1; // (steps required for the minimum dependency, among the three) + the step itself

        //return
        return arr[n];
    }

    // driver code, contains the store
    int countStepsTo1(int n)
    {
        int *arr = new int[n+1];

        arr[0] = arr[1] = 0;    //zero will never be reached, 1 is the answer we know

        for(int i=2; i<n+1; i++)    // initialize all uncalculated values to -1
            arr[i] = -1;

        return helper(n, arr);
    }

</details>

---

</details>

<details> <summary><strong> 2. Code : Min Steps to 1 using DP </strong></summary>

# 2. Code : Min Steps to 1 using DP

    Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.

        1.) Subtract 1 from it. (n= n - ­1) ,
        2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
        3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).

    The time complexity of your code should be O(n).

**Input format**

    Line 1 : A single integer i.e. n

**Output format**

    Line 1 : Single integer i.e number of steps

**Constraints**:

    1 <= n <= 500

**Sample Input 1**

    4

**Sample Output 1**

    2

**Sample Output 1 Explanation**:

    For n = 4
    Step 1 : n = 4/2 = 2
    Step 2 : n = 2/2 = 1

**Sample Input 2**

    7

**Sample Output 2**

    3

**Sample Output 2 Explanation**:

    For n = 7
    Step 1 : n = 7 ­ - 1 = 6
    Step 2 : n = 6 / 3 = 2
    Step 3 : n = 2 / 2 = 1

<details> <summary><strong>Code</strong></summary>

    // helper function
    int helper(int n, int* arr)
    {
        // base case: if present, return the answer
        if(arr[n]!=-1)
            return arr[n];

        // else - we need to calculate it

        int n1 = n-1, n2 = n-1, n3 = n-1; // max value is n-1

        n1 = helper(n-1, arr);    // steps required for n-1

        if(n%2==0)
                n2 = helper(n/2, arr);    // steps required for n/2

        if(n%3==0)
                n3 = helper(n/3, arr);    // steps required for n/3

        // store, we could have saved a function call if we checked if n/2 and /3 exist, that does not add to the complexity of the solution, as it is O(1)

        // also direct calling works because we save our work before returning

        arr[n] = min(n1, min(n2,n3)) + 1; // (steps required for the minimum dependency, among the three) + the step itself

        //return
        return arr[n];
    }

    // driver code, contains the store
    int countStepsTo1(int n)
    {
        int *arr = new int[n+1];

        arr[0] = arr[1] = 0;    //zero will never be reached, 1 is the answer we know

        for(int i=2; i<n+1; i++)    // initialize all uncalculated values to -1
            arr[i] = -1;

        return helper(n, arr);
    }

</details>

---

</details>

<details> <summary><strong> 3. Code : Staircase using DP </strong></summary>

# 3. Code : Staircase using DP

    A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.

    Time complexity of your code should be O(n).

**Input format**

    Integer n (No. of steps)

**Constraints**:

    n<=70

**Sample Input**

    4

**Sample Output**

    7

<details> <summary><strong>Code</strong></summary>

    // bottom up approach

    // concrete values of (n, staricase(n)): (0, 1), (1, 1), (2, 2), (3, 4)
    // every other value = arr[n-1] + arr[n-2] + arr[n-3]

    long staircase(int n)
    {
        // number of stores = n + 1
        long* arr = new long[n+2];

        for(int i=0; i< n+1;i++)
            arr[i] = -1L;

        arr[0] = 1;    // just don't move
        arr[1] = 1;    // 1 possible move
        arr[2] = 2;    // (1 + 1) or (2)
        arr[3] = 4;    // (1 + 1 + 1) or (1 + 2) or (2 + 1) or (3)

        // start from the first unknown, or else we'd have to check it for being -1, somewhat expensive
        // i.e n = 4

        for(int i=4; i<n+1; i++)
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];    // T.C = O(3*n) = O(n)
        return arr[n];
    }

</details>

---

</details>

<details> <summary><strong> 4. Code : Minimum Count </strong></summary>

# 4. Code : Minimum Count

    Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.

    That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.

    Note : x^y represents x raise to the power y.

**Input format**

    Integer N

**Output format**

    Required minimum count

**Constraints**:

    1 <= N <= 1000

**Sample Input 1**

    12

**Sample Output 1**

    3

**Sample Output 1 Explanation**:

    12 can be represented as :
    1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
    1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
    1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
    2^2 + 2^2 + 2^2
    As we can see, the output should be 3.

**Sample Input 2**

    9

**Sample Output 2**

    1

<details> <summary><strong>Code</strong></summary>

    // DP iterative
    // bottom-down approach

    // T(n) = sum from 2 to n[sum of 1 to sqrt(n)]
    // S = O(n)

    int minCount(int n)
    {
        int* arr = new int[n+1];
        // no initialization required

        // concrete answers
        arr[0] = 0;    // for perfect squares
        arr[1] = 1;    // 1 is 1^2

        // start from the unknowns
        for(int i=2; i<=n; i++)
        {
            // max value can be i*(1^1)
            int min = i, curr; // curr is current value, min is the minimum, we can omit this and write arr[i] directly

            for(int j=1; j*j<=i; j++)
            {
                curr =  1 + arr[i-j*j]; // represents f(n-j^2)+ j^2
                if(min > curr)
                    min = curr;
            }
            arr[i] = min;
        }
        return arr[n];
    }

    //--------------------------------------------------------------------------

    /* memoized solution

    // T(n) = sum from 2 to n[sum of 1 to sqrt(n)]
    // S = O(n)
    // recursion - so function overhead

    int minCount_h(int n, int* arr)
    {
        // arr[n] has the minimum value
        if(arr[n]!=-1)
            return arr[n];

        int min = n, curr; // n =  n^1 max
        // calculate
        for(int i=1; i*i<=n; i++)
        {
            curr = 1 + minCount_h(n-i*i, arr);
            if(min > curr)
                min = curr;
        }
        arr[n] = min; // store
        return arr[n];
    }

    int minCount(int n)
    {
        int* arr = new int[n+1];
        // in the worst case we require all

        for(int i=0; i<n+1; i++)
            arr[i] = -1;
        arr[0] = 0;
        return minCount_h(n, arr);
    }
    */

    //--------------------------------------------------------------------------

    /* brute force solution

    int minCount(int n)
    {
        if(n==0)
            return 0;

        int min = n, curr; // n =  n^1 max

        // start from i = 1, otherwise recursion is invalid
        for(int i=1; i*i<=n; i++)    // equality for perfect squares
        {
            curr = 1 + minCount(n-i*i);    // if perfect square, then answer is 1
            if(min > curr)
                min = curr;
        }
        return min;
    }
    */

</details>

---

</details>

<details> <summary><strong> 5. Code : No. of balanced BTs </strong></summary>

# 5. Code : No. of balanced BTs

    Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

    This number can be huge, so return output modulus 10^9 + 7.
    Write a simple recursive solution.

**Input format**

    Integer h

**Output format**

    Count % 10^9 + 7

**Constraints**:

    1 <= N <= 40

**Sample Input 1**

    3

**Sample Output 1**

    15

**Sample Input 2**

    4

**Sample Output 2**

    315

<details> <summary><strong>Code</strong></summary>

    prime = 1000000007
    # for making the outcomes collide the least

    def balancedBTBF(n):
        ''' Return no of balanced BT of height n using Brute Force'''
        if n<2:
            return 1
        h1 = balancedBTBF(n-1)
        h2 = balancedBTBF(n-2)
        return (h1*h1 + 2*h1*h2)%prime

    '''
    Explanation:

        For f(h),
        we can have the leftsubtree of max height h-1, same for the right subtree (as we need a balanced tree)
        Possible left and right subtree height values are:

        L       R                                Total trees possible
        h-1    h-1                                    f(h-1)*f(h-1)
        h-1    h-2 (difference of 1 is allowed)       f(h-1)*f(h-2)
        h-2    h-1 (difference of 1 is allowed)       f(h-2)*f(h-1)
                                            Total = f(h-1)*f(h-1) + 2*f(h-1)*f(h-2)
    '''

    # Main
    from sys import setrecursionlimit
    setrecursionlimit(11000)
    n=int(input())
    print(balancedBTBF(n))

</details>

---

</details>

<details> <summary><strong> 6. Code : No. of balanced BTs using DP</strong></summary>

# 6. Code : No. of balanced BTs using DP

    Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

    This number can be huge, so return output modulus 10^9 + 7.

    Write a dynamic programming approach

**Input format**

    Integer h

**Output format**

    Count % 10^9 + 7

**Constraints**:

    1 <= N <= 10^7

**Sample Input 1**

    3

**Sample Output 1**

    15

**Sample Input 2**

    4

**Sample Output 2**

    315

<details> <summary><strong>Code</strong></summary>

    # python3 code

    prime = 1000000007
    def balancedBTBF(n):
        # DP solution
        arr = [1, 1]    # for n = 0 and 1
        # as we are doing basic counting, no need of initialization.

        # starting from the unknown - 2
        for i in range(2, n+1):
            arr.append((arr[i-1]*arr[i-1] + 2*arr[i-1]*arr[i-2])%prime)
        return arr[n]%prime

    '''
    Explanation:

        For f(h),
        we can have the leftsubtree of max height h-1, same for the right subtree (as we need a balanced tree)
        Possible left and right subtree height values are:

        L       R                                Total trees possible
        h-1    h-1                                    f(h-1)*f(h-1)
        h-1    h-2 (difference of 1 is allowed)       f(h-1)*f(h-2)
        h-2    h-1 (difference of 1 is allowed)       f(h-2)*f(h-1)
                                            Total = f(h-1)*f(h-1) + 2*f(h-1)*f(h-2)

        DP insight:
        We make the solution from the concrete values, which are:
        arr[0] = 1
        arr[1] = 1
    '''

    # Main
    n=int(input())
    print(balancedBTBF(n))

</details>

---

</details>

