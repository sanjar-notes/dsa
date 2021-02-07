<details> <summary><strong> 1. Midpoint of LL </strong></summary>

# 1. Midpoint of LL

    Given a linked list, find and return the midpoint.

    If the length of linked list is even, return the first mid point.

**Input format**

    Linked list elements (separated by space and terminated by -1)

**Output format**

    The midpoint(if odd sized) or the last of the first half(if even sized)

**Sample Input 1**

    1 2 3 4 5 -1

**Sample Output 1**

    3

**Sample Input 2**

    1 2 3 4 -1

**Sample Output 2**

    2

<details> <summary><strong>Code</strong></summary>

    node *midpoint_linkedlist(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;    // empty and uni taken care of

        node *trav2x = head, *travx = head;

        while (trav2x->next != NULL && trav2x->next->next != NULL)
        {
            trav2x = trav2x->next->next;
            travx = travx->next;
        }
        // reaches the middle or the last of the first half, maid 2k+1
        return travx;
    }

</details>

---

</details>

<details> <summary><strong> 2. Merge Two Sorted LL </strong></summary>

# 2. Merge Two Sorted LL

    Given two linked lists sorted in increasing order. Merge them in such a way that the result list is also sorted (in increasing order).

    Try solving with O(1) auxiliary space (in-place). You just need to return the head of new linked list, don't print the elements.

**Input Format**

    Line 1 : Linked list 1 elements of length n (separated by space and terminated by -1)

    Line 2 : Linked list 2 elements of length m (separated by space and terminated by -1)

**Output Format**

    Merged list elements (separated by space)

**Constraints**

    1 <= n, m <= 10^4

**Sample Input**

    2 5 8 12 -1
    3 6 9 -1

**Sample Output**

     2 3 5 6 8 9 12

<details> <summary><strong>Code</strong></summary>

    Node *mergeTwoLLs(Node *head1, Node *head2)
    {
        if (head1 == NULL || head2 == NULL)
        {
            if (head1 != NULL)
                return head1;
            return head2;   // don't care condition about the nature of head2
        } // one or both empty taken care of

        /*
        variables required, 1. two iterators for traversing the lists.
                            2. one pointer for keeping the last node of the merged list
                            3. head of the merged list, for returning
        */

        // both are non null, as we checked if one or both are NULL
        Node *mhead = head1->data < head2->data ? head1 : head2;
        Node *last_node = mhead; // we will add nodes to the end, so we need the last node of the merged list

        Node *i = mhead->next;                    // iterator to list 1
        // bug warning, if i is initialized as mhead, then it will form a loop which will go on forever. It is not smart to repeat work anyways. Here last_node is mhead, so i should be mhead->next;
        Node *j = mhead != head1 ? head1 : head2; // iterator to the second list

        while (i != NULL && j != NULL)
        {
            if (i->data < j->data)
            {
                last_node->next = i; // last node connnects to the new node
                last_node = i;       // last node becomes the new node
                i = i->next;         // the iterator moves forward in the list
            }
            else
            {
                last_node->next = j;    // same as the if case
                last_node = j;
                j = j->next;
            }
        }

        // when the loop ends, either one or both have exhausted, i.e either i or j is NULL

        // store the head of the remaining list in i
        if (i == NULL)
            i = j;

        // got the remaining list's head as i
        // connect last node to this, remember that the last_node cannot be null, as it is the always the address of an existing node
        last_node->next = i;

        return mhead;
    }

    // insights: Merging can be done in-place in case of LL. SC = O(1)
    //              Time complexity = min(m, n) = theta(min(m,n)) = theta(n),
    // min comes here and not in the array because, the non-exhausted list can be added here in o(1).
    // In case of arrays, it needs to be fed/copied into the merged list. Hence theta(m+n).
    // Comparisons in LL: min(m,n) same in arrays
    // Copy operations =  0, in LL. m+n copy ops in arrays.

</details>

---

</details>

<details> <summary><strong> 3. Merge Sort </strong></summary>

# 3. Merge Sort

    Sort a given linked list using Merge Sort.

    You don't need to print the elements, just sort the elements and return the head of updated LL.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Output Format**

    Updated LL elements (separated by space)

**Constraints**

    1 <= Length of LL <= 1000

**Sample Input**

    1 4 5 2 -1

**Sample Output**

    1 2 4 5

