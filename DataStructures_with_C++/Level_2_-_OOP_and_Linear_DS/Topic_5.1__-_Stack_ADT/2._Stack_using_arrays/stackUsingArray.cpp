#include <iostream>
#include <climits>
using namespace std;

class Stack
{
private:
    int nextIndex; // the position where we are ready to write
    int *data;
    int capacity;

public:
    Stack(int totalSize = 0)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    Stack(const Stack &t)
    {
        data = new int[t.capacity];
        for (nextIndex = 0; nextIndex < t.nextIndex; nextIndex++)
            data[nextIndex] = t.data[t.nextIndex];
        // copy everything till the nextIndex, excluding it.
    }

    void operator=(const Stack &t)
    {
        delete data;
        nextIndex = 0;

        data = new int[t.capacity];
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

    void push(int element) //insert the element
    {
        if (nextIndex == capacity) // max value of nextIndex can be (capacity - 1)
        {
            cout << "Stack is full\n";
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int top() // delete the element
    {
        if (!isEmpty())
            return data[nextIndex - 1];
        cout << "Stack is empty\n";
        return INT_MIN;
    }

    int pop()
    {
        if (!isEmpty())
            nextIndex--;
        cout << "Stack is empty\n";
        return INT_MIN;
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
