<details> <summary><strong> 1. Length of LL </strong></summary>

# 1. Length of LL

    Given a linked list, find and return the length of input LL. Do it iteratively.

**Input format**

    Linked list elements (separated by space and terminated by -1)

**Output format**

    Length of LL

**Sample Input**

    3 4 5 2 6 1 9 -1

**Sample Output**

    7

<details> <summary><strong>Code</strong></summary>

    int length(Node *head)
    {
        int length = 0;
        while(head!=NULL)
            head = head -> next, length++;
        return length;
    }

</details>

---

</details>

<details> <summary><strong> 2. Print ith node </strong></summary>

# 2. Print ith node

    Given a linked list and a position i, print the node at ith position.
    If position i is greater than length of LL, then don't print anything.

    Indexing starts from 0.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)
    Line 2 : Integer i (position)

**Output Format**

    Element at ith position

**Sample Input 1**

    3 4 5 2 6 1 9 -1
    3

**Sample Output 1**

    2

**Sample Input 2**

    3 4 5 2 6 1 9 -1
    0

**Sample Output 2**

    3

<details> <summary><strong>Code</strong></summary>

    void printIthNode(Node *head, int i)
    {
        for(int j=0; j<i && head!=NULL; j++)
            head = head->next;

        if(head!=NULL)
            cout << head -> data;
    }

</details>

---

</details>

<details> <summary><strong> 3. Delete node </strong></summary>

# 3. Delete node

    Given a linked list and a position i, delete the node of ith position from Linked List iteratively.

    If position i is greater than length of LL, then you should return the same LL without any change.

    Indexing starts from 0. You don't need to print the elements, just delete the node and return the head of updated LL.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

    Line 2 : Integer i (position)

**Output Format**

    Updated LL elements (separated by space)

**Sample Input 1**

    3 4 5 2 6 1 9 -1
    3

**Sample Output 1**

    3 4 5 6 1 9

**Sample Input 2**

    3 4 5 2 6 1 9 -1
    0

**Sample Output 2**

    4 5 2 6 1 9

<details> <summary><strong>Code</strong></summary>

    Node* deleteNode(Node *head, int i)
    {
        if(head==NULL || i<0)
            return head;
        // Empty list case handled

        // change head for 2 cases
        if(i==0)
        {
            Node* p = head;
            head = head->next;
            delete p;
            return head;
        }

        // index zero handled
        Node* trav = head;
        for(int j = 0; j < i - 1 && trav->next!=NULL; j++)
            trav = trav->next;

        if(trav->next==NULL)
            return head;// overrun

        Node*p = trav->next;

        trav->next = p->next;

        delete p;

        return head;
    }

</details>

---

</details>

<details> <summary><strong> 4. Length of LL (recursive) </strong></summary>

# 4. Length of LL (recursive)

    Given a linked list, find and return the length of input LL recursively.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Output Format**

    Length of LL

**Sample Input**

    3 4 5 2 6 1 9 -1

**Sample Output**

    7

<details> <summary><strong>Code</strong></summary>

    int length(Node *head)
    {
        if(head==NULL)
            return 0;

        return 1 + length(head->next);    // very easy
    }

</details>

---

</details>

<details> <summary><strong> 5. Insert node (recursive) </strong></summary>

# 5. Insert node (recursive)

    Given a linked list, an integer n and a position i, Insert that node n into Linked List at ith position recursively.

    If position i is greater than length of LL, then you should return the same LL without any change. And if position i is equal to length of input LL, insert the node at last position.

    Indexing starts from 0. You don't need to print the elements, just insert and return the head of updated LL.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

    Line 2 : Integer i (position)

    Line 3 : Integer n (Node to be inserted)

**Output Format**

    Updated LL elements (separated by space)

**Sample Input 1**

    3 4 5 2 6 1 9 -1
    3
    100

**Sample Output 1**

    3 4 5 100 2 6 1 9

**Sample Input 2**

    3 4 5 2 6 1 9 -1
    0
    20

**Sample Output 2**

    20 3 4 5 2 6 1 9

<details> <summary><strong>Code</strong></summary>

    Node* insertNodeRec(Node *head, int i, int data)
    {
        if(head==NULL && i!=0)
            return head;

        if(i==0)
        {
            Node* newnode = new Node(data);
            newnode->next  = head;
            return newnode; // insertion at the beginning
        }

        head->next =  insertNodeRec(head->next, i-1, data); // traverses to the next element, makes a connection to the list which is present
        return head;
    }

</details>

---

</details>

<details> <summary><strong> 6. Delete node (recursive) </strong></summary>

# 6. Delete node (recursive)

    Given a linked list and a position i, delete the node of ith position from Linked List recursively.

    If position i is greater than length of LL, then you should return the same LL without any change.


    Indexing starts from 0. You don't need to print the elements, just delete the node and return the head of updated LL.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

    Line 2 : Integer i (position)

**Output Format**

    Updated LL elements (separated by space)

**Sample Input 1**

    3 4 5 2 6 1 9 -1
    3

**Sample Output 1**

    3 4 5 6 1 9

**Sample Input 2**

    3 4 5 2 6 1 9 -1
    0

**Sample Output 2**

    4 5 2 6 1 9

<details> <summary><strong>Code</strong></summary>

    Node* deleteNodeRec(Node *head, int i)
    {
        if(head==NULL)
            return head;

        if(i==0)
        {
            Node* p = head->next;
            delete head;
            return p;
        }

        head -> next = deleteNodeRec(head->next, i-1);
    }

</details>

---

</details>
