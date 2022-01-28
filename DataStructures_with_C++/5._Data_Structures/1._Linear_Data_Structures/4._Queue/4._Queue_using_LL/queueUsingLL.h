template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T idata)
    {
        data = idata;
        next = NULL;
    }
};

template <typename T>
class QueueUsingLL
{
private:
    Node<T> *head, *tail;
    int size;

public:
    QueueUsingLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool isEmpty() // checks if empty or not
    {
        return size == 0;
    }

    int getSize() // returns the number of elements present in the queue
    {
        return size;
    }

    void enqueue(T idata) // inserts data
    {
        // add node to tail, independent of head generally except the first element
        if (size == 0)
        {
            Node<T> *newNode = new Node<T>(idata);
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
        }
        else // i.e a tail is present, adding to end of LL, does work for single node LL.
        {
            Node<T> *newNode = new Node<T>(idata);
            tail->next = newNode; // newnode always points at NULL
            tail = tail->next;
            newNode->next = NULL;
        }
        size++; // common in both
    }

    T dequeue()
    { // 2 cases are possible, zero and non zero. Removed case of 1 because we are using circular LinkedList
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return 0; // generic value
        }
        else if (size == 1) // dequeuing is generally independent of tail, but this is an exception
        {
            T ans = head->data;
            delete head;
            head = NULL;
            tail = NULL;
            size = 0; // same as size--
            return ans;
        }
        else
        {
            // independent of the tail
            T ans = head->data;
            Node<T> *to_be_deleted = head; // node to be deleted
            head = head->next;             //head updated
            delete to_be_deleted;
            size--;
            return ans;
        }
    }

    T front()
    {
        if (size == 0)
            return 0;
        return head->data;
    }

    void print()
    {
        cout << "f[";
        if (size == 0)
        {
            cout << "]b\n";
            return;
        }
        for (Node<T> *trav = head; trav != NULL; trav = trav->next) // move clockwise circularly, print size number of times
            cout << trav->data << ", ";
        cout << "\b\b]b\n";
    }
};

/*
    Insights:
        1. No need of being circular here.
        2. We mainatin a size here in order to keep getSize() TC o(1)
        3. Enqueue has a special case here, when both head and tail are NULL. Otherwise, enqueueing is independent of the head, even for a singleton queue.
        4. Dequeue has 2 special cases, first the one on for an empty queue(which is trivial), other being for singleton queue, as the tail also needs to be updated.
                Else it is independent of the tail.
        5. Special cases are formed by: trivial things + observing the variables which need a change even though they don't require so for the general case(as per the ADT sugar - ADT intuition)
*/
