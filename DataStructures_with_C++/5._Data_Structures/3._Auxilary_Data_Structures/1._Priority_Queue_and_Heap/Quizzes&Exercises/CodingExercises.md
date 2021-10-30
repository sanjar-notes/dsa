<details> <summary><strong> 1. Code : Remove Min </strong></summary>

# 1. Code : Remove Min

    Implement the function RemoveMin for the min priority queue class.

    For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.

    Note : main function is given for your reference which we are using internally to test the code.

<details> <summary><strong>Code</strong></summary>

    #include <vector>
    class PriorityQueue {
        vector<int> pq;

        private:
        bool heapPropertyCheck(int par)
        { // only for non-duplicates too elements
            if (2 * par + 1 >= pq.size())
                return true;
            else // the left one exists
            {
                if (pq.at(2 * par + 1) >= pq.at(par)) // left one satisies the property
                {
                    // checking the right one
                    if (2 * par + 2 < pq.size()) // it exists
                    {
                        if (pq.at(2 * par + 2) >= pq.at(par))
                            return true;
                        return false; // right child less than parent
                    }
                    return true; // right does not exist
                }
                // child less than the parent
                return false;
            }
        }
        public :

        PriorityQueue() {

        }

        bool isEmpty() {
            return pq.size() == 0;
        }

        // Return the size of priorityQueue - no of elements present
        int getSize() {
            return pq.size();
        }

        int getMin() {
            if(isEmpty()) {
                return 0;		// Priority Queue is empty
            }
            return pq[0];
        }

        void insert(int element) {
            pq.push_back(element);

            int childIndex = pq.size() - 1;

            while(childIndex > 0) {
                int parentIndex = (childIndex - 1) / 2;

                if(pq[childIndex] < pq[parentIndex]) {
                    int temp = pq[childIndex];
                    pq[childIndex] = pq[parentIndex];
                    pq[parentIndex] = temp;
                }
                else {
                    break;
                }
                childIndex = parentIndex;
            }

        }

    int removeMin()
        {
            if (pq.empty())
            {
                cout << "Priority Queue is empty\n";
                return -1 ;
            }
            int data = pq.front();

            if (pq.size() == 1)
            {
                pq.pop_back();
                return data;
            }

            // copy to root, pop back
            pq.at(0) = pq.at(pq.size() - 1);
            pq.pop_back();
            int par = 0;

            while (2 * par + 1 < pq.size())
            {
                // the left one exists for sure, can't say about the right
                if (2 * par + 2 < pq.size()) // right exists
                {
                    int tb_swap = pq.at(2 * par + 1) <= pq.at(2 * par + 2) ? 2 * par + 1 : 2 * par + 2;
                    int temp = pq.at(par);
                    pq.at(par) = pq.at(tb_swap);
                    pq.at(tb_swap) = temp;
                    par = tb_swap;
                }
                else    // you are at the last node
                {
                    int temp = pq.at(par);
                    pq.at(par) = pq.at(2 * par + 1);
                    pq.at(2 * par + 1) = temp;
                    return data;
                    break;
                }
            }
        return data;
        }
    };

</details>

---

</details>

<details> <summary><strong> 2. Code : Max Priority Queue </strong></summary>

# 2. Code : Max Priority Queue

    Implement the class for Max Priority Queue which includes following functions -

    1. getSize -
    Return the size of priority queue i.e. number of elements present in the priority queue.

    2. isEmpty -
    Check if priority queue is empty or not. Return true or false accordingly.

    3. insert -
    Given an element, insert that element in the priority queue at the correct position.

    4. getMax -
    Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.

    5. removeMax -
    Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.

    Note : main function is given for your reference which we are using internally to test the class.

<details> <summary><strong>Code</strong></summary>

    #include<vector>

    class PriorityQueue
    {
        vector<int> pq;

        private:
        public:
        PriorityQueue()
        {
        }

        bool isEmpty()
        {
            return pq.empty(); // returns true if empty
        }

        int getMax()
        {
            if (!pq.empty())
                return pq.at(0);
            return 0;
        }

        int getSize()
        {
            return pq.size();
        }

        void insert(int data)
        {
            // insert at the end
            pq.push_back(data);
            // check if property is satisfied, else sift up
            // parInent < childIn
            int childIn = pq.size() - 1;
            int parIn = (childIn - 1) / 2;
            int temp;

            while (childIn > 0 && pq.at(parIn) < pq.at(childIn)) // no need to heck anything else
            {
                temp = pq.at(parIn);
                pq.at(parIn) = pq.at(childIn);
                pq.at(childIn) = temp;

                childIn = parIn;
                parIn = (childIn - 1) / 2;
            }
        }

        int removeMax()
        {
            if (pq.empty())
                return 0;

            int data = pq.front();
            if (pq.size() == 1)
            {
                pq.pop_back();
                return data;
            }

            // copy to root, pop back
            pq.at(0) = pq.back();
            pq.pop_back();
            int par = 0;

            // we have checked that the CBT is not a single node, we stop at the end, i.e when no left child exists
            while (2 * par + 1 < pq.size())
            {
                // the left one exists for sure, can't say about the right
                if (2 * par + 2 < pq.size()) // right exists
                {
                    int tb_swap = pq.at(2 * par + 1) > pq.at(2 * par + 2) ? 2 * par + 1 : 2 * par + 2;
                    int temp = pq.at(par);
                    pq.at(par) = pq.at(tb_swap);
                    pq.at(tb_swap) = temp;
                    par = tb_swap;
                }
                else
                {
                    if(pq.at(2*par+1)<pq.at(par))
                        return data;

                    int temp = pq.at(par);
                    pq.at(par) = pq.at(2 * par + 1);
                    pq.at(2 * par + 1) = temp;
                    par = 2*par+1;
                }
            }
            return data;
        }
    };

