# Lecture 1 and 2: Characters and Pointers

**Linear Search Worst Case**

    The Worst case(s) occur in linear search algorithm when -

**Options**

    a. Item is somewhere in the middle of the array
    b. Item is the last element in the array
    c. Item is present at first index of the array.
    d. Item is not in the array at all

<details> <summary><strong>Correct Answer</strong></summary>

    b. and d.
    Basics

</details>

---

**Linear Search**

    The worst case time complexity of Linear search is :

**Options**

    a. O(n)
    b. O(n^2)
    c. O(nlogn)
    d. O(logn)

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(n)
    Basics

</details>

---

**Insertion Sort Worst Case Time Complexity**

    Worst case time complexity of insertion sort is ?

**Options**

    a. O(n)
    b. O(n^2)
    c. O(nlogn)
    d. O(logn)

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(n^2)
    Basics

</details>

---

**Selection Sort Worst Case Time Complexity**

    Worst case time complexity of selection sort is ?

**Options**

    a. O(n)
    b. O(n^2)
    c. O(nlogn)
    d. O(logn)

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(n^2)
    Basics

</details>

---

# Lecture 3, 4 and 5: Analysis of basic sorting and searching algorithms

**Efficiency of an Algorithm**

    Two main measures for the efficiency of an algorithm are -

**Options**

    a. Processor and memory
    b. Complexity and capacity
    c. Time and space
    d. Data and space

<details> <summary><strong>Correct Answer</strong></summary>

    c. Time and space
    Basics

</details>

---

**Theoretical Analysis**

    In theoretical analysis the time factor when determining the efficiency of algorithm is measured by -

**Options**

    a. Counting microseconds
    b. Counting the number of statements in code
    c. Counting the number of unit operations
    d. Counting the kilobytes of algorithm

<details> <summary><strong>Correct Answer</strong></summary>

    c. Counting the number of unit operations
    Basics

</details>

---

**Time Complexity**

    If the number of primary operations of an algorithm that takes an array of size n as input are 3n^2 + 5n. The worst case time complexity of the algorithm will be ?

**Options**

    a. O(n^3)
    b. O((n^2)*logn)
    c. O(n^2)
    d. O(n)

<details> <summary><strong>Correct Answer</strong></summary>

    c. O(n^2)
    Basics

</details>

---

**Time Complexity of Code**

    What will be the Time Complexity of following code in terms of ‘n’ ?

    Refer the code for C++ -

    for(int i = 0; i < n; i++)
    {
        for(; i < n; i++)
        {
            cout << i << endl;
        }
    }

**Options**

    a. O(n)
    b. O(n^2)
    c. O(logn)
    d. O(nlogn)

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(n)
    i will be n in the inner loop itself.

</details>

---

**Time Complexity of Code**

    What will be the Time Complexity of following code in terms of ‘n’ ?

    Note : Assume k to be a constant value

    Refer the code for C++ -

    for(int i = 0; i < n; i++)
    {
        for(int j = 1 ; j < k; j++)
        {
            cout << (i + j ) << endl;
        }
    }

**Options**

    a. O(n^2)
    b. O(n)
    c. O(logn)
    d. None of these

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(n)
    i will be n in the inner loop itself.

</details>

---

**Time Complexity of Code**

    For merging two sorted arrays of size m and n into a sorted array of size m+n, we require operations -

**Options**

    a. O(m * n)
    b. O(m + n)
    c. O(m) if m >= n
    d. O(n) if n > m

<details> <summary><strong>Correct Answer</strong></summary>

    a. The time complexity is the worst time possible.
    Hence O(m+n)

</details>

---

**Recurrence for Merge Sort**

    What is the recurrence relation for merge sort :

**Options**

    a. T(n) = 2T(n/2)
    b. T(n) = 2T(n/2) + k
    c. T(n) = 2T(n/2) + O(n)
    d. T(n) = 2T(n/2) + O(log n)

<details> <summary><strong>Correct Answer</strong></summary>

    c. T(n) = 2T(n/2) + O(n)
    After we have successfully sorted the two halves, merge them O(n/2+/2) = O(n)

</details>

---

**Merge Sort**

    What is the time complexity of merge sort :

**Options**

    a. O(n)
    b. O(n^2)
    c. O(nlogn)
    d. O(log n)

<details> <summary><strong>Correct Answer</strong></summary>

    c. T(n) = 2T(n/2) + O(n)
    After we have successfully sorted the two halves, merge them, copy them k1*n + O(n/2+/2) = O(n)

</details>

---

**What is time complexity**

    What is the time complexity of following code ?

    int multiplyRec(int m, int n)
    {
        if(n == 1)
            return m;
        return m + multiplyRec(m,  n - 1);
    }

**Options**

    a. O(m*n)
    b. O(n)
    c. O(n^2)
    d. O(m)

<details> <summary><strong>Correct Answer</strong></summary>

    b. O(n)
    f(n) = k + f(n-1); f(n) = n*k + 0 = O(n)

</details>

---

**What is time complexity**

    int sumOfDigits(int n)
    {
            int sum;
            if(n < 10)
            {
                return n;
            }
            sum = (n % 10) + sumOfDigits(n / 10);
            return sum;
    }

**Options**

    a. O(logn) - log is to the base 10
    b. O(n)
    c. O(n^2)
    d. None of these

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(logn) - log is to the base 10
    Basics

</details>

---

**Fibonacci**

    What is the time complexity of following code for calculating nth fibonacci number
    long fib(int n)
    {
        if(n == 0 || n == 1)
        {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

**Options**

    a. O(n)
    b. O(n^2)
    c. O(2^n)
    d. O(n^3)

<details> <summary><strong>Correct Answer</strong></summary>

    c. O(2^n)
    assume n-2  ~ n-1 -> f(n) = 2*f(n-1)
    Exponential

</details>

---

# Lecture 8 and 9

**Merge Sort space**

    The space complexity for merge sort is :

**Options**

    a. O(n)
    b. O(n^2)
    c. O(nlogn)
    d. O(log n)

<details> <summary><strong>Correct Answer</strong></summary>

    c. O(n)

    A doubt: Why not take into account the memory of the stack?
    Ans: Maximum stack memory is 12*log(n) = (8 Bytes + 4Bytes ~ pointer + size) * logn. But for the array it is much greater i.e max(12logn, 4n) = O(n)

</details>

---

**Fibonacci**

    The space complexity for finding nth fibonacci number using recursion is :

**Options**

    a. O(n)
    b. O(2^n)
    c. O(log n)
    d. O(n^2)
    e. O(nlogn)

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(n)
    The max height, corresponding to the left most branch(if we do f(n-1) before f(n-2), from left to right). Only for the single variable.

</details>

---