<details> <summary><strong>Code</strong></summary>

    node *merge(node *head1, node *head2)
    {
        if (head1 == NULL || head2 == NULL)
        {
            if (head1 != NULL)
                return head1;
            return head2;
        } // one or both empty taken care of

        node *mhead = head1->data < head2->data ? head1 : head2;
        node *last_node = mhead;

        node *i = mhead->next;
        node *j = mhead != head1 ? head1 : head2;

        while (i != NULL && j != NULL)
        {
            if (i->data < j->data)
            {
                last_node->next = i;
                last_node = i;
                i = i->next;
            }
            else
            {
                last_node->next = j;
                last_node = j;
                j = j->next;
            }
        }

        if (i == NULL)
            i = j;
        last_node->next = i;
        return mhead;
    }

    node *mergeSort(node *head)
    {
        // need to go to the middle elemeny
        // no need of copying here, as everything is in place
        if (head == NULL || head->next == NULL)
            return head; // no need of merge sort
        // base case done

        node *trav2x = head, *travx = head;

        while (trav2x->next != NULL && trav2x->next->next != NULL)
        {
            trav2x = trav2x->next->next;
            travx = travx->next;
        }

        // need to terminate the indiviual LLs
        // But store the head of the 2nd half first
        node *&second = trav2x; // no memory consumption
        second = travx->next;
        travx->next = NULL;

        return merge(mergeSort(head), mergeSort(second));
    }

    // insights: In place saves a lot of space
    // This is faster than doing mergeSort on arrays because, merging is also faster here.
    // here finding the middle replaces the copying part.

</details>

---

</details>

<details> <summary><strong> 4. Reverse LL (Recursive) </strong></summary>

# 4. Reverse LL (Recursive)

    Given a linked list, reverse it using recursion.

    You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Output Format**

    Elements of the LL seperated by space

**Sample Input**

    1 2 3 4 5 -1

**Sample Output**

    5 4 3 2 1

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

<details> <summary><strong> 5. Reverse LL (Recursive) using two pointers (recursive) </strong></summary>

# 5. Reverse LL (Recursive) using two pointers

    Given a linked list, reverse it using recursion.

    You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Output Format**

    Elements of the LL seperated by space

**Sample Input**

    1 2 3 4 5 -1

**Sample Output**

    5 4 3 2 1

<details> <summary><strong>Code</strong></summary>

    class Pair
    {
    public:
        node *head;
        node *tail;

        Pair(){}

        Pair(node *head, node *tail)
        {
            this->head = head;
            this->tail = tail;
        }
    };

    Pair reverse_ll_rec(node *head)
    {
        if (head->next == NULL) // base case
        {
            Pair last(head, head);
            return last;
        }

        Pair ac = reverse_ll_rec(head->next); // obtained the head and last of the reversed list
        ac.tail->next = head;                 // attach the node in ACR to the list
        ac.tail = head;                       // update the value of last
        head->next = NULL;                    // as the node in ACR is the last, so made it point to NULL
        return ac;                            // return the Pair value
    }

    node *reverse_linked_list_rec(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Pair ans = reverse_ll_rec(head);
        return ans.head;
    }

</details>

---

</details>
<details> <summary><strong> 6. Reverse LL (Recursive) in linear time with a single pointer (recursive) </strong></summary>

# 6. Reverse LL (Recursive) in linear time with a single pointer

    Given a linked list, reverse it using recursion.

    You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Output Format**

    Elements of the LL seperated by space

**Sample Input**

    1 2 3 4 5 -1

**Sample Output**

    5 4 3 2 1

<details> <summary><strong>Code</strong></summary>

    node *reverse_linked_list_rec(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        node *ret = reverse_linked_list_rec(head->next); // brings the head of the reversed linked list

        head->next->next = head; // head->next is actually the last node, made it point to the ACR node

        head->next = NULL; // end the list, for now
        return ret;        //return the head
    }

    // how this works: We are exploiting the fact that even after a node is made null, the node to be added has it's next to the last node. Hence, there's no need of storing the last node.

</details>

---

</details>

<details> <summary><strong> 7. Reverse LL (Iterative) </strong></summary>

# 7. Reverse LL (Iterative)

    Given a linked list, reverse it iteratively.

    You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Output Format**

    Updated LL elements (separated by space)

**Sample Input**

    1 2 3 4 5 -1

**Sample Output**

    5 4 3 2 1

<details> <summary><strong>Code</strong></summary>

    node *rev_linkedlist_itr(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        // uni and empty taken care of

        node *r = NULL, *q = NULL, *p = head;
        while (p != NULL)
        {
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }

        // q, r is the head at last. P is the untouched node
        return r;
    }

</details>

---

</details>
