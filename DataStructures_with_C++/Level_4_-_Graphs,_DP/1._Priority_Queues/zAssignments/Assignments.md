# Assignments

<details> <summary><strong> 1. Check Max-Heap </strong></summary>

# 1. Check Max-Heap

    Given an array of integers, check whether it represents max-heap or not.

    Return true or false.

**Input format**

    Line 1 : An integer N i.e. size of the array
    Line 2 : N integers which are elements of the array, separated by spaces

**Sample Input**

    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

**Output Format**

    True if it represents max-heap and false if it is not a max-heap.

**Constraints** :

    1 <= N <= 10^5
    1 <= Ai <= 10^5

<details> <summary><strong>Code</strong></summary>

    bool checkMaxHeap(int arr[], int n)
    {
        if(n<=1)
            return true;

        int par = 0, child = 1;

        while(child<n) //left child exists
        {
            if(arr[par]>=arr[child])
            {
                if(child+1<n) // right one exists
                {
                    if(arr[par]>=arr[child+1])
                    {
                        par++; // parent updated
                        child = 2*par+1; // left child updated
                        continue;
                    }
                    else
                        return false;
                }
                else
                    return true;    // done with the tree, as right does not exist
            }
            else
                return false;    // the left one does not hold
        }
        // no need for else
        return true;
    }

</details>

---

</details>

<details> <summary><strong> 2. Kth largest element </strong></summary>

# 2. Kth largest element

    Given an array A of random integers and an integer k, find and return the kth largest element in the array.
    Try to do this question in less than O(nlogn) time.

**Input Format**

    Line 1 : An integer N i.e. size of the array
    Line 2 : N integers which are elements of the array, separated by spaces
    Line 3 : An integer k

**Output Format**

    kth largest element

**Input Constraints** :

    1 <= N, Ai, k <= 10^5

**Sample Input 1**

    6
    9 4 8 7 11 3
    2

**Sample Output 1**

    9

**Sample Input 2**

    8
    2 6 10 11 13 4 1 20
    4

**Sample Output 2**

    10

<details> <summary><strong>Code</strong></summary>

    #include<queue>
    #include<vector>
    using namespace std;

    int kthLargest(vector<int> arr, int n, int k)
    {
        //largest, getting rid of smaller elements. We need a min priority queue

        priority_queue<int, vector<int>, greater<int>> pq;

        // heapify first k elements
        for(int i=0; i<k; i++)
            pq.push(arr.at(i));

        // go and remove the minimum from the heap
        for(int i=k; i<n; i++)
        {
            if(arr.at(i) > pq.top())
            {
                pq.pop();
                pq.push(arr.at(i));
            }
        }
        // the element at top is the k'th largest element
        return pq.top();
    }

</details>

---

</details>

<details> <summary><strong> 3.  Merge K sorted arrays </strong></summary>

# 3. Merge K sorted arrays

    Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).

    Hint : Use Heaps.

**Input Format**

    Line 1 : Integer K
    Line 2 : Arrays 1 size (n1)
    Line 3 : Array 1 elements (separated by space)
    Line 4 : Array 2 size (n2)
    and so on for next arrays

**Sample Input**

    4
    3
    1 5 9
    2
    45 90
    5
    2 6 78 100 234
    1
    0

**Sample Output**

   0 1 2 5 6 9 45 78 90 100 234

