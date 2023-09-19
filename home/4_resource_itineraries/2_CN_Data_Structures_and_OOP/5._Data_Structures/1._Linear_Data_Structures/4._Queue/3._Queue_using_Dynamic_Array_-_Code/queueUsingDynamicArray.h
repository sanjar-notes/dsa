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
        nextIndex = 0;   // the exit point, not at the last element, as ADT has no need/spec in interface for accessing last element
        firstIndex = -1; // first Element of the quueue, points to the element because we need to remove it, and acess for front.
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

        if (size == 0) // this is important coz we need to take care of the -1 as firstIndex
        {
            data[0] = idata;
            firstIndex = 0;
            nextIndex = 1;
            size = 1;
            return;
        }
        else if (size == capacity)
        {
            T *newQueue = new T[capacity * 2];
            for (int i = firstIndex, count = 0; count < size; i = (i + 1) % capacity, count++) // rearrange while copying, for fastre access
                newQueue[count] = data[i];                                                     // This rearrangement is mandatory, as circularity needs to be maintained

            delete[] data; // delete old array
            data = newQueue;
            data[capacity] = idata; // write the data

            firstIndex = 0; // set the attributes as a linear queue
            size++; // same as capacity + 1
            nextIndex = size;
            capacity *= 2;
            // cout << "Queue is full\n"; This has been handled
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
            size--; // i.e size  = 0
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
        cout << "f2[";
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
        3. We learnt to move circularly using count this is great. This made our lives easier, for printing and all. This relieves us from all ops in a circular stucture.
        4. The dynamic size doubling, rearranged the queue as linear, coz making the queue cicrulat requires that all elements are first in a line before the capacity is full.
            i.e we have to open the necklace to extend it, and as head is to be preserved, hence we need to open the necklace from the head index only.
        5. We make the enqueue to init as fI = 0 and nI = 1, this is done because the the firstIndex does not exist. Hence it has to be made -1.
            If it is 0, then front() will return garbage even if not element has been enqueued.
            Technically, this does not change efficiency in any way. Except that a single. But is better for debugging purposes.
*/
