#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class Stack
{
private:
    int nextIndex; // the position where we are ready to write
    int capacity;
    T *data;

public:
    Stack()
    {
        data = new T[1];
        nextIndex = 0;
        capacity = 2;
    }

    Stack(const Stack &t)
    {
        data = new T[t.capacity];
        for (nextIndex = 0; nextIndex < t.nextIndex; nextIndex++)
            data[nextIndex] = t.data[t.nextIndex];
        // copy everything till the nextIndex, excluding it.
    }

    void operator=(const Stack &t)
    {
        delete[] data;
        nextIndex = 0;

        data = new T[t.capacity];
        for (nextIndex = 0; nextIndex < t.nextIndex; nextIndex++)
            data[nextIndex] = t.data[t.nextIndex];
    }

    int size() // returns the number of elements present
    {
        return nextIndex; // as number of elements before nextIndex index is just its value
    }

    bool isEmpty() //returns if the stack is empty
    {
        return nextIndex == 0; // woah
    }

    void push(T element) //insert the element
    {
        if (nextIndex == capacity) // max value of nextIndex can be (capacity - 1)
        {
            T *newdata = new T[capacity * 2];
            for (int i = 0; i < nextIndex; i++) // copied
                newdata[i] = data[i];

            delete[] data; // old array deleted
            data = newdata;
            capacity *= 2; // change the capacity
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int top() // delete the element
    {
        if (!isEmpty())
            return data[nextIndex - 1];
        cout << "Stack is empty\n";
        return 0; // cannot use INT_MIN as that's int specific
    }

    int pop()
    {
        if (!isEmpty())
            nextIndex--;
        cout << "Stack is empty\n";
        return 0; // cannot use INT_MIN as that's int specific
    }

    void print()
    {
        cout << "[";
        for (int i = 0; i < nextIndex; i++) // will not display even in nextIndex is zero
            cout << data[i] << ", ";
        if (nextIndex == 0)
            cout << "]\n";
        else
            cout << "\b\b]-\n";
    }
};
