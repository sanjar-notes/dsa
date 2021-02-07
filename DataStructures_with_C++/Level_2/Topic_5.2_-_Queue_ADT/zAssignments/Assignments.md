# Assignments

<details> <summary><strong> 1. Reverse Stack </strong></summary>

# 1. Reverse Stack

    Reverse a given Stack with the help of another empty stack. Two stacks will be given. Out of which first contains some integers and second one is empty. You need to reverse the first one using second stack. Change in the given first stack itself.

    Note : You don't need to print or return the stack, just reverse the given stack and it will be printed internally.

**Input format**

    Line 1 : Size of Stack

    Line 2 : Stack elements (separated by space)

**Output format**

    Index

**Sample Input 1**

    4
    1 2 3 4     (4 is at top)

**Sample Output 1**

    1 2 3 4    (1 is at top)

<details> <summary><strong>Code</strong></summary>

    #include <queue>
    // using stack implicitly
    void reverseQueue(queue<int> &q)
    {
        // using recursion

        //base case
        if (q.size() == 0)
            return;

        // calc1
        int p = q.front(); // 1 out from 1234, saved in p
        q.pop();           // 2 3 4

        // recursion
        reverseQueue(q); // 4 3 2

        // calc2
        q.push(p); // 4 3 2 1
    }

</details>

---

</details>

<details> <summary><strong> 2. Reverse Queue </strong></summary>

# 2. Reverse Queue

    Given a queue of integers, reverse it without help of any explicit stack or queue. You need to change in the given queue itself.
    Note : No need to return or print the queue.

**Input Format**

    First Element - Size of Queue, Rest Elements - Elements Of Queue

**Output Format**

    Queue elements

**Sample Input**

    4 1 2 3 4     (1 is at front)

**Sample Output**

    4 3 2 1    (4 is at front)

<details> <summary><strong>Code</strong></summary>

</details>

    #include <queue>
    // using stack implicitly
    void reverseQueue(queue<int> &q)
    {
        // using recursion

        //base case
        if (q.size() == 0)
            return;

        // calc1
        int p = q.front(); // 1 out from 1234, saved in p
        q.pop();           // 2 3 4

        // recursion
        reverseQueue(q); // 4 3 2

        // calc2
        q.push(p); // 4 3 2 1
    }

---

</details>

<details> <summary><strong> 3. Check redundant brackets </strong></summary>

# 3. Check redundant brackets

    Given a string mathematical expression, return true if redundant brackets are present in the expression. Brackets are redundant if there is nothing inside the bracket or more than one pair of brackets are present.

    Assume the given string expression is balanced and contains only one type of bracket i.e. ().

    Note: You will not get partial score for this problem. You will get marks only if all test cases are passed.

**Input Format**

    String s (Expression)

**Output Format**

    true or false

**Sample Input 1**

    ((a + b))

**Sample Output 1**

    true

**Sample Input 2**

    (a+b)

**Sample Output 2**

    false

<details> <summary><strong>Code</strong></summary>

    #include <stack>
    bool checkRedundantBrackets(char *input)
    {
        stack<char> s;
        while (*input != 0)
        {
            if (*input != ')')
                s.push(*input);
            else
            {
                int count = 0;
                while (s.top() != '(')
                {
                    s.pop();
                    count++;
                }
                if (count == 0) // Checked if there are any useful characters in between
                    return true;
                s.pop(); // remove the ( brace, move forward
            }

            input += 1;
        }
        return false;
    }
    /*
        How to do this:
            We use all characters, if redundant brackets are present they would, be just after each other.i.e with nothing in between. i.e () = ((a+b)) after the inner part is done.
            We can use stack to do easily as we can count if a+b is present or not, this done by keeping a count before popping.
    */

</details>

---

</details>

<details> <summary><strong> 4. Stock Span </strong></summary>

# 4. Stock Span

    The span si of a stock’s price on a certain day i is the minimum number of consecutive days (up to the current day) the price of the stock has been less than its price on that ith day. If for a particular day, if no stock price is greater then just count the number of days till 0th day including current day.

    For eg. if given price array is {3, 6, 8, 1, 2}, span for 4th day (which has price 2) is 2 because minimum count of consecutive days (including 4th day itself) from current day which has price less than 4th day is 2 (i.e. day 3 & 4). Similarly, span for 2nd day is 3 because no stock price in left is greater than 2nd day's price. So count is 3 till 0th day.

    Given an input array with all stock prices, you need to return the array with corresponding spans of each day.

    Note : Try doing it in O(n).

**Input Format**

    Line 1 : Integer n, Arrays Size

    Line 2 : Price for n days (separated by space). It can contain duplicate values.

**Output Format**

    Return an array that contain span for each day

**Constraints**

    Time Limit: 1 second
    Size of input array lies in the range: [1, 1000000]

**Sample Input 1**

    8
    60 70 80 100 90 75 80 120

**Sample Output 1**

    1 2 3 4 1 1 2 8

**Sample Input 2**

    4
    1 1 1 1

**Sample Output 2**

    1 1 1 1

<details> <summary><strong>Code</strong></summary>

    #include <stack>
    int *stockSpan(int *price, int size)
    {
        if (size == 0)
            return NULL;
        int *op = new int[size];
        stack<int> s;
        for (int i = 0; i < size; i++)
        {
            op[i] = 1;
            if (s.empty() == true || price[s.top()] > price[i]) // for empty stack and greater, push
                s.push(i);
            else
            {
                // start adding the smaller walls till you can
                while (s.empty() == false && price[s.top()] < price[i])
                {
                    op[i] += op[s.top()];
                    s.pop();
                }
                // after doing this, you are now facing an empty stack or a bigger one, push(), just like the if became true
                s.push(i);
            }
        }
        return op;
    }
    /*
        Insights: As we need to cut down calculation, we try to observe the system for natural caching points, the bigger prices are one here.
                1. If we are smaller, we are don. We mat be used for other days, so push.
                2. If we are bigger, we are just the sum of all the walls less than us.
            Note: Initializing to 1 was important here. Precision too.
        Complexity: As we are traversing each element once and removing it once. Hence 2*n steps so O(n)
    */

</details>

---

</details>

<details> <summary><strong> 5. Minimum bracket Reversal </strong></summary>

# 5. Minimum bracket Reversal

    Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.

    Return -1 if the given expression can't be balanced.

**Input Format**

    String S

**Output Format**

    Required count

**Sample Input 1**

    {{{

**Sample Output 1**

    -1

**Sample Input 2**

    {{{{}}

**Sample Output 2**

    1

<details> <summary><strong>Code</strong></summary>

    #include <stack>

    int countBracketReversals(char input[])
    {
        stack<char> s;
        int op = 0, cl = 0;
        while (*input != 0)
        {
            if (*input == '{')
            {
                s.push(*input);
                op++;
            }
            else if (s.empty() == false && s.top() == '{') // only parenthesis are present
            {
                s.pop(); //popped
                op--;
            }
            else
            {
                s.push(*input);
                cl++;
            }

            input++;
        }
        if ((op + cl) % 2 == 1)
            return -1;

        if (op % 2 == 1) // done mathematically
            return s.size() / 2 + 1;
        return s.size() / 2;
    }

</details>

---

</details>
