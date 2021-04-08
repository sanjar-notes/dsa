#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next; // as we have to read the next node, knowing about it is important, hence Node is now bound with <>.
    Node(T element)
    {
        data = element;
        next = NULL;
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    Stack(const Stack &t)
    {
        if (t.head == NULL) // nothing to do for empty stack
        {
            head = NULL;
            size = 0;
        }
        else
        {
            head = new Node<T>;        // head created
            head->data = t.head->data; // head's data is set
            head->next = NULL;         // head next is NULL for now

            Node<T> *trav = head;    // at the node where a node needs to be inserted
            Node<T> *travt = t.head; // node at the second node

            while (travt->next != NULL)
            {
                trav->next = new Node<T>(travt->next->data);
                trav = trav->next;
                travt = travt->next;
            }
            trav->next = NULL;
        }
    }

    // void operator=(const Stack &t)
    // {
    // }

    int getSize() // returns the number of elements present
    {
        return size; // as number of elements before nextIndex index is just its value
    }

    bool isEmpty() //returns if the stack is empty
    {
        return size == 0; // woah
    }

    void push(T element)
    {
        Node<T> *newnode = new Node<T>(element); // works for the first insertion too.
        newnode->next = head;
        head = newnode;
        size++;
    }

    T pop()
    {
        // Return 0 if stack is empty. Don't display any other message
        if (size == 0)
            return 0;
        T pop_val = head->data;
        Node<T> *to_be_popped = head;
        head = head->next;   // move head
        delete to_be_popped; // delete old head
        size--;
        return pop_val;
    }

    T top()
    {
        // Return 0 if stack is empty. Don't display any other message
        if (size == 0)
            return 0;
        return head->data;
    }

    void print()
    {
        cout << "-[";
        for (Node<T> *trav = head; trav != NULL; trav = trav->next) // will not display even in nextIndex is zero
            cout << trav->data << ", ";
        if (size == 0)
            cout << "]\n";
        else
            cout << "\b\b]\n";
    }
};
