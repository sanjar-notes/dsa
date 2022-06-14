# Assignments

<details> <summary><strong> 1. Find a node in LL </strong></summary>

# 1. Find a node in LL

    Given a linked list and an integer n you need to find and return index where n is present in the LL. Do this iteratively.

    Return -1 if n is not present in the LL.

    Indexing of nodes starts from 0.

**Input format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

    Line 2 : Integer n

**Output format**

    Index

**Sample Input 1**

    3 4 5 2 6 1 9 -1
    5

**Sample Output 1**

    2

**Sample Input 2**

    3 4 5 2 6 1 9 -1
    6

**Sample Output 1**

    4

<details> <summary><strong>Code</strong></summary>

    int length(Node *head)
    {
        int length = 0;
        while (head != NULL)
            head = head->next, length++;
        return length;
    }

</details>

---

</details>

<details> <summary><strong> 2. AppendLastNToFirst </strong></summary>

# 2. AppendLastNToFirst

    Given a linked list and an integer n, append the last n elements of the LL to front.

    Indexing starts from 0. You don't need to print the elements, just update the elements and return the head of updated LL.

    Assume given n will be smaller than length of LL.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

**Output Format**

    Element at ith position

**Sample Input**

    1 2 3 4 5 -1
    3

**Sample Output**

    3 4 5 1 2

<details> <summary><strong>Code</strong></summary>

    node *append_LinkedList(node *head, int n)
    {
        if (head == NULL || head->next == NULL) // if only one element is there no need to do anything
            return head;

        int length = 0;

        node *trav = head;

        while (trav->next != NULL) // coz we need the second last node
        {
            trav = trav->next;
            length++;
        }

        length++; // we stopped at the last node

        if (length - n <= 0) // this is assumed to be Okay as per the question
            return head;

        trav->next = head; // connected the last to the head

        // go to the start
        trav = head;

        for (int i = 0; i < length - n - 1; i++)
            trav = trav->next;

        head = trav->next; // the new head, to be returned

        trav->next = NULL;
        return head;
    }

</details>

---

</details>

<details> <summary><strong> 3. Eliminate duplicates from LL </strong></summary>

# 3. Eliminate duplicates from LL

    Given a sorted linked list (elements are sorted in ascending order). Eliminate duplicates from the given LL, such that output LL contains only unique elements.

    You don't need to print the elements, just remove duplicates and return the head of updated LL.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Output Format**

    Updated LL elements (separated by space)

**Sample Input**

    1 2 3 3 3 4 4 5 5 5 7 -1

**Sample Output**

    1 2 3 4 5 7

<details> <summary><strong>Code</strong></summary>

    node *eliminate_duplicate(node *head)
    {
        // sorted list
        if (head == NULL || head->next == NULL)
            return head;

        node *trav = head;

        // step by step elimination, deleting at index 1 from the current.
        // this means we don't have to delete the first node ever, so no need of the special case

        while (trav->next != NULL) // stop when you are the last man standing
        {
            if (trav->data == trav->next->data)
            {
                node *to_be_deleted = trav->next;
                trav->next = trav->next->next;
                delete to_be_deleted; // trav not changed
            }
            else
                trav = trav->next;
        }

        return head;
    }

</details>

---

</details>

<details> <summary><strong> 4. Print reverse LinkedList </strong></summary>

# 4. Print reverse LinkedList

    Print a given linked list in reverse order. You need to print the tail first and head last. You can’t change any pointer in the linked list, just print it in reverse order.

**Input Format**

    Linked List elements (separated by space and terminated by -1)

**Output Format**

    Linked List elements in reverse order (separated by space)

**Sample Input 1**

    1 2 3 4 5 -1

**Sample Output 1**

    5 4 3 2 1

**Sample Input 2**

    1 2 3 -1

**Sample Output 2**

    3 2 1

<details> <summary><strong>Code</strong></summary>

    // Iterative Approach

    void print_linkedlist_spl(node *head)
    {
        if (head == NULL)
            return; // uni loop is a palindrome

        // making a new linked list;

        node *phead = NULL; // we need to point here for the first node

        while (head != NULL)
        {
            node *newnode = new node(head->data); // creates a node with data from the original list
            newnode->next = phead;                // node points to phead
            phead = newnode;                      // phead becomes the node we need to point to in the next iteration

            head = head->next; // traverse the original list by one step
        }

        // head at null, phead at the last node of the original list. Hence it is the head.

        // Now, just travel the list with phead, and deallocate memory for each block.

        node* to_be_deleted = 0;
        while(phead!=NULL)
        {
            to_be_deleted = phead;

            cout << to_be_deleted -> data << " ";
            delete to_be_deleted;

            phead = phead->next;
            to_be_deleted = phead;
        }
    }
    ---------------------
    // Recursive Approach

    void print_linkedlist_spl(node *head)
    {
        if (head == NULL)
            return;
        print_linkedlist_spl(head->next);
        cout << head->data << " ";
    }

</details>

---

</details>

<details> <summary><strong> 5. Palindrome LinkedList </strong></summary>

# 5. Palindrome LinkedList

    Check if a given linked list is palindrome or not. Return true or false.
    Indexing starts from 0.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Sample Input 1**

    9 2 3 3 2 9 -1

**Sample Output 1**

    true

**Sample Input 2**

    0 2 3 2 5 -1

**Sample Output 2**

false

<details> <summary><strong>Code</strong></summary>

    bool check_palindrome(node *head)
    {
        // for doing in o(1) space we need to reverse the list from the middle
        if (head == NULL || head->next == NULL)
            return true;

        node *travx = head, *trav2x = head;

        while (trav2x != NULL && trav2x->next != NULL)
        {
            trav2x = trav2x->next->next;
            travx = travx->next;
        }
        // trav2x reaches the end while travx reaches the first half's last, or the middle

        /* even size = 1 2 3 4 5 6
            pass - (travx, trav2x)
            1 - (1, 2)
            2 - (2, 4)
            3 - (3, 6)

            Conclusion: 1st half of the list
            Proof: PMI
            --------------------

            odd size = 1 2 3 4 5
            pass - (travx, trav2x)
            1 - (1, 2)
            2 - (2, 4)
            stop
            Conclusion: 1st half of the list
            Proof: PMI

            // how to acertain:
            if trav2x == NULL, it is an odd size list. do travx = trav -> next -> next; you are on the 1st of the right side list

            else // (i.e trav->next==NULL)
                trav = trav -> next, you are on the first of the right half
        */

        // reverse the second half of the list, remember p is the element not in the list
        // q, r is the head of the reversed linked list

        node *r = 0, *q = 0, *p = travx;

        while (p != NULL)
        {
            q = p;       // q comes at p
            p = p->next; // p moves over befor the current node loses the next

            q->next = r; // join made
            r = q;       // r moves over
        }

        node *trav = r;
        // both head and trav follow the same distance, so checking any one would suffice

        while (trav != NULL)
        {
            if (trav->data != head->data)
                return false;

            trav = trav->next;
            head = head->next;
        }

        return true;
    }

</details>

---

</details>