</details>

---

</details>

<details> <summary><strong> 3. Level order traversal </strong></summary>

# 3. Code : In-place heap sort

    Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
    Space complexity should be O(1).

**Input Format**

    Line 1 : Integer n, Array size
    Line 2 : Array elements, separated by space

**Output Format**

    Array elements after sorting

**Constraints** :

    1 <= n <= 10^6

**Sample Input**

    6
    2 6 8 5 4 3

**Sample Output**

    8 6 5 4 3 2

<details> <summary><strong>Code</strong></summary>

    void insert(int* arr, int n, int data)
    {
        // assuming the array has enough space
        // n is the current size
        arr[n] = data;
        // sift up
        int i = n;
        // parent is (i-1)/2
        while(i > 0 && arr[(i-1)/2] > arr[i])    // min priority queue - for reverse sort
        {
            int temp = arr[i];
            arr[i] = arr[(i-1)/2];
            arr[(i-1)/2] = temp;
            i = (i-1)/2; // i becomes the parent
        }
    }    // works for empty case too

    int remove(int* arr, int n)
    {
        int ret = arr[0]; // max value

        arr[0] = arr[n-1]; // flip root with the last node

        // sift down
        int i = 0;

        while(2*i+2 < n-1 && (arr[i] > arr[2*i+1] || arr[i] > arr[2*i+2])) // last possible child's index < length
        {
            // flip with greater of the two
            int f = arr[2*i+1] < arr[2*i+2] ? 2*i+1 : 2*i+2;
            int temp = arr[f];
            arr[f] = arr[i];
            arr[i] = temp;

            i = f; // f will have to be sifted down now
        }

        // if the last child is a left child
        if(2*i+1 < n-1 && arr[2*i+1] < arr[i])
        {
            int temp = arr[2*i+1];
            arr[2*i+1] = arr[i];
            arr[i] = temp;
        }
        return ret;
    }

    void inplaceHeapSort(int input[], int n)
    {
        int* arr = input;
        for(int i=0; i<n; i++)
            insert(arr, i, arr[i]);

        // made a max p queue
        for(int i=n; i>0; i--)    // array head remains the same
            arr[i-1] = remove(arr, i) ;
    }

</details>

---

</details>

<details> <summary><strong> 4. Code : K smallest Elements </strong></summary>

# 4. Code : K smallest Elements

    You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.

    Time complexity should be O(nlogk) and space complexity should be not more than O(k).

**Input Format**

    Line 1 : Size of array (n)
    Line 2 : Array elements (separated by space)
    Line 3 : Integer k

**Output Format**

    k smallest elements

**Sample Input**

    13
    2 12 9 16 10 5 3 20 25 11 1 8 6
    4

**Sample Output**

    5
    3
    2
    1

<details> <summary><strong>Code</strong></summary>

    #include<queue>
    #include<vector>
    vector<int> kSmallest(int *input, int n, int k)
    {
        priority_queue<int> pq;
        int i = 0;
        for(i=0; i<k; i++)
            pq.push(input[i]);

        // heapified
        for(; i<n; i++)
        {
            if(pq.top()>input[i])
            {
                pq.pop();
                pq.push(input[i]);
            }
        }
        // done, our heap has the least elements now
        vector<int> ret;
        for(int i=0; i<k; i++)
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
        // Time complexity nlogk = klogk + (n-k)logk = nlogk
    }

</details>

---

</details>

<details> <summary><strong> 5. Code : K largest elements </strong></summary>

# 5. Code : K largest elements

    You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.

    Time complexity should be O(nlogk) and space complexity should be not more than O(k).

    Order of elements in the output is not important.

**Input Format**

    Line 1 : Size of array (n)
    Line 2 : Array elements (separated by space)
    Line 3 : Integer k

**Output Format**

    k largest elements

**Sample Input**

    13
    2 12 9 16 10 5 3 20 25 11 1 8 6
    4

**Sample Output**

    12
    16
    20
    25

<details> <summary><strong>Code</strong></summary>

    #include<queue>
    // #include<vector>
    vector<int> kLargest(int *input, int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        for(i=0; i<k; i++)
            pq.push(input[i]);

        // heapified
        for(; i<n; i++)
        {
            if(pq.top()<input[i])
            {
                pq.pop();
                pq.push(input[i]);
            }
        }
        // done, our heap has the least elements now
        vector<int> ret;
        for(int i=0; i<k; i++)
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
        // Time complexity nlogk = klogk + (n-k)logk = nlogk
    }

</details>

---

</details>
