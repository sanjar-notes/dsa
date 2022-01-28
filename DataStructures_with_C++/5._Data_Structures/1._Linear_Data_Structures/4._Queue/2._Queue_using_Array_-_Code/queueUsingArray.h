template <typename T>
class QueueUsingArray
{
private:
    T *data;
    int size;
    int capacity;
    int nextIndex;
    int firstIndex;

public:
    QueueUsingArray(int cap)
    {
        if (cap == 0)
            capacity = 1;
        else
            capacity = cap;
        data = new T[capacity];
        nextIndex = 0;
        firstIndex = -1; // i.e no head now
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
        if (size == 0)
        {
            data[0] = idata;
            firstIndex = 0;
            nextIndex = 1;
            size = 1;
            return;
        }
        else if (size == capacity)
        {
            cout << "Queue is full\n";
            return;
        }
        // else
        data[nextIndex] = idata;
        nextIndex = (nextIndex + 1) % capacity; // change only at entry point
        size++;
    }

    T dequeue()
    { // 2 cases are possible, zero and non zero. Removed case of 1 because we are using circular LinkedList
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return 0;
        }
        else if (size == 1) // we will refresh our queue here, FOR DEBUGGING ONLY
        {
            T ans = data[firstIndex];
            firstIndex = -1; // initialize as fresh
            nextIndex = 0;
            size = 0;
            return ans;
        }
        else
        {
            T ans = data[firstIndex];
            firstIndex = (firstIndex + 1) % capacity; // change at the exit point
            size--;
            return ans;
        }
    }

    T front()
    {
        if (size == 0)
            return 0;
        return data[firstIndex];
    }

    void print()
    {
        cout << "f1[";
        if (size == 0)
        {
            cout << "]b\n";
            return;
        }
        for (int i = firstIndex, count = 0; count < size; i = (i + 1) % capacity, count++) // move clockwise circularly, print size number of times
            cout << data[i] << ", ";
        cout << "\b\b]b\n";
    }
};

/*
    Insights:
        1. We never shift here. That is too time consuming, and is dependent on the type of data;
        2. size has to be kept seperately coz if firstIndex and nextIndex are equal there are two answers. So size is not a function od last and firstIndex. Hence, cannot be calculated.
        3. We learnt to move circularly using count this is great. This made our lives easier, for printing and all.
        4. We make the enqueue to init as fI = 0 and nI = 1, this is done because the the firstIndex does not exist. Hence it has to be made -1.
            If it is 0, then front() will return garbage even if not element has been enqueued.
            Technically, this does not change efficiency in any way. Except that a single. But is better for debugging purposes.
*/



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
/*
class Node{
    public:
        int data;
        Node* next;
};

class Deque {
    int* head, *tail, size, capacity;
    public:
    Deque(int cap)
    {
        size = 0;
        capacity = cap;
        head = NULL;
        tail = NULL;
    }
    void insertfront(int data)
    {

        Node* newNode =  new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void

};

*/
