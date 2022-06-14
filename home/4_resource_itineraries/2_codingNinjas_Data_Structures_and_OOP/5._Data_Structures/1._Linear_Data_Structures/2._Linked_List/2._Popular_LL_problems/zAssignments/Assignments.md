# Assignments

<details> <summary><strong> 1. Find a node in LL (recursive) </strong></summary>

# 1. Find a node in LL (recursive)

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

    int indexOfNRecursive(Node *head, int n)
    {
        if (head == NULL)
            return -1; // base case 1

        if (head->data == n)
            return 0; // base case 2

        //recursive step
        int result = indexOfNRecursive(head->next, n);

        //small calc
        if (result == -1)
            return -1;
        return 1 + result;
    }

</details>

---

</details>

<details> <summary><strong> 2. Even after Odd LinkedList </strong></summary>

# 2. Even after Odd LinkedList

    Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.

    Note: Input and Output has already managed for you. You don't need to print the elements, instead return the head of updated LL.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

**Output Format**

    Print the elements of updated Linked list.

**Sample Input**

    1 4 5 2 -1

**Sample Output**

    1 5 4 2

**Sample Input**

    1 11 3 6 8 0 9 -1

**Sample Output**

    1 11 3 9 6 8 0

<details> <summary><strong>Code</strong></summary>

    // Following is the node structure
    /**************
    class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
    };
    ***************/

    node *arrange_LinkedList(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head; // uni and empty taken care of

        // initializing the oddhead and the evenhead is a special case

        int k = head->data % 2;

        node *trav = head;
        while (trav->next != NULL && trav->next->data % 2 == k)
            trav = trav->next; // trav is the head before the mismatch

        if (trav->next == NULL)
            return head; // the LL is homogeneous

        // storing heads of the odd and even lists
        node *oddhead = k == 1 ? head : trav->next; // trav->next is the mismatch
        node *evenhead = k == 0 ? head : trav->next;

        // storing lastnodes of the odd and even lists, as any new nodes will be added here
        node *lastnode_odd = trav, *lastnode_even = trav; // initializing as trav as one will retain value

        // the other's last node
        if (k == 0)
            lastnode_odd = trav->next; // if k == 0, trav is correct as head of lastnode_even. Hence odd should change.
        else
            lastnode_even = trav->next;

        // we are at the first head of the remaining list now
        trav = trav->next->next;

        // ending the odd and even LLs
        lastnode_odd->next = NULL;
        lastnode_even->next = NULL;

        // attach nodes to the LL's as per nature
        while (trav != NULL)
        {
            if (trav->data % 2 == 0)
            {
                lastnode_even->next = trav; // connected the new node
                lastnode_even = trav;       // updated the last node
            }
            else
            {
                lastnode_odd->next = trav;
                lastnode_odd = trav;
            }
            trav = trav->next;
        }
        //doubt, don't worry about ending the LL's at each iteration. Because they were seperated just before the while loop started.
        // Hence lastnodes take care of the end

        lastnode_even->next = NULL;
        lastnode_odd->next = evenhead;

        return oddhead;
    }

    // Insights:
    // 1. By taking a 2 step stance, our algorithm is adaptive. This wouldn't have been the case for the mixed approach, where every node is worked upon for even being suspected.
    // 2. We saved a lot of comparisons(i.e oddhead==NULL || evenhead==NULL) because we made starting the first node a special case. This is what helped no. 1
    // 3. Readable and understandable

</details>

---

</details>

<details> <summary><strong> 3. Delete every N nodes </strong></summary>

# 3. Delete every N nodes

    Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list. That is, in the given linked list you need to delete N nodes after every M nodes.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

    Line 2 : M

    Line 3 : N

**Output Format**

    Updated LL elements (separated by space)

**Sample Input 1**

    1 2 3 4 5 6 7 8 -1
    2
    2

**Sample Output 1**

    1 2 5 6

**Sample Input 2**

    1 2 3 4 5 6 7 8 -1
    2
    3

**Sample Output 2**

    1 2 6 7

<details> <summary><strong>Code</strong></summary>

    node *skipMdeleteN(node *head, int m, int n)
    {
        // 4 cases are possible for prelim
        if (m == 0) // retain none
            return NULL;
        if (n == 0) // delete none, retain some - retain all
            return head;

        // as skipping is first hence head is never changed, i.e deletion at head node is not carrired out.
        node *trav = head, *dtrav = head;
        int i = 0;

        while (trav != NULL)
        {
            for (i = 0; trav != NULL && i < m - 1; i++) // travelling to the m-1th node
                trav = trav->next;

            if (trav == NULL || trav->next == NULL) // overrun check
                return head;                        // i.e retain less than 'm' at last Okay

            dtrav = trav;   // deleter traverses tothe position where we need to go if n are deleted. trav is the last node

            for (i = 0; dtrav != NULL && i < n; i++)    // go
                dtrav = dtrav->next;

            if (dtrav == NULL) // safe deletion and exit, i.e delete last elements < n
            {
                trav->next = dtrav;
                return head;
            }

            trav->next = dtrav->next; // lastnode_retained-> lastnode_deleted->next;
            trav = trav->next;        // move the iterator like for the first iteration
        }
        return head;
    }
    /*
    Insights: Function names are very important, skipping and retaining are not the same when it comes to empty list.
        Retain none: Okay return empty LL;
        Skip none: Return LL as it is.
    */