<details> <summary><strong>Code</strong></summary>

    #include <queue>
    using namespace std;
    vector<int> mergeKSortedArrays(vector<vector<int> *> input)
    {
        int max_size = -10;
        for (auto arr : input)
        {
            if (max_size < arr->size())
                max_size = arr->size();
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ret;

        for (int i = 0; i < max_size; i++)
        {
            // add to heap
            for (auto arr : input)
            {
                if (i < arr->size())
                    pq.push(arr->at(i));
            }
            ret.push_back(pq.top());
            pq.pop();
        }

        // we need to pop out everything from pq
        while (pq.empty() == false)
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }

</details>

---

</details>

<details> <summary><strong> 4. Running median </strong></summary>

# 4. Running median

    You are given a stream of n integers. For every ith integer, add it to the running list of integers and print the resulting median (of the list till now).

    Print the only integer part of median.

**Input Format**

    Line 1 : An integer N denoting the number of integers in the stream
    Line 2 : N integers which are separated by spaces

**Output Format**

    After each new integer is added to the list print the updated median on a new line

**Input Constraints**:

    1 <= n <= 10^5
    1 <= Ai <= 10^5

**Sample Input**

    6
    6 2 1 3 7 5

**Sample Output**

    6
    4
    2
    2
    3
    4

**Sample Output Explanation**:

    S = {6}, median = 6
    S = {6, 2} -> {2, 6}, median = 4
    S = {6, 2, 1} -> {1, 2, 6}, median = 2
    S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
    S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
    S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

<details> <summary><strong>Code</strong></summary>

    #include<queue>
    using namespace std;

    void findMedian(int arr[], int n)
    {

        priority_queue<int> s;
        priority_queue<int,vector<int>,greater<int> > g;

        int med = arr[0];
        s.push(arr[0]);

        cout << med << endl;

        for (int i=1; i < n; i++)
        {
            int x = arr[i];

            // case1(left side heap has more elements)
            if (s.size() > g.size())
            {
                if (x < med)
                {
                    g.push(s.top());
                    s.pop();
                    s.push(x);
                }
                else
                    g.push(x);

                med = (s.top() + g.top())/2.0;
            }

            // case2(both heaps are balanced)
            else if (s.size()==g.size())
            {
                if (x < med)
                {
                    s.push(x);
                    med = (int)s.top();
                }
                else
                {
                    g.push(x);
                    med = (int)g.top();
                }
            }

            // case3(right side heap has more elements)
            else
            {
                if (x > med)
                {
                    s.push(g.top());
                    g.pop();
                    g.push(x);
                }
                else
                    s.push(x);

                med = (s.top() + g.top())/2.0;
            }

            cout << med << endl;
        }
    }

    /*
    void findMedian(int arr[], int n)
    {
        // we need the middle of a list with the first and second hald
        // a max on the left and a min on the right will do

        // we need to keep them balanced, we like to keep the number of 0 <= left - right <= 1

        // median = left's last for odd length
        // median = left last + right's first /2 for even length

        if(n==1)
        {
            cout << arr[0] <<"\n";
            return;
        }

        priority_queue<int> left; // max
        priority_queue<int, vector<int>, greater<int>> right; // min

        // for initial terms
        int l = arr[0] < arr[1] ? arr[0] : arr[1];
        int r = arr[0] + arr[1] - l;

        left.push(l);
        right.push(r);
        cout << arr[0] << "\n" << (arr[0] + arr[1])/2 << "\n";

        for(int i=2; i<n; i++) // for proper even and odd
        {
            // assume that both are balanced here
            // choosing the correct side
            if(arr[i] > right.top())
                right.push(arr[i]);
            else
                left.push(arr[i]);

            // Balance it at each step
            // Two cases of imbalance are possible
            //  1. Left is > than right by more than 1.
            //  2. Right is > than left. Not allowed.
            //
            int temp = 0;
            // while(1)
            // {
            if(left.size()-right.size()>1)
            {
                temp = left.top();
                left.pop();
                right.push(temp);
            }
            else if(right.size()>left.size())
            {
                temp = right.top();
                right.pop();
                left.push(temp);
            }
                // else    // everything is okay
                //     break;
            // }

            if(i%2==0) // meaning we have an odd number of elements in the system
                cout << left.top() << "\n";
            else
                cout << (left.top()+right.top())/2 << "\n";
        }
    }*/

</details>

---

</details>

<details> <summary><strong> 5. Buy the ticket </strong></summary>

# 5. Buy the ticket

    You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.

    A queue is maintained for buying the tickets and every person has attached with a priority (an integer, 1 being the lowest priority). The tickets are sold in the following manner -

    1. The first person (pi) in the queue asked to comes out.

    2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.

    3. Otherwise, give him the ticket (and don't make him stand in queue again).

    Giving a ticket to a person takes exactly 1 minutes and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.

    Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.

**Input Format**

    Line 1 : Integer N (Total number of people standing in queue)
    Line 2 : Priorities of every person (n space separated integers)
    Line 3 : Integer k (index of your priority)

**Output Format**

    Time required

**Sample Input 1**

    3
    3 9 4
    2

**Sample Output 1**

    2
**Sample Output 1 Explanation**:
    Person with priority 3 comes out. But there is a person with higher priority than him. So he goes and then stands in the queue at the end. Queue's status : {9, 4, 3}. Time : 0 secs.

    Next, the person with priority 9 comes out. And there is no person with higher priority than him. So he'll get the ticket. Queue's status : {4, 3}. Time : 1 secs.

    Next, the person with priority 4 comes out (which is you). And there is no person with higher priority than you. So you'll get the ticket. Time : 2 secs.

**Sample Input 2**:
    5
    2 3 2 2 4
    3

**Sample Output 2**:

    4

<details> <summary><strong>Code</strong></summary>

    #include<queue>
    int buyTicket (int *arr, int n, int k)
    {
        int time = 1;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>arr[k])
                time++;
            // if less, don't add time.
        }
        return time;
    }

</details>

---

</details>
