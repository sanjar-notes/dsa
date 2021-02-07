#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }

    Node(const Node &t)
    {
        this->data = t.data;
        this->next = NULL;
    }
};

//----------------------------------------------------

void print(Node *&head)
{
    if (head == NULL) // for empty list
        return;

    Node *trav = head;
    cout << "Start: ";
    while (trav != NULL) // check we reach the end
    {
        cout << trav->data << " ";
        trav = trav->next;
    }

    cout << "END\n";
}

void insertNode(Node *&head, int index, int data)
{
    /* cases possible

    1.  Empty list
        a. Index at 0, i.e make the first node
        b. Index != 0 do nothing
    2. Non Empty list
        a. index at 0, Make the node shift the head
        how to prevent negative indices ?
        b. index < length -1, reach the (i-1)th node, create a node
        c. index > length - 1 , do nothing

    Conclusion: 1. 1.a and 2. a are the same thing, create a node at the beginning
                2. 1.b is different // impossible
                3. 2.b and 2.c are intertwined  //
    */
    if (index < 0)
    {
        cout << "Insert Error: Negative Index\n";
        return;
    }
    if (index == 0) // Always allowed
    {
        Node *newnode = new Node(data);
        newnode->next = head; // handles both cases, i.e empty and non-empty lists
        head = newnode;
        return;
    }

    if (head == NULL) // Empty list but index!=0
    {
        cout << "Insert Error: Empty list, index > 0\n";
        return;
    }

    // case 2.b and 2.c
    Node *trav = head;                                                     //moving
    for (int i = 0; i < index - 1 && trav != NULL; i++, trav = trav->next) // also prevents negative indices
        ;

    // 2.c handled
    if (trav == NULL) // LL overrun
    {
        cout << "Insert Error: List overrun\n";
        return;
    }

    // within bounds
    Node *newnode = new Node(data);
    newnode->next = trav->next;
    trav->next = newnode;
    return;
}

void deleteNode(Node *&head, int index)
{
    if (head == NULL || index < 0)
    {
        cout << "Delete Error: Empty List or negative index\n";
        return; // nothing to delete, empty LL.
    }
    if (index == 0) // change in head required.
    {
        Node *p = head;
        head = head->next;
        delete p;
        return;
    }

    Node *trav = head;
    for (int i = 0; i < index - 1 && trav->next != NULL; i++, trav = trav->next)
        ;

    if (trav->next == NULL)
    {
        cout << "Delete Error: Index Overrun\n";
        return; //overrun
    }

    Node *p = trav->next;
    trav->next = p->next;
    delete p;
}
/*
class Node
{
    int data;
    Node *next;

public:
    inline static Node *head = NULL;
    inline static int node_count = 0;

    Node(int data = 0)
    {
        node_count++;
        this->data = data;
        this->next = NULL;
    }

    Node(const Node &t)
    {
        node_count++;
        this->data = t.data;
        this->next = NULL;
    }

    static void print()
    {
        Node *trav = head;
        while (trav != NULL)
        {
            cout << trav->data << " ";
            trav = trav->next;
        }
        cout << endl;
    }

    void add_at(int index, int data)
    {
        if (index == 0)
        {
            Node *newnode = new Node;
            newnode->data = data;
            newnode->next = this;

            head = newnode;
            return;
        }
        Node *trav = head;
        // for replacing head at ith index, we need to reach the i-1 th index.
        // n-1 steps

        for (int i = 0; trav != NULL && i < index; i++, trav = trav->next)
            ;

        if (trav == NULL)
            return;
        Node *newnode = new Node;
        newnode->data = data;

        newnode->next = trav->next;
        trav->next = newnode;
    }

    ~Node()
    {
        node_count--;
    }
};
*/