</details>

---

</details>

<details> <summary><strong> 4. Swap two Node of LL </strong></summary>

# 4. Swap two Node of LL

    Given a linked list, i & j, swap the nodes that are present at i & j position in the LL. You need to swap the entire nodes, not just the data.

    Indexing starts from 0. You don't need to print the elements, just swap and return the head of updated LL.

    Assume i & j given will be within limits. And i can be greater than j also.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

    Line 2 : i and j (separated by space)

**Output Format**

    Linked List elements in reverse order (separated by space)

**Sample Input 1**

    3 4 5 2 6 1 9 -1
    3 4

**Sample Output 1**

    3 4 5 6 2 1 9

**Sample Input 2**

    3 4 5 2 6 1 9 -1
    2 4

**Sample Output 2**

    3 4 6 2 5 1 9

<details> <summary><strong>Code</strong></summary>

    // Approach 1
    node *swap_nodes(node *head, int i, int j)
    {
        // base case
        if (head == NULL || head->next == NULL || i == j || i < 0 || j < 0)
            return head;

        // we've got atleast two nodes now.
        // case 1: 0 and something else
        // case 2: non zero and non zero
        if (i > j)
        {
            int temp = i;
            i = j;
            j = temp;
        }

        // i is less than j.

        if (i == 0)
        {
            // add a buffer
            node *newnode = new node(0);
            newnode->next = head;
            node *ret = swap_nodes(newnode, 1, j + 1); // head is now the second
            ret = ret->next;
            delete newnode; // deallocated one node
            return ret;
        } // 1 step recursion

        node *iprev = head, *jprev = head;

        int a = 0; //same counter for both the traversals
        for (; a < i - 1 && iprev != NULL; a++, iprev = iprev->next, jprev = iprev)
            ;   // iprev at i-1th index
                // check overrun
        if (iprev == NULL || iprev->next == NULL)
            return head;
        for (; a < j - 1 && jprev != NULL; a++, jprev = jprev->next)
            ; // jprev at j-1 th index

        // check overrun
        if (jprev == NULL || jprev->next == NULL)
            return head;

        // swapping procedure, handles cases of
        node *ith = iprev->next;
        node *jth = jprev->next;

        node *inext = iprev->next->next;
        node *jnext = jprev->next->next;

        iprev->next = jth;
        jprev->next = ith;
        ith->next = jnext;
        jth->next = inext;
        if (jprev == ith) //contiguos element
        {
            jth->next = ith;
        }
        return head;
        // duplicating code: finding the j-1 th term, swapping is the same, why not add a buffer and call the function again. Just call recursion
    }


    // Approach 2

    node *swap_nodes(node *head, int i, int j)
    {
        // base case
        if (head == NULL || head->next == NULL || i == j || i < 0 || j < 0)
            return head;

        // case 1: i = 0 and contiguous
        // case 2: i = 0 and non-contiguous
        // case 3: i = not zero and contiguous
        // case 4: i = not zero and non contiguos

        if (i > j)
        {
            int temp = i;
            i = j;
            j = temp;
        }

        // i is < j now.
        if (i == 0)
        {
            // contiguos
            if (j == 1)
            {
                node *p = head->next;
                head->next = p->next;
                p->next = head;
                return p;
            }
            else // zero and non contiguos
            {
                node *jprev = head;
                for (int a = 0; a < j - 1 && jprev != NULL; a++)
                    jprev = jprev->next;

                if (jprev == NULL || jprev->next == NULL) //overrun
                    return head;

                node *jth = jprev->next;
                node *headn = head->next;

                jprev->next = head;
                head->next = jth->next;
                jth->next = headn;
                return jth; // it's the head now
            }
        }
        else
        {
            if (j == i + 1) // contiguous
            {
                // go to the ith node
                node *iprev = head;
                for (int a = 0; a < i - 1 && iprev != NULL; a++)
                    iprev = iprev->next;

                if (iprev == NULL || iprev->next == NULL || iprev->next->next == NULL) // overrun check
                    return head;

                node *ith = iprev->next;
                node *jth = ith->next;
                node *jnext = jth->next;

                ith->next = jnext;
                jth->next = ith;
                iprev->next = jth;
                return head;
            }
            else
            {
                node *iprev = head;
                int a = 0;

                for (a = 0; a < i - 1 && iprev != NULL; a++)
                    iprev = iprev->next;

                if (iprev == NULL || iprev->next == NULL) //overrun check
                    return head;

                node *jprev = iprev;

                for (; a < j - 1 && jprev != NULL; a++)
                    jprev = jprev->next;

                if (jprev == NULL || jprev->next == NULL) // oevrrun check
                    return head;

                node *ith = iprev->next;
                node *jth = jprev->next;
                node *inext = ith->next;
                node *jnext = jth->next;

                iprev->next = jth;
                jprev->next = ith;
                ith->next = jnext;
                jth->next = inext;

                return head;
            }
        }
    }

