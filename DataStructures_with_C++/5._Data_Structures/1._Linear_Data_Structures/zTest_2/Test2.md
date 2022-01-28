# Coding Problems

<details> <summary><strong> 1. Next Number ? </strong></summary>

# 1. Next Number ?

    Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).

    Note: You don't need to print the elements, just update the elements and return the head of updated LL.

**Input Constraints**

    1 <= Length of Linked List <=10^6.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

**Output Format**

    Line 1: Updated linked list elements

**Sample Input 1**

    3 9 2 5 -1

**Sample Output 1**

    3 9 2 6

**Sample Input 2**

    9 9 9 -1

**Sample Output 2**

    1 0 0 0

<details> <summary><strong>Code</strong></summary>

    Node *NextLargeNumber(Node *head)
    {
        if (head == NULL)
            return head;

        // traverse and check last node
        Node *trav = head;

        while (trav->next != NULL)
            trav = trav->next;

        if (trav->data < 9)
        {
            trav->data += 1;    // last digit is non 9, add by 1 and we are done
            return head;
        }
        else
        {
            // unit digit is 9
            // reverse the LL
            // to implement elementary addition
            Node *r = NULL, *q = NULL, *p = head;
            while (p != NULL)
            {
                q = p;
                p = p->next;
                q->next = r;
                r = q;
            }
            head = r;
            // r stores head of the reversed LL

            //reuse trav
            trav = head;
            while (trav->next != NULL && trav->data == 9)
            {
                trav->data = 0;
                trav = trav->next;
            }

            // we reached a non 9 value or we reached the end

            if (trav->next != NULL) //we have reached a non 9 value
                trav->data += 1;
            else    // reached the end, the MST can be both 9 and non 9
            { // trav->next==NULL
                if (trav->data == 9)    //MST is 9
                {
                    Node *newNode = new Node(1);
                    trav->data = 0;
                    trav->next = newNode;
                    newNode->next = NULL;
                }
                else    // MST not 9
                    trav->data += 1;
            }

            //reverse the LL back, to get the original number
            r = NULL;
            q = NULL;
            p = head;
            while (p != NULL)
            {
                q = p;
                p = p->next;
                q->next = r;
                r = q;
            }
            head = r;   // head points to the number
        }

        return head;
    }

</details>

---

</details>

<details> <summary><strong> 2. Dequeue </strong></summary>

# 2. Dequeue

    You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.

    You don't need to double the capacity.

    You need to implement the following functions -
    1. constructor
    You need to create the appropriate constructor. Size for the queue passed is 10.
    2. insertFront -
    This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
    3. insertRear -
    This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
    4. deleteFront -
    This function removes an element from the front of queue. Print -1 if queue is empty.
    5. deleteRear -
    This function removes an element from the end of queue. Print -1 if queue is empty.
    6. getFront -
    Returns the element which is at front of the queue. Return -1 if queue is empty.
    7. getRear -
    Returns the element which is at end of the queue. Return -1 if queue is empty.

**Input Format**

    Line 1 : choice and/or argument
    terminated by -1

**Output Format**

    Printing taken care of by main()

**Sample Input 1**

    5 1 49 1 64 2 99 5 6 -1

**Sample Output 1**

    -1
    64
    99

**Sample Input 2**

    2 32 3 5 4 6 1 109 2 100 5 6 -1

**Sample Output 2**

    -1
    -1
    -1
    109
    100

**Sample Input 3**

    2 32 3 5 4 6 1 109 2 100 5 -1

**Sample Output 3**

    -1
    -1
    -1
    109

<details> <summary><strong>Code</strong></summary>

    /**********

    Following is the main function we are using internally.
    Refer this for completing the Dequeue class.


    int main()
    {
    Deque dq(10);
    int choice,input;
    while(true) {
    cin >> choice;
    switch (choice) {
    case 1:
    cin >> input;
    dq.insertfront(input);
    break;
    case 2:
    cin >> input;
    dq.insertrear(input);
    break;
    case 3:
    dq.deletefront();
    break;
    case 4:
    dq.deleterear();
    break;
    case 5:
    cout << dq.getFront() << "\n";
    break;
    case 6:
    cout << dq.getRear() << "\n";
    break;
    default:
    return 0;
    }
    }

    return 0;
    }

    ************/

    class Deque
    {
        // Complete this class
    public:
        int *arr;
        int size, capacity;
        int firstIndex, nextIndex;
        Deque(int cap = 0)
        {
            arr = new int[cap];
            size = 0;
            capacity = cap;
            firstIndex = cap - 1; // front of the queue
            nextIndex = 0;        // ready to be written at
        }

        void insertRear(int data)
        {
            if (size == capacity)
            {
                cout << -1 << endl;
                return;
            }
            if (size == 0)
            {
                firstIndex = capacity - 1;
                arr[0] = data;
                nextIndex = 1;
            }
            else
            {
                arr[nextIndex] = data;
                nextIndex = (nextIndex + 1) % capacity;
            }
            size++;
        }

        void insertFront(int data)
        {
            if (size == capacity)
            {
                cout << -1 << endl;
                return;
            }
            if (size == 0)
            {
                arr[capacity - 1] = data;
                firstIndex = capacity - 2;
                nextIndex = 0;
            }
            else
            {
                arr[firstIndex] = data;

                if (firstIndex == 0)
                    firstIndex = capacity - 1;
                else
                    firstIndex--;
            }
            size++;
        }

        void deleteFront()
        {
            if (size == 0)
            {
                cout << -1 << endl;
                return;
            }
            firstIndex = (firstIndex + 1) % capacity;
            size--;
        }

        void deleteRear()
        {
            if (size == 0)
            {
                cout << -1 << endl;
                return;
            }
            if (nextIndex == 0)
                nextIndex = capacity - 1;
            else
                nextIndex--;
            size--;
        }

        int getFront()
        {
            if (size == 0)
                return -1;
            // int front = (firstIndex+1)%capacity;
            return arr[(firstIndex + 1) % capacity];
        }

        int getRear()
        {
            if (size == 0)
                return -1;
            if (nextIndex == 0)
                return arr[capacity - 1];
            else
                return arr[nextIndex - 1];
        }

        ~Deque()
        {
            delete[] arr;
        }
    };
    /*
        Insights:
            1. Don't worry about corner cases, they will come to you, once you've practiced enough.
            2. We have kept both firstIndex and nextIndex as write ready heads
            3. Just reset the config when size 0, in the insert function
    */

</details>

---

</details>

<details> <summary><strong> 3. Delete alternate nodes </strong></summary>

# 3. Delete alternate nodes

    Given a linked list, delete all alternate nodes in the list. That means given Linked List is -
    10 20 30 40 50 60

    you need to delete nodes - 20, 40 and 60

    Note : Head of the list will remain same. Don't need to print or return anything.

**Input Constraints**

    1 <= Length of Linked List <=10^6.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Output Format**

    Updated linked list elements, taken care of by main()

**Constraints**

    1 <= N <= 50

**Sample Input 1**

    1 2 3 4 5 -1

**Sample Output**

    1 3 5

<details> <summary><strong>Code</strong></summary>

    // Following is the node structure
    /**************
    class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

        ~Node() {
            if(next) {
                delete next;
            }
        }
    };
    ***************/

    void delete_alternate_node_LinkedList(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *trav = head;

        while (trav != NULL && trav->next != NULL)
        {
            Node *p = trav->next;
            trav->next = trav->next->next;
            trav = trav->next;
        }
    }

</details>

---

</details>