</details>

---

</details>

<details> <summary><strong> 5. Palindrome LinkedList </strong></summary>

# 5. kReverse

    Implement kReverse( int k ) in a linked list i.e. you need to reverse first K elements then reverse next k elements and join the linked list and so on.

    Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well. If k is greater than length of LL, reverse the complete LL.

    You don't need to print the elements, just return the head of updated LL.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

    Line 2 : k

**Output Format**

    Linked List elements in reverse order (separated by space)

**Sample Input 1**

    1 2 3 4 5 6 7 8 9 10 -1
    4

**Sample Output 1**

    4 3 2 1 8 7 6 5 10 9

**Sample Input 2**

    1 2 3 4 5 -1
    2

**Sample Output 2**

    2 1 4 3 5

**Sample Input 3**

    1 2 3 4 5 6 7 -1
    3

**Sample Output 3**

    3 2 1 6 5 4 7

<details> <summary><strong>Code</strong></summary>

    node *kReverse(node *head, int n)
    {
        // node* last = reverse(head, n);
        if (head == NULL)
            return head;
        node *ret = NULL;
        node *lastnode_prev = NULL, *lastnode_curr = NULL;
        node *r = NULL, *q = NULL, *p = head;
        while (p != NULL)
        {
            r = NULL, q = NULL;
            lastnode_curr = p; // last node
            for (int i = 0; i < n && p != NULL; i++)
            {
                q = p;
                p = p->next;
                q->next = r;
                r = q;
            } // we've got the LL with head at r

            if (lastnode_prev == 0)
            {
                ret = r;
                lastnode_prev = lastnode_curr;
            }
            lastnode_prev->next = r;
            lastnode_prev = lastnode_curr;
        }
        return ret;
    }

</details>

---

</details>

<details> <summary><strong> 6. Bubble Sort (Iterative) LinkedList </strong></summary>

# 6. Bubble Sort (Iterative) LinkedList

    Sort a given linked list using Bubble Sort (iteratively). While sorting, you need to swap the entire nodes, not just the data.

    You don't need to print the elements, just sort the elements and return the head of updated LL.

**Input Format**

    Line 1 : Linked list elements (separated by space and terminated by -1)

**Output Format**

    Updated LL elements (separated by space)

**Sample Input**

    1 4 5 2 -1

**Sample Output**

    1 2 4 5

<details> <summary><strong>Code</strong></summary>

    node *swapnext(node *head, node *trav) // swaps trav and trav->next
    {
        if (head == 0 || head->next == NULL)
            return head;

        if (head == trav)
        {
            node *p = head->next;
            head->next = p->next;
            p->next = head;
            return p;
        }
        else
        {
            node *iprev = head;
            while (iprev->next != trav) // iprev is not null as head is not NULL
                iprev = iprev->next;

            if (iprev == NULL || iprev->next == NULL || iprev->next->next == NULL) // overrun check
                return head;

            node *ith = iprev->next;
            node *jth = ith->next;
            node *jnext = jth->next;

            ith->next = jnext;
            jth->next = ith;
            iprev->next = jth;
            return head;
        }
    }

    node *bubble_sort_LinkedList_itr(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        node *trav = head;
        bool flag = true;
        while (1)
        {
            flag = true;
            trav = head;

            while (trav->next != NULL) // no need to check if trav is the last or if we have reached the last node
            // nether trav nor trav->next is null intially as checker by the worst case condition
            {
                if (trav->data > trav->next->data) // trav always means the least of the two values of the pair window
                {
                    flag = false;
                    head = swapnext(head, trav); // trav goes automatically to the next node
                }
                else
                    trav = trav->next; // trav has to be taken to the next node
            }
            if (flag == true)
                return head;
        }
        // This is not optimized, i.e till n-i. As we cannot keep record of that
    }

</details>

---

</details>
